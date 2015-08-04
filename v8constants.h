
/*
* File automatically generated by genv8constants. Do not edit.
*
* The following offsets are dynamically from libv8_base.a.  See src/v8ustack.d
* for details on how these values are used.
*/

#ifndef V8_CONSTANTS_H
#define V8_CONSTANTS_H

#define _V8DBG_FRAMETYPE_ENTRYFRAME 0x1
#define _V8DBG_FRAMETYPE_ENTRYCONSTRUCTFRAME 0x2
#define _V8DBG_FRAMETYPE_EXITFRAME 0x3
#define _V8DBG_FRAMETYPE_JAVASCRIPTFRAME 0x4
#define _V8DBG_FRAMETYPE_OPTIMIZEDFRAME 0x5
#define _V8DBG_FRAMETYPE_STUBFRAME 0x6
#define _V8DBG_FRAMETYPE_STUBFAILURETRAMPOLINEFRAME 0x7
#define _V8DBG_FRAMETYPE_INTERNALFRAME 0x8
#define _V8DBG_FRAMETYPE_CONSTRUCTFRAME 0x9
#define _V8DBG_FRAMETYPE_ARGUMENTSADAPTORFRAME 0xa
#define _V8DBG_FIRSTNONSTRINGTYPE 0x80
#define _V8DBG_ISNOTSTRINGMASK 0x80
#define _V8DBG_NOTSTRINGTAG 0x80
#define _V8DBG_STRINGENCODINGMASK 0x4
#define _V8DBG_ASCIISTRINGTAG 0x4
#define _V8DBG_STRINGREPRESENTATIONMASK 0x3
#define _V8DBG_CONSSTRINGTAG 0x1
#define _V8DBG_EXTERNALSTRINGTAG 0x2
#define _V8DBG_SLICEDSTRINGTAG 0x3
#define _V8DBG_HEAPOBJECTTAG 0x1
#define _V8DBG_HEAPOBJECTTAGMASK 0x3
#define _V8DBG_SMITAGMASK 0x1
#define _V8DBG_SMIVALUESHIFT 0x1
#define _V8DBG_POINTERSIZELOG2 0x2
#define _V8DBG_ODDBALLTRUE 0x1
#define _V8DBG_ODDBALLTHEHOLE 0x2
#define _V8DBG_ODDBALLNULL 0x3
#define _V8DBG_ODDBALLARGUMENTMARKER 0x4
#define _V8DBG_ODDBALLUNDEFINED 0x5
#define _V8DBG_ODDBALLUNINITIALIZED 0x6
#define _V8DBG_ODDBALLOTHER 0x7
#define _V8DBG_ODDBALLEXCEPTION 0x8
#define _V8DBG_PROP_IDX_FIRST 0x2
#define _V8DBG_PROP_TYPE_FIELD 0x1
#define _V8DBG_PROP_TYPE_MASK 0x7
#define _V8DBG_PROP_INDEX_MASK 0x3ff00000
#define _V8DBG_PROP_INDEX_SHIFT 0x14
#define _V8DBG_PROP_DESC_DETAILS 0x1
#define _V8DBG_PROP_DESC_VALUE 0x2
#define _V8DBG_PROP_DESC_SIZE 0x3
#define _V8DBG_ELEMENTS_FAST_HOLEY_ELEMENTS 0x3
#define _V8DBG_ELEMENTS_FAST_ELEMENTS 0x2
#define _V8DBG_ELEMENTS_DICTIONARY_ELEMENTS 0x6
#define _V8DBG_BIT_FIELD2_ELEMENTS_KIND_MASK 0xf8
#define _V8DBG_BIT_FIELD2_ELEMENTS_KIND_SHIFT 0x3
#define _V8DBG_BIT_FIELD3_DICTIONARY_MAP_SHIFT 0x14
#define _V8DBG_FIELDINDEX_MASK 0x0
#define _V8DBG_FIELDINDEX_SHIFT 0x14
#define _V8DBG_OFF_FP_CONTEXT -0x4
#define _V8DBG_OFF_FP_MARKER -0x8
#define _V8DBG_OFF_FP_FUNCTION -0x8
#define _V8DBG_OFF_FP_ARGS 0x8
#define _V8DBG_TYPE_ACCESSORPAIR__ACCESSOR_PAIR_TYPE 0xa2
#define _V8DBG_TYPE_ACCESSCHECKINFO__ACCESS_CHECK_INFO_TYPE 0xa3
#define _V8DBG_TYPE_ALIASEDARGUMENTSENTRY__ALIASED_ARGUMENTS_ENTRY_TYPE 0xb0
#define _V8DBG_TYPE_ALLOCATIONMEMENTO__ALLOCATION_MEMENTO_TYPE 0xab
#define _V8DBG_TYPE_ALLOCATIONSITE__ALLOCATION_SITE_TYPE 0xaa
#define _V8DBG_TYPE_SEQONEBYTESTRING__ASCII_STRING_TYPE 0x44
#define _V8DBG_TYPE_BREAKPOINTINFO__BREAK_POINT_INFO_TYPE 0xb3
#define _V8DBG_TYPE_BYTEARRAY__BYTE_ARRAY_TYPE 0x89
#define _V8DBG_TYPE_CALLHANDLERINFO__CALL_HANDLER_INFO_TYPE 0xa5
#define _V8DBG_TYPE_CELL__CELL_TYPE 0x84
#define _V8DBG_TYPE_CODECACHE__CODE_CACHE_TYPE 0xad
#define _V8DBG_TYPE_CODE__CODE_TYPE 0x82
#define _V8DBG_TYPE_CONSTANTPOOLARRAY__CONSTANT_POOL_ARRAY_TYPE 0xb5
#define _V8DBG_TYPE_CONSSTRING__CONS_ASCII_STRING_TYPE 0x45
#define _V8DBG_TYPE_CONSSTRING__CONS_STRING_TYPE 0x41
#define _V8DBG_TYPE_DEBUGINFO__DEBUG_INFO_TYPE 0xb2
#define _V8DBG_TYPE_DECLAREDACCESSORDESCRIPTOR__DECLARED_ACCESSOR_DESCRIPTOR_TYPE 0x9f
#define _V8DBG_TYPE_DECLAREDACCESSORINFO__DECLARED_ACCESSOR_INFO_TYPE 0xa0
#define _V8DBG_TYPE_EXECUTABLEACCESSORINFO__EXECUTABLE_ACCESSOR_INFO_TYPE 0xa1
#define _V8DBG_TYPE_EXTERNALASCIISTRING__EXTERNAL_ASCII_STRING_TYPE 0x46
#define _V8DBG_TYPE_EXTERNALFLOAT32ARRAY__EXTERNAL_FLOAT32_ARRAY_TYPE 0x91
#define _V8DBG_TYPE_EXTERNALFLOAT64ARRAY__EXTERNAL_FLOAT64_ARRAY_TYPE 0x92
#define _V8DBG_TYPE_EXTERNALINT16ARRAY__EXTERNAL_INT16_ARRAY_TYPE 0x8d
#define _V8DBG_TYPE_EXTERNALINT32ARRAY__EXTERNAL_INT32_ARRAY_TYPE 0x8f
#define _V8DBG_TYPE_EXTERNALINT8ARRAY__EXTERNAL_INT8_ARRAY_TYPE 0x8b
#define _V8DBG_TYPE_EXTERNALTWOBYTESTRING__EXTERNAL_STRING_TYPE 0x42
#define _V8DBG_TYPE_EXTERNALUINT16ARRAY__EXTERNAL_UINT16_ARRAY_TYPE 0x8e
#define _V8DBG_TYPE_EXTERNALUINT32ARRAY__EXTERNAL_UINT32_ARRAY_TYPE 0x90
#define _V8DBG_TYPE_EXTERNALUINT8ARRAY__EXTERNAL_UINT8_ARRAY_TYPE 0x8c
#define _V8DBG_TYPE_EXTERNALUINT8CLAMPEDARRAY__EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE 0x93
#define _V8DBG_TYPE_FIXEDARRAY__FIXED_ARRAY_TYPE 0xb4
#define _V8DBG_TYPE_FIXEDDOUBLEARRAY__FIXED_DOUBLE_ARRAY_TYPE 0x9d
#define _V8DBG_TYPE_FOREIGN__FOREIGN_TYPE 0x88
#define _V8DBG_TYPE_FREESPACE__FREE_SPACE_TYPE 0x8a
#define _V8DBG_TYPE_FUNCTIONTEMPLATEINFO__FUNCTION_TEMPLATE_INFO_TYPE 0xa6
#define _V8DBG_TYPE_HEAPNUMBER__HEAP_NUMBER_TYPE 0x86
#define _V8DBG_TYPE_INTERCEPTORINFO__INTERCEPTOR_INFO_TYPE 0xa4
#define _V8DBG_TYPE_JSARRAYBUFFER__JS_ARRAY_BUFFER_TYPE 0xc4
#define _V8DBG_TYPE_JSARRAY__JS_ARRAY_TYPE 0xc3
#define _V8DBG_TYPE_JSBUILTINSOBJECT__JS_BUILTINS_OBJECT_TYPE 0xc1
#define _V8DBG_TYPE_JSDATAVIEW__JS_DATA_VIEW_TYPE 0xc6
#define _V8DBG_TYPE_JSDATE__JS_DATE_TYPE 0xbb
#define _V8DBG_TYPE_JSFUNCTIONPROXY__JS_FUNCTION_PROXY_TYPE 0xb7
#define _V8DBG_TYPE_JSFUNCTION__JS_FUNCTION_TYPE 0xce
#define _V8DBG_TYPE_JSGENERATOROBJECT__JS_GENERATOR_OBJECT_TYPE 0xbe
#define _V8DBG_TYPE_JSGLOBALOBJECT__JS_GLOBAL_OBJECT_TYPE 0xc0
#define _V8DBG_TYPE_JSMESSAGEOBJECT__JS_MESSAGE_OBJECT_TYPE 0xba
#define _V8DBG_TYPE_JSMODULE__JS_MODULE_TYPE 0xbf
#define _V8DBG_TYPE_JSOBJECT__JS_OBJECT_TYPE 0xbc
#define _V8DBG_TYPE_JSPROXY__JS_PROXY_TYPE 0xb8
#define _V8DBG_TYPE_JSREGEXP__JS_REGEXP_TYPE 0xcd
#define _V8DBG_TYPE_JSTYPEDARRAY__JS_TYPED_ARRAY_TYPE 0xc5
#define _V8DBG_TYPE_JSVALUE__JS_VALUE_TYPE 0xb9
#define _V8DBG_TYPE_JSWEAKMAP__JS_WEAK_MAP_TYPE 0xcb
#define _V8DBG_TYPE_JSWEAKSET__JS_WEAK_SET_TYPE 0xcc
#define _V8DBG_TYPE_MAP__MAP_TYPE 0x81
#define _V8DBG_TYPE_OBJECTTEMPLATEINFO__OBJECT_TEMPLATE_INFO_TYPE 0xa7
#define _V8DBG_TYPE_ODDBALL__ODDBALL_TYPE 0x83
#define _V8DBG_TYPE_POLYMORPHICCODECACHE__POLYMORPHIC_CODE_CACHE_TYPE 0xae
#define _V8DBG_TYPE_PROPERTYCELL__PROPERTY_CELL_TYPE 0x85
#define _V8DBG_TYPE_SCRIPT__SCRIPT_TYPE 0xac
#define _V8DBG_TYPE_SHAREDFUNCTIONINFO__SHARED_FUNCTION_INFO_TYPE 0xb6
#define _V8DBG_TYPE_SIGNATUREINFO__SIGNATURE_INFO_TYPE 0xa8
#define _V8DBG_TYPE_SLICEDSTRING__SLICED_ASCII_STRING_TYPE 0x47
#define _V8DBG_TYPE_SLICEDSTRING__SLICED_STRING_TYPE 0x43
#define _V8DBG_TYPE_SEQTWOBYTESTRING__STRING_TYPE 0x40
#define _V8DBG_TYPE_SEQTWOBYTESTRING__SYMBOL_TYPE 0x80
#define _V8DBG_TYPE_TYPEFEEDBACKINFO__TYPE_FEEDBACK_INFO_TYPE 0xaf
#define _V8DBG_TYPE_TYPESWITCHINFO__TYPE_SWITCH_INFO_TYPE 0xa9
#define _V8DBG_CLASS_JSOBJECT__PROPERTIES__FIXEDARRAY 0x4
#define _V8DBG_CLASS_ODDBALL__TO_STRING__STRING 0x4
#define _V8DBG_CLASS_ODDBALL__TO_NUMBER__OBJECT 0x8
#define _V8DBG_CLASS_PROPERTYCELL__DEPENDENT_CODE__DEPENDENTCODE 0xc
#define _V8DBG_CLASS_FIXEDARRAYBASE__LENGTH__SMI 0x4
#define _V8DBG_CLASS_FREESPACE__SIZE__SMI 0x4
#define _V8DBG_CLASS_STRING__LENGTH__SMI 0x8
#define _V8DBG_CLASS_SYMBOL__NAME__OBJECT 0x8
#define _V8DBG_CLASS_SYMBOL__FLAGS__SMI 0xc
#define _V8DBG_CLASS_SLICEDSTRING__OFFSET__SMI 0x10
#define _V8DBG_CLASS_MAP__INSTANCE_DESCRIPTORS__DESCRIPTORARRAY 0x1c
#define _V8DBG_CLASS_MAP__CODE_CACHE__OBJECT 0x20
#define _V8DBG_CLASS_MAP__DEPENDENT_CODE__DEPENDENTCODE 0x24
#define _V8DBG_CLASS_MAP__CONSTRUCTOR__OBJECT 0x14
#define _V8DBG_CLASS_JSFUNCTION__SHARED__SHAREDFUNCTIONINFO 0x14
#define _V8DBG_CLASS_JSFUNCTION__LITERALS_OR_BINDINGS__FIXEDARRAY 0x1c
#define _V8DBG_CLASS_JSFUNCTION__NEXT_FUNCTION_LINK__OBJECT 0x20
#define _V8DBG_CLASS_GLOBALOBJECT__BUILTINS__JSBUILTINSOBJECT 0xc
#define _V8DBG_CLASS_GLOBALOBJECT__NATIVE_CONTEXT__CONTEXT 0x10
#define _V8DBG_CLASS_GLOBALOBJECT__GLOBAL_CONTEXT__CONTEXT 0x14
#define _V8DBG_CLASS_GLOBALOBJECT__GLOBAL_PROXY__JSOBJECT 0x18
#define _V8DBG_CLASS_JSGLOBALPROXY__NATIVE_CONTEXT__OBJECT 0xc
#define _V8DBG_CLASS_JSGLOBALPROXY__HASH__OBJECT 0x10
#define _V8DBG_CLASS_ACCESSORINFO__NAME__OBJECT 0x4
#define _V8DBG_CLASS_ACCESSORINFO__FLAG__SMI 0x8
#define _V8DBG_CLASS_ACCESSORINFO__EXPECTED_RECEIVER_TYPE__OBJECT 0xc
#define _V8DBG_CLASS_DECLAREDACCESSORDESCRIPTOR__SERIALIZED_DATA__BYTEARRAY 0x4
#define _V8DBG_CLASS_DECLAREDACCESSORINFO__DESCRIPTOR__DECLAREDACCESSORDESCRIPTOR 0x10
#define _V8DBG_CLASS_EXECUTABLEACCESSORINFO__GETTER__OBJECT 0x10
#define _V8DBG_CLASS_EXECUTABLEACCESSORINFO__SETTER__OBJECT 0x14
#define _V8DBG_CLASS_EXECUTABLEACCESSORINFO__DATA__OBJECT 0x18
#define _V8DBG_CLASS_BOX__VALUE__OBJECT 0x4
#define _V8DBG_CLASS_ACCESSORPAIR__GETTER__OBJECT 0x4
#define _V8DBG_CLASS_ACCESSORPAIR__SETTER__OBJECT 0x8
#define _V8DBG_CLASS_ACCESSCHECKINFO__NAMED_CALLBACK__OBJECT 0x4
#define _V8DBG_CLASS_ACCESSCHECKINFO__INDEXED_CALLBACK__OBJECT 0x8
#define _V8DBG_CLASS_ACCESSCHECKINFO__DATA__OBJECT 0xc
#define _V8DBG_CLASS_INTERCEPTORINFO__GETTER__OBJECT 0x4
#define _V8DBG_CLASS_INTERCEPTORINFO__SETTER__OBJECT 0x8
#define _V8DBG_CLASS_INTERCEPTORINFO__QUERY__OBJECT 0xc
#define _V8DBG_CLASS_INTERCEPTORINFO__DELETER__OBJECT 0x10
#define _V8DBG_CLASS_INTERCEPTORINFO__ENUMERATOR__OBJECT 0x14
#define _V8DBG_CLASS_INTERCEPTORINFO__DATA__OBJECT 0x18
#define _V8DBG_CLASS_CALLHANDLERINFO__CALLBACK__OBJECT 0x4
#define _V8DBG_CLASS_CALLHANDLERINFO__DATA__OBJECT 0x8
#define _V8DBG_CLASS_TEMPLATEINFO__TAG__OBJECT 0x4
#define _V8DBG_CLASS_TEMPLATEINFO__PROPERTY_LIST__OBJECT 0x8
#define _V8DBG_CLASS_TEMPLATEINFO__PROPERTY_ACCESSORS__OBJECT 0xc
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__SERIAL_NUMBER__OBJECT 0x10
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__CALL_CODE__OBJECT 0x14
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__PROTOTYPE_TEMPLATE__OBJECT 0x18
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__PARENT_TEMPLATE__OBJECT 0x1c
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__NAMED_PROPERTY_HANDLER__OBJECT 0x20
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__INDEXED_PROPERTY_HANDLER__OBJECT 0x24
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__INSTANCE_TEMPLATE__OBJECT 0x28
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__CLASS_NAME__OBJECT 0x2c
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__SIGNATURE__OBJECT 0x30
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__INSTANCE_CALL_HANDLER__OBJECT 0x34
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__ACCESS_CHECK_INFO__OBJECT 0x38
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__FLAG__SMI 0x3c
#define _V8DBG_CLASS_OBJECTTEMPLATEINFO__CONSTRUCTOR__OBJECT 0x10
#define _V8DBG_CLASS_OBJECTTEMPLATEINFO__INTERNAL_FIELD_COUNT__OBJECT 0x14
#define _V8DBG_CLASS_SIGNATUREINFO__RECEIVER__OBJECT 0x4
#define _V8DBG_CLASS_SIGNATUREINFO__ARGS__OBJECT 0x8
#define _V8DBG_CLASS_TYPESWITCHINFO__TYPES__OBJECT 0x4
#define _V8DBG_CLASS_ALLOCATIONSITE__TRANSITION_INFO__OBJECT 0x4
#define _V8DBG_CLASS_ALLOCATIONSITE__NESTED_SITE__OBJECT 0x8
#define _V8DBG_CLASS_ALLOCATIONSITE__PRETENURE_DATA__SMI 0xc
#define _V8DBG_CLASS_ALLOCATIONSITE__PRETENURE_CREATE_COUNT__SMI 0x10
#define _V8DBG_CLASS_ALLOCATIONSITE__DEPENDENT_CODE__DEPENDENTCODE 0x14
#define _V8DBG_CLASS_ALLOCATIONSITE__WEAK_NEXT__OBJECT 0x18
#define _V8DBG_CLASS_ALLOCATIONMEMENTO__ALLOCATION_SITE__OBJECT 0x4
#define _V8DBG_CLASS_SCRIPT__SOURCE__OBJECT 0x4
#define _V8DBG_CLASS_SCRIPT__NAME__OBJECT 0x8
#define _V8DBG_CLASS_SCRIPT__ID__SMI 0x24
#define _V8DBG_CLASS_SCRIPT__LINE_OFFSET__SMI 0xc
#define _V8DBG_CLASS_SCRIPT__COLUMN_OFFSET__SMI 0x10
#define _V8DBG_CLASS_SCRIPT__CONTEXT_DATA__OBJECT 0x14
#define _V8DBG_CLASS_SCRIPT__WRAPPER__FOREIGN 0x18
#define _V8DBG_CLASS_SCRIPT__TYPE__SMI 0x1c
#define _V8DBG_CLASS_SCRIPT__LINE_ENDS__OBJECT 0x20
#define _V8DBG_CLASS_SCRIPT__EVAL_FROM_SHARED__OBJECT 0x28
#define _V8DBG_CLASS_SCRIPT__EVAL_FROM_INSTRUCTIONS_OFFSET__SMI 0x2c
#define _V8DBG_CLASS_SCRIPT__FLAGS__SMI 0x30
#define _V8DBG_CLASS_SCRIPT__SOURCE_URL__OBJECT 0x34
#define _V8DBG_CLASS_SCRIPT__SOURCE_MAPPING_URL__OBJECT 0x38
#define _V8DBG_CLASS_DEBUGINFO__SHARED__SHAREDFUNCTIONINFO 0x4
#define _V8DBG_CLASS_DEBUGINFO__ORIGINAL_CODE__CODE 0x8
#define _V8DBG_CLASS_DEBUGINFO__CODE__CODE 0xc
#define _V8DBG_CLASS_DEBUGINFO__BREAK_POINTS__FIXEDARRAY 0x14
#define _V8DBG_CLASS_BREAKPOINTINFO__CODE_POSITION__SMI 0x4
#define _V8DBG_CLASS_BREAKPOINTINFO__SOURCE_POSITION__SMI 0x8
#define _V8DBG_CLASS_BREAKPOINTINFO__STATEMENT_POSITION__SMI 0xc
#define _V8DBG_CLASS_BREAKPOINTINFO__BREAK_POINT_OBJECTS__OBJECT 0x10
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__NAME__OBJECT 0x4
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__OPTIMIZED_CODE_MAP__OBJECT 0xc
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__CONSTRUCT_STUB__CODE 0x14
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__FEEDBACK_VECTOR__FIXEDARRAY 0x2c
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__INSTANCE_CLASS_NAME__OBJECT 0x18
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__FUNCTION_DATA__OBJECT 0x1c
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__SCRIPT__OBJECT 0x20
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__DEBUG_INFO__OBJECT 0x24
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__INFERRED_NAME__STRING 0x28
#define _V8DBG_CLASS_FUNCTIONTEMPLATEINFO__LENGTH__SMI 0x40
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__LENGTH__SMI 0x30
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__FORMAL_PARAMETER_COUNT__SMI 0x34
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__EXPECTED_NOF_PROPERTIES__SMI 0x38
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__NUM_LITERALS__SMI 0x3c
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__START_POSITION_AND_TYPE__SMI 0x40
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__END_POSITION__SMI 0x44
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__FUNCTION_TOKEN_POSITION__SMI 0x48
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__COMPILER_HINTS__SMI 0x4c
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__OPT_COUNT_AND_BAILOUT_REASON__SMI 0x50
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__COUNTERS__SMI 0x54
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__AST_NODE_COUNT__SMI 0x58
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__PROFILER_TICKS__SMI 0x5c
#define _V8DBG_CLASS_CODECACHE__DEFAULT_CACHE__FIXEDARRAY 0x4
#define _V8DBG_CLASS_CODECACHE__NORMAL_TYPE_CACHE__OBJECT 0x8
#define _V8DBG_CLASS_POLYMORPHICCODECACHE__CACHE__OBJECT 0x4
#define _V8DBG_CLASS_JSFUNCTION__PROTOTYPE_OR_INITIAL_MAP__OBJECT 0x10
#define _V8DBG_CLASS_JSPROXY__HANDLER__OBJECT 0x4
#define _V8DBG_CLASS_JSPROXY__HASH__OBJECT 0x8
#define _V8DBG_CLASS_JSFUNCTIONPROXY__CALL_TRAP__OBJECT 0xc
#define _V8DBG_CLASS_JSFUNCTIONPROXY__CONSTRUCT_TRAP__OBJECT 0x10
#define _V8DBG_CLASS_JSCOLLECTION__TABLE__OBJECT 0xc
#define _V8DBG_CLASS_JSWEAKCOLLECTION__TABLE__OBJECT 0xc
#define _V8DBG_CLASS_JSWEAKCOLLECTION__NEXT__OBJECT 0x10
#define _V8DBG_CLASS_JSGENERATOROBJECT__FUNCTION__JSFUNCTION 0xc
#define _V8DBG_CLASS_JSGENERATOROBJECT__CONTEXT__CONTEXT 0x10
#define _V8DBG_CLASS_JSGENERATOROBJECT__RECEIVER__OBJECT 0x14
#define _V8DBG_CLASS_JSGENERATOROBJECT__CONTINUATION__SMI 0x18
#define _V8DBG_CLASS_JSGENERATOROBJECT__OPERAND_STACK__FIXEDARRAY 0x1c
#define _V8DBG_CLASS_JSGENERATOROBJECT__STACK_HANDLER_INDEX__SMI 0x20
#define _V8DBG_CLASS_JSMODULE__CONTEXT__OBJECT 0xc
#define _V8DBG_CLASS_JSMODULE__SCOPE_INFO__SCOPEINFO 0x10
#define _V8DBG_CLASS_JSVALUE__VALUE__OBJECT 0xc
#define _V8DBG_CLASS_JSDATE__VALUE__OBJECT 0xc
#define _V8DBG_CLASS_JSDATE__CACHE_STAMP__OBJECT 0x2c
#define _V8DBG_CLASS_JSDATE__YEAR__OBJECT 0x10
#define _V8DBG_CLASS_JSDATE__MONTH__OBJECT 0x14
#define _V8DBG_CLASS_JSDATE__DAY__OBJECT 0x18
#define _V8DBG_CLASS_JSDATE__WEEKDAY__OBJECT 0x1c
#define _V8DBG_CLASS_JSDATE__HOUR__OBJECT 0x20
#define _V8DBG_CLASS_JSDATE__MIN__OBJECT 0x24
#define _V8DBG_CLASS_JSDATE__SEC__OBJECT 0x28
#define _V8DBG_CLASS_JSMESSAGEOBJECT__TYPE__STRING 0xc
#define _V8DBG_CLASS_JSMESSAGEOBJECT__ARGUMENTS__JSARRAY 0x10
#define _V8DBG_CLASS_JSMESSAGEOBJECT__SCRIPT__OBJECT 0x14
#define _V8DBG_CLASS_JSMESSAGEOBJECT__STACK_FRAMES__OBJECT 0x18
#define _V8DBG_CLASS_JSMESSAGEOBJECT__START_POSITION__SMI 0x1c
#define _V8DBG_CLASS_JSMESSAGEOBJECT__END_POSITION__SMI 0x20
#define _V8DBG_CLASS_CODE__RELOCATION_INFO__BYTEARRAY 0x8
#define _V8DBG_CLASS_CODE__HANDLER_TABLE__FIXEDARRAY 0xc
#define _V8DBG_CLASS_CODE__DEOPTIMIZATION_DATA__FIXEDARRAY 0x10
#define _V8DBG_CLASS_CODE__RAW_TYPE_FEEDBACK_INFO__OBJECT 0x14
#define _V8DBG_CLASS_CODE__NEXT_CODE_LINK__OBJECT 0x18
#define _V8DBG_CLASS_CODE__GC_METADATA__OBJECT 0x1c
#define _V8DBG_CLASS_JSARRAY__LENGTH__OBJECT 0xc
#define _V8DBG_CLASS_JSARRAYBUFFER__BYTE_LENGTH__OBJECT 0x10
#define _V8DBG_CLASS_JSARRAYBUFFER__FLAG__SMI 0x14
#define _V8DBG_CLASS_JSARRAYBUFFER__WEAK_NEXT__OBJECT 0x18
#define _V8DBG_CLASS_JSARRAYBUFFER__WEAK_FIRST_VIEW__OBJECT 0x1c
#define _V8DBG_CLASS_JSARRAYBUFFERVIEW__BUFFER__OBJECT 0xc
#define _V8DBG_CLASS_JSARRAYBUFFERVIEW__BYTE_OFFSET__OBJECT 0x10
#define _V8DBG_CLASS_JSARRAYBUFFERVIEW__BYTE_LENGTH__OBJECT 0x14
#define _V8DBG_CLASS_JSARRAYBUFFERVIEW__WEAK_NEXT__OBJECT 0x18
#define _V8DBG_CLASS_JSTYPEDARRAY__LENGTH__OBJECT 0x20
#define _V8DBG_CLASS_JSREGEXP__DATA__OBJECT 0xc
#define _V8DBG_CLASS_ALIASEDARGUMENTSENTRY__ALIASED_CONTEXT_SLOT__SMI 0x4
#define _V8DBG_CLASS_JSOBJECT__ELEMENTS__OBJECT 0x8
#define _V8DBG_CLASS_FIXEDARRAY__DATA__UINTPTR_T 0x8
#define _V8DBG_CLASS_MAP__INSTANCE_ATTRIBUTES__INT 0x8
#define _V8DBG_CLASS_MAP__INOBJECT_PROPERTIES__INT 0x5
#define _V8DBG_CLASS_MAP__INSTANCE_SIZE__INT 0x4
#define _V8DBG_CLASS_MAP__BIT_FIELD__CHAR 0x9
#define _V8DBG_CLASS_MAP__BIT_FIELD2__CHAR 0xa
#define _V8DBG_CLASS_MAP__BIT_FIELD3__INT 0xc
#define _V8DBG_CLASS_MAP__PROTOTYPE__OBJECT 0x10
#define _V8DBG_CLASS_NAMEDICTIONARYSHAPE__PREFIX_SIZE__INT 0x2
#define _V8DBG_CLASS_NAMEDICTIONARYSHAPE__ENTRY_SIZE__INT 0x3
#define _V8DBG_CLASS_SEEDEDNUMBERDICTIONARYSHAPE__PREFIX_SIZE__INT 0x2
#define _V8DBG_CLASS_NUMBERDICTIONARYSHAPE__ENTRY_SIZE__INT 0x3
#define _V8DBG_CLASS_ODDBALL__KIND_OFFSET__INT 0xc
#define _V8DBG_CLASS_HEAPNUMBER__VALUE__DOUBLE 0x4
#define _V8DBG_CLASS_CONSSTRING__FIRST__STRING 0xc
#define _V8DBG_CLASS_CONSSTRING__SECOND__STRING 0x10
#define _V8DBG_CLASS_EXTERNALSTRING__RESOURCE__OBJECT 0xc
#define _V8DBG_CLASS_SEQONEBYTESTRING__CHARS__CHAR 0xc
#define _V8DBG_CLASS_SEQTWOBYTESTRING__CHARS__CHAR 0xc
#define _V8DBG_CLASS_SHAREDFUNCTIONINFO__CODE__CODE 0x8
#define _V8DBG_CLASS_SLICEDSTRING__PARENT__STRING 0xc
#define _V8DBG_CLASS_CODE__INSTRUCTION_START__UINTPTR_T 0x40
#define _V8DBG_CLASS_CODE__INSTRUCTION_SIZE__INT 0x4
#define _V8DBG_STRINGTAG 0x0
#define _V8DBG_TWOBYTESTRINGTAG 0x0
#define _V8DBG_SEQSTRINGTAG 0x0
#define _V8DBG_SMITAG 0x0
#define _V8DBG_SMISHIFTSIZE 0x0
#define _V8DBG_ODDBALLFALSE 0x0
#define _V8DBG_PROP_DESC_KEY 0x0
#define _V8DBG_OFF_FP_CONSTANT_POOL 0x0
#define _V8DBG_PARENT_ACCESSCHECKINFO__STRUCT 0x0
#define _V8DBG_PARENT_ACCESSORINFO__STRUCT 0x0
#define _V8DBG_PARENT_ACCESSORPAIR__STRUCT 0x0
#define _V8DBG_PARENT_ALIASEDARGUMENTSENTRY__STRUCT 0x0
#define _V8DBG_PARENT_ALLOCATIONMEMENTO__STRUCT 0x0
#define _V8DBG_PARENT_ALLOCATIONSITE__STRUCT 0x0
#define _V8DBG_PARENT_BREAKPOINTINFO__STRUCT 0x0
#define _V8DBG_PARENT_BYTEARRAY__FIXEDARRAYBASE 0x0
#define _V8DBG_PARENT_CALLHANDLERINFO__STRUCT 0x0
#define _V8DBG_PARENT_CELL__HEAPOBJECT 0x0
#define _V8DBG_PARENT_CODE__HEAPOBJECT 0x0
#define _V8DBG_PARENT_CODECACHE__STRUCT 0x0
#define _V8DBG_PARENT_CONSSTRING__STRING 0x0
#define _V8DBG_PARENT_CONSTANTPOOLARRAY__HEAPOBJECT 0x0
#define _V8DBG_PARENT_DEBUGINFO__STRUCT 0x0
#define _V8DBG_PARENT_DECLAREDACCESSORDESCRIPTOR__STRUCT 0x0
#define _V8DBG_PARENT_DECLAREDACCESSORINFO__ACCESSORINFO 0x0
#define _V8DBG_PARENT_DEOPTIMIZATIONINPUTDATA__FIXEDARRAY 0x0
#define _V8DBG_PARENT_DEOPTIMIZATIONOUTPUTDATA__FIXEDARRAY 0x0
#define _V8DBG_PARENT_DEPENDENTCODE__FIXEDARRAY 0x0
#define _V8DBG_PARENT_DESCRIPTORARRAY__FIXEDARRAY 0x0
#define _V8DBG_PARENT_EXECUTABLEACCESSORINFO__ACCESSORINFO 0x0
#define _V8DBG_PARENT_EXTERNALARRAY__FIXEDARRAYBASE 0x0
#define _V8DBG_PARENT_EXTERNALASCIISTRING__EXTERNALSTRING 0x0
#define _V8DBG_PARENT_EXTERNALFLOAT32ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALFLOAT64ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALINT16ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALINT32ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALINT8ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALSTRING__STRING 0x0
#define _V8DBG_PARENT_EXTERNALTWOBYTESTRING__EXTERNALSTRING 0x0
#define _V8DBG_PARENT_EXTERNALUINT16ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALUINT32ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALUINT8ARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_EXTERNALUINT8CLAMPEDARRAY__EXTERNALARRAY 0x0
#define _V8DBG_PARENT_FIXEDARRAY__FIXEDARRAYBASE 0x0
#define _V8DBG_PARENT_FIXEDARRAYBASE__HEAPOBJECT 0x0
#define _V8DBG_PARENT_FIXEDDOUBLEARRAY__FIXEDARRAYBASE 0x0
#define _V8DBG_PARENT_FIXEDTYPEDARRAY__FIXEDTYPEDARRAYBASE 0x0
#define _V8DBG_PARENT_FIXEDTYPEDARRAYBASE__FIXEDARRAYBASE 0x0
#define _V8DBG_PARENT_FOREIGN__HEAPOBJECT 0x0
#define _V8DBG_PARENT_FREESPACE__HEAPOBJECT 0x0
#define _V8DBG_PARENT_FUNCTIONTEMPLATEINFO__TEMPLATEINFO 0x0
#define _V8DBG_PARENT_GLOBALOBJECT__JSOBJECT 0x0
#define _V8DBG_PARENT_HASHTABLE__FIXEDARRAY 0x0
#define _V8DBG_PARENT_HEAPNUMBER__HEAPOBJECT 0x0
#define _V8DBG_PARENT_HEAPOBJECT__OBJECT 0x0
#define _V8DBG_PARENT_INTERCEPTORINFO__STRUCT 0x0
#define _V8DBG_PARENT_JSARRAY__JSOBJECT 0x0
#define _V8DBG_PARENT_JSARRAYBUFFER__JSOBJECT 0x0
#define _V8DBG_PARENT_JSARRAYBUFFERVIEW__JSOBJECT 0x0
#define _V8DBG_PARENT_JSBUILTINSOBJECT__GLOBALOBJECT 0x0
#define _V8DBG_PARENT_JSDATAVIEW__JSARRAYBUFFERVIEW 0x0
#define _V8DBG_PARENT_JSDATE__JSOBJECT 0x0
#define _V8DBG_PARENT_JSFUNCTION__JSOBJECT 0x0
#define _V8DBG_PARENT_JSFUNCTIONPROXY__JSPROXY 0x0
#define _V8DBG_PARENT_JSFUNCTIONRESULTCACHE__FIXEDARRAY 0x0
#define _V8DBG_PARENT_JSGENERATOROBJECT__JSOBJECT 0x0
#define _V8DBG_PARENT_JSGLOBALOBJECT__GLOBALOBJECT 0x0
#define _V8DBG_PARENT_JSMESSAGEOBJECT__JSOBJECT 0x0
#define _V8DBG_PARENT_JSMODULE__JSOBJECT 0x0
#define _V8DBG_PARENT_JSOBJECT__JSRECEIVER 0x0
#define _V8DBG_PARENT_JSPROXY__JSRECEIVER 0x0
#define _V8DBG_PARENT_JSRECEIVER__HEAPOBJECT 0x0
#define _V8DBG_PARENT_JSREGEXP__JSOBJECT 0x0
#define _V8DBG_PARENT_JSREGEXPRESULT__JSARRAY 0x0
#define _V8DBG_PARENT_JSTYPEDARRAY__JSARRAYBUFFERVIEW 0x0
#define _V8DBG_PARENT_JSVALUE__JSOBJECT 0x0
#define _V8DBG_PARENT_JSWEAKCOLLECTION__JSOBJECT 0x0
#define _V8DBG_PARENT_JSWEAKMAP__JSWEAKCOLLECTION 0x0
#define _V8DBG_PARENT_JSWEAKSET__JSWEAKCOLLECTION 0x0
#define _V8DBG_PARENT_MAP__HEAPOBJECT 0x0
#define _V8DBG_PARENT_NAME__HEAPOBJECT 0x0
#define _V8DBG_PARENT_NORMALIZEDMAPCACHE__FIXEDARRAY 0x0
#define _V8DBG_PARENT_OBJECTTEMPLATEINFO__TEMPLATEINFO 0x0
#define _V8DBG_PARENT_ODDBALL__HEAPOBJECT 0x0
#define _V8DBG_PARENT_ORDEREDHASHTABLE__FIXEDARRAY 0x0
#define _V8DBG_PARENT_ORDEREDHASHTABLEITERATOR__JSOBJECT 0x0
#define _V8DBG_PARENT_POLYMORPHICCODECACHE__STRUCT 0x0
#define _V8DBG_PARENT_PROPERTYCELL__CELL 0x0
#define _V8DBG_PARENT_SCRIPT__STRUCT 0x0
#define _V8DBG_PARENT_SEQONEBYTESTRING__SEQSTRING 0x0
#define _V8DBG_PARENT_SEQSTRING__STRING 0x0
#define _V8DBG_PARENT_SEQTWOBYTESTRING__SEQSTRING 0x0
#define _V8DBG_PARENT_SHAREDFUNCTIONINFO__HEAPOBJECT 0x0
#define _V8DBG_PARENT_SIGNATUREINFO__STRUCT 0x0
#define _V8DBG_PARENT_SLICEDSTRING__STRING 0x0
#define _V8DBG_PARENT_SMI__OBJECT 0x0
#define _V8DBG_PARENT_STRING__NAME 0x0
#define _V8DBG_PARENT_STRUCT__HEAPOBJECT 0x0
#define _V8DBG_PARENT_SYMBOL__NAME 0x0
#define _V8DBG_PARENT_TEMPLATEINFO__STRUCT 0x0
#define _V8DBG_PARENT_TYPEFEEDBACKINFO__STRUCT 0x0
#define _V8DBG_PARENT_TYPESWITCHINFO__STRUCT 0x0
#define _V8DBG_CLASS_HEAPOBJECT__MAP__MAP 0x0
#define _V8DBG_CLASS_UNSEEDEDNUMBERDICTIONARYSHAPE__PREFIX_SIZE__INT 0x0


#endif /* V8_CONSTANTS_H */