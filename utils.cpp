//#pragma once
//#ifndef _UTILS_H_
//	#define _UTILS_H_
//#endif
//#include <wdbgexts.h>
//#pragma region LOGGING
//
//#define FUN_INFO() dprintf("%s:%d", __func__, __LINE__);
//
//
//void dprintmessage(char * format, va_list args)
//{
//	char debug_message[255];
//	vsprintf_s(debug_message + 10, 245, format, args);
//	OutputDebugStringA(debug_message);
//	if (IsDebuggerPresent())
//	{
//		OutputDebugStringA("\n");
//	}
//
//	return;
//}
//
//void dprintverbose(char * format, ...)
//{
//	va_list args;
//	va_start(args, format);
//	dprintmessage(format, args);
//	va_end(args);
//}
//
//void dprintwarning(char * format, ...)
//{
//	va_list args;
//	va_start(args, format);
//	dprintmessage(format, args);
//	va_end(args);
//}
//
//void DBG_LOGGING(char * format, ...)
//{
//	va_list args;
//	va_start(args, format);
//	dprintmessage(format, args);
//	va_end(args);
//}
//
//#pragma endregion
