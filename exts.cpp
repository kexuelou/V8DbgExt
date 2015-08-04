/*-----------------------------------------------------------------------------
   Copyright (c) 2000  Microsoft Corporation

Module:
  exts.cpp

  Sampe file showing couple of extension examples
  
  wzhao@microsoft.com added V8 Script Engine Debugging Feature
-----------------------------------------------------------------------------*/

#include "v8dbgexts.h"
#include <string.h>
#include "v8constants.h"
#include "utils.h"

bool isDbg()
{
#ifdef _DEBUG
	return 1;
#else
	return 0;
#endif

}
#pragma region UTILS


//#define DBG_TRACE (dprintf("%s(%d)-<%s>: ", __FILE__, __LINE__, __FUNCTION__), dprintf)
#define DBG_TRACE(fmt, ...) \
		if (isDbg()) \
					{dprintf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); dprintf("\n");}


			//(dprintf("%s(%d)-<%s>: ", __FILE__, __LINE__, __FUNCTION__), dprintf)
											
		//
//#define DBG_TRACE(fmt, ...) \
//		vsprintf_s(debug_message, 255, "%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
//		OutputDebugStringA(debug_message);

void DBG_OUT(PCSTR format, ULONG64 value)
{
#ifdef _DEBUG
	//dprintf("\n******\t");
	dprintf(format, value);
	//dprintf("\t******\n");
#endif
}

void DBG_OUT_LN(PCSTR format, ULONG64 value)
{
#ifdef _DEBUG
	//dprintf("\n******\t");
	dprintf(format, value);
	dprintf("\n");
#endif
}

#pragma endregion


//clear the last two bits of V8 object PTR
#define	V8_OFF_HEAP(x)			((x) - _V8DBG_HEAPOBJECTTAG)

//clear the last two bits of V8 object PTR
#define DEV8PTR(ptr)  ((INT64)ptr & 0xfffffffc)

/*
* Determine the encoding and representation of a V8 string.
*/
#define	V8_TYPE_STRING(type)	(((type) & _V8DBG_ISNOTSTRINGMASK) == _V8DBG_STRINGTAG)

//is ASCII string
#define	V8_STRENC_ASCII(type)	(((type) & _V8DBG_STRINGENCODINGMASK) == _V8DBG_ASCIISTRINGTAG)

//is Two-Byte string
#define	V8_STRENC_TWOBYTE(type)	(((type) & _V8DBG_STRINGENCODINGMASK) == _V8DBG_TWOBYTESTRINGTAG)


//isSMI
#define	V8_IS_SMI(ptr)		(((ptr) & _V8DBG_SMITAGMASK) == _V8DBG_SMITAG)

#define	V8_SMI_VALUE(value)		((UINT32)((value) >> (_V8DBG_SMIVALUESHIFT + _V8DBG_SMISHIFTSIZE) ))

#define	V8_IS_HEAPOBJECT(ptr)	(((ptr) & _V8DBG_HEAPOBJECTTAGMASK) == _V8DBG_HEAPOBJECTTAG)

//Sequence String
#define	V8_STRREP_SEQ(type)	(((type) & _V8DBG_STRINGREPRESENTATIONMASK) == _V8DBG_SEQSTRINGTAG)

//Concat String
#define	V8_STRREP_CONS(type) (((type) & _V8DBG_STRINGREPRESENTATIONMASK) == _V8DBG_CONSSTRINGTAG)

//Sliced String 
//#define	V8_STRREP_SLICED(type) (((type) & _V8DBG_STRINGREPRESENTATIONMASK) == v8dbg_SlicedStringTag)

//External String
#define	V8_STRREP_EXT(type)	(((type) & _V8DBG_STRINGREPRESENTATIONMASK) == _V8DBG_EXTERNALSTRINGTAG)

//Script Object
#define	V8_TYPE_SCRIPT(type)	(type == _V8DBG_TYPE_SCRIPT__SCRIPT_TYPE)

//Object properties
#define	V8_DESC_ISFIELD(x)	((V8_SMI_VALUE(x) & _V8DBG_PROP_TYPE_MASK) == _V8DBG_PROP_TYPE_FIELD)

#define	V8_PROP_FIELDINDEX(value)	((V8_SMI_VALUE(value) & _V8DBG_FIELDINDEX_MASK) >> _V8DBG_FIELDINDEX_SHIFT)


HRESULT dumpStringWithWidth(ULONG64 offSet, int width)
{
	CHAR mem;
	ULONG bytes;
	ULONG64 address = offSet;
	int len = 0;
	while (len < MAX_PATH)
	{
		if (!ReadMemory(address+len, &mem, 1, &bytes))
			return S_FALSE;
		if (mem == 0)
		{
			break;
		}
		else
		{
			dprintf("%c", mem);
			len++;
		}
	}
	
	while (len < width)
	{
		dprintf(" ");
		len++;
	}
	return S_OK;
}



HRESULT ReadString(ULONG64 address, ULONG lenth, char* buffer)
{
	CHAR chr;
	ULONG bytes;
	ULONG i = 0;
	while (i < lenth)
	{
		if (!ReadMemory(address + i, &chr, 1, &bytes))
			return S_FALSE;

		if (chr == 0)
		{
			break;
		}
		
		buffer[i] = chr;
		i++;
	}

	buffer[i] = 0;
	return S_OK;
}



HRESULT dumpString(ULONG64 offSet)
{
	CHAR mem;
	ULONG bytes;
	ULONG64 address = offSet;
	int len = 0;
	while (len < MAX_PATH)
	{
		if (!ReadMemory(address + len, &mem, 1, &bytes))
			return S_FALSE;
		if (mem ==0)
		{
			break;
		}
		else
		{
			if (mem > 31) //ignore invisible
				dprintf("%c", mem);
			else 
				dprintf("%c", '.');
			len++;
		}
	}

	return S_OK;
}

//
//extern "C"
//HRESULT CALLBACK
//dumpCallStack(PDEBUG_CLIENT4 Client, PCSTR args)
//{
//
//	INIT_API();
//
//	UNREFERENCED_PARAMETER(args);
//
//
//	dprintf("%d", v8dbg_FirstNonstringType);
//
//	EXIT_API();
//	return S_OK;
//}


extern "C"
HRESULT CALLBACK
dumpCurrentRequestUrl(PDEBUG_CLIENT4 Client, PCSTR args)
{
	INIT_API();

	UNREFERENCED_PARAMETER(args);

	

	EXIT_API();
	return S_OK;
}

/*
  This gets called (by DebugExtensionNotify whentarget is halted and is accessible
*/
HRESULT
NotifyOnTargetAccessible(PDEBUG_CONTROL Control)
{
    /*dprintf("Extension dll detected a break");
    if (Connected) {
        dprintf(" connected to ");
        switch (TargetMachine) {
        case IMAGE_FILE_MACHINE_I386:
            dprintf("X86");
            break;
        case IMAGE_FILE_MACHINE_IA64:
            dprintf("IA64");
            break;
        default:
            dprintf("Other");
            break;
        }
    }*/
    //dprintf("\n");

    //
    // show the top frame and execute dv to dump the locals here and return
    //
    //Control->Execute(DEBUG_OUTCTL_ALL_CLIENTS |
    //                 DEBUG_OUTCTL_OVERRIDE_MASK |
    //                 DEBUG_OUTCTL_NOT_LOGGED,
    //                 ".frame", // Command to be executed
    //                 DEBUG_EXECUTE_DEFAULT );
    //Control->Execute(DEBUG_OUTCTL_ALL_CLIENTS |
    //                 DEBUG_OUTCTL_OVERRIDE_MASK |
    //                 DEBUG_OUTCTL_NOT_LOGGED,
    //                 "dv", // Command to be executed
    //                 DEBUG_EXECUTE_DEFAULT );
    return S_OK;
}

int ReadByte(UINT8 *out, ULONG_PTR addr)
{
	ULONG cb = 0;

	//get the instance attributes at addr + _V8DBG_CLASS_MAP__INSTANCE_ATTRIBUTES__INT  == addr + 0x8
	if (ReadMemory(addr, out, sizeof(*out), &cb) && cb == sizeof(*out))
	{
		return 0;
		//DBG_TRACE("Type byte for object %x is %x\n", addr, *out);

		/*DBG_OUT("Type byte for object %p ", addr);
		DBG_OUT("is %d\n", *out);*/
	}
	return -1;

}

//Get the Addr of Object Map
int ReadMapAddr(ULONG_PTR *out, ULONG_PTR addr)
{
	ULONG cb = 0;
	//ULONG_PTR mapObj;

	//if (ReadMemory(addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP, &mapObj, sizeof(mapObj), &cb) && cb == sizeof(mapObj))
	//{
	//	DBG_TRACE("Map for object @ %p is %p\n", addr, mapObj);
	//}

	//get the map at addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP == addr + 0x0
	if (ReadMemory(addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP, out, sizeof(ULONG_PTR), &cb) && cb == sizeof(ULONG_PTR))
	{
		DBG_TRACE("Map for object @ %x is %x\n", addr, *out);
		return 0;
	}
	else
	{
		DBG_TRACE("Failed to read Map for Object %x\n", addr);
		return -1;
	}
	
}

//Read the type byte of an Object
int GetTypeByte(UINT8* typeByte, ULONG_PTR addr)
{
	ULONG cb = 0;
	ULONG_PTR mapObj;
	//ULONG_PTR mapobj2;


	//get the map at addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP == addr + 0x0
	//DBG_TRACE("reading memory at at %p\n", addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP);
	//if (ReadMemory(addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP, &mapobj2, sizeof(mapobj2), &cb) && cb == sizeof(mapobj2))
	//{
	//	DBG_TRACE(" test Map for object @ %p is %p\n", addr + _V8DBG_CLASS_HEAPOBJECT__MAP__MAP, mapobj2);
	//}

	if (ReadMapAddr(&mapObj, DEV8PTR(addr)) == 0)
	{
		//DBG_TRACE("Map for object %x @ %x\n", addr, mapObj);

		//get the instance attributes at addr + _V8DBG_CLASS_MAP__INSTANCE_ATTRIBUTES__INT  == addr + 0x8
		if (ReadByte(typeByte, DEV8PTR(mapObj) + _V8DBG_CLASS_MAP__INSTANCE_ATTRIBUTES__INT) == 0)
		{
			return 0;
		}
	}

	DBG_TRACE("Failed to read typeByte for object @ %x\n", addr);
	return -1;
	
}


#pragma region GetTtypeString

void V8TypeToString(UINT8 objType, char** typeStr)
{
	*typeStr = (char*)malloc(50);
	switch (objType) {
#define X(uc, lc) case _V8DBG_TYPE_##uc: *typeStr = #lc; break;
		V8_OBJECT_TYPE_MAP(X)
#undef X
default: *typeStr = "<unknown>";
	}

	//DBG_TRACE("typestring: %x", typeStr);

	DBG_TRACE("type:%d(%s)", objType, *typeStr);
}


void V8FrameTypeToString(UINT8 objType, char** typeStr)
{
	*typeStr = (char*)malloc(50);
	switch (objType) {
#define X(uc, lc) case _V8DBG_FRAMETYPE_##uc: *typeStr = #lc; break;
		V8_FRAME_TYPE_MAP(X)
#undef X
	default: *typeStr = "UNKNOWN";
	}

	DBG_TRACE("type:%d(%s)", objType, *typeStr);
}



#pragma endregion

/*
* Like read_heap_ptr, but assume the field is an SMI and store the actual value
* into *valp rather than the encoded representation.
*/
int read_heap_smi(ULONG_PTR *valp, ULONG_PTR addr)
{
	ULONG smi;
	ULONG cb = 0;

	//Read the smi at specified address
	if (ReadMemory(addr, &smi, sizeof(smi), &cb) && cb == sizeof(&smi))
	{
		if (!V8_IS_SMI(smi)) {
			DBG_OUT("%d is not a SMI object", addr);
			return (-1);
		}

		*valp = V8_SMI_VALUE(smi);
		DBG_TRACE("SMI is %d, value = %d", smi, *valp);
	}
	else
	{
		dprintf("Failed to read SMI @ %p\n", addr);
	}

	return (0);
}


/*
* Given a heap object, returns in *valp the size of the object.  For
* variable-size objects, returns an undefined value.
*/
int read_size(size_t *valp, ULONG_PTR addr)
{
	ULONG_PTR mapaddr;
	UINT8 size;

	if (ReadMapAddr(&mapaddr, addr) != 0)
		return (-1);

	if (!V8_IS_HEAPOBJECT(mapaddr)) {
		DBG_TRACE("object %x map %x is not itself a heap object\n", addr, mapaddr);
		return (-1);
	}

	if (ReadByte(&size, DEV8PTR(mapaddr) + _V8DBG_CLASS_MAP__INSTANCE_SIZE__INT) != 0)
		return -1;

	*valp = size << _V8DBG_POINTERSIZELOG2;
	DBG_TRACE("object %x size %d(%d)", addr, size, *valp);

	return (0);
}


/*
* Assuming "addr" refers to a FixedArray that is implementing a
* StringDictionary, iterate over its contents calling the specified function
* with key and value.
*/
//
//int read_heap_dict(ULONG_PTR addr) //, int(*func)(const char *, uintptr_t, void *), void *arg)
//{
//	UINT8 type;
//	ULONG_PTR len;
//	char buf[512];
//	char *bufp;
//	int rval = -1;
//	ULONG_PTR *dict;
//	size_t ndict, i;
//
//	if (read_heap_array(addr, &dict, &ndict, 0) != 0)
//		return (-1);
//
//	if (_V8DBG_CLASS_NUMBERDICTIONARYSHAPE__ENTRY_SIZE__INT < 2) {
//		DBG_TRACE("dictionary entry size (%d) is too small for a "
//			"key and value\n", _V8DBG_CLASS_NUMBERDICTIONARYSHAPE__ENTRY_SIZE__INT);
//		goto out;
//	}
//
//	for (i = V8_DICT_START_INDEX + V8_DICT_PREFIX_SIZE; i < ndict;
//		i += _V8DBG_CLASS_NUMBERDICTIONARYSHAPE__ENTRY_SIZE__INT) {
//		/*
//		* The layout here is key, value, details. (This is hardcoded
//		* in Dictionary<Shape, Key>::SetEntry().)
//		*/
//		if (jsobj_is_undefined(dict[i]))
//			continue;
//
//		if (V8_IS_SMI(dict[i])) {
//			intptr_t val = V8_SMI_VALUE(dict[i]);
//			(void)snprintf(buf, sizeof(buf), "%" PRIdPTR, val);
//		}
//		else {
//			if (jsobj_is_hole(dict[i])) {
//				/*
//				* In some cases, the key can (apparently) be a
//				* hole, in which case we skip over it.
//				*/
//				continue;
//			}
//
//			if (read_typebyte(&type, dict[i]) != 0)
//				goto out;
//
//			if (!V8_TYPE_STRING(type))
//				goto out;
//
//			bufp = buf;
//			len = sizeof(buf);
//
//			if (jsstr_print(dict[i], JSSTR_NUDE, &bufp, &len) != 0)
//				goto out;
//		}
//
//		if (func(buf, dict[i + 1], arg) == -1)
//			goto out;
//	}
//
//	rval = 0;
//out:
//	mdb_free(dict, ndict * sizeof(uintptr_t));
//
//	return (rval);
//}


/*
* Assuming "addr" refers to a FixedArray, return a newly-allocated array
* representing its contents.
*/
int read_heap_array(ULONG_PTR addr, ULONG_PTR **retp, size_t *lenp, int flags)
{
	UINT8 type;
	ULONG_PTR len;
	ULONG cb = 0;
	ULONG i = 0;

	if (!V8_IS_HEAPOBJECT(addr))
	{
		DBG_OUT_LN("Not a valid HeapObject @ %p", addr);
		return (-1);
	}

	if (GetTypeByte(&type, addr) != 0)
	{
		DBG_OUT_LN("Failed to read the Array Lenth @ %p", addr);
		return (-1);
	}

	//fixed array
	if (type != _V8DBG_TYPE_FIXEDARRAY__FIXED_ARRAY_TYPE)
		return (-1);

	//read the array length
	if (read_heap_smi(&len, DEV8PTR(addr) + _V8DBG_CLASS_FIXEDARRAYBASE__LENGTH__SMI) != 0)
	{
		DBG_OUT_LN("Failed to read the Array Lenth @ %p", addr);
		return (-1);
	}

	*lenp = len;

	DBG_TRACE("Array @ %x contains %d items", addr, len);

	if (len == 0) {
		*retp = NULL;
		return (0);
	}


	if ((*retp = (ULONG_PTR *)malloc(len * sizeof(ULONG_PTR))) == NULL)
		return (-1);

	//get the array data start from addr + v8dbg_class_FixedArray__data__uintptr_t == addr + 0x8
	if (ReadMemory(DEV8PTR(addr) + _V8DBG_CLASS_FIXEDARRAY__DATA__UINTPTR_T, *retp, sizeof(ULONG_PTR)*len, &cb) && cb == sizeof(ULONG_PTR)*len)
	{
		for (i = 0; i < len; i++)
		{
			DBG_TRACE("item %d: %x", i, *(*retp+i));
		}
			
		return 0;
	}
	else
	{
		DBG_OUT_LN("failed to read data for array %p ", addr);
		return -1;
	}

	return (0);
}



//
int isStringObject(ULONG_PTR strObj)
{
	UINT8 typeByte;

	if (GetTypeByte(&typeByte, DEV8PTR(strObj)) != 0) {
		DBG_OUT("Failed to Read Type Byte for %p\n", DEV8PTR(strObj));
		return 0;
	}

	DBG_OUT("Type Byte for %p ", DEV8PTR(strObj));
	DBG_OUT("is %d", typeByte);

	if (!V8_TYPE_STRING(typeByte))
	{
		DBG_OUT("object @ %p is not a string object\n", strObj);
		return 0;
	}

	return 1;
}


char* Read_heap_string(ULONG_PTR strObj);

#pragma region odball
/*
* Returns true if the given address refers to the named oddball object (e.g.
* "undefined").  Returns false on failure (since we shouldn't fail on the
* actual "undefined" value).
*/
int jsobj_is_oddball(ULONG_PTR addr, char *oddball)
{
	UINT8 type;
	ULONG_PTR strptr;
	char* typeStr;
	char buf[16];
	char *bufp = buf;
	size_t len = sizeof(buf);
	ULONG cb;

	//v8_silent++;
	if (GetTypeByte(&type, addr) != 0) {
		//v8_silent--;
		return 0;
	}

	//v8_silent--;
	V8TypeToString(type, &typeStr);
	DBG_TRACE("Type string: %x", typeStr);
	DBG_TRACE("Object: %x Type : %s", addr, typeStr);
	
	if (strcmp(typeStr, "ODDBALL_TYPE") != 0)
		return 0;

	if (ReadMemory(DEV8PTR(addr) + _V8DBG_CLASS_ODDBALL__TO_STRING__STRING, &strptr, sizeof(strptr), &cb) && cb == sizeof(strptr))
		return 0;

	bufp = Read_heap_string(strptr);

	return (strcmp(buf, oddball) == 0);
}

int jsobj_is_undefined(ULONG_PTR addr)
{
	return (jsobj_is_oddball(addr, "undefined"));
}

int jsobj_is_hole(ULONG_PTR addr)
{
	return (jsobj_is_oddball(addr, "hole"));
}

#pragma endregion



int PrintStringObject(ULONG_PTR strObj);
/* return value:
0: empty string
-1: failed to read string content
1: good
*/
int PrintConsStringObject(ULONG_PTR strObj, UINT8 objType)
{
	ULONG_PTR part1;
	ULONG_PTR part2;
	ULONG cb = 0;

	//First part of Cons stirng _V8DBG_CLASS_CONSSTRING__FIRST__STRING
	if (! (ReadMemory(strObj + _V8DBG_CLASS_CONSSTRING__FIRST__STRING, &part1, sizeof(part1), &cb) && cb == sizeof(part1)) )
	{
		DBG_OUT("Failed to read first part of Cons String %p\n", strObj);
		return -1;
	}
	DBG_OUT("First part of Cons String %p ", strObj);
	DBG_OUT("is  %p\n", part1);
	
	//Second part of Cons string _V8DBG_CLASS_CONSSTRING__SECOND__STRING
	if (! (ReadMemory(strObj + _V8DBG_CLASS_CONSSTRING__SECOND__STRING, &part2, sizeof(part2), &cb) && cb == sizeof(part2)) )
	{
		DBG_OUT("Failed to read second part of Cons String %p\n", strObj);
		return -1;
	}

	DBG_OUT("Second part of Cons String %p ", strObj);
	DBG_OUT("is  %p", part2);
	
	if (PrintStringObject(DEV8PTR(part1)) == -1)
		return -1;
	return PrintStringObject(DEV8PTR(part2));

}



char* ReadConsStringObject(ULONG_PTR strObj, UINT8 objType)
{
	ULONG_PTR part1;
	ULONG_PTR part2;
	ULONG cb = 0;
	char* strPart1;
	char* strPart2;
	char* buf;
	int len;

	//First part of Cons stirng _V8DBG_CLASS_CONSSTRING__FIRST__STRING
	if (!(ReadMemory(strObj + _V8DBG_CLASS_CONSSTRING__FIRST__STRING, &part1, sizeof(part1), &cb) && cb == sizeof(part1)))
	{
		DBG_OUT_LN("ReadConsStringObject -- Failed to read first part of Cons String %p\n", strObj);
		return NULL;
	}
	DBG_OUT("ReadConsStringObject -- First part of Cons String %p ", strObj);
	DBG_OUT_LN("is  %p", part1);

	//Second part of Cons string _V8DBG_CLASS_CONSSTRING__SECOND__STRING
	if (!(ReadMemory(strObj + _V8DBG_CLASS_CONSSTRING__SECOND__STRING, &part2, sizeof(part2), &cb) && cb == sizeof(part2)))
	{
		DBG_OUT_LN("ReadConsStringObject -- Failed to read second part of Cons String %p\n", strObj);
		return NULL;
	}

	DBG_OUT("ReadConsStringObject --  Second part of Cons String %p ", strObj);
	DBG_OUT_LN("is  %p", part2);

	strPart1 = Read_heap_string(DEV8PTR(part1));

	strPart2 = Read_heap_string(DEV8PTR(part2));

	if ((NULL == strPart1))
		return strPart2;
	
	if (NULL == strPart2)
		return strPart1;

	len = strlen(strPart1) + strlen(strPart2) + 1;
	DBG_OUT_LN("ReadConsStringObject --  string's final length is %d", len);

	buf = (char*)malloc(len);
	if (NULL == buf)
	{
		DBG_OUT_LN("ReadConsStringObject -- failed to allocate string buffer, the length is %d", len);
		return NULL;
	}

	if (strcpy_s(buf, len, strPart1) != 0)
	{
		DBG_OUT_LN("ReadConsStringObject -- failed to copy the first part of the string: %s", (ULONG64)strPart1);
		return NULL;
	}

	if (strcat_s(buf, len, strPart2) != 0)
	{
		DBG_OUT_LN("ReadConsStringObject -- failed to copy the second part of the string: %s", (ULONG64)strPart2);
		return NULL;
	}

	free(strPart1);
	free(strPart2);

	return buf;
}


/*
NULL if:
    failed to read the string
	empty string
*/

char* ReadSeqStringObject(ULONG_PTR strObj, UINT8 objType)
{
	ULONG len = 0;
	ULONG offset = 0;
	ULONG cb = 0;

	char *buf;

	//For SeqString length is v8dbg_class_String__length__SMI is 8
	read_heap_smi(&len, strObj + _V8DBG_CLASS_STRING__LENGTH__SMI);
	

	if (len == 0)
	{
		DBG_OUT_LN("ReadSeqStringObject -- Length of String %p is 0x0", strObj);
		return NULL;
	}

	//len = V8_SMI_VALUE(len);

	DBG_TRACE("ReadSeqStringObject -- length is %d", len);
	
	//no matter one byte string or two bytes string, both start from 0xc.
	//offset = V8_STRENC_ASCII(objType) ? _V8DBG_CLASS_SEQASCIISTRING__CHARS__CHAR : v8dbg_class_SeqTwoByteString__chars__char;
	offset = _V8DBG_CLASS_SEQONEBYTESTRING__CHARS__CHAR;
		


	//For ASCII string the first char is started at strObj + _V8DBG_CLASS_SEQASCIISTRING__CHARS__CHAR
	//For two bytes string the first char is started at strObj + v8dbg_class_SeqTwoByteString__chars__char
	buf = (char*)malloc(len+1);

	if (NULL == buf)
	{
		DBG_OUT_LN("ReadSeqStringObject -- failed to allocate buf for string, the length is %d", len);
		return NULL;
	}

	if (ReadMemory(strObj + offset, buf, len, &cb) && cb == len)
	{
		buf[len] = '\0';
		DBG_OUT_LN("ReadSeqStringObject -- string is : %s", (ULONG64)buf);
	}
	else
	{
		DBG_OUT_LN("ReadSeqStringObject -- failed to read string content at: ", strObj);
		return NULL;
	}

	return buf;
}



char* Read_heap_string(ULONG_PTR strObj)
{
	//char* buf;
	ULONG cb = 0;
	ULONG len = 0;
	ULONG offset = 0;

	UINT8 objType;

	if (GetTypeByte(&objType, DEV8PTR(strObj)) != 0) {
		DBG_OUT_LN("Failed to Read Type Byte for %p\n", DEV8PTR(strObj));
		return NULL;
	}

	if (!V8_TYPE_STRING(objType))
	{
		DBG_OUT("object @ %p is not a string object\n", strObj);
		return NULL;
	}

	if (V8_STRREP_SEQ(objType))
	{
		DBG_OUT_LN("Read_heap_string -- string %p is a Seq-String", DEV8PTR(strObj));
		return ReadSeqStringObject(strObj, objType);
	}

	if (V8_STRREP_CONS(objType))
	{
		DBG_OUT_LN("Read_heap_string -- string %p is a Cons-String", DEV8PTR(strObj));
		return ReadConsStringObject(strObj, objType);
	}

	return NULL;
}


/* return value:
0: empty string
-1: failed to read string content
1: good
*/
int PrintSeqStringObject(ULONG_PTR strObj, UINT8 objType)
{
	char *buf;

	buf = ReadSeqStringObject(strObj, objType);

	if (buf)
	{
		dprintf("%s", buf);
		free(buf);
		return 1;
	}

	return 0;

}

/* return value:
0: empty string
-1: failed to read string content
1: good
*/
int PrintStringObject(ULONG_PTR strObj)
{
	ULONG cb = 0;
	ULONG len = 0;
	//assuming the funcName is less than 256.
	ULONG offset = 0;

	UINT8 objType;

	if (GetTypeByte(&objType, DEV8PTR(strObj)) != 0) {
		DBG_OUT("Failed to Read Type Byte for %p\n", DEV8PTR(strObj));
		return -1;
	}

	if (!V8_TYPE_STRING(objType))
	{
		DBG_OUT("object @ %p is not a string object\n", strObj);
		return -1;
	}

	if (V8_STRREP_SEQ(objType))
	{
		return PrintSeqStringObject(strObj, objType);
	}

	if (V8_STRREP_CONS(objType))
	{
		return PrintConsStringObject(strObj, objType);
	}


	////For SeqString v8dbg_class_String__length__SMI is 8, but actually, it is 4.
	//read_heap_smi(&len, strObj + 4);
	////dprintf("length = %x\n", len);

	//if (len == 0)
	//{
	//	DBG_OUT("Length of String %p is 0x0\n", strObj);
	//	return 0;
	//}

	//if (!V8_STRENC_ASCII(objType))
	//{
	//	len = len / 2;
	//}

	//DBG_OUT("string object %p ", strObj);
	//DBG_OUT("length is %d\n", len);



	//offset = V8_STRENC_ASCII(objType) ? _V8DBG_CLASS_SEQASCIISTRING__CHARS__CHAR : v8dbg_class_SeqTwoByteString__chars__char;

	////For ASCII string the first char is started at strObj + _V8DBG_CLASS_SEQASCIISTRING__CHARS__CHAR
	////For two bytes string the first char is started at strObj + v8dbg_class_SeqTwoByteString__chars__char
	//if (ReadMemory(strObj + offset, funcName, len, &cb) && cb == len)
	//{
	//	funcName[len] = '\0';
	//	dprintf("%s\n", funcName);
	//}
	//else
	//{
	//	dprintf("%s %p+%p\n", "failed to read string content function at: ", strObj, _V8DBG_CLASS_SEQASCIISTRING__CHARS__CHAR);
	//	return -1;
	//}

	return 1;
}

#pragma region PrintJsObjProps


//
//int
//findjsobjects_prop(const char *desc, uintptr_t val, void *arg)
//{
//	findjsobjects_state_t *fjs = arg;
//	findjsobjects_obj_t *current = fjs->fjs_current;
//	findjsobjects_prop_t *prop;
//
//	if (desc == NULL)
//		desc = "<unknown>";
//
//	prop = mdb_zalloc(sizeof(findjsobjects_prop_t) +
//		strlen(desc), UM_SLEEP);
//
//	strcpy(prop->fjsp_desc, desc);
//
//	if (current->fjso_last != NULL) {
//		current->fjso_last->fjsp_next = prop;
//	}
//	else {
//		current->fjso_props = prop;
//	}
//
//	current->fjso_last = prop;
//	current->fjso_nprops++;
//	current->fjso_malformed =
//		val == NULL && current->fjso_nprops == 1 && desc[0] == '<';
//
//	return (0);
//}
//


/*ARGSUSED*/
//int
//findjsobjects_prop(const char *desc, uintptr_t val, void *arg)
//{
//	findjsobjects_state_t *fjs = arg;
//	findjsobjects_obj_t *current = fjs->fjs_current;
//	findjsobjects_prop_t *prop;
//
//	if (desc == NULL)
//		desc = "<unknown>";
//
//	prop = mdb_zalloc(sizeof(findjsobjects_prop_t) +
//		strlen(desc), UM_SLEEP);
//
//	strcpy(prop->fjsp_desc, desc);
//
//	if (current->fjso_last != NULL) {
//		current->fjso_last->fjsp_next = prop;
//	}
//	else {
//		current->fjso_props = prop;
//	}
//
//	current->fjso_last = prop;
//	current->fjso_nprops++;
//	current->fjso_malformed =
//		val == NULL && current->fjso_nprops == 1 && desc[0] == '<';
//
//	return (0);
//}


//Print the JObject properties
void PrintJsObjProps(ULONG_PTR objAddr)
{
	byte objType;
	ULONG_PTR objPropsAddr, objElemsAddr, mapAddr;
	ULONG cb = 0;
	ULONG_PTR *elts;
	size_t len;

	char* typeStr;
	ULONG i;


	UINT8 bit_field2, kind;

	//V8_PROP_INFO propinfo;

	//size_t sz;


	/*
	* we need the Map to figure out how to iterate the properties for this object.
	*/
	if (GetTypeByte(&objType, DEV8PTR(objAddr)) != 0)
	{
		DBG_TRACE("failed to read type byte for jscript object %p\n", DEV8PTR(objAddr));
		return;
	}
	DBG_TRACE("type of Object @ %p is %d\n", objAddr, objType);

#pragma region readObjectProperties
	/*
	* First, check if the JSObject's "properties" field is a FixedArray.
	*/
	//objAddr + _V8DBG_CLASS_JSOBJECT__PROPERTIES__FIXEDARRAY  == Object Addr+0x4, read the properties Object
	if (ReadMemory(DEV8PTR(objAddr) + _V8DBG_CLASS_JSOBJECT__PROPERTIES__FIXEDARRAY, &objPropsAddr, sizeof(objPropsAddr), &cb) && cb == sizeof(objPropsAddr))
	{
		DBG_TRACE("Object @ %p, Properties @ %p\n", DEV8PTR(objAddr), DEV8PTR(objPropsAddr));
	}
	else
	{
		DBG_TRACE("Failed to Read Properties of Object @ %p", DEV8PTR(objAddr));
		return;
	}

	if (!V8_IS_HEAPOBJECT(objPropsAddr))
		return;

	//the properties should be a fixed array
	if (GetTypeByte(&objType, DEV8PTR(objPropsAddr)) == 0)
	{
		switch (objType) {
#define X(uc, lc) case _V8DBG_TYPE_##uc: typeStr = #lc; break;
			V8_OBJECT_TYPE_MAP(X)
#undef X
default: typeStr = "<unknown>";
		}

	}
	else
	{
		DBG_TRACE("failed to read type byte for jscript object properties %p\n", DEV8PTR(objPropsAddr));
		return;
	}

	//must be a fixed array type
	if (objType != _V8DBG_TYPE_FIXEDARRAY__FIXED_ARRAY_TYPE)
	{
		DBG_TRACE("Object: %x, properties @ %x type: %s\n", objAddr, objPropsAddr, typeStr);
		return;
	}

#pragma endregion

#pragma region readObjectElements
	/*
	* Check to see if our elements member is an array and non-zero; if
	* so, it contains numerically-named properties.  Whether or not there
	* are any numerically-named properties, there may be other kinds of
	* properties.
	*/

	DBG_TRACE("/***********************************"
		"Check to see if our elements member is an array and non-zero; "
		"*****************************************************");

	//objAddr + _V8DBG_CLASS_JSOBJECT__ELEMENTS__OBJECT  == Object Addr+0x8, read the elements Object
	if (ReadMemory(DEV8PTR(objAddr) + _V8DBG_CLASS_JSOBJECT__ELEMENTS__OBJECT, &objElemsAddr, sizeof(objElemsAddr), &cb) && cb == sizeof(objElemsAddr))
	{
		DBG_TRACE("Object @ %p, Elements @ %p\n ", DEV8PTR(objAddr), DEV8PTR(objElemsAddr));
	}
	else
	{
		DBG_TRACE("Failed to Read Elements of Object @ %p", DEV8PTR(objAddr));
		return;
	}


	//if (GetTypeByte(&objType, DEV8PTR(objElemsAddr)) != 0)
	//{
	//	DBG_TRACE("elements type is %d(%x)", objType, objType);
	//	return;
	//}

	//DBG_TRACE("Object Elements Type %d\n", objType);

	// Read the Array Items
	if (!(read_heap_array(objElemsAddr, &elts, &len, 0) == 0 && len != 0))
	{
		DBG_TRACE("Failed to read Object: %x, elements @ %x", objAddr, objElemsAddr);
		return;
	}
	DBG_TRACE("Object: %x, elements @ %x #of elements: %d", objAddr, objElemsAddr, len);
		
	//dprintf("Object: %x, elements @ %x #of elements: %d\n", objAddr, objElemsAddr, len);
	//return;

	//Read the bit_field 2
	if (ReadMapAddr(&mapAddr, DEV8PTR(objAddr)) != 0)
	{
		DBG_TRACE("Failed to read bit_field2 for object %x", objAddr);
		return;
	}

	if ( ! (ReadMemory(DEV8PTR(mapAddr) + _V8DBG_CLASS_MAP__BIT_FIELD2__CHAR, &bit_field2, sizeof(bit_field2), &cb) && cb == sizeof(bit_field2) ) ) {
		//sz = len * sizeof(uintptr_t);
		DBG_TRACE("Failed to read bit_field2 for object %x", objAddr);
		free(elts);
		return;
	}


	kind = (bit_field2 & _V8DBG_BIT_FIELD2_ELEMENTS_KIND_MASK) >> _V8DBG_BIT_FIELD2_ELEMENTS_KIND_SHIFT;
	DBG_TRACE("bit_field2: %d, kind: %d", bit_field2, kind);

	//propinfo |= JPI_NUMERIC;

	if (kind == _V8DBG_ELEMENTS_FAST_ELEMENTS ||
		kind == _V8DBG_ELEMENTS_FAST_HOLEY_ELEMENTS) {
		for (i = 0; i < len; i++) {
			char name[10];

			if (kind == _V8DBG_ELEMENTS_FAST_HOLEY_ELEMENTS &&
				jsobj_is_hole(elts[i]))
				continue;

			_snprintf_s(name, sizeof(name), _TRUNCATE, "%d", i);
			//dprintf("i = %d (%lld)\n", i, i);
			DBG_TRACE("name: %s", name);
			/*if (func(name, elts[ii], arg) != 0) {
				mdb_free(elts, sz);
				goto err;
				}*/
		}
	}
//		else if (kind == V8_ELEMENTS_DICTIONARY_ELEMENTS) {
//			propinfo |= JPI_DICT;
//			if (read_heap_dict(elements, func, arg) != 0) {
//				mdb_free(elts, sz);
//				goto err;
//			}
//		}
//
//		mdb_free(elts, sz);
//	}


	if (_V8DBG_BIT_FIELD3_DICTIONARY_MAP_SHIFT != -1) {
		/*
		* If dictionary properties are supported (the V8_DICT_SHIFT
		* offset is not -1), then bitfield 3 tells us ifkElementsKindBitCount the properties
		* for this object are stored in "properties" field of the
		* object using a Dictionary representation.
		*
		* Versions of V8 prior to Node 0.12 treated bit_field3 as an
		* SMI, so it was pointer-sized, and it has to be converted from
		* an SMI before using it.  In 0.12, it's treated as a raw
		* uint32_t, meaning it's always int-sized and it should not be
		* converted.  We can tell which case we're in because the debug
		* constant (v8dbg_class_map__bit_field3__TYPE) tells us whether
		* the TYPE is "SMI" or "int".
		*/

		//flp = conf_field_lookup("Map", "bit_field3");
		//if (flp == NULL || flp->v8f_isbyte) {
			/*
			* v8f_isbyte indicates the type is "int", so we're in
			* the int-sized not-a-SMI world.
			*/
		ULONG_PTR bit_field3;
		UINT32 bf3_value;

		if (!(ReadMemory(DEV8PTR(mapAddr) + _V8DBG_CLASS_MAP__BIT_FIELD3__INT, &bf3_value, sizeof(bf3_value), &cb) && cb == sizeof(bf3_value))) {
			DBG_TRACE("Failed to read bit_field3 for object %x", objAddr);
			free(elts);
			return;
		}

		bit_field3 = (ULONG_PTR)bf3_value;
		if (V8_IS_SMI(bit_field3))
		{
			DBG_TRACE("Object %x, bit_field3 %x, SMI %x", objAddr, bit_field3, V8_SMI_VALUE(bit_field3));
		}
		else
			DBG_TRACE("Object %x, bit_field3 %x", objAddr, bit_field3);
		//}
		//else {
		//	/* The metadata indicates this is an SMI. */
		//	if (mdb_vread(&bit_field3, sizeof(bit_field3),
		//		map + V8_OFF_MAP_BIT_FIELD3) == -1)
		//		goto err;
		//	bit_field3 = V8_SMI_VALUE(bit_field3);
		//}

		if (bit_field3 & (1 << _V8DBG_BIT_FIELD3_DICTIONARY_MAP_SHIFT)) {
			//propinfo |= JPI_DICT;
			//if (propinfop != NULL)
				//*propinfop = propinfo;
			//return (read_heap_dict(ptr, func, arg));
		}
	}
	//else if (V8_OFF_MAP_INSTANCE_DESCRIPTORS != -1) {
	//	uintptr_t bit_field3;

	//	if (mdb_vread(&bit_field3, sizeof(bit_field3),
	//		map + V8_OFF_MAP_INSTANCE_DESCRIPTORS) == -1)
	//		goto err;

	//	if (V8_SMI_VALUE(bit_field3) == (1 << V8_ISSHARED_SHIFT)) {
	//		/*
	//		* On versions of V8 prior to that used in 0.10,
	//		* the instance descriptors were overloaded to also
	//		* be bit_field3 -- and there was no way from that
	//		* field to infer a dictionary type.  Because we
	//		* can't determine if the map is actually the
	//		* hash_table_map, we assume that if it's an object
	//		* that has kIsShared set, that it is in fact a
	//		* dictionary -- an assumption that is assuredly in
	//		* error in some cases.
	//		*/
	//		propinfo |= JPI_DICT;
	//		if (propinfop != NULL)
	//			*propinfop = propinfo;
	//		return (read_heap_dict(ptr, func, arg));
	//	}
	//}

#pragma endregion

#pragma region ReadPropertyDescriptor
	
	DBG_TRACE("/***********************************"
		"Check to see instance descriptors"
		"******************************************/");

	ULONG_PTR *props; //array for properties
	size_t nprops; //number of properties
	if (read_heap_array(objPropsAddr, &props, &nprops, 0) != 0)
		return;

	///*
	//* Check if we're looking at an older version of V8, where the instance
	//* descriptors are stored not directly in the Map, but in the
	//* "transitions" array that's stored in the Map.
	//*/
	//if (V8_OFF_MAP_INSTANCE_DESCRIPTORS == -1) {
	//	if (V8_OFF_MAP_TRANSITIONS == -1 ||
	//		V8_TRANSITIONS_IDX_DESC == -1 ||
	//		V8_PROP_IDX_CONTENT != -1) {
	//		mdb_warn("missing instance_descriptors, but did "
	//			"not find expected transitions array metadata; "
	//			"cannot read properties\n");
	//		goto err;
	//	}

	//	propinfo |= JPI_HASTRANSITIONS;
	//	off = V8_OFF_MAP_TRANSITIONS;
	//	if (mdb_vread(&ptr, ps, map + off) == -1)
	//		goto err;

	//	if (read_heap_array(ptr, &trans, &ntrans, UM_SLEEP) != 0)
	//		goto err;

	//	ptr = trans[V8_TRANSITIONS_IDX_DESC];
	//	mdb_free(trans, ntrans * sizeof(uintptr_t));
	//}
	//else {
	//off = V8_OFF_MAP_INSTANCE_DESCRIPTORS;
	//if (mdb_vread(&ptr, ps, map + off) == -1)
	//goto err;
	//}

	//care the new version only
	ULONG_PTR objDesc;
	
	if (!(ReadMemory(DEV8PTR(mapAddr) + _V8DBG_CLASS_MAP__INSTANCE_DESCRIPTORS__DESCRIPTORARRAY, &objDesc, sizeof(objDesc), &cb) && (cb == sizeof(objDesc)))) {
		DBG_TRACE("Failed to read descriptor for object %x", objAddr);
		return;
	}

	DBG_TRACE("Object %x, map %x, descriptor %x", objAddr, mapAddr, objDesc);

	if (!V8_IS_HEAPOBJECT(objDesc))
		return;

	//the properties should be a fixed array
	if (GetTypeByte(&objType, DEV8PTR(objDesc)) == 0)
	{
		//V8TypeToString(objType, &typeStr);

		//must be a fixed array type
		if (objType != _V8DBG_TYPE_FIXEDARRAY__FIXED_ARRAY_TYPE)
		{
			DBG_TRACE("Object: %x, properties @ %x type: %s\n", objAddr, objDesc, typeStr);
			return;
		}

	}
	else
	{
		DBG_TRACE("failed to read type byte for jscript object %x descriptor %x\n", objAddr, objDesc);
		return;
	}

	

	/*
	* Either way, at this point "ptr" should refer to the descriptors
	* array.
	*/
	ULONG_PTR *descs;
	size_t ndescs;

	DBG_TRACE("/***********************************"
		"_V8DBG_CLASS_MAP__INSTANCE_DESCRIPTORS__DESCRIPTORARRAY"
		"******************************************/");

	if (read_heap_array(objDesc, &descs, &ndescs, 0) != 0)
		return;


#pragma endregion


#pragma region instancesize

	/*
	* For cases where property values are stored directly inside the object
	* ("fast properties"), we need to know the whole size of the object and
	* the number of properties in the object in order to calculate the
	* correct offset for each property.
	*/

	DBG_TRACE("/***********************************"
		"For cases where property values are stored directly inside the object (fast properties)"
		"******************************************/");
		
	size_t size;
	if (read_size(&size, DEV8PTR(objAddr)) != 0)
		size = 0;

	//ULONG_PTR pInProps;
	UINT8 ninprops;

	if (!(ReadMemory(DEV8PTR(mapAddr) + _V8DBG_CLASS_MAP__INSTANCE_DESCRIPTORS__DESCRIPTORARRAY, &objDesc, sizeof(objDesc), &cb) && (cb == sizeof(objDesc)))) {
		DBG_TRACE("Failed to read descriptor for object %x", objAddr);
		return;
	}

	if (!(ReadMemory(DEV8PTR(mapAddr) + _V8DBG_CLASS_MAP__INOBJECT_PROPERTIES__INT, &ninprops, sizeof(ninprops), &cb) && (cb == sizeof(ninprops)))) {
		DBG_TRACE("Failed to read _V8DBG_CLASS_MAP__INOBJECT_PROPERTIES__INT for object %x, map %x", objAddr, mapAddr);
		return;
	}

	DBG_TRACE("Object %x, map %x, INOBJECT_PROPERTIES__INT %d", objAddr, mapAddr, ninprops);

	//
	//We are definitely v0.8 and later
	//
	//if (V8_PROP_IDX_CONTENT == -1) {
		/*
		* On node v0.8 and later, the content is not stored in a
		* separate FixedArray, but rather with the descriptors.  The
		* number of actual properties is the length of the array minus
		* the first (non-property) elements divided by the number of
		* elements per property.
		*/
	ULONG_PTR *content;
	size_t ncontent, rndescs;

		content = descs;
		ncontent = ndescs;
		rndescs = ndescs > _V8DBG_PROP_IDX_FIRST ?
			(ndescs - _V8DBG_PROP_IDX_FIRST) / _V8DBG_PROP_DESC_SIZE : 0;

		DBG_TRACE("ncontent %d, rndescs %d", ncontent, rndescs);

	//}
	//else {
	//	/*
	//	* On older versions, the content is stored in a separate array,
	//	* and there's one entry per property (rather than three).
	//	*/
	//	if (V8_PROP_IDX_CONTENT < ndescs &&
	//		read_heap_array(descs[V8_PROP_IDX_CONTENT], &content,
	//		&ncontent, UM_SLEEP) != 0)
	//		goto err;

	//	rndescs = ndescs - V8_PROP_IDX_FIRST;
	//	propinfo |= JPI_HASCONTENT;
	//}

#pragma endregion
		/*
		* At this point, we've read all the pieces we need to process the list
		* of instance descriptors.
		*/
		DBG_TRACE("/******************************************"
			"At this point, we've read all the pieces we need to process the list of instance descriptors."
			"******************************************/");

		ULONG ii = 0;
		for (ii = 0; ii < rndescs; ii++) {
			ULONG_PTR keyidx, validx, detidx;//, baseidx;
			char buf[1024];
			ULONG_PTR val;
			size_t len = sizeof(buf);
			char *c = buf;
			ULONG_PTR ptr;

			//
			//We are definitely v0.8 and later
			//
			//if (V8_PROP_IDX_CONTENT != -1) {
			/*
			* In node versions prior to v0.8, this was hardcoded
			* in the V8 implementation, so we hardcode it here
			* as well.
			*/
			keyidx = ii + _V8DBG_PROP_IDX_FIRST;
			validx = ii << 1;
			detidx = (ii << 1) + 1;
			DBG_TRACE("ii = %d, keyidx = %d, validx = %d, detidx = %d", ii, keyidx, validx, detidx);
			//}
			/*else {
				baseidx = V8_PROP_IDX_FIRST + (ii * V8_PROP_DESC_SIZE);
				keyidx = baseidx + V8_PROP_DESC_KEY;
				validx = baseidx + V8_PROP_DESC_VALUE;
				detidx = baseidx + V8_PROP_DESC_DETAILS;
				}*/

			/*
			* Ignore cases where our understanding doesn't appear to match
			* what's here.
			*/
			if (detidx >= ncontent) {
				//propinfo |= JPI_SKIPPED;
				DBG_TRACE("property descriptor %d: detidx (%d) out of bounds for content array (length %d)\n",
					ii, detidx, ncontent);
				continue;
			}

			/*
			* We only process fields.  There are other entries here
			* (notably: transitions) that we don't care about (and these
			* are not errors).
			*/
			if (!V8_DESC_ISFIELD(content[detidx]))
			{
				DBG_TRACE("property descriptor %x: detidx (%d) is not a FIELD", content[detidx], detidx);
				continue;
			}

			if (keyidx >= ndescs) {
				//propinfo |= JPI_SKIPPED;
				DBG_TRACE("property descriptor %d: keyidx (%d) out of bounds for descriptor array (length %d)\n",
					ii, keyidx, ndescs);
				continue;
			}

			DBG_TRACE("print string object property descriptor %x: keyidx (%d)", descs[detidx], keyidx);
			if (PrintStringObject(descs[keyidx]) == -1)
				continue;

			/*if (jsstr_print(descs[keyidx], JSSTR_NUDE, &c, &len) != 0) {
				propinfo |= JPI_SKIPPED;
				continue;
				}
				*/
			val = (ULONG_PTR)content[validx];
			if (!V8_IS_SMI(val)) {
				//propinfo |= JPI_SKIPPED;
				DBG_TRACE("object %x: property descriptor %d: value "
					"index is not an SMI: %x\n", objAddr, ii, val);
				continue;
			}

			/*
			* The "value" part of each property descriptor tells us whether
			* the property value is stored directly in the object or in the
			* related "props" array.  See JSObject::RawFastPropertyAt() in
			* the V8 source.
			*/
			val = V8_SMI_VALUE(val) - ninprops;
			if (val < 0) {
				ULONG_PTR propaddr;

				/*
				* The property is stored directly inside the object.
				* In Node 0.10, "val - ninprops" is the (negative)
				* index of the property counted from the end of the
				* object.  In that context, -1 refers to the last
				* word in the object; -2 refers to the second-last
				* word, and so on.
				*
				* In Node 0.12, we get the 0-based index from the
				* first property inside the object by reading certain
				* bits from the property descriptor details word.
				* These constants are literal here because they're
				* literal in the V8 source itself.
				*/
				//we are 3.28 now.
				//if (v8_major > 3 || (v8_major == 3 && v8_minor >= 26)) {
				val = V8_PROP_FIELDINDEX(content[detidx]);
				propaddr = objAddr + V8_OFF_HEAP(size - (ninprops - val) * sizeof(ULONG_PTR));
				//}
				//else {
				//	propaddr = addr + V8_OFF_HEAP(size + val * ps);
				//}

				DBG_TRACE("object %x: property at %x", objAddr, propaddr);

				if (!(ReadMemory(DEV8PTR(propaddr), &ptr, sizeof(ptr), &cb) && (cb == sizeof(ptr)))) {
					DBG_TRACE("object %x: failed to read in-object "
						"property at %x", objAddr, propaddr);
					continue;
				}

				//if (mdb_vread(&ptr, sizeof(ptr), propaddr) == -1) {
				//	//propinfo |= JPI_SKIPPED;
				//	DBG_TRACE("object %p: failed to read in-object "
				//		"property at %p", objAddr, propaddr);
				//	continue;
				//}

				//propinfo |= JPI_INOBJECT;
			}
			else {
				/*
				* The property is in the separate "props" array.
				*/
				if (val >= nprops) {
					/*
					* This can happen when properties are deleted.
					* If this value isn't obviously corrupt, we'll
					* just silently ignore it.
					*/
					if (val < rndescs)
						continue;

					//propinfo |= JPI_SKIPPED;
					DBG_TRACE("object %x: property descriptor %d: "
						"value index value (%d) out of bounds "
						"(%d)\n", objAddr, ii, val, nprops);
					//goto err;
					return;
				}

				//propinfo |= JPI_PROPS;
				ptr = props[val];
			}

			DBG_TRACE("object %x: property descriptor %d: value %x", objAddr, ii, ptr);

			//if (func(buf, ptr, arg) != 0)
			//	goto err;
		} // end for ii

}

//
// Extension to dump stacktrace
//
DECLARE_API(dumpJsObj)
{
	ULONG_PTR addr = 0;
	//char *endptr;

	byte objType;

	addr = (ULONG)GetExpression(args);
	DBG_TRACE("Object address is %p\n", args, addr);

	if (!addr)
	{
		DBG_TRACE("Provided address %s converted to 0x%p is not a valid address\n", args, addr);
	}

	//if (V8_IS_SMI(addr)) {
	//	DBG_TRACE("0x%p is a SMI\n", addr);
	//	//print the interger

	//	return;
	//}

	//if (!V8_IS_HEAPOBJECT(addr)) {
	//	DBG_TRACE("0x%p is not an V8 Heap Object\n", addr);
	//	return;
	//}

	if (GetTypeByte(&objType, DEV8PTR(addr)) != 0)
	{
		dprintf("failed to read type byte for jscript object %p", DEV8PTR(addr));
		return;
	}

	DBG_TRACE("Object Type is %d\n", objType);

	if (V8_TYPE_STRING(objType)) {
		DBG_OUT_LN("0x%p is a string object", addr);
		return;
	}

	PrintJsObjProps(addr);
}

#pragma endregion



#pragma region FindJsObject


void findjsobjects_range(ULONG_PTR addr, ULONG_PTR endAddr)
{
	//ULONG_PTR limit;
	UINT8 objType;
	//int jsobject = V8_TYPE_JSOBJECT, jsarray = V8_TYPE_JSARRAY;
	//int jsfunction = V8_TYPE_JSFUNCTION;
	char* typeStr;

	ULONG_PTR base = addr, mapAddr;

	for (; addr < endAddr; addr = addr + sizeof(ULONG_PTR)) {

		//SMI
		//if (V8_IS_SMI(addr))
		//{
		//	DBG_TRACE("Object @ %x is SMI", addr);
		//	continue;
		//}
		//Not a valid heap object
		//if (!V8_IS_HEAPOBJECT(addr))
		//{
		//	DBG_TRACE("Object @ %x is not a valid heap object", addr);
		//	continue;
		//}


		//Get the MAP of Object and make sure it is an HeapObject as well
		if (0 == ReadMapAddr(&mapAddr, addr))
		{
			if (!V8_IS_HEAPOBJECT(mapAddr))
			{
				//Not a valid Heap Object
				DBG_TRACE("Object @ %x is not a valid Heap Object", addr);
				continue;
				
			}
		}
		else
		{
			//Not a valid Heap Object
			DBG_TRACE("Object @ %x is not a valid Heap Object", addr);
			continue;
		}

		if (GetTypeByte(&objType, addr) == 0)
		{
			switch (objType) {
				#define X(uc, lc) case _V8DBG_TYPE_##uc: typeStr = #lc; break;
				    V8_OBJECT_TYPE_MAP(X)
                #undef X
                default: typeStr = "<unknown>";
			}
			DBG_TRACE("Object: %x Type: %s %x(%d) \n", addr, typeStr, objType, objType);
		}

		if (objType == _V8DBG_TYPE_JSOBJECT__JS_OBJECT_TYPE)
		{
			//dprintf("Object: %x Type: %s %x(%d) \n", addr, typeStr, objType, objType);
			PrintJsObjProps(addr);
		}

	}
}


DECLARE_API(findJsObject)
{
	ULONG64 addr;
	ULONG_PTR endAddr;

	//char* pEnd;
	//byte objType;

	if (GetExpressionEx(args, &addr, &args)) {
		endAddr = (ULONG_PTR)GetExpression(args);
		DBG_TRACE("Address range: %x - %x", addr, endAddr);
	}
	else {
		dprintf("Usage:   !findJsObject <start-Address> <end-Address>\n");
		return;
	}

	findjsobjects_range((ULONG_PTR)addr, endAddr);
}


#pragma endregion


void PrintJSFunctionName(ULONG_PTR jsSharedFunction)
{
	//ULONG_PTR jsFun;
	ULONG_PTR jsFuncName;
	ULONG_PTR jsInferNamed;
	ULONG cb = 0;
	UINT8 typeByte = 0;

	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__NAME__OBJECT = SharedFunction+0x4, Read Name of SharedFunctionInfo
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__NAME__OBJECT, &jsFuncName, sizeof(jsFuncName), &cb) && cb == sizeof(jsFuncName))
	{
		DBG_OUT("FuntionName @ %p\n", DEV8PTR(jsFuncName));
		
		if (!isStringObject(DEV8PTR(jsFuncName)))
		{
			return;
		}
		
		//empty function name, maybe an anounymous, try inferred name
		if (PrintStringObject(DEV8PTR(jsFuncName)) == 0)
		{
			//SharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__INFERRED_NAME__STRING = SharedFunction+0n40, Read Inferred of SharedFunctionInfo
			if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__INFERRED_NAME__STRING, &jsInferNamed, sizeof(jsInferNamed), &cb) && cb == sizeof(jsInferNamed))
			{
				DBG_OUT("Inferred Name is @ %p\n", DEV8PTR(jsInferNamed));
				if (isStringObject(DEV8PTR(jsInferNamed)))
				{
					if (PrintStringObject(DEV8PTR(jsInferNamed)) == 1)
					{
						return;
					}
				}
			}
   
			dprintf("<anounymous>");
		}
	}
	else
	{
		dprintf("%\n", "??");
	}

}


void PrintJSScriptFileName(ULONG_PTR jsSharedFunction)
{

	ULONG_PTR jsScriptFile;
	ULONG cb = 0;
	UINT8 objType = 0;
	ULONG_PTR JSScriptFileName;

	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT = SharedFunction+0x4, Read the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT, &jsScriptFile, sizeof(jsScriptFile), &cb) && cb == sizeof(jsScriptFile))
	{
		DBG_TRACE("Script Object @ %p", DEV8PTR(jsScriptFile));

		if (GetTypeByte(&objType, DEV8PTR(jsScriptFile)) != 0) {
			DBG_OUT("Failed to Read Type Byte for Script Object @ %p", DEV8PTR(jsScriptFile));
			return;
		}

		DBG_TRACE("type is %d", objType);
		/*if (!V8_TYPE_SCRIPT(objType))
		{
			DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
			return;
		}*/
	}
	else
	{
		DBG_OUT("Failed to read Script Object @ %p", jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT);
		return;
	}


	//_V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT == the name of script file
	if (ReadMemory(DEV8PTR(jsScriptFile) + _V8DBG_CLASS_SCRIPT__NAME__OBJECT, &JSScriptFileName, sizeof(JSScriptFileName), &cb) && cb == sizeof(JSScriptFileName))
	{
		DBG_OUT("Script File Name Object @ %p", DEV8PTR(JSScriptFileName));
		
		if (isStringObject(DEV8PTR(JSScriptFileName)))
		{
			if (PrintStringObject(DEV8PTR(JSScriptFileName)) == 1)
			{
				return;
			}
		}

		/*if (!V8_TYPE_SCRIPT(objType))
		{
		DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
		return;
		}*/
	}
	else
	{
		DBG_OUT("Script File Name Object @ %p", DEV8PTR(JSScriptFileName));
	}


	DBG_OUT("Exit PrintJSScriptFileName %p", jsSharedFunction);
	return;


}

/*
Given a token position and script content, calculate the line number of the position.
*/
ULONG64 CalculateLineNo(ULONG64 tokenPos, char* buf)
{
	ULONG64 i = 0;
	
	//start from 1;
	ULONG64 num = 1;

	ULONG64 len = strlen(buf);

	if (tokenPos > len)
		return -1;

	for (i = 0; i < tokenPos; i++)
	{
		if (buf[i] == '\n')
		{
			num++;
		}
	}

	return num;
}


int printFunction(ULONG64 start, ULONG64 end, char* buf)
{
	ULONG64 len = strlen(buf);

	DBG_TRACE("start position : %d", start);
	DBG_TRACE("end position : %d", end);
	DBG_TRACE("source buf lengh is :%d", len);

	if (start > len)
		return -1;

	if (end > len)
		return -1;

	DBG_TRACE("print function now buf");
	for (ULONG64 i= start; i < end; i++)
	{
		//DBG_TRACE("%ld", i);
		dprintf("%c", buf[i]);
	}

	dprintf("\n");

	return 1;

}

int GetFuncEndPostion(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR endPos;
	ULONG cb = 0;

	//Read the Token Position 
	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__END_POSITION__SMI = the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__END_POSITION__SMI, &endPos, sizeof(endPos), &cb) && cb == sizeof(endPos))
	{
		DBG_TRACE("SHAREDFUNCTIONINFO__END_POSITION__SMI of Shared Function %x is %d", jsSharedFunction, endPos);

		//isSMI
		if (V8_IS_SMI(endPos))
		{
			endPos = V8_SMI_VALUE(endPos);
		}
		else
		{
			DBG_TRACE("SHAREDFUNCTIONINFO__END_POSITION__SMI %d is not a SMI", endPos);
			return -1;
		}
		DBG_TRACE("SHAREDFUNCTIONINFO__END_POSITION__SMI %d", endPos);
	}
	else
	{
		DBG_TRACE("Failed to read SHAREDFUNCTIONINFO__END_POSITION__SMI of Shared Function @ %p", jsSharedFunction);
		return -1;
	}

	return endPos;
}



int GetFuncStartPostion(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR startPos;
	ULONG cb = 0;

	//Read the Token Position 
	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__START_POSITION_AND_TYPE__SMI = the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__START_POSITION_AND_TYPE__SMI, &startPos, sizeof(startPos), &cb) && cb == sizeof(startPos))
	{
		DBG_TRACE("START_POSITION_AND_TYPE__SMI of Shared Function %x is %d", jsSharedFunction, startPos);

		//isSMI
		if (V8_IS_SMI(startPos))
		{
			startPos = V8_SMI_VALUE(startPos) >> kStartPositionShift;
		}
		else
		{
			DBG_TRACE("START_POSITION_AND_TYPE__SMI %d is not a SMI", startPos);
			return -1;
		}
		DBG_TRACE("START_POSITION_AND_TYPE__SMI %d", startPos);
	}
	else
	{
		DBG_TRACE("Failed to read START_POSITION_AND_TYPE__SMI of Shared Function @ %p", jsSharedFunction);
		return -1;
	}

	return startPos;
}


int GetFuncTokenPostion(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR tokenPos;
	ULONG cb = 0;

	//Read the Token Position 
	//SharedFunction+v8dbg_class_SharedFunctionInfo__function_token_position__SMI = the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__FUNCTION_TOKEN_POSITION__SMI, &tokenPos, sizeof(tokenPos), &cb) && cb == sizeof(tokenPos))
	{
		DBG_TRACE("FUNCTION_TOKEN_POSITION__SMI of Shared Function %x is %d", jsSharedFunction, tokenPos);

		//isSMI
		if (V8_IS_SMI(tokenPos))
		{
			tokenPos = V8_SMI_VALUE(tokenPos);
		}
		else
		{
			DBG_TRACE("FUNCTION_TOKEN_POSITION__SMI %d is not a SMI", tokenPos);
			return -1;
		}
		DBG_TRACE("FUNCTION_TOKEN_POSITION__SMI %d", tokenPos);
	}
	else
	{
		DBG_TRACE("Failed to read FUNCTION_TOKEN_POSITION__SMI of Shared Function @ %p", jsSharedFunction);
		return -1;
	}

	return tokenPos;
}


char* ReadScriptSource(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR jsScriptFile;
	ULONG_PTR jsScriptSource;
	UINT8 objType;
	ULONG cb;

	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT = SharedFunction+0x4, Read the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT, &jsScriptFile, sizeof(jsScriptFile), &cb) && cb == sizeof(jsScriptFile))
	{
		DBG_TRACE("SharedFunction %x, Script Object @ %x", DEV8PTR(jsSharedFunction), DEV8PTR(jsScriptFile));

		if (GetTypeByte(&objType, DEV8PTR(jsScriptFile)) != 0) {
			DBG_TRACE("Failed to Read Type Byte for Script Object @ %p", DEV8PTR(jsScriptFile));
			return NULL;
		}

		DBG_TRACE("type is %d", objType);
		if (!V8_TYPE_SCRIPT(objType))
		{
			DBG_TRACE("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
			return NULL;
		}
	}
	else
	{
		DBG_TRACE("Failed to read Script Object @ %x\n", jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT);
		return NULL;
	}


	//debug_support!_V8DBG_CLASS_SCRIPT__SOURCE__OBJECT == 0n4 == the source of script file
	if (ReadMemory(DEV8PTR(jsScriptFile) + _V8DBG_CLASS_SCRIPT__SOURCE__OBJECT, &jsScriptSource, sizeof(jsScriptSource), &cb) && cb == sizeof(jsScriptSource))
	{
		DBG_TRACE("Script File source Object @ %x", DEV8PTR(jsScriptSource));

		if (!isStringObject(DEV8PTR(jsScriptSource)))
		{
			DBG_TRACE("Script File source Object @ %x is not a string object", DEV8PTR(jsScriptSource));
			return NULL;
		}
	}
	else
	{
		DBG_OUT("Failed to read Script File source Object @ %p", DEV8PTR(jsScriptSource));
	}

	return Read_heap_string(DEV8PTR(jsScriptSource));

}
void PrintLineNo(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR jsScriptFile;
	ULONG_PTR jsScriptSource;
	
	ULONG_PTR tokenPos;

	ULONG cb = 0;
	UINT8 objType = 0;
	
	ULONG64 lineNo = 0;
	char* buf;


	
	//Read the Token Position 
	//SharedFunction+v8dbg_class_SharedFunctionInfo__function_token_position__SMI = the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__FUNCTION_TOKEN_POSITION__SMI, &tokenPos, sizeof(tokenPos), &cb) && cb == sizeof(tokenPos))
	{
		DBG_TRACE("Token_position of Shared Function %x is %d", jsSharedFunction, tokenPos);

		//isSMI
		if (V8_IS_SMI(tokenPos))
		{
			tokenPos = V8_SMI_VALUE(tokenPos);
		}
		else
		{
			DBG_OUT_LN("PrintLineNo -- Token_position %d is not a SMI", tokenPos);
			return;
		}
		DBG_TRACE("token position %d", tokenPos);
	}
	else
	{
		DBG_OUT_LN("PrintLineNo -- Failed to read token position of Shared Function @ %p", jsSharedFunction);
		return;
	}


	//SharedFunction+_V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT = SharedFunction+0x4, Read the Script Object
	if (ReadMemory(jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT, &jsScriptFile, sizeof(jsScriptFile), &cb) && cb == sizeof(jsScriptFile))
	{
		DBG_TRACE("SharedFunction %x, Script Object @ %X", DEV8PTR(jsSharedFunction), DEV8PTR(jsScriptFile));

		if (GetTypeByte(&objType, DEV8PTR(jsScriptFile)) != 0) {
			DBG_OUT("Failed to Read Type Byte for Script Object @ %p", DEV8PTR(jsScriptFile));
			return;
		}

		DBG_TRACE("type is %d", objType);
		/*if (!V8_TYPE_SCRIPT(objType))
		{
		DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
		return;
		}*/
	}
	else
	{
		DBG_OUT_LN("Failed to read Script Object @ %p", jsSharedFunction + _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT);
		return;
	}


	//debug_support!_V8DBG_CLASS_SCRIPT__SOURCE__OBJECT == 0n4 == the source of script file
	if (ReadMemory(DEV8PTR(jsScriptFile) + _V8DBG_CLASS_SCRIPT__SOURCE__OBJECT, &jsScriptSource, sizeof(jsScriptSource), &cb) && cb == sizeof(jsScriptSource))
	{
		DBG_OUT("Script File source Object @ %p", DEV8PTR(jsScriptSource));

		if (!isStringObject(DEV8PTR(jsScriptSource)))
		{
			DBG_OUT("Script File source Object @ %p is not a string object", DEV8PTR(jsScriptSource));
			return;
		}

		/*if (!V8_TYPE_SCRIPT(objType))
		{
		DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
		return;
		}*/
	}
	else
	{
		DBG_OUT("Failed to read Script File source Object @ %p", DEV8PTR(jsScriptSource));
	}

	buf = Read_heap_string(DEV8PTR(jsScriptSource));
	DBG_TRACE("JscriptSource %x, %s", buf, buf);
	if (buf)
	{
		//dprintf("script source is %s\n", buf);
		lineNo = CalculateLineNo(tokenPos, buf);
		dprintf(" @ %d", lineNo);
	}
	//else
	//{
	//	dprintf("@ 0", buf);
	//}
	//DBG_OUT("Failed to read Script File source Object @ %p", DEV8PTR(jsScriptSource));

	return;

	///*
	//* Although the token position is technically an SMI, we're going to
	//* byte-compare it to other SMI values so we don't want decode it here.
	//*/
	//if (read_heap_ptr(&tokpos, funcinfop,
	//	V8_OFF_SHAREDFUNCTIONINFO_FUNCTION_TOKEN_POSITION) != 0)
	//	return (DCMD_ERR);

	//if (read_heap_ptr(&scriptp, funcinfop,
	//	V8_OFF_SHAREDFUNCTIONINFO_SCRIPT) != 0)
	//	return (DCMD_ERR);

	//if (read_heap_ptr(&ptrp, scriptp, V8_OFF_SCRIPT_NAME) != 0)
	//	return (DCMD_ERR);

	//bufp = buf;
	//len = sizeof(buf);
	//(void)jsstr_print(ptrp, JSSTR_NUDE, &bufp, &len);

	//if (prop != NULL && strcmp(prop, "file") == 0) {
	//	mdb_printf("%s\n", buf);
	//	return (DCMD_OK);
	//}

	//if (prop == NULL) {
	//	(void)mdb_inc_indent(4);
	//	mdb_printf("file: %s\n", buf);
	//}

	//if (read_heap_ptr(&lendsp, scriptp, V8_OFF_SCRIPT_LINE_ENDS) != 0)
	//	return (DCMD_ERR);

	//if (read_heap_smi(&nargs, funcinfop,
	//	V8_OFF_SHAREDFUNCTIONINFO_LENGTH) == 0) {
	//	for (ii = 0; ii < nargs; ii++) {
	//		uintptr_t argptr;
	//		char arg[10];

	//		if (mdb_vread(&argptr, sizeof(argptr),
	//			fptr + V8_OFF_FP_ARGS + (nargs - ii - 1) *
	//			sizeof(uintptr_t)) == -1)
	//			continue;

	//		(void)snprintf(arg, sizeof(arg), "arg%d", ii + 1);

	//		if (prop != NULL) {
	//			if (strcmp(arg, prop) != 0)
	//				continue;

	//			mdb_printf("%p\n", argptr);
	//			return (DCMD_OK);
	//		}

	//		bufp = buf;
	//		len = sizeof(buf);
	//		(void)obj_jstype(argptr, &bufp, &len, NULL);

	//		mdb_printf("arg%d: %p (%s)\n", (ii + 1), argptr, buf);
	//	}
	//}

}


int PrintSpecialJSFrame(ULONG_PTR fptr)
{

	ULONG_PTR jsFun;
	ULONG cb;
	//UINT8 typeByte;
	char *frametype;

		/*
		* Figure out what kind of frame this is using the same algorithm as
		* V8's ComputeType function.  First, look for an ArgumentsAdaptorFrame.
		*/

		//framePoint + _V8DBG_OFF_FP_FUNCTION == EBP - 8, read the JavaScript Functino(JSFunction)
		if (ReadMemory(fptr + _V8DBG_OFF_FP_FUNCTION, &jsFun, sizeof(jsFun), &cb) && cb == sizeof(jsFun))
		{
			DBG_TRACE("JSFunction @ %x\n", DEV8PTR(jsFun));
			if V8_IS_SMI(jsFun)
			{
				V8FrameTypeToString((UINT8)jsFun, &frametype);
				dprintf("%s\n", frametype);
				return 1;
			}

		}
		else
		{
			DBG_TRACE("Failed to Read JavaScript Function at: %x", fptr + _V8DBG_OFF_FP_FUNCTION);
			dprintf("??\n");
			return 1;
		}



		/*
		* Other special frame types are indicated by a marker.
		*/
		if (ReadMemory(fptr + _V8DBG_OFF_FP_MARKER, &jsFun, sizeof(jsFun), &cb) && cb == sizeof(jsFun))
		{
			DBG_TRACE("JSFunction @ %x\n", DEV8PTR(jsFun));
			if V8_IS_SMI(jsFun)
			{
				V8FrameTypeToString((UINT8)jsFun, &frametype);
				dprintf("%s\n", frametype);
				return 1;
			}

		}
		else
		{
			DBG_TRACE("Failed to Read JavaScript Function at: %x", fptr + _V8DBG_OFF_FP_MARKER);
			dprintf("??\n");
			return 1;
		}

		return 0;
}

void PrintJSFrame(ULONG64 framePoint, ULONG64 retrunAddr)
{
	//ULONG_PTR jsFun;
	//JSFunction
	PVOID jsFun;

	//SharedFunctionInfo
	PVOID sharedFuncInfo;

	ULONG cb = 0;
	UINT8 typeByte = 0;

	dprintf("%08p %08p ", framePoint, retrunAddr);


	if (PrintSpecialJSFrame(DEV8PTR(framePoint)))
		return;

	//framePoint + _V8DBG_OFF_FP_FUNCTION == EBP - 8, read the JavaScript Functino(JSFunction)
	if (ReadMemory(framePoint + _V8DBG_OFF_FP_FUNCTION, &jsFun, sizeof(jsFun), &cb) && cb == sizeof(jsFun))
	{
		DBG_OUT("JSFunction @ %p\n", DEV8PTR(jsFun));

		if (GetTypeByte(&typeByte, DEV8PTR(jsFun)) != 0)
		{
			DBG_OUT("Failed to Read Type Byte for Java Script Function Object %p", DEV8PTR(jsFun));
			dprintf("??(%p)\n", jsFun);
			return;
		}

		//DBG_TRACE("%x(%s)", typeByte, V8TypeToString(typeByte));
		//DBG_OUT("Java Script Function Object Type is %d\n", typeByte);

		if (typeByte == _V8DBG_TYPE_CODE__CODE_TYPE)
		{
			dprintf("Internal Frame(%p)\n", jsFun);
			return;
		}
		
		if (typeByte != _V8DBG_TYPE_JSFUNCTION__JS_FUNCTION_TYPE)
		{
			dprintf("??(%p)\n", jsFun);
			return;
		}

		/*if (typeByte == _V8DBG_TYPE_CODE__CODE_TYPE)
		{
			dprintf("Internal Frame(%p)", jsFun);
		}*/
		//JSFunction+_V8DBG_OFF_FP_FUNCTION == JSFunction+0n20, read the SharedFunctionInfo Object
		if (ReadMemory(DEV8PTR(jsFun) + _V8DBG_CLASS_JSFUNCTION__SHARED__SHAREDFUNCTIONINFO, &sharedFuncInfo, sizeof(sharedFuncInfo), &cb) && cb == sizeof(sharedFuncInfo))
		{
			DBG_OUT("SharedFuncInfo @ %p\n", DEV8PTR(sharedFuncInfo));
		}
		else
		{
			DBG_OUT("Failed to Read SharedFuncInfo at: %p", DEV8PTR(jsFun) + _V8DBG_CLASS_JSFUNCTION__SHARED__SHAREDFUNCTIONINFO);
			dprintf("??\n");
			return;
		}

		PrintJSFunctionName(DEV8PTR(sharedFuncInfo));

	}
	else
	{
		DBG_OUT("Failed to Read JavaScript Function at: %P", framePoint + _V8DBG_OFF_FP_FUNCTION);
		dprintf("??\n");
		return;
	}

	dprintf(" [");
	PrintJSScriptFileName(DEV8PTR(sharedFuncInfo));
	PrintLineNo(DEV8PTR(sharedFuncInfo));

	dprintf(" ]");
	dprintf("\n");

	return;
}

//
// Extension to dump stacktrace
//
DECLARE_API(stack)
{
	EXTSTACKTRACE64 stk[100];
	ULONG frames, i;
	CHAR Buffer[256];
	ULONG64 displacement;
	
	ULONG64 framePtr = 0x0081f614;
	ULONG64 retAddr = 0x1d70e501;

	// Get stacktrace for surrent thread 
	frames = StackTrace(0, 0, 0, stk, 100);

	if (!frames) {
		dprintf("Stacktrace failed\n");
	}

	for (i = 0; i<frames; i++) {

		if (i == 0) {
			dprintf(" #  ChildEBP RetAddr  Args to Child\n");
		}

		Buffer[0] = '!';
		GetSymbol(stk[i].ProgramCounter, (PCHAR)Buffer, &displacement);

		dprintf("%02x ", i);
		if (Buffer[0] == '\0')
		{
			PrintJSFrame(stk[i].FramePointer,
				stk[i].ReturnAddress);
			continue;
		}

		dprintf("%08p %08p %s",
			stk[i].FramePointer,
			stk[i].ReturnAddress,
			//stk[i].Args[0],
			//stk[i].Args[1],
			//stk[i].Args[2],
			Buffer
			);

		if (displacement) {
			dprintf("+0x%01p", displacement);
		}

		dprintf("\n");
	}
}


//
// Extension to display V8 version
//
DECLARE_API(v8ver)
{
	CHAR buffer[MAX_PATH];
	ULONG64 v8Ver = NULL;
	ULONG64 v8VerStr = NULL;
	//IDebugClient *DebugClient;

	// Get stacktrace for surrent thread 
	v8Ver = GetExpression("node!v8::internal::Version::version_string_");

	DBG_OUT_LN("Addres of *!v8::internal::Version::version_string_ is %p", v8Ver);
	if (NULL == v8Ver)
		return;

	if (!ReadPointer(v8Ver, &v8VerStr))
	{
		DBG_OUT_LN("Failed to read V8 version string point at %p", v8Ver);
	}

	DBG_OUT_LN("V8 version string at %p", v8VerStr);

	if (NULL == v8VerStr)
		return;

	if (SUCCEEDED(ReadString(v8VerStr, MAX_PATH, buffer)))
		dprintf("V8 Version: %s\n", buffer);
	else
		dprintf("V8 Version is unknown\n", buffer);
}


#pragma region test
//
// Extension to test memory read feature
//
DECLARE_API(test)
{

	ULONG_PTR obj;
	ULONG_PTR addr = (ULONG)GetExpression(args);
	ULONG cb;
	
	//read memory at specified address
	if ((ReadMemory(addr, &obj, sizeof(obj), &cb) && cb == sizeof(obj)))
	{
		//DBG_TRACE("Memory at address %p", addr);
		//DBG_TRACE(" is %p\n", obj);
		DBG_TRACE("Memory @ address %x is %x", addr, obj);
	}
	else
		DBG_TRACE("Failed to read memory @ address %p\n", addr);
}

#pragma endregion


#pragma region objType

DECLARE_API(objType)
{
	char *typeStr;
	UINT8 objType;
	ULONG_PTR obj = (ULONG_PTR)GetExpression(args);

	DBG_TRACE("object @ %x", obj);
	if (NULL == obj)
	{
		dprintf("usage: !objType <object address>");
		return;
	}

	/*
	* we need the Map to figure out how to iterate the properties for this object.
	*/
	if (GetTypeByte(&objType, DEV8PTR(obj)) != 0)
	{
		dprintf("failed to read type byte for jscript object %x\n", DEV8PTR(obj));
		return;
	}
	

	switch (objType) {
		#define X(uc, lc) case _V8DBG_TYPE_##uc: typeStr = #lc; break;
		V8_OBJECT_TYPE_MAP(X)
#undef X
	case _V8DBG_ASCIISTRINGTAG: typeStr = "ASCIISTRING"; break;
	case _V8DBG_CONSSTRINGTAG: typeStr = "CONSSTRING"; break;
	case _V8DBG_EXTERNALSTRINGTAG: typeStr = "EXTERNALSTRING"; break;
	case _V8DBG_SLICEDSTRINGTAG: typeStr = "SLICEDSTRING"; break;
	default: typeStr = "<unknown>";
	}
	DBG_TRACE("type of Object @ %x is %x(%d)(%s)\n", obj, objType, objType, typeStr);

	dprintf("Object @ %x type=%x ( %s ) \n", obj, objType, typeStr);
}

#pragma endregion




#pragma region objType
void PrintJSFuncInfo(ULONG_PTR sharedFuncInfo)
{
	
	ULONG cb = 0;
	UINT8 objType = 0;
	char* source;

	/*
	* we need the Map to figure out how to iterate the properties for this object.
	*/
	if (GetTypeByte(&objType, DEV8PTR(sharedFuncInfo)) != 0)
	{
		dprintf("failed to read type byte for jscript object %x\n", DEV8PTR(sharedFuncInfo));
		return;
	}

	if (objType != _V8DBG_TYPE_SHAREDFUNCTIONINFO__SHARED_FUNCTION_INFO_TYPE)
	{
		dprintf("object %s is not an V8 shared function info type\n");
		return;
	}


	PrintJSFunctionName(DEV8PTR(sharedFuncInfo));
	PrintJSScriptFileName(DEV8PTR(sharedFuncInfo));
	//PrintLineNo(DEV8PTR(sharedFuncInfo));

	int end = GetFuncEndPostion(DEV8PTR(sharedFuncInfo));
	int start = GetFuncStartPostion(DEV8PTR(sharedFuncInfo));
	int current = GetFuncTokenPostion(DEV8PTR(sharedFuncInfo));

	source = ReadScriptSource(DEV8PTR(sharedFuncInfo));
	printFunction(start<current?start:current, end, source);

	return;
}

DECLARE_API(dumpJsFun)
{
	ULONG_PTR obj = (ULONG_PTR)GetExpression(args);

	DBG_TRACE("object @ %x", obj);
	if (NULL == obj)
	{
		dprintf("usage: !dumpJsFun <V8 Shared Function info object address>\n");
		return;
	}

	PrintJSFuncInfo(obj);
}

#pragma endregion



/*
  A built-in help for the extension dll
*/
extern "C"
HRESULT CALLBACK
help(PDEBUG_CLIENT4 Client, PCSTR args)
{
    INIT_API();

    UNREFERENCED_PARAMETER(args);

    dprintf("Help for V8DbgExts.dll\n"
            "  help						- Shows this help\n"
			"  stack					- Dump Call Stacks with JavaScript stack\n"
			"  dumpJsObj				- dump a JSObject\n"
			"  v8ver					- Get V8 Version\n"
			"  findJsObject				- Find JSObject in specified address, if no address give, search whole V8 heap\n"
			"  objType					- Given an JSObject address, print the type of object\n"
			"  dumpJsFun				- Given an JsSharedFunction object address, print the details of the function\n"
            );

	EXIT_API();

    return S_OK;
}


//
//if ((DebugCreate(__uuidof(IDebugClient),
//	(void **)&DebugClient)) != S_OK)
//{
//	return;
//}
//
//if ((DebugClient->QueryInterface(__uuidof(IDebugSymbols2),
//	(void **)&g_ExtSymbols)) != S_OK)
//{
//	return;
//}
//
//DBG_OUT_LN("g_ExtSymbols %p", (ULONG64)g_ExtSymbols);
//g_ExtSymbols->GetOffsetByName("node!v8::internal::Version::version_string_", &v8Ver);