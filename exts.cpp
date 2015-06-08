/*-----------------------------------------------------------------------------
   Copyright (c) 2000  Microsoft Corporation

Module:
  exts.cpp

  Sampe file showing couple of extension examples
  
  wzhao@microsoft.com added V8 Script Engine Debugging Feature
-----------------------------------------------------------------------------*/

#include "v8dbgexts.h"
#include <string.h>

extern "C" 
{
	extern int v8dbg_class_SeqOneByteString__chars__char = 12;
	extern int v8dbg_class_ExternalString__resource__Object = 12;
	extern int v8dbg_class_Map__bit_field3__SMI = 12;
	extern int v8dbg_parent_DebugInfo__Struct = 0;
	extern int v8dbg_type_ExternalUint16Array__EXTERNAL_UINT16_ARRAY_TYPE = 142;
	extern int v8dbg_parent_FixedArrayBase__HeapObject = 0;
	extern int v8dbg_type_InterceptorInfo__INTERCEPTOR_INFO_TYPE = 164;
	extern int v8dbg_type_DebugInfo__DEBUG_INFO_TYPE = 178;
	extern int v8dbg_class_Code__instruction_start__uintptr_t = 64;
	extern int v8dbg_type_SeqTwoByteString__STRING_TYPE = 64;
	extern int v8dbg_parent_NormalizedMapCache__FixedArray = 0;
	extern int v8dbg_parent_JSArrayBufferView__JSObject = 0;
	extern int v8dbg_type_FixedDoubleArray__FIXED_DOUBLE_ARRAY_TYPE = 157;
	extern int v8dbg_prop_index_shift = 19;
	extern int v8dbg_type_ExternalUint32Array__EXTERNAL_UINT32_ARRAY_TYPE = 144;
	extern int v8dbg_class_JSRegExp__data__Object = 12;
	extern int v8dbg_class_JSArrayBuffer__weak_first_view__Object = 28;
	extern int v8dbg_type_ExternalUint8ClampedArray__EXTERNAL_UINT8_CLAMPED_ARRAY_TYPE = 147;
	extern int v8dbg_parent_JSValue__JSObject = 0;
	extern int v8dbg_elements_fast_elements = 2;
	extern int v8dbg_parent_ExternalUint16Array__ExternalArray = 0;
	extern int v8dbg_HeapObjectTagMask = 3;
	extern int v8dbg_class_JSFunction__shared__SharedFunctionInfo = 20;
	extern int v8dbg_type_JSWeakMap__JS_WEAK_MAP_TYPE = 204;
	extern int v8dbg_parent_SlicedString__String = 0;
	extern int v8dbg_class_JSMessageObject__start_position__SMI = 28;
	extern int v8dbg_parent_DependentCode__FixedArray = 0;
	extern int v8dbg_class_SharedFunctionInfo__feedback_vector__TypeFeedbackVector = 44;
	extern int v8dbg_class_SharedFunctionInfo__end_position__SMI = 68;
	extern int v8dbg_class_SeqTwoByteString__chars__char = 12;
	extern int v8dbg_parent_TemplateInfo__Struct = 0;
	extern int v8dbg_parent_OrderedHashTableIterator__JSObject = 0;
	extern int v8dbg_StringTag = 0;
	extern int v8dbg_off_fp_constant_pool = 0;
	extern int v8dbg_class_CodeCache__default_cache__FixedArray = 4;
	extern int v8dbg_class_SharedFunctionInfo__function_data__Object = 28;
	extern int v8dbg_class_SeededNumberDictionaryShape__prefix_size__int = 2;
	extern int v8dbg_class_FunctionTemplateInfo__access_check_info__Object = 56;
	extern int v8dbg_class_JSMessageObject__script__Object = 20;
	extern int v8dbg_class_JSDate__min__Object = 36;
	extern int v8dbg_class_JSModule__context__Object = 12;
	extern int v8dbg_class_CallHandlerInfo__callback__Object = 4;
	extern int v8dbg_class_AccessCheckInfo__indexed_callback__Object = 8;
	extern int v8dbg_NotStringTag = 128;
	extern int v8dbg_off_fp_function = -8;
	extern int v8dbg_class_JSArray__length__Object = 12;
	extern int v8dbg_class_GlobalObject__native_context__Context = 16;
	extern int v8dbg_parent_SeqOneByteString__SeqString = 0;
	extern int v8dbg_prop_index_mask = 536346624;
	extern int v8dbg_class_JSFunctionProxy__call_trap__Object = 12;
	extern int v8dbg_class_Code__handler_table__FixedArray = 8;
	extern int v8dbg_type_ConstantPoolArray__CONSTANT_POOL_ARRAY_TYPE = 181;
	extern int v8dbg_type_JSArrayBuffer__JS_ARRAY_BUFFER_TYPE = 197;
	extern int v8dbg_parent_HashTable__FixedArray = 0;
	extern int v8dbg_type_AccessorPair__ACCESSOR_PAIR_TYPE = 162;
	extern int v8dbg_class_SharedFunctionInfo__expected_nof_properties__SMI = 56;
	extern int v8dbg_class_DeclaredAccessorInfo__descriptor__DeclaredAccessorDescriptor = 16;
	extern int v8dbg_class_AccessorInfo__flag__SMI = 8;
	extern int v8dbg_class_Symbol__name__Object = 8;
	extern int v8dbg_class_JSFunctionProxy__construct_trap__Object = 16;
	extern int v8dbg_parent_JSFunctionResultCache__FixedArray = 0;
	extern int v8dbg_parent_DeclaredAccessorDescriptor__Struct = 0;
	extern int v8dbg_class_SharedFunctionInfo__name__Object = 4;
	extern int v8dbg_type_HeapNumber__HEAP_NUMBER_TYPE = 134;
	extern int v8dbg_parent_JSTypedArray__JSArrayBufferView = 0;
	extern int v8dbg_class_JSDate__year__Object = 16;
	extern int v8dbg_class_JSArrayBuffer__weak_next__Object = 24;
	extern int v8dbg_class_Map__constructor__Object = 20;
	extern int v8dbg_parent_ExternalUint32Array__ExternalArray = 0;
	extern int v8dbg_frametype_ArgumentsAdaptorFrame = 10;
	extern int v8dbg_parent_CodeCache__Struct = 0;
	extern int v8dbg_type_ConsString__CONS_ONE_BYTE_STRING_TYPE = 69;
	extern int v8dbg_type_ExternalString__EXTERNAL_ONE_BYTE_STRING_TYPE = 70;
	extern int v8dbg_class_JSGeneratorObject__function__JSFunction = 12;
	extern int v8dbg_OddballException = 8;
	extern int v8dbg_class_HeapNumber__value__double = 4;
	extern int v8dbg_parent_ExternalFloat32Array__ExternalArray = 0;
	extern int v8dbg_type_JSModule__JS_MODULE_TYPE = 192;
	extern int v8dbg_type_CodeCache__CODE_CACHE_TYPE = 173;
	extern int v8dbg_class_Code__deoptimization_data__FixedArray = 12;
	extern int v8dbg_parent_JSDate__JSObject = 0;
	extern int v8dbg_type_Cell__CELL_TYPE = 132;
	extern int v8dbg_class_JSArrayBufferView__byte_length__Object = 20;
	extern int v8dbg_class_DebugInfo__shared__SharedFunctionInfo = 4;
	extern int v8dbg_class_JSWeakCollection__table__Object = 12;
	extern int v8dbg_frametype_ConstructFrame = 9;
	extern int v8dbg_type_JSFunction__JS_FUNCTION_TYPE = 207;
	extern int v8dbg_class_BreakPointInfo__break_point_objects__Object = 16;
	extern int v8dbg_parent_String__Name = 0;
	extern int v8dbg_class_FunctionTemplateInfo__indexed_property_handler__Object = 36;
	extern int v8dbg_type_ExternalInt8Array__EXTERNAL_INT8_ARRAY_TYPE = 139;
	extern int v8dbg_parent_JSFunctionProxy__JSProxy = 0;
	extern int v8dbg_type_Code__CODE_TYPE = 130;
	extern int v8dbg_class_Script__context_data__Object = 20;
	extern int v8dbg_class_SharedFunctionInfo__optimized_code_map__Object = 12;
	extern int v8dbg_off_fp_marker = -8;
	extern int v8dbg_class_SharedFunctionInfo__debug_info__Object = 36;
	extern int v8dbg_parent_ObjectTemplateInfo__TemplateInfo = 0;
	extern int v8dbg_class_Code__next_code_link__Object = 20;
	extern int v8dbg_parent_ExternalInt32Array__ExternalArray = 0;
	extern int v8dbg_class_DeclaredAccessorDescriptor__serialized_data__ByteArray = 4;
	extern int v8dbg_class_AllocationSite__transition_info__Object = 4;
	extern int v8dbg_bit_field3_dictionary_map_shift = 20;
	extern int v8dbg_class_Script__eval_from_shared__Object = 40;
	extern int v8dbg_class_PolymorphicCodeCache__cache__Object = 4;
	extern int v8dbg_class_Map__instance_size__int = 4;
	extern int v8dbg_prop_type_field = 1;
	extern int v8dbg_parent_FixedTypedArrayBase__FixedArrayBase = 0;
	extern int v8dbg_parent_CallHandlerInfo__Struct = 0;
	extern int v8dbg_class_SharedFunctionInfo__ast_node_count__SMI = 88;
	extern int v8dbg_parent_ExternalFloat64Array__ExternalArray = 0;
	extern int v8dbg_parent_JSWeakCollection__JSObject = 0;
	extern int v8dbg_type_JSDate__JS_DATE_TYPE = 188;
	extern int v8dbg_class_InterceptorInfo__query__Object = 12;
	extern int v8dbg_class_SharedFunctionInfo__function_token_position__SMI = 72;
	extern int v8dbg_class_SignatureInfo__receiver__Object = 4;
	extern int v8dbg_parent_SeqString__String = 0;
	extern int v8dbg_parent_FixedArray__FixedArrayBase = 0;
	extern int v8dbg_class_JSObject__properties__FixedArray = 4;
	extern int v8dbg_class_FunctionTemplateInfo__flag__SMI = 60;
	extern int v8dbg_class_AccessorPair__setter__Object = 8;
	extern int v8dbg_parent_Smi__Object = 0;
	extern int v8dbg_parent_PolymorphicCodeCache__Struct = 0;
	extern int v8dbg_class_Oddball__kind_offset__int = 12;
	extern int v8dbg_type_ExecutableAccessorInfo__EXECUTABLE_ACCESSOR_INFO_TYPE = 161;
	extern int v8dbg_class_SharedFunctionInfo__num_literals__SMI = 60;
	extern int v8dbg_parent_JSArrayBuffer__JSObject = 0;
	extern int v8dbg_parent_ExternalTwoByteString__ExternalString = 0;
	extern int v8dbg_class_FunctionTemplateInfo__signature__Object = 48;
	extern int v8dbg_parent_ExecutableAccessorInfo__AccessorInfo = 0;
	extern int v8dbg_parent_Cell__HeapObject = 0;
	extern int v8dbg_class_Script__type__SMI = 28;
	extern int v8dbg_class_String__length__SMI = 8;
	extern int v8dbg_class_BreakPointInfo__source_position__SMI = 8;
	extern int v8dbg_OddballFalse = 0;
	extern int v8dbg_parent_JSReceiver__HeapObject = 0;
	extern int v8dbg_class_NameDictionaryShape__prefix_size__int = 2;
	extern int v8dbg_parent_JSModule__JSObject = 0;
	extern int v8dbg_ConsStringTag = 1;
	extern int v8dbg_parent_JSObject__JSReceiver = 0;
	extern int v8dbg_type_DeclaredAccessorDescriptor__DECLARED_ACCESSOR_DESCRIPTOR_TYPE = 159;
	extern int v8dbg_parent_JSWeakMap__JSWeakCollection = 0;
	extern int v8dbg_parent_DeoptimizationInputData__FixedArray = 0;
	extern int v8dbg_parent_AllocationMemento__Struct = 0;
	extern int v8dbg_parent_ExternalArray__FixedArrayBase = 0;
	extern int v8dbg_class_AllocationSite__nested_site__Object = 8;
	extern int v8dbg_class_ObjectTemplateInfo__constructor__Object = 16;
	extern int v8dbg_class_Script__column_offset__SMI = 16;
	extern int v8dbg_type_ByteArray__BYTE_ARRAY_TYPE = 137;
	extern int v8dbg_type_FunctionTemplateInfo__FUNCTION_TEMPLATE_INFO_TYPE = 166;
	extern int v8dbg_class_JSProxy__hash__Object = 8;
	extern int v8dbg_class_Script__source_url__Object = 52;
	extern int v8dbg_type_JSTypedArray__JS_TYPED_ARRAY_TYPE = 198;
	extern int v8dbg_type_JSGeneratorObject__JS_GENERATOR_OBJECT_TYPE = 191;
	extern int v8dbg_SmiTagMask = 1;
	extern int v8dbg_SmiTag = 0;
	extern int v8dbg_parent_FunctionTemplateInfo__TemplateInfo = 0;
	extern int v8dbg_class_SharedFunctionInfo__formal_parameter_count__SMI = 52;
	extern int v8dbg_class_FunctionTemplateInfo__parent_template__Object = 28;
	extern int v8dbg_HeapObjectTag = 1;
	extern int v8dbg_class_GlobalObject__global_proxy__JSObject = 24;
	extern int v8dbg_type_JSRegExp__JS_REGEXP_TYPE = 206;
	extern int v8dbg_parent_DeclaredAccessorInfo__AccessorInfo = 0;
	extern int v8dbg_OddballUninitialized = 6;
	extern int v8dbg_IsNotStringMask = 128;
	extern int v8dbg_type_ConsString__CONS_STRING_TYPE = 65;
	extern int v8dbg_class_AccessorInfo__expected_receiver_type__Object = 12;
	extern int v8dbg_class_Map__inobject_properties__int = 5;
	extern int v8dbg_class_JSDate__cache_stamp__Object = 44;
	extern int v8dbg_class_Script__flags__SMI = 48;
	extern int v8dbg_class_Map__instance_descriptors__DescriptorArray = 28;
	extern int v8dbg_parent_JSProxy__JSReceiver = 0;
	extern int v8dbg_class_Script__id__Smi = 36;
	extern int v8dbg_parent_ExternalUint8ClampedArray__ExternalArray = 0;
	extern int v8dbg_class_Map__code_cache__Object = 32;
	extern int v8dbg_class_JSArrayBuffer__flag__SMI = 20;
	extern int v8dbg_class_Map__dependent_code__DependentCode = 36;
	extern int v8dbg_type_JSBuiltinsObject__JS_BUILTINS_OBJECT_TYPE = 194;
	extern int v8dbg_type_FixedArray__FIXED_ARRAY_TYPE = 180;
	extern int v8dbg_class_FreeSpace__size__SMI = 4;
	extern int v8dbg_class_AccessorPair__getter__Object = 4;
	extern int v8dbg_type_SignatureInfo__SIGNATURE_INFO_TYPE = 168;
	extern int v8dbg_class_SharedFunctionInfo__inferred_name__String = 40;
	extern int v8dbg_TwoByteStringTag = 0;
	extern int v8dbg_frametype_ExitFrame = 3;
	extern int v8dbg_class_AccessCheckInfo__data__Object = 12;
	extern int v8dbg_class_ObjectTemplateInfo__internal_field_count__Object = 20;
	extern int v8dbg_parent_JSGlobalObject__GlobalObject = 0;
	extern int v8dbg_class_JSFunction__prototype_or_initial_map__Object = 16;
	extern int v8dbg_class_CallHandlerInfo__data__Object = 8;
	extern int v8dbg_parent_JSArray__JSObject = 0;
	extern int v8dbg_class_FunctionTemplateInfo__instance_template__Object = 40;
	extern int v8dbg_class_SlicedString__offset__SMI = 16;
	extern int v8dbg_class_Script__source__Object = 4;
	extern int v8dbg_class_Script__source_mapping_url__Object = 56;
	extern int v8dbg_class_JSDate__value__Object = 12;
	extern int v8dbg_class_SharedFunctionInfo__start_position_and_type__SMI = 64;
	extern int v8dbg_parent_JSMessageObject__JSObject = 0;
	extern int v8dbg_class_Code__raw_type_feedback_info__Object = 16;
	extern int v8dbg_OddballArgumentMarker = 4;
	extern int v8dbg_type_JSGlobalObject__JS_GLOBAL_OBJECT_TYPE = 193;
	extern int v8dbg_class_FunctionTemplateInfo__prototype_template__Object = 24;
	extern int v8dbg_type_ExternalTwoByteString__EXTERNAL_STRING_TYPE = 66;
	extern int v8dbg_prop_desc_value = 2;
	extern int v8dbg_class_SignatureInfo__args__Object = 8;
	extern int v8dbg_parent_ExternalInt16Array__ExternalArray = 0;
	extern int v8dbg_class_JSCollection__table__Object = 12;
	extern int v8dbg_StringRepresentationMask = 3;
	extern int v8dbg_class_SharedFunctionInfo__compiler_hints__SMI = 76;
	extern int v8dbg_class_JSObject__elements__Object = 8;
	extern int v8dbg_class_SharedFunctionInfo__length__SMI = 48;
	extern int v8dbg_class_NameDictionaryShape__entry_size__int = 3;
	extern int v8dbg_parent_PropertyCell__Cell = 0;
	extern int v8dbg_class_JSValue__value__Object = 12;
	extern int v8dbg_class_JSDate__month__Object = 20;
	extern int v8dbg_class_AllocationSite__dependent_code__DependentCode = 20;
	extern int v8dbg_class_ConsString__first__String = 12;
	extern int v8dbg_class_JSFunction__literals_or_bindings__FixedArray = 28;
	extern int v8dbg_class_Map__bit_field__char = 9;
	extern int v8dbg_class_JSArrayBufferView__weak_next__Object = 24;
	extern int v8dbg_parent_SharedFunctionInfo__HeapObject = 0;
	extern int v8dbg_parent_Name__HeapObject = 0;
	extern int v8dbg_class_ConsString__second__String = 16;
	extern int v8dbg_parent_ByteArray__FixedArrayBase = 0;
	extern int v8dbg_class_GlobalObject__builtins__JSBuiltinsObject = 12;
	extern int v8dbg_class_SharedFunctionInfo__script__Object = 32;
	extern int v8dbg_prop_desc_details = 1;
	extern int v8dbg_parent_Struct__HeapObject = 0;
	extern int v8dbg_class_InterceptorInfo__getter__Object = 4;
	extern int v8dbg_type_AllocationSite__ALLOCATION_SITE_TYPE = 170;
	extern int v8dbg_class_SharedFunctionInfo__instance_class_name__Object = 24;
	extern int v8dbg_parent_DescriptorArray__FixedArray = 0;
	extern int v8dbg_class_Map__bit_field2__char = 10;
	extern int v8dbg_SeqStringTag = 0;
	extern int v8dbg_class_JSGeneratorObject__stack_handler_index__SMI = 32;
	extern int v8dbg_frametype_StubFailureTrampolineFrame = 7;
	extern int v8dbg_class_AccessorInfo__name__Object = 4;
	extern int v8dbg_class_JSArrayBufferView__byte_offset__Object = 16;
	extern int v8dbg_parent_JSFunction__JSObject = 0;
	extern int v8dbg_class_JSArrayBuffer__byte_length__Object = 16;
	extern int v8dbg_class_HeapObject__map__Map = 0;
	extern int v8dbg_parent_ConsString__String = 0;
	extern int v8dbg_parent_JSGeneratorObject__JSObject = 0;
	extern int v8dbg_class_Box__value__Object = 4;
	extern int v8dbg_OddballTrue = 1;
	extern int v8dbg_class_SharedFunctionInfo__construct_stub__Code = 20;
	extern int v8dbg_type_ExternalFloat64Array__EXTERNAL_FLOAT64_ARRAY_TYPE = 146;
	extern int v8dbg_type_PolymorphicCodeCache__POLYMORPHIC_CODE_CACHE_TYPE = 174;
	extern int v8dbg_type_SeqOneByteString__ONE_BYTE_STRING_TYPE = 68;
	extern int v8dbg_parent_AliasedArgumentsEntry__Struct = 0;
	extern int v8dbg_class_AllocationSite__pretenure_data__SMI = 12;
	extern int v8dbg_type_AccessCheckInfo__ACCESS_CHECK_INFO_TYPE = 163;
	extern int v8dbg_frametype_InternalFrame = 8;
	extern int v8dbg_frametype_OptimizedFrame = 5;
	extern int v8dbg_class_JSProxy__handler__Object = 4;
	extern int v8dbg_prop_type_mask = 3;
	extern int v8dbg_type_JSFunctionProxy__JS_FUNCTION_PROXY_TYPE = 184;
	extern int v8dbg_parent_SeqTwoByteString__SeqString = 0;
	extern int v8dbg_class_NumberDictionaryShape__entry_size__int = 3;
	extern int v8dbg_class_Oddball__to_string__String = 4;
	extern int v8dbg_parent_Foreign__HeapObject = 0;
	extern int v8dbg_OddballTheHole = 2;
	extern int v8dbg_type_Script__SCRIPT_TYPE = 172;
	extern int v8dbg_parent_ConstantPoolArray__HeapObject = 0;
	extern int v8dbg_class_JSGeneratorObject__continuation__SMI = 24;
	extern int v8dbg_class_JSMessageObject__stack_frames__Object = 24;
	extern int v8dbg_class_Map__instance_attributes__int = 8;
	extern int v8dbg_parent_DeoptimizationOutputData__FixedArray = 0;
	extern int v8dbg_type_ExternalFloat32Array__EXTERNAL_FLOAT32_ARRAY_TYPE = 145;
	extern int v8dbg_class_SlicedString__parent__String = 12;
	extern int v8dbg_class_JSGeneratorObject__operand_stack__FixedArray = 28;
	extern int v8dbg_class_JSGeneratorObject__receiver__Object = 20;
	extern int v8dbg_OddballNull = 3;
	extern int v8dbg_type_ExternalInt32Array__EXTERNAL_INT32_ARRAY_TYPE = 143;
	extern int v8dbg_class_JSDate__hour__Object = 32;
	extern int v8dbg_prop_idx_first = 2;
	extern int v8dbg_class_FixedArray__data__uintptr_t = 8;
	extern int v8dbg_type_FreeSpace__FREE_SPACE_TYPE = 138;
	extern int v8dbg_class_Script__name__Object = 8;
	extern int v8dbg_class_Script__eval_from_instructions_offset__SMI = 44;
	extern int v8dbg_class_FunctionTemplateInfo__named_property_handler__Object = 32;
	extern int v8dbg_parent_AccessorPair__Struct = 0;
	extern int v8dbg_class_JSWeakCollection__next__Object = 16;
	extern int v8dbg_class_JSDate__day__Object = 24;
	extern int v8dbg_type_AliasedArgumentsEntry__ALIASED_ARGUMENTS_ENTRY_TYPE = 176;
	extern int v8dbg_class_FunctionTemplateInfo__serial_number__Object = 16;
	extern int v8dbg_type_SlicedString__SLICED_ONE_BYTE_STRING_TYPE = 71;
	extern int v8dbg_class_CodeCache__normal_type_cache__Object = 8;
	extern int v8dbg_class_Code__instruction_size__int = 28;
	extern int v8dbg_SlicedStringTag = 3;
	extern int v8dbg_frametype_EntryFrame = 1;
	extern int v8dbg_parent_JSDataView__JSArrayBufferView = 0;
	extern int v8dbg_class_PropertyCell__dependent_code__DependentCode = 12;
	extern int v8dbg_class_JSMessageObject__arguments__JSArray = 16;
	extern int v8dbg_class_TemplateInfo__property_list__Object = 8;
	extern int v8dbg_frametype_JavaScriptFrame = 4;
	extern int v8dbg_class_Script__line_offset__SMI = 12;
	extern int v8dbg_type_Foreign__FOREIGN_TYPE = 136;
	extern int v8dbg_class_Script__line_ends__Object = 32;
	extern int v8dbg_class_JSArrayBufferView__buffer__Object = 12;
	extern int v8dbg_class_Symbol__flags__Smi = 12;
	extern int v8dbg_type_Oddball__ODDBALL_TYPE = 131;
	extern int v8dbg_type_DeclaredAccessorInfo__DECLARED_ACCESSOR_INFO_TYPE = 160;
	extern int v8dbg_class_DebugInfo__break_points__FixedArray = 20;
	extern int v8dbg_class_FunctionTemplateInfo__class_name__Object = 44;
	extern int v8dbg_type_TypeSwitchInfo__TYPE_SWITCH_INFO_TYPE = 169;
	extern int v8dbg_parent_AccessorInfo__Struct = 0;
	extern int v8dbg_class_UnseededNumberDictionaryShape__prefix_size__int = 0;
	extern int v8dbg_class_JSGeneratorObject__context__Context = 16;
	extern int v8dbg_class_InterceptorInfo__setter__Object = 8;
	extern int v8dbg_ExternalStringTag = 2;
	extern int v8dbg_parent_OrderedHashTable__FixedArray = 0;
	extern int v8dbg_parent_Oddball__HeapObject = 0;
	extern int v8dbg_class_JSDate__sec__Object = 40;
	extern int v8dbg_type_JSProxy__JS_PROXY_TYPE = 185;
	extern int v8dbg_class_BreakPointInfo__statement_position__SMI = 12;
	extern int v8dbg_type_ExternalInt16Array__EXTERNAL_INT16_ARRAY_TYPE = 141;
	extern int v8dbg_class_BreakPointInfo__code_position__SMI = 4;
	extern int v8dbg_parent_BreakPointInfo__Struct = 0;
	extern int v8dbg_class_JSDate__weekday__Object = 28;
	extern int v8dbg_parent_TypeFeedbackInfo__Struct = 0;
	extern int v8dbg_type_CallHandlerInfo__CALL_HANDLER_INFO_TYPE = 165;
	extern int v8dbg_type_ExternalUint8Array__EXTERNAL_UINT8_ARRAY_TYPE = 140;
	extern int v8dbg_parent_GlobalObject__JSObject = 0;
	extern int v8dbg_class_GlobalObject__global_context__Context = 20;
	extern int v8dbg_prop_desc_size = 3;
	extern int v8dbg_class_TemplateInfo__property_accessors__Object = 12;
	extern int v8dbg_parent_ExternalString__String = 0;
	extern int v8dbg_OneByteStringTag = 4;
	extern int v8dbg_class_JSMessageObject__end_position__SMI = 32;
	extern int v8dbg_OddballOther = 7;
	extern int v8dbg_parent_Symbol__Name = 0;
	extern int v8dbg_elements_dictionary_elements = 6;
	extern int v8dbg_parent_JSBuiltinsObject__GlobalObject = 0;
	extern int v8dbg_class_SharedFunctionInfo__code__Code = 8;
	extern int v8dbg_class_ExecutableAccessorInfo__data__Object = 24;
	extern int v8dbg_class_AllocationSite__weak_next__Object = 24;
	extern int v8dbg_off_fp_args = 8;
	extern int v8dbg_type_JSWeakSet__JS_WEAK_SET_TYPE = 205;
	extern int v8dbg_SmiValueShift = 1;
	extern int v8dbg_class_SharedFunctionInfo__profiler_ticks__SMI = 92;
	extern int v8dbg_parent_Code__HeapObject = 0;
	extern int v8dbg_class_Map__prototype__Object = 16;
	extern int v8dbg_parent_FreeSpace__HeapObject = 0;
	extern int v8dbg_type_PropertyCell__PROPERTY_CELL_TYPE = 133;
	extern int v8dbg_parent_AccessCheckInfo__Struct = 0;
	extern int v8dbg_type_TypeFeedbackInfo__TYPE_FEEDBACK_INFO_TYPE = 175;
	extern int v8dbg_class_ExecutableAccessorInfo__setter__Object = 20;
	extern int v8dbg_parent_HeapNumber__HeapObject = 0;
	extern int v8dbg_class_SharedFunctionInfo__counters__SMI = 84;
	extern int v8dbg_class_AliasedArgumentsEntry__aliased_context_slot__SMI = 4;
	extern int v8dbg_parent_JSRegExpResult__JSArray = 0;
	extern int v8dbg_type_AllocationMemento__ALLOCATION_MEMENTO_TYPE = 171;
	extern int v8dbg_class_ExecutableAccessorInfo__getter__Object = 16;
	extern int v8dbg_parent_ExternalInt8Array__ExternalArray = 0;
	extern int v8dbg_type_SharedFunctionInfo__SHARED_FUNCTION_INFO_TYPE = 182;
	extern int v8dbg_type_BreakPointInfo__BREAK_POINT_INFO_TYPE = 179;
	extern int v8dbg_type_JSMessageObject__JS_MESSAGE_OBJECT_TYPE = 187;
	extern int v8dbg_class_JSGlobalProxy__hash__Object = 16;
	extern int v8dbg_elements_fast_holey_elements = 3;
	extern int v8dbg_parent_Script__Struct = 0;
	extern int v8dbg_class_FunctionTemplateInfo__call_code__Object = 20;
	extern int v8dbg_class_DebugInfo__original_code__Code = 8;
	extern int v8dbg_class_FixedArrayBase__length__SMI = 4;
	extern int v8dbg_type_ObjectTemplateInfo__OBJECT_TEMPLATE_INFO_TYPE = 167;
	extern int v8dbg_class_Code__gc_metadata__Object = 24;
	extern int v8dbg_class_JSModule__scope_info__ScopeInfo = 16;
	extern int v8dbg_class_JSMessageObject__type__String = 12;
	extern int v8dbg_parent_HeapObject__Object = 0;
	extern int v8dbg_class_AccessCheckInfo__named_callback__Object = 4;
	extern int v8dbg_FirstNonstringType = 128;
	extern int v8dbg_class_InterceptorInfo__deleter__Object = 16;
	extern int v8dbg_frametype_StubFrame = 6;
	extern int v8dbg_parent_FixedTypedArray__FixedTypedArrayBase = 0;
	extern int v8dbg_class_InterceptorInfo__enumerator__Object = 20;
	extern int v8dbg_type_SeqTwoByteString__SYMBOL_TYPE = 128;
	extern int v8dbg_type_JSDataView__JS_DATA_VIEW_TYPE = 199;
	extern int v8dbg_class_Script__wrapper__HeapObject = 24;
	extern int v8dbg_class_JSGlobalProxy__native_context__Object = 12;
	extern int v8dbg_class_TemplateInfo__tag__Object = 4;
	extern int v8dbg_class_AllocationSite__pretenure_create_count__SMI = 16;
	extern int v8dbg_StringEncodingMask = 4;
	extern int v8dbg_class_FunctionTemplateInfo__instance_call_handler__Object = 52;
	extern int v8dbg_parent_TypeSwitchInfo__Struct = 0;
	extern int v8dbg_parent_Map__HeapObject = 0;
	extern int v8dbg_prop_desc_key = 0;
	extern int v8dbg_type_Map__MAP_TYPE = 129;
	extern int v8dbg_parent_AllocationSite__Struct = 0;
	extern int v8dbg_class_SharedFunctionInfo__opt_count_and_bailout_reason__SMI = 80;
	extern int v8dbg_type_JSValue__JS_VALUE_TYPE = 186;
	extern int v8dbg_class_JSTypedArray__length__Object = 32;
	extern int v8dbg_class_Oddball__to_number__Object = 8;
	extern int v8dbg_class_InterceptorInfo__data__Object = 24;
	extern int v8dbg_parent_SignatureInfo__Struct = 0;
	extern int v8dbg_parent_JSRegExp__JSObject = 0;
	extern int v8dbg_type_SlicedString__SLICED_STRING_TYPE = 67;
	extern int v8dbg_parent_FixedDoubleArray__FixedArrayBase = 0;
	extern int v8dbg_off_fp_context = -4;
	extern int v8dbg_class_AllocationMemento__allocation_site__Object = 4;
	extern int v8dbg_parent_JSWeakSet__JSWeakCollection = 0;
	extern int v8dbg_parent_ExternalUint8Array__ExternalArray = 0;
	extern int v8dbg_class_TypeSwitchInfo__types__Object = 4;
	extern int v8dbg_class_FunctionTemplateInfo__length__SMI = 64;
	extern int v8dbg_class_Code__relocation_info__ByteArray = 4;
	extern int v8dbg_frametype_EntryConstructFrame = 2;
	extern int v8dbg_class_JSFunction__next_function_link__Object = 32;
	extern int v8dbg_SmiShiftSize = 0;
	extern int v8dbg_parent_InterceptorInfo__Struct = 0;
	extern int v8dbg_PointerSizeLog2 = 2;
	extern int v8dbg_type_JSObject__JS_OBJECT_TYPE = 189;
	extern int v8dbg_class_DebugInfo__code__Code = 12;
	extern int v8dbg_OddballUndefined = 5;
	extern int v8dbg_type_JSArray__JS_ARRAY_TYPE = 196;

}


//clear the last twi bits of V8 object PTR
#define DEV8PTR(ptr)  ((INT64)ptr & 0xfffffffc)

/*
* Determine the encoding and representation of a V8 string.
*/
#define	V8_TYPE_STRING(type)	(((type) & v8dbg_IsNotStringMask) == v8dbg_StringTag)

//is ASCII string
#define	V8_STRENC_ASCII(type)	(((type) & v8dbg_StringEncodingMask) == v8dbg_OneByteStringTag)

//is Two-Byte string
#define	V8_STRENC_TWOBYTE(type)	(((type) & v8dbg_StringEncodingMask) == v8dbg_TwoByteStringTag)


//isSMI
#define	V8_IS_SMI(ptr)		(((ptr) & v8dbg_SmiTagMask) == v8dbg_SmiTag)

#define	V8_SMI_VALUE(value)		((UINT32)((value) >> v8dbg_SmiValueShift))


//Sequence String
#define	V8_STRREP_SEQ(type)	(((type) & v8dbg_StringRepresentationMask) == v8dbg_SeqStringTag)

//Concat String
#define	V8_STRREP_CONS(type) (((type) & v8dbg_StringRepresentationMask) == v8dbg_ConsStringTag)

//Sliced String 
#define	V8_STRREP_SLICED(type) (((type) & v8dbg_StringRepresentationMask) == v8dbg_SlicedStringTag)

//External String
#define	V8_STRREP_EXT(type)	(((type) & v8dbg_StringRepresentationMask) == v8dbg_ExternalStringTag)

//Script Object
#define	V8_TYPE_SCRIPT(type)	(type == v8dbg_type_Script__SCRIPT_TYPE)



//int main(int argc, char* argv[]) {
//
//	getch();
//	PV(v8dbg_class_Code__instruction_size__int);
//	PV(v8dbg_frametype_JavaScriptFrame);
//	return 0;
//}













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
	int i = 0;
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

int ReadByte(UINT8 *typeByte, ULONG_PTR addr)
{
	ULONG cb = 0;

	//get the instance attributes at addr + v8dbg_class_Map__instance_attributes__int  == addr + 0x8
	if (ReadMemory(addr + v8dbg_class_Map__instance_attributes__int, typeByte, sizeof(*typeByte), &cb) && cb == sizeof(*typeByte))
	{
		DBG_OUT("Type byte for object %p ", addr);
		DBG_OUT("is %d\n", *typeByte);
	}
	else
	{
		return -1;
	}

	return 0;
}

int GetTypeByte(UINT8* typeByte, ULONG_PTR addr)
{
	ULONG_PTR mapObj;
	ULONG cb = 0;

	//get the map at addr + v8dbg_class_HeapObject__map__Map == addr + 0x0
	if (ReadMemory(addr + v8dbg_class_HeapObject__map__Map, &mapObj, sizeof(mapObj), &cb) && cb == sizeof(mapObj))
	{
		DBG_OUT("Map for object %p ", addr);
		DBG_OUT("at % p\n", DEV8PTR(mapObj));

		if (ReadByte(typeByte, DEV8PTR(mapObj)) != 0)
		{
			dprintf("Failed to read type byte at %p\n", mapObj);
			return -1;
		}
	}
	else 
	{
		DBG_OUT("Failed to read Map for Object %p\n", addr);
		return -1;
	}


	return 0;
}

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

		DBG_OUT("SMI is %d", smi);

		*valp = smi;
	}
	else
	{
		dprintf("Failed to read SMI @ %p\n", addr);
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



/* return value:
0: empty string
-1: failed to read string content
1: good
*/
int PrintSeqStringObject(ULONG_PTR strObj, UINT8 objType)
{

	ULONG len = 0;
	ULONG offset = 0;
	ULONG cb = 0;

	char buffer[256];

	//For SeqString v8dbg_class_String__length__SMI is 8, but actually, it is 4.
	read_heap_smi(&len, strObj + 4);
	//dprintf("length = %x\n", len);

	if (len == 0)
	{
		DBG_OUT("Length of String %p is 0x0", strObj);
		return 0;
	}
	
	DBG_OUT("ObjType == %d", objType);
	DBG_OUT("v8dbg_StringEncodingMask == %d", v8dbg_StringEncodingMask); 
	DBG_OUT("ObjType&v8dbg_StringEncodingMask == %d", objType&v8dbg_StringEncodingMask);

	if ( V8_STRENC_ASCII(objType) )
	{
		len = len / 2;
		DBG_OUT("two bytes string, length is %d", len);
	}

	DBG_OUT("string object %p ", strObj);
	DBG_OUT("length is %d", len);

	offset = V8_STRENC_ASCII(objType) ? v8dbg_class_SeqOneByteString__chars__char : v8dbg_class_SeqTwoByteString__chars__char;

	//For ASCII string the first char is started at strObj + v8dbg_class_SeqOneByteString__chars__char
	//For two bytes string the first char is started at strObj + v8dbg_class_SeqTwoByteString__chars__char
	if (ReadMemory(strObj + offset, buffer, len, &cb) && cb == len)
	{
		buffer[len] = '\0';
		dprintf("%s", buffer);
	}
	else
	{
		dprintf("%s %p+%p\n", "failed to read string content function at: ", strObj, offset);
		return -1;
	}

	return 1;
}


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

	//First part of Cons stirng v8dbg_class_ConsString__first__String
	if (! (ReadMemory(strObj + v8dbg_class_ConsString__first__String, &part1, sizeof(part1), &cb) && cb == sizeof(part1)) )
	{
		DBG_OUT("Failed to read first part of Cons String %p\n", strObj);
		return -1;
	}
	DBG_OUT("First part of Cons String %p ", strObj);
	DBG_OUT("is  %p\n", part1);
	
	//Second part of Cons string v8dbg_class_ConsString__second__String
	if (! (ReadMemory(strObj + v8dbg_class_ConsString__second__String, &part2, sizeof(part2), &cb) && cb == sizeof(part2)) )
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

char* Read_heap_string(ULONG_PTR strObj);

char* ReadConsStringObject(ULONG_PTR strObj, UINT8 objType)
{
	ULONG_PTR part1;
	ULONG_PTR part2;
	ULONG cb = 0;
	char* strPart1;
	char* strPart2;
	char* buf;
	int len;

	//First part of Cons stirng v8dbg_class_ConsString__first__String
	if (!(ReadMemory(strObj + v8dbg_class_ConsString__first__String, &part1, sizeof(part1), &cb) && cb == sizeof(part1)))
	{
		DBG_OUT_LN("ReadConsStringObject -- Failed to read first part of Cons String %p\n", strObj);
		return NULL;
	}
	DBG_OUT("ReadConsStringObject -- First part of Cons String %p ", strObj);
	DBG_OUT_LN("is  %p", part1);

	//Second part of Cons string v8dbg_class_ConsString__second__String
	if (!(ReadMemory(strObj + v8dbg_class_ConsString__second__String, &part2, sizeof(part2), &cb) && cb == sizeof(part2)))
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

	//For SeqString v8dbg_class_String__length__SMI is 8, but actually, it is 4.
	read_heap_smi(&len, strObj + 4);
	//dprintf("length = %x\n", len);

	if (len == 0)
	{
		DBG_OUT_LN("ReadSeqStringObject -- Length of String %p is 0x0", strObj);
		return NULL;
	}

	DBG_OUT_LN("ReadSeqStringObject -- ObjType == %d", objType);
	DBG_OUT_LN("ReadSeqStringObject -- v8dbg_StringEncodingMask == %d", v8dbg_StringEncodingMask);
	DBG_OUT_LN("ReadSeqStringObject -- ObjType&v8dbg_StringEncodingMask == %d", objType&v8dbg_StringEncodingMask);

	len = V8_SMI_VALUE(len);

	DBG_OUT_LN("ReadSeqStringObject -- length is %d", len);

	offset = V8_STRENC_ASCII(objType) ? v8dbg_class_SeqOneByteString__chars__char : v8dbg_class_SeqTwoByteString__chars__char;

	//For ASCII string the first char is started at strObj + v8dbg_class_SeqOneByteString__chars__char
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



	//offset = V8_STRENC_ASCII(objType) ? v8dbg_class_SeqOneByteString__chars__char : v8dbg_class_SeqTwoByteString__chars__char;

	////For ASCII string the first char is started at strObj + v8dbg_class_SeqOneByteString__chars__char
	////For two bytes string the first char is started at strObj + v8dbg_class_SeqTwoByteString__chars__char
	//if (ReadMemory(strObj + offset, funcName, len, &cb) && cb == len)
	//{
	//	funcName[len] = '\0';
	//	dprintf("%s\n", funcName);
	//}
	//else
	//{
	//	dprintf("%s %p+%p\n", "failed to read string content function at: ", strObj, v8dbg_class_SeqOneByteString__chars__char);
	//	return -1;
	//}

	return 1;
}


void PrintJSFunctionName(ULONG_PTR jsSharedFunction)
{
	//ULONG_PTR jsFun;
	ULONG_PTR jsFuncName;
	ULONG_PTR jsInferNamed;
	ULONG cb = 0;
	UINT8 typeByte = 0;

	//SharedFunction+v8dbg_class_SharedFunctionInfo__name__Object = SharedFunction+0x4, Read Name of SharedFunctionInfo
	if (ReadMemory(jsSharedFunction + v8dbg_class_SharedFunctionInfo__name__Object, &jsFuncName, sizeof(jsFuncName), &cb) && cb == sizeof(jsFuncName))
	{
		DBG_OUT("FuntionName @ %p\n", DEV8PTR(jsFuncName));
		
		if (!isStringObject(DEV8PTR(jsFuncName)))
		{
			return;
		}
		

		//empty function name, maybe an anounymous, try inferred name
		if (PrintStringObject(DEV8PTR(jsFuncName)) == 0)
		{
			//SharedFunction+v8dbg_class_SharedFunctionInfo__inferred_name__String = SharedFunction+0n40, Read Inferred of SharedFunctionInfo
			if (ReadMemory(jsSharedFunction + v8dbg_class_SharedFunctionInfo__inferred_name__String, &jsInferNamed, sizeof(jsInferNamed), &cb) && cb == sizeof(jsInferNamed))
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
		dprintf("%s %p\n", "Failed to Read JavaScript Function Name at: ", jsSharedFunction + v8dbg_off_fp_function);
	}

}


void PrintJSScriptFileName(ULONG_PTR jsSharedFunction)
{
	
	
	//v8dbg_class_SharedFunctionInfo__function_token_position__SMI
	//v8dbg_class_SharedFunctionInfo__script__Object

	//v8dbg_class_Script__name__Object = 0n8
	//v8dbg_type_Script__SCRIPT_TYPE = 0n172

	ULONG_PTR jsScriptFile;
	ULONG cb = 0;
	UINT8 objType = 0;
	ULONG_PTR JSScriptFileName;

	//SharedFunction+v8dbg_class_SharedFunctionInfo__script__Object = SharedFunction+0x4, Read the Script Object
	if (ReadMemory(jsSharedFunction + v8dbg_class_SharedFunctionInfo__script__Object, &jsScriptFile, sizeof(jsScriptFile), &cb) && cb == sizeof(jsScriptFile))
	{
		DBG_OUT("Script Object @ %p", DEV8PTR(jsScriptFile));

		if (GetTypeByte(&objType, DEV8PTR(jsScriptFile)) != 0) {
			DBG_OUT("Failed to Read Type Byte for Script Object @ %p", DEV8PTR(jsScriptFile));
			return;
		}

		DBG_OUT("type is %d", objType);
		/*if (!V8_TYPE_SCRIPT(objType))
		{
			DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
			return;
		}*/
	}
	else
	{
		DBG_OUT("Failed to read Script Object @ %p", jsSharedFunction + v8dbg_class_SharedFunctionInfo__script__Object);
		return;
	}


	//v8dbg_class_Script__name__Object == the name of script file
	if (ReadMemory(DEV8PTR(jsScriptFile) + v8dbg_class_Script__name__Object, &JSScriptFileName, sizeof(JSScriptFileName), &cb) && cb == sizeof(JSScriptFileName))
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



void PrintLineNo(ULONG_PTR jsSharedFunction)
{
	ULONG_PTR jsScriptFile;
	ULONG_PTR jsScriptSource;
	
	ULONG_PTR tokenPos;

	ULONG cb = 0;
	UINT8 objType = 0;
	
	ULONG64 lineNo = 0;
	char* buf;

	//Read the Token Position, the offset is 0n80 instead of 0n72.
	//SharedFunction+v8dbg_class_SharedFunctionInfo__function_token_position__SMI = the Script Object
	if (ReadMemory(jsSharedFunction + 80, &tokenPos, sizeof(tokenPos), &cb) && cb == sizeof(tokenPos))
	{
		DBG_OUT("PrintLineNo -- Token_position of Shared Function %p ", jsSharedFunction);
		DBG_OUT_LN("is %d", tokenPos);

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

	}
	else
	{
		DBG_OUT_LN("PrintLineNo -- Failed to read token position of Shared Function @ %p", jsSharedFunction);
		return;
	}


	//SharedFunction+v8dbg_class_SharedFunctionInfo__script__Object = SharedFunction+0x4, Read the Script Object
	if (ReadMemory(jsSharedFunction + v8dbg_class_SharedFunctionInfo__script__Object, &jsScriptFile, sizeof(jsScriptFile), &cb) && cb == sizeof(jsScriptFile))
	{
		DBG_OUT("Script Object @ %p", DEV8PTR(jsScriptFile));

		if (GetTypeByte(&objType, DEV8PTR(jsScriptFile)) != 0) {
			DBG_OUT("Failed to Read Type Byte for Script Object @ %p", DEV8PTR(jsScriptFile));
			return;
		}

		DBG_OUT("type is %d", objType);
		/*if (!V8_TYPE_SCRIPT(objType))
		{
		DBG_OUT("object @ %p is not a script object\n", DEV8PTR(jsScriptFile));
		return;
		}*/
	}
	else
	{
		DBG_OUT_LN("Failed to read Script Object @ %p", jsSharedFunction + v8dbg_class_SharedFunctionInfo__script__Object);
		return;
	}


	//debug_support!v8dbg_class_Script__source__Object == 0n4 == the source of script file
	if (ReadMemory(DEV8PTR(jsScriptFile) + v8dbg_class_Script__source__Object, &jsScriptSource, sizeof(jsScriptSource), &cb) && cb == sizeof(jsScriptSource))
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

	//framePoint + v8dbg_off_fp_function == EBP - 8, read the JavaScript Functino(JSFunction)
	if (ReadMemory(framePoint + v8dbg_off_fp_function, &jsFun, sizeof(jsFun), &cb) && cb == sizeof(jsFun))
	{
		DBG_OUT("JSFunction @ %p\n", DEV8PTR(jsFun));

		if (GetTypeByte(&typeByte, DEV8PTR(jsFun)) != 0)
		{
			DBG_OUT("Failed to Read Type Byte for Java Script Function Object %p", DEV8PTR(jsFun));
			dprintf("??\n");
			return;
		}

		//DBG_OUT("Java Script Function Object Type is %d\n", typeByte);
		
		//JSFunction+v8dbg_off_fp_function == JSFunction+0n20, read the SharedFunctionInfo Object
		if (ReadMemory(DEV8PTR(jsFun) + v8dbg_class_JSFunction__shared__SharedFunctionInfo, &sharedFuncInfo, sizeof(sharedFuncInfo), &cb) && cb == sizeof(sharedFuncInfo))
		{
			DBG_OUT("SharedFuncInfo @ %p\n", DEV8PTR(sharedFuncInfo));
		}
		else
		{
			DBG_OUT("Failed to Read SharedFuncInfo at: %p", DEV8PTR(jsFun) + v8dbg_class_JSFunction__shared__SharedFunctionInfo);
			dprintf("??\n");
			return;
		}

		PrintJSFunctionName(DEV8PTR(sharedFuncInfo));

	}
	else
	{
		DBG_OUT("Failed to Read JavaScript Function at: %P", framePoint + v8dbg_off_fp_function);
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
// Extension to dump stacktrace
//
DECLARE_API(dumpJsObj)
{

	dprintf("dump a JSObject\n");
}





//
// Extension to display V8 version
//
DECLARE_API(v8ver)
{
	CHAR buffer[MAX_PATH];
	ULONG64 v8Ver = NULL;
	ULONG64 v8VerStr = NULL;
	IDebugClient *DebugClient;

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
            "  help                   - Shows this help\n"
			"  stack          - Dump Call Stacks with JavaScript stack\n"
			"  dumpJsObj          - dump a JSObject\n"
			"  v8ver                  - Get V8 Version\n"
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