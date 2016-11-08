#define _CRT_SECURE_NO_DEPRECATE

#include "CaptureLog.hpp"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;


bool xclibRestartLog () {
	FILE* file = fopen ( LOG_FILE, "w" );
	if ( !file ){
		fprintf (
			stderr,
			"ERROR: could't open LOG_FILE log file %s for writing\n",
			LOG_FILE
			);
		return false;
	} 

	time_t tnow = time ( NULL );
	char* tdate = ctime ( &tnow );
	fprintf ( file, "XCLIB Capture log. local time %s\n", tdate );
	fclose ( file );

	return true;
}

bool xclibAppendLog ( const char* message, ... ){
	va_list argptr;

	FILE* file = fopen ( LOG_FILE, "a" );
	if ( !file ){
		fprintf (
			stderr,
			"ERROR: could't open LOG_FILE log file %s for appending\n",
			LOG_FILE
			);
		return false;
	}

	va_start ( argptr, message );
	vfprintf ( file, message, argptr );
	va_end ( argptr );
	fclose ( file );

	return true;
}

bool xclibAppendLogConsole ( const char* message, ... ){
	va_list argptr;

	FILE* file = fopen ( LOG_FILE, "a" );
	if ( !file ){
		fprintf (
			stderr,
			"ERROR: could't open LOG_FILE log file %s for appending\n",
			LOG_FILE
			);
		return false;
	}

	// Print to File
	va_start ( argptr, message );
	vfprintf ( file, message, argptr );
	va_end ( argptr );
	// Print to Terminal
	va_start ( argptr, message );
	vfprintf ( stderr, message, argptr );
	va_end ( argptr );

	fclose ( file );

	return true;
}