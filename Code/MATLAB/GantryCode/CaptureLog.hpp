#ifndef _CAPTURE_LOG_HPP
#define _CAPTURE_LOG_HPP

#if defined(WIN32) || defined(_WIN32)

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#pragma warning(disable:4996)

#endif //WIN32 _WIN32

#include <stdarg.h>


#define LOG_FILE "capture.log"


bool xclibRestartLog ();
bool xclibAppendLog ( const char* message, ... );
bool xclibAppendLogConsole ( const char* message, ... );


#endif //_CAPTURE_LOG_HPP