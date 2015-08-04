
/*
* File automatically generated . Do not edit.
*/

#ifndef V8_CONSTANTS_UTIL_H
#define V8_CONSTANTS_UTIL_H

#include "v8constants.h"


/*
*Type definition for V8 Object type
*/
/*
typedef enum {
_V8DBG_TYPE_SEQTWOBYTESTRING__STRING_TYPE = 0x40,
_V8DBG_TYPE_CONSSTRING__CONS_STRING_TYPE = 0x41,
_V8DBG_TYPE_EXTERNALTWOBYTESTRING__EXTERNAL_STRING_TYPE = 0x42,
_V8DBG_TYPE_SLICEDSTRING__SLICED_STRING_TYPE = 0x43,
_V8DBG_TYPE_SEQONEBYTESTRING__ASCII_STRING_TYPE = 0x44,
_V8DBG_TYPE_CONSSTRING__CONS_ASCII_STRING_TYPE = 0x45,
_V8DBG_TYPE_EXTERNALASCIISTRING__EXTERNAL_ASCII_STRING_TYPE = 0x46,
_V8DBG_TYPE_SLICEDSTRING__SLICED_ASCII_STRING_TYPE = 0x47,
_V8DBG_TYPE_SEQTWOBYTESTRING__SYMBOL_TYPE = 0x80,
_V8DBG_TYPE_MAP__MAP_TYPE = 0x81,
_V8DBG_TYPE_CODE__CODE_TYPE = 0x82,
_V8DBG_TYPE_ODDBALL__ODDBALL_TYPE = 0x83,
_V8DBG_TYPE_CELL__CELL_TYPE = 0x84,
_V8DBG_TYPE_PROPERTYCELL__PROPERTY_CELL_TYPE = 0x85,
_V8DBG_TYPE_HEAPNUMBER__HEAP_NUMBER_TYPE = 0x86,
_V8DBG_TYPE_FOREIGN__FOREIGN_TYPE = 0x88,
_V8DBG_TYPE_BYTEARRAY__BYTE_ARRAY_TYPE = 0x89,
_V8DBG_TYPE_FREESPACE__FREE_SPACE_TYPE = 0x8a,
_V8DBG_TYPE_EXTERNALINT8ARRAY__EXTERNAL_INT8_ARRAY_TYPE = 0x8b,
_V8DBG_TYPE_EXTERNALUINT8ARRAY__EXTERNAL_UINT8_ARRAY_TYPE = 0x8c,
_V8DBG_TYPE_EXTERNALINT16ARRAY__EXTERNAL_INT16_ARRAY_TYPE = 0x8d,
_V8DBG_TYPE_EXTERNALUINT16ARRAY__EXTERNAL_UINT16_ARRAY_TYPE = 0x8e,
_V8DBG_TYPE_EXTERNALINT32ARRAY__EXTERNAL_INT32_ARRAY_TYPE = 0x8f,
_V8DBG_TYPE_EXTERNALUINT32ARRAY__EXTERNAL_UINT32_ARRAY_TYPE = 0x90,
_V8DBG_TYPE_EXTERNALFLOAT32ARRAY__EXTERNAL_FLOAT32_ARRAY_TYPE = 0x91,
_V8DBG_TYPE_EXTERNALFLOAT64ARRAY__EXTERNAL_FLOAT64_ARRAY_TYPE = 0x92,
_V8DBG_TYPE_EXTERNALUINT8CLAMPEDARRAY__EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE = 0x93,
_V8DBG_TYPE_FIXEDDOUBLEARRAY__FIXED_DOUBLE_ARRAY_TYPE = 0x9d,
_V8DBG_TYPE_DECLAREDACCESSORDESCRIPTOR__DECLARED_ACCESSOR_DESCRIPTOR_TYPE = 0x9f,
_V8DBG_TYPE_DECLAREDACCESSORINFO__DECLARED_ACCESSOR_INFO_TYPE = 0xa0,
_V8DBG_TYPE_EXECUTABLEACCESSORINFO__EXECUTABLE_ACCESSOR_INFO_TYPE = 0xa1,
_V8DBG_TYPE_ACCESSORPAIR__ACCESSOR_PAIR_TYPE = 0xa2,
_V8DBG_TYPE_ACCESSCHECKINFO__ACCESS_CHECK_INFO_TYPE = 0xa3,
_V8DBG_TYPE_INTERCEPTORINFO__INTERCEPTOR_INFO_TYPE = 0xa4,
_V8DBG_TYPE_CALLHANDLERINFO__CALL_HANDLER_INFO_TYPE = 0xa5,
_V8DBG_TYPE_FUNCTIONTEMPLATEINFO__FUNCTION_TEMPLATE_INFO_TYPE = 0xa6,
_V8DBG_TYPE_OBJECTTEMPLATEINFO__OBJECT_TEMPLATE_INFO_TYPE = 0xa7,
_V8DBG_TYPE_SIGNATUREINFO__SIGNATURE_INFO_TYPE = 0xa8,
_V8DBG_TYPE_TYPESWITCHINFO__TYPE_SWITCH_INFO_TYPE = 0xa9,
_V8DBG_TYPE_ALLOCATIONSITE__ALLOCATION_SITE_TYPE = 0xaa,
_V8DBG_TYPE_ALLOCATIONMEMENTO__ALLOCATION_MEMENTO_TYPE = 0xab,
_V8DBG_TYPE_SCRIPT__SCRIPT_TYPE = 0xac,
_V8DBG_TYPE_CODECACHE__CODE_CACHE_TYPE = 0xad,
_V8DBG_TYPE_POLYMORPHICCODECACHE__POLYMORPHIC_CODE_CACHE_TYPE = 0xae,
_V8DBG_TYPE_TYPEFEEDBACKINFO__TYPE_FEEDBACK_INFO_TYPE = 0xaf,
_V8DBG_TYPE_ALIASEDARGUMENTSENTRY__ALIASED_ARGUMENTS_ENTRY_TYPE = 0xb0,
_V8DBG_TYPE_DEBUGINFO__DEBUG_INFO_TYPE = 0xb2,
_V8DBG_TYPE_BREAKPOINTINFO__BREAK_POINT_INFO_TYPE = 0xb3,
_V8DBG_TYPE_FIXEDARRAY__FIXED_ARRAY_TYPE = 0xb4,
_V8DBG_TYPE_CONSTANTPOOLARRAY__CONSTANT_POOL_ARRAY_TYPE = 0xb5,
_V8DBG_TYPE_SHAREDFUNCTIONINFO__SHARED_FUNCTION_INFO_TYPE = 0xb6,
_V8DBG_TYPE_JSFUNCTIONPROXY__JS_FUNCTION_PROXY_TYPE = 0xb7,
_V8DBG_TYPE_JSPROXY__JS_PROXY_TYPE = 0xb8,
_V8DBG_TYPE_JSVALUE__JS_VALUE_TYPE = 0xb9,
_V8DBG_TYPE_JSMESSAGEOBJECT__JS_MESSAGE_OBJECT_TYPE = 0xba,
_V8DBG_TYPE_JSDATE__JS_DATE_TYPE = 0xbb,
_V8DBG_TYPE_JSOBJECT__JS_OBJECT_TYPE = 0xbc,
_V8DBG_TYPE_JSGENERATOROBJECT__JS_GENERATOR_OBJECT_TYPE = 0xbe,
_V8DBG_TYPE_JSMODULE__JS_MODULE_TYPE = 0xbf,
_V8DBG_TYPE_JSGLOBALOBJECT__JS_GLOBAL_OBJECT_TYPE = 0xc0,
_V8DBG_TYPE_JSBUILTINSOBJECT__JS_BUILTINS_OBJECT_TYPE = 0xc1,
_V8DBG_TYPE_JSARRAY__JS_ARRAY_TYPE = 0xc3,
_V8DBG_TYPE_JSARRAYBUFFER__JS_ARRAY_BUFFER_TYPE = 0xc4,
_V8DBG_TYPE_JSTYPEDARRAY__JS_TYPED_ARRAY_TYPE = 0xc5,
_V8DBG_TYPE_JSDATAVIEW__JS_DATA_VIEW_TYPE = 0xc6,
_V8DBG_TYPE_JSWEAKMAP__JS_WEAK_MAP_TYPE = 0xcb,
_V8DBG_TYPE_JSWEAKSET__JS_WEAK_SET_TYPE = 0xcc,
_V8DBG_TYPE_JSREGEXP__JS_REGEXP_TYPE = 0xcd,
_V8DBG_TYPE_JSFUNCTION__JS_FUNCTION_TYPE = 0xce

} V8_OBJECT_TYPE;
*/

/*
*Type handle map for V8 Object type
*/

#define V8_OBJECT_TYPE_MAP(XX)    \
  XX(SEQTWOBYTESTRING__STRING_TYPE, STRING_TYPE)			\
  XX(CONSSTRING__CONS_STRING_TYPE, CONS_STRING_TYPE)			\
  XX(EXTERNALTWOBYTESTRING__EXTERNAL_STRING_TYPE, EXTERNAL_STRING_TYPE)			\
  XX(SLICEDSTRING__SLICED_STRING_TYPE, SLICED_STRING_TYPE)			\
  XX(SEQONEBYTESTRING__ASCII_STRING_TYPE, ASCII_STRING_TYPE)			\
  XX(CONSSTRING__CONS_ASCII_STRING_TYPE, CONS_ASCII_STRING_TYPE)			\
  XX(EXTERNALASCIISTRING__EXTERNAL_ASCII_STRING_TYPE, EXTERNAL_ASCII_STRING_TYPE)			\
  XX(SLICEDSTRING__SLICED_ASCII_STRING_TYPE, SLICED_ASCII_STRING_TYPE)			\
  XX(SEQTWOBYTESTRING__SYMBOL_TYPE, SYMBOL_TYPE)			\
  XX(MAP__MAP_TYPE, MAP_TYPE)			\
  XX(CODE__CODE_TYPE, CODE_TYPE)			\
  XX(ODDBALL__ODDBALL_TYPE, ODDBALL_TYPE)			\
  XX(CELL__CELL_TYPE, CELL_TYPE)			\
  XX(PROPERTYCELL__PROPERTY_CELL_TYPE, PROPERTY_CELL_TYPE)			\
  XX(HEAPNUMBER__HEAP_NUMBER_TYPE, HEAP_NUMBER_TYPE)			\
  XX(FOREIGN__FOREIGN_TYPE, FOREIGN_TYPE)			\
  XX(BYTEARRAY__BYTE_ARRAY_TYPE, BYTE_ARRAY_TYPE)			\
  XX(FREESPACE__FREE_SPACE_TYPE, FREE_SPACE_TYPE)			\
  XX(EXTERNALINT8ARRAY__EXTERNAL_INT8_ARRAY_TYPE, EXTERNAL_INT8_ARRAY_TYPE)			\
  XX(EXTERNALUINT8ARRAY__EXTERNAL_UINT8_ARRAY_TYPE, EXTERNAL_UINT8_ARRAY_TYPE)			\
  XX(EXTERNALINT16ARRAY__EXTERNAL_INT16_ARRAY_TYPE, EXTERNAL_INT16_ARRAY_TYPE)			\
  XX(EXTERNALUINT16ARRAY__EXTERNAL_UINT16_ARRAY_TYPE, EXTERNAL_UINT16_ARRAY_TYPE)			\
  XX(EXTERNALINT32ARRAY__EXTERNAL_INT32_ARRAY_TYPE, EXTERNAL_INT32_ARRAY_TYPE)			\
  XX(EXTERNALUINT32ARRAY__EXTERNAL_UINT32_ARRAY_TYPE, EXTERNAL_UINT32_ARRAY_TYPE)			\
  XX(EXTERNALFLOAT32ARRAY__EXTERNAL_FLOAT32_ARRAY_TYPE, EXTERNAL_FLOAT32_ARRAY_TYPE)			\
  XX(EXTERNALFLOAT64ARRAY__EXTERNAL_FLOAT64_ARRAY_TYPE, EXTERNAL_FLOAT64_ARRAY_TYPE)			\
  XX(EXTERNALUINT8CLAMPEDARRAY__EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE, EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE)			\
  XX(FIXEDDOUBLEARRAY__FIXED_DOUBLE_ARRAY_TYPE, FIXED_DOUBLE_ARRAY_TYPE)			\
  XX(DECLAREDACCESSORDESCRIPTOR__DECLARED_ACCESSOR_DESCRIPTOR_TYPE, DECLARED_ACCESSOR_DESCRIPTOR_TYPE)			\
  XX(DECLAREDACCESSORINFO__DECLARED_ACCESSOR_INFO_TYPE, DECLARED_ACCESSOR_INFO_TYPE)			\
  XX(EXECUTABLEACCESSORINFO__EXECUTABLE_ACCESSOR_INFO_TYPE, EXECUTABLE_ACCESSOR_INFO_TYPE)			\
  XX(ACCESSORPAIR__ACCESSOR_PAIR_TYPE, ACCESSOR_PAIR_TYPE)			\
  XX(ACCESSCHECKINFO__ACCESS_CHECK_INFO_TYPE, ACCESS_CHECK_INFO_TYPE)			\
  XX(INTERCEPTORINFO__INTERCEPTOR_INFO_TYPE, INTERCEPTOR_INFO_TYPE)			\
  XX(CALLHANDLERINFO__CALL_HANDLER_INFO_TYPE, CALL_HANDLER_INFO_TYPE)			\
  XX(FUNCTIONTEMPLATEINFO__FUNCTION_TEMPLATE_INFO_TYPE, FUNCTION_TEMPLATE_INFO_TYPE)			\
  XX(OBJECTTEMPLATEINFO__OBJECT_TEMPLATE_INFO_TYPE, OBJECT_TEMPLATE_INFO_TYPE)			\
  XX(SIGNATUREINFO__SIGNATURE_INFO_TYPE, SIGNATURE_INFO_TYPE)			\
  XX(TYPESWITCHINFO__TYPE_SWITCH_INFO_TYPE, TYPE_SWITCH_INFO_TYPE)			\
  XX(ALLOCATIONSITE__ALLOCATION_SITE_TYPE, ALLOCATION_SITE_TYPE)			\
  XX(ALLOCATIONMEMENTO__ALLOCATION_MEMENTO_TYPE, ALLOCATION_MEMENTO_TYPE)			\
  XX(SCRIPT__SCRIPT_TYPE, SCRIPT_TYPE)			\
  XX(CODECACHE__CODE_CACHE_TYPE, CODE_CACHE_TYPE)			\
  XX(POLYMORPHICCODECACHE__POLYMORPHIC_CODE_CACHE_TYPE, POLYMORPHIC_CODE_CACHE_TYPE)			\
  XX(TYPEFEEDBACKINFO__TYPE_FEEDBACK_INFO_TYPE, TYPE_FEEDBACK_INFO_TYPE)			\
  XX(ALIASEDARGUMENTSENTRY__ALIASED_ARGUMENTS_ENTRY_TYPE, ALIASED_ARGUMENTS_ENTRY_TYPE)			\
  XX(DEBUGINFO__DEBUG_INFO_TYPE, DEBUG_INFO_TYPE)			\
  XX(BREAKPOINTINFO__BREAK_POINT_INFO_TYPE, BREAK_POINT_INFO_TYPE)			\
  XX(FIXEDARRAY__FIXED_ARRAY_TYPE, FIXED_ARRAY_TYPE)			\
  XX(CONSTANTPOOLARRAY__CONSTANT_POOL_ARRAY_TYPE, CONSTANT_POOL_ARRAY_TYPE)			\
  XX(SHAREDFUNCTIONINFO__SHARED_FUNCTION_INFO_TYPE, SHARED_FUNCTION_INFO_TYPE)			\
  XX(JSFUNCTIONPROXY__JS_FUNCTION_PROXY_TYPE, JS_FUNCTION_PROXY_TYPE)			\
  XX(JSPROXY__JS_PROXY_TYPE, JS_PROXY_TYPE)			\
  XX(JSVALUE__JS_VALUE_TYPE, JS_VALUE_TYPE)			\
  XX(JSMESSAGEOBJECT__JS_MESSAGE_OBJECT_TYPE, JS_MESSAGE_OBJECT_TYPE)			\
  XX(JSDATE__JS_DATE_TYPE, JS_DATE_TYPE)			\
  XX(JSOBJECT__JS_OBJECT_TYPE, JS_OBJECT_TYPE)			\
  XX(JSGENERATOROBJECT__JS_GENERATOR_OBJECT_TYPE, JS_GENERATOR_OBJECT_TYPE)			\
  XX(JSMODULE__JS_MODULE_TYPE, JS_MODULE_TYPE)			\
  XX(JSGLOBALOBJECT__JS_GLOBAL_OBJECT_TYPE, JS_GLOBAL_OBJECT_TYPE)			\
  XX(JSBUILTINSOBJECT__JS_BUILTINS_OBJECT_TYPE, JS_BUILTINS_OBJECT_TYPE)			\
  XX(JSARRAY__JS_ARRAY_TYPE, JS_ARRAY_TYPE)			\
  XX(JSARRAYBUFFER__JS_ARRAY_BUFFER_TYPE, JS_ARRAY_BUFFER_TYPE)			\
  XX(JSTYPEDARRAY__JS_TYPED_ARRAY_TYPE, JS_TYPED_ARRAY_TYPE)			\
  XX(JSDATAVIEW__JS_DATA_VIEW_TYPE, JS_DATA_VIEW_TYPE)			\
  XX(JSWEAKMAP__JS_WEAK_MAP_TYPE, JS_WEAK_MAP_TYPE)			\
  XX(JSWEAKSET__JS_WEAK_SET_TYPE, JS_WEAK_SET_TYPE)			\
  XX(JSREGEXP__JS_REGEXP_TYPE, JS_REGEXP_TYPE)			\
  XX(JSFUNCTION__JS_FUNCTION_TYPE, JS_FUNCTION_TYPE)			\


/*
*Type definition for V8 frame type
*/
/*
typedef enum {
_V8DBG_FRAMETYPE_ENTRYFRAME = 0x1,
_V8DBG_FRAMETYPE_ENTRYCONSTRUCTFRAME = 0x2,
_V8DBG_FRAMETYPE_EXITFRAME = 0x3,
_V8DBG_FRAMETYPE_JAVASCRIPTFRAME = 0x4,
_V8DBG_FRAMETYPE_OPTIMIZEDFRAME = 0x5,
_V8DBG_FRAMETYPE_STUBFRAME = 0x6,
_V8DBG_FRAMETYPE_STUBFAILURETRAMPOLINEFRAME = 0x7,
_V8DBG_FRAMETYPE_INTERNALFRAME = 0x8,
_V8DBG_FRAMETYPE_CONSTRUCTFRAME = 0x9,
_V8DBG_FRAMETYPE_ARGUMENTSADAPTORFRAME = 0xa

} V8_FRAME_TYPE;
*/

/*
*Type handle map for V8 Object type
*/
#define V8_FRAME_TYPE_MAP(XX)    \
  XX(ENTRYFRAME, ENTRYFRAME)			\
  XX(ENTRYCONSTRUCTFRAME, ENTRYCONSTRUCTFRAME)			\
  XX(EXITFRAME, EXITFRAME)			\
  XX(JAVASCRIPTFRAME, JAVASCRIPTFRAME)			\
  XX(OPTIMIZEDFRAME, OPTIMIZEDFRAME)			\
  XX(STUBFRAME, STUBFRAME)			\
  XX(STUBFAILURETRAMPOLINEFRAME, STUBFAILURETRAMPOLINEFRAME)			\
  XX(INTERNALFRAME, INTERNALFRAME)			\
  XX(CONSTRUCTFRAME, CONSTRUCTFRAME)			\
  XX(ARGUMENTSADAPTORFRAME, ARGUMENTSADAPTORFRAME)			\


#endif /* V8_CONSTANTS_UTIL_H */



typedef enum {
	JPI_NONE = 0,

	/*
	* Indicates how properties are stored in this object.  There can be
	* both numeric properties and some of the other kinds.
	*/
	JPI_NUMERIC = 0x01,	/* numeric-named properties in "elements" */
	JPI_DICT = 0x02,	/* dictionary properties */
	JPI_INOBJECT = 0x04,	/* properties stored inside object */
	JPI_PROPS = 0x08,	/* "properties" array */

	/* error-like cases */
	JPI_SKIPPED = 0x10,	/* some properties were skipped */
	JPI_BADLAYOUT = 0x20,	/* we didn't recognize the layout at all */

	/* fallback cases */
	JPI_HASTRANSITIONS = 0x100, /* found a transitions array */
	JPI_HASCONTENT = 0x200, /* found a separate content array */
} V8_PROP_INFO;




static const int kStartPositionShift = 2;
