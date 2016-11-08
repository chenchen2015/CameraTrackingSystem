/*
*
*	XCLIB Console FrameGrabber v1
*
*	Chen Chen, MacIver Lab
*	03-09-2015
*
*	Example program for the XCLIB 'CPP' Library.
*	Example works and tested in Windows 7 SP1 x64
*
*	Frame Grabber: PIXCI(R) E8
*	Can be used with other PIXCI(R) frame grabbers,
*	altho some controls may be meaningless.
*
*
*/


/*
*  INSTRUCTIONS:
*
*  1)	Set 'define' options below according to the intended camera
*	and video format.
*
*	For PIXCI(R) E8 frame grabbers
*   use "default" to select the default format for the camera
*	for which the PIXCI(R) frame grabber is intended.
*
*	For non default formats, use XCAP to save the video set-up to a
*	file, and set FORMAT to the saved file's name.
*	For camera's with RS-232 control, note that the saved
*	video set-up only resets the PIXCI(R) frame grabber's
*	settings, but XCLIB does not reset the camera's settings.
*
*	Alternately, this could be modified to use getenv("PIXCI"),
*	GetPrivateProfileString(...), RegQueryValueEx(...), or any
*	other convention chosen by the programmer to allow run time
*	selection of the video format and resolution.
*
*/

#define _CRT_SECURE_NO_WARNINGS		1
#define _CRT_SECURE_NO_DEPRECATE	1

#if !defined(FORMAT) && !defined(FORMATFILE)

/*
	Choose ONLY one option from below
	This will specify the intended initial configuration
	for each of the frame grabber boards

	Code Intended for PIXCI(R) E8

	Chen Chen
	Apr. 13, 2015
*/

// Option #1: Keep everything default
//#define FORMAT  "default"	  // as per board's intended camera

// Option #2: Load custom configuration file
// Hint: Need to use XCAP software to export intended settings into *.fmt file
//		 and put that file under the same folder with the frame grabber program
#define FORMATFILE   "MaxAOI_100FPS.fmt"  // .. loaded from file during execution

#endif


/*
*  2.1) Set number of expected PIXCI(R) image boards.
*  The XCLIB Simple 'C' Functions expect that the boards are
*  identical and operated at the same resolution.
*
*  For PIXCI(R) frame grabbers with multiple, functional units,
*  the XCLIB presents the two halves of the
*  PIXCI(R) E1DB, E4DB, E8CAM, E8DB, e104x4-2f, ECB2, EL1DB, ELS2, SI2, or SV7 frame grabbers,
*  or the three parts of the PIXCI(R) e104x4-f2b frame grabber,
*  or the four quarters of the PIXCI(R) e104x4-4b or SI4 frame grabbers,
*  as two, three, or four independent PIXCI(R) frame grabbers, respectively.
*
*/
#define UNIT0BITMASK	1	// Camera #1
#define UNIT1BITMASK	2	// Camera #2
#define UNIT2BITMASK	4	// Camera #3
#define UNIT3BITMASK	8	// Camera #4

#if !defined(UNITS)
#define UNITS	3
#endif
//#define UNITSMAP    ((1<<UNITS)-1)  /* shorthand - bitmap of all units */
#define UNITSMAP    ( UNIT0BITMASK | UNIT1BITMASK | UNIT2BITMASK )  /* shorthand - bitmap of all units */
#if !defined(UNITSOPENMAP)
#define UNITSOPENMAP UNITSMAP
#endif


/*
*  2.2) Optionally, set driver configuration parameters.
*  These are normally left to the default, "".
*  The actual driver configuration parameters include the
*  desired PIXCI(R) frame grabbers, but to make configuation easier,
*  code, below, will automatically add board selection to this.
*
*  Note: Under Windows, the image frame buffer memory can't be set as
*  a run time option. It MUST be set via SYSTEM.INI for Win 95/98,
*  or via the Registry for Win NT, so the memory can be reserved
*  during Window's initialization.
*/
#if !defined(DRIVERPARMS)
//#define DRIVERPARMS "-QU 0"     // don't use interrupts
//#define DRIVERPARMS "-IM 8192"  // request 8192 mbyte of frame buffer memory
#define DRIVERPARMS ""	    // default
#endif


/*
*  3)	Choose whether the PXIPL Image Processing Library
*	is available, with which images can be displayed on the S/VGA.
*	(Image display on S/VGA is available under Windows with or
*	without the PXIPL library, but not shown in this command-line
*	oriented example).
*/
#if !defined(USE_PXIPL)
#define USE_PXIPL	1
#endif

/*
*  4) Select directory for saving of images.
*  This example will never overwrite existing images files;
*  so directory selection is not critical.
*/
#if !defined(IMAGEFILE_DIR)
#define IMAGEFILE_DIR    "."
#endif

/*
*  5) Run without prompts?
*/
#if !defined(USER_PROMPTS)
#define USER_PROMPTS   1
#endif


/*
*  NECESSARY INCLUDES:
*/

#include <stdio.h>		// c library
#include <signal.h>		// c library
#include <stdlib.h>		// c library
#include <stdarg.h>		// c library
#include <string.h>		// c library
#include <algorithm>
#include <string>
#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#include <windows.h>
#endif
#if USE_PXIPL
extern "C" {
	#include "pxipl.h"
}
#include "pxextras.h"           
#endif
#include "xcliball.h"		// function prototypes

#include "ConFG_v2.hpp"
#include "CaptureLog.hpp"
#include "timeCount.hpp"
#include "PXIPLfun.hpp"


#define LOG_LINE_SEG 	{xclibAppendLogConsole ( "------------------------------------------------------------------------------------\n" );}


/*
*  SUPPORT STUFF:
*
*  Slow down execution speed so
*  each step/function can be observed.
*/
void user (char *mesg)
{
	if ( mesg && *mesg )
		printf ("%s\n", mesg);
#if USER_PROMPTS
	fprintf (stderr, "\n\nContinue (Key ENTER) ?");
	while ( _fgetchar () != '\n' );
#endif
	fprintf (stderr, "\n");
}


/*
* Open the XCLIB C Library for use.
*/
int do_open (void)
{
	int r;

	LOG_LINE_SEG;

	xclibAppendLogConsole ( "Opening EPIX(R) PIXCI(R) Frame Grabber,\n" );
	xclibAppendLogConsole ( "using configuration parameters '%s',\n", DRIVERPARMS ? DRIVERPARMS : "default" );

	//
	// Either FORMAT or FORMATFILE should have been
	// selected above.
	//
#if defined(FORMAT)
	printf ("and using predefined format '%s'.\n\n", FORMAT);
	r = pxd_PIXCIopen (DRIVERPARMS, FORMAT, "");
#endif
#if defined(FORMATFILE)
	xclibAppendLogConsole ( "and using format file '%s'.\n\n", FORMATFILE );
	r = pxd_PIXCIopen (DRIVERPARMS, "", FORMATFILE);
#endif
	if ( r >= 0 ) {
		//
		// For the sake of demonstrating optional interrupt hooks.
		//
#if !(defined(_WIN32) || defined(__WIN32__) || defined(_WIN64))
		pxd_eventCapturedFieldCreate (1, irqfunction, NULL);
#endif

		user ("Open OK");
	}
	else {
		xclibAppendLogConsole ( "Open Error %d\a\a\n", r );
		pxd_mesgFault (UNITSMAP);
		user ("");
	}
	return( r );
}

/*
* Report image frame buffer memory size
*/
void do_imsize (void)
{
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Image and Basic Video Information\n" );
#if 1
	xclibAppendLogConsole ( "Image frame buffer memory size: %.3f Kbytes\n", ( double ) pxd_infoMemsize ( UNITSMAP ) / 1024 );
#elif defined(OS_WIN64)|defined(OS_WIN64_DLL)
	printf ("Image frame buffer memory size: %I64u Kbytes\n", pxd_infoMemsize (UNITSMAP) / 1024);
#else
	printf ("Image frame buffer memory size: %lu Kbytes\n", pxd_infoMemsize (UNITSMAP) / 1024);
#endif
	xclibAppendLogConsole ( "Image frame buffers           : %d\n", pxd_imageZdim () );
	xclibAppendLogConsole ( "Number of boards              : %d\n", pxd_infoUnits () );
	user ("");
}

/*
* Report image resolution.
*/
void do_vidsize (void)
{
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Image resolution:\n" );
	xclibAppendLogConsole ( "xdim           = %d\n", pxd_imageXdim () );
	xclibAppendLogConsole ( "ydim           = %d\n", pxd_imageYdim () );
	xclibAppendLogConsole ( "colors         = %d\n", pxd_imageCdim () );
	xclibAppendLogConsole ( "bits per pixel = %d\n", pxd_imageCdim ()*pxd_imageBdim () );
	LOG_LINE_SEG;
	user ( "" );
}



/*
* Be nice and careful: For sake of this example which uses a
* file name not selected by the user, and which might already exist,
* don't overwrite the file if it already exists.
* This check for a pre-existant file is the only reason
* that fopen() need be done; this section of code
* isn't a requirement for saving images.
*/
int checkexist (char *name)
{
	FILE    *fp;
	if ( ( fp = fopen (name, "rb") ) != NULL ) {
		fclose (fp);
		xclibAppendLogConsole ( "Image not saved, file %s already exists\n", name );
		user ("");
		return( 1 );
	}
	return( 0 );
}

/*
* Close the PIXCI(R) frame grabber
*/
void do_close (void)
{
	pxd_PIXCIclose ();
	user ("PIXCI(R) frame grabber closed");
}


void hello (void)
{
	xclibRestartLog (); // Restart XCLIB Log file

	printf ("\n\n");
	printf ("PIXCI(R) Frame Grabber v3 - Based on XCLIB 'C' Library\n");
	printf ("\n");
	user ("");
}

// Specifies file type
enum FileType{
	JPEG,
	BMP,
	TIFF
};

inline int savebmp ( UINT seq, pxbuffer_t buff = 1 )
{
	int     u, err = 0;
	char name[] = IMAGEFILE_DIR "/Imgs/" "Unit#_Seq$$$$.bmp";
	char seqChar[] = "0000.bmp";

	for ( u = 0; u < UNITS; u++ ) {
		name[11] = '0' + u;  // Units #
		sprintf ( seqChar, "%04d.bmp", seq );
		strcpy ( &name[16], seqChar ); // Sequence $

		//
		// Don't overwrite existing file.
		//
		//if ( checkexist ( name ) )	return -23;

		//
		// Do save of entire image to disk in Bitmap format.
		// Monochrome image buffers are saved as an 8 bit monochrome image,
		// color image buffers are saved as an 24 bit RGB color image.
		//
		// int pxd_saveBmp(unitmap, pathname, framebuf, ulx, uly, lrx, lry, savemode, options);
		err = pxd_saveBmp (
			1 << u,		// Unit selection bit map (1 for single unit)
			name,		// File path name to load from, or save to
			buff,		// Image frame buffer
			0,			// Upper left x coord. of area of interest
			0,			// Upper left y coord. of area of interest
			-1,			// Lower right x coord. exclusive of AOI
			-1,			// Lower right y coord. exclusive of AOI
			0,			// Reserved, should be 0
			0			// Reserved, should be 0
			);
		if ( err < 0 ){
			return err;
		}
	}
	return 0;
}

inline int savetiff ( UINT seq, pxbuffer_t buff = 1 )
{
	int     u, err = 0;
	char name[] = IMAGEFILE_DIR "/Imgs/" "Unit#_Seq$$$$.tiff";
	char seqChar[] = "0000.tiff";

	for ( u = 0; u < UNITS; u++ ) {
		name[11] = '0' + u;  // Units #
		sprintf ( seqChar, "%04d.tiff", seq );
		strcpy ( &name[16], seqChar ); // Sequence $

		//pxImg a;

		if ( err < 0 ){
			return -24;
		}

		//
		// Don't overwrite existing file.
		//
		//if ( checkexist ( name ) )	return -23;

		//
		// Do save of entire image to disk in Bitmap format.
		// Monochrome image buffers are saved as an 8 bit monochrome image,
		// color image buffers are saved as an 24 bit RGB color image.
		//
		// int pxd_saveTiff(unitmap, pathname, framebuf, ulx, uly, lrx, lry, savemode, options);
		err = pxd_saveTiff ( 
			1 << u,		// Unit selection bit map (1 for single unit)
			name,		// File path name to load from, or save to
			buff,		// Image frame buffer
			0,			// Upper left x coord. of area of interest
			0,			// Upper left y coord. of area of interest
			-1,			// Lower right x coord. exclusive of AOI
			-1,			// Lower right y coord. exclusive of AOI
			0,			// Reserved, should be 0
			0			// Reserved, should be 0
			);
		if ( err < 0 ){
			return err;
		}
	}
	return 0;
}

inline int savejpeg ( UINT seq, pxbuffer_t buff = 1 )
{
#if USE_PXIPL
	int	u, err = 0;
	char name[] = IMAGEFILE_DIR "/Imgs/" "Unit#_Seq$$$$.jpg";
	char seqChar[] = "0000.jpg";
	int xdim, ydim;

	for ( u = 0; u < UNITS; u++ ) {
		name[11] = '0' + u;  // Units #
		sprintf ( seqChar, "%04d.jpg", seq );
		strcpy ( &name[16], seqChar ); // Sequence $
		//
		// Don't overwrite existing file.
		//
		if ( checkexist ( name ) )	return -23;

		//
		// Do save of entire image to disk in JPEG format.
		//
		//xclibAppendLog ( "Unit %d Image %d being saved to file %s\n", u, seq, name );

		err = pxio8_jpegwrite (
			NULL,	// Premature termination function, or NULL
			pxd_defineImage (
				1 << u,	// Unit selection bit map (1 for single unit)
				buff,	// Image frame buffer
				0,		// Upper left x coord. of area of interest
				0,		// Upper left y coord. of area of interest
				-1,		// Lower right x coord. exclusive of AOI
				-1,		// Lower right y coord. exclusive of AOI
				"RGB"	// Name of requested color representation
			),	// Image & AOI to save
			NULL,	// Reserved, must be NULL
			name,	// File path name
			8,		// Bits per pixie to save. Must be 8
			NULL );	// Additional parms, or NULL for default

		if ( err < 0 ){
			return err;
		}
	}
	return 0;
#endif
}


#define PXD_DOSNAP_ERR	-1
#define PXD_SAVEJPEG_ERR -2
#define SAVEJPEG_FILE_EXIST -23
int CaptureLoopLive ( UINT numFrames, FileType fileType ){
	int err = 0;

	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Capturing Frames ...\n" );

	err = pxd_goLive (
		UNITSMAP,	// unitmap: Unit selection bit map (1 for single unit)
		1			// buffer: Image frame buffer
		);
	if ( err < 0 ){
		xclibAppendLogConsole ( "pxd_goLive error: %s\n", pxd_mesgErrorCode ( err ) );
		return PXD_DOSNAP_ERR;
	}


	for ( UINT i = 1; i <= numFrames; i++ ){
		//xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		switch ( fileType ){
		case FileType::BMP:
			err = savebmp ( i );
			break;
		case FileType::TIFF:
			err = savetiff ( i );
			break;
		case FileType::JPEG:
			err = savejpeg ( i );
			break;
		}
		if ( err < 0 ){
			xclibAppendLogConsole ( "Error while attempting to save JPEG file:\t" );
			switch ( err ){
			case PXERROR:
				xclibAppendLogConsole ( "Invalid parameters!!\n" );
				break;
			case PXERMALLOC:
				xclibAppendLogConsole ( "Memory allocation error!!\n" );
				break;
			case PXERNODATA:
				xclibAppendLogConsole ( "Pixel data type is not supported!!\n" );
				break;
			case PXERNOCOLOR:
				xclibAppendLogConsole ( "Pixel color is not supported!!\n" );
				break;
			case PXERNEWFILE:
				xclibAppendLogConsole ( "File can't be created!!\n" );
				break;
			case PXERDOSIO:
				xclibAppendLogConsole ( "DOS/Windows I/O write error!!\n" );
				break;
			case PXERBREAK:
				xclibAppendLogConsole ( "Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested)!!\n" );
				break;
			case SAVEJPEG_FILE_EXIST:
				xclibAppendLogConsole ( "File already exist!!\n" );
				break;
			default:
				xclibAppendLogConsole ( "pxio8_jpegwrite: %s\n", pxd_mesgErrorCode ( err ) );
				break;
			}
			return PXD_SAVEJPEG_ERR;
		}
	}
	//pxd_goUnLive ( UNITSMAP );
	return 0;
}

int CaptureLoopLivePair ( UINT numFrames, FileType fileType ){
	int err = 0;
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );

	err = pxd_goLivePair (
		UNITSMAP,	// unitmap: Unit selection bit map (1 for single unit)
		1,			// buffer1: Image frame buffer 1
		2			// buffer2: Image frame buffer 2
		);
	if ( err < 0 ){
		xclibAppendLogConsole ( "pxd_goLive error: %s\n", pxd_mesgErrorCode ( err ) );
		return PXD_DOSNAP_ERR;
	}

	for ( UINT i = 1; i <= numFrames; i++ ){
		//xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		switch ( fileType ){
		case FileType::BMP:
			err = savebmp ( i );
			break;
		case FileType::TIFF:
			err = savetiff ( i );
			break;
		case FileType::JPEG:
			err = savejpeg ( i );
			break;
		}
		if ( err < 0 ){
			xclibAppendLogConsole ( "Error while attempting to save JPEG file:\t" );
			switch ( err ){
			case PXERROR:
				xclibAppendLogConsole ( "Invalid parameters!!\n" );
				break;
			case PXERMALLOC:
				xclibAppendLogConsole ( "Memory allocation error!!\n" );
				break;
			case PXERNODATA:
				xclibAppendLogConsole ( "Pixel data type is not supported!!\n" );
				break;
			case PXERNOCOLOR:
				xclibAppendLogConsole ( "Pixel color is not supported!!\n" );
				break;
			case PXERNEWFILE:
				xclibAppendLogConsole ( "File can't be created!!\n" );
				break;
			case PXERDOSIO:
				xclibAppendLogConsole ( "DOS/Windows I/O write error!!\n" );
				break;
			case PXERBREAK:
				xclibAppendLogConsole ( "Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested)!!\n" );
				break;
			case SAVEJPEG_FILE_EXIST:
				xclibAppendLogConsole ( "File already exist!!\n" );
				break;
			default:
				xclibAppendLogConsole ( "pxio8_jpegwrite: %s\n", pxd_mesgErrorCode ( err ) );
				break;
			}
			return PXD_SAVEJPEG_ERR;
		}
	}
	pxd_goUnLive ( UNITSMAP );
	return 0;
}

int CaptureLoopLiveSeq ( UINT numFrames, FileType fileType ){
	int err = 0;
	UINT startBuf, endBuf, incBuf;
	unsigned long strField, endField;
	TimeT tBegin, tEnd;

	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );

	startBuf = 1;
	incBuf = 1;
	endBuf = startBuf + numFrames * incBuf + 3;


	tBegin = TIME_NOW;
	strField = pxd_getFieldCount ( 1 );
	err = pxd_goLiveSeq (
		UNITSMAP,	// unitmap: Unit selection bit map (1 for single unit)
		startBuf,	// startbuf: Starting image frame buffer
		endBuf,		// endbuf: Ending image frame buffer
		incBuf,		// incbuf: Image frame buffer number increment
		numFrames + 2,	// numbuf: Number of captured images
		1			// videoperiod: Period between captured images
		);
	if ( err < 0 ){
		xclibAppendLogConsole ( "pxd_doSnap error: %s\n", pxd_mesgErrorCode ( err ) );
		return PXD_DOSNAP_ERR;
	}
	xclibAppendLogConsole ( "Processing Images...\t\n" );
	

	xclibAppendLogConsole ( "done! \n" );
	tEnd = TIME_NOW;
	auto tl = TIME_MICROSEC ( tEnd - tBegin ).count ();

	xclibAppendLogConsole ( "Capture: %d frames, Time elapsed: %.4f ms, average FPS: %.2f\n",
		numFrames, tl / 1000.0, 1000000.0 * numFrames / tl );
	pxd_goUnLive ( UNITSMAP );

	xclibAppendLogConsole ( "Freeing Pxipl Buffer Memory...\t" );
	


	xclibAppendLogConsole ( "done! \n" );
	
	tBegin = TIME_NOW;
	for ( UINT i = 1; i <= numFrames; i++ ){
		//xclibAppendLogConsole ( "Capturing frame #%d\n", i );


		switch ( fileType ){
		case FileType::BMP:
			err = savebmp ( i, i );
			break;
		case FileType::TIFF:
			err = savetiff ( i, i );
			break;
		case FileType::JPEG:
			err = savejpeg ( i, i );
			break;
		}

		if ( err < 0 ){
			xclibAppendLogConsole ( "Error while attempting to save JPEG file:\t" );
			switch ( err ){
			case PXERROR:
				xclibAppendLogConsole ( "Invalid parameters!!\n" );
				break;
			case PXERMALLOC:
				xclibAppendLogConsole ( "Memory allocation error!!\n" );
				break;
			case PXERNODATA:
				xclibAppendLogConsole ( "Pixel data type is not supported!!\n" );
				break;
			case PXERNOCOLOR:
				xclibAppendLogConsole ( "Pixel color is not supported!!\n" );
				break;
			case PXERNEWFILE:
				xclibAppendLogConsole ( "File can't be created!!\n" );
				break;
			case PXERDOSIO:
				xclibAppendLogConsole ( "DOS/Windows I/O write error!!\n" );
				break;
			case PXERBREAK:
				xclibAppendLogConsole ( "Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested)!!\n" );
				break;
			case SAVEJPEG_FILE_EXIST:
				xclibAppendLogConsole ( "File already exist!!\n" );
				break;
			default:
				xclibAppendLogConsole ( "pxio8_jpegwrite: %s\n", pxd_mesgErrorCode ( err ) );
				break;
			}
			return PXD_SAVEJPEG_ERR;
		}
	}
	tEnd = TIME_NOW;
	tl = TIME_MICROSEC ( tEnd - tBegin ).count ();
	switch ( fileType ){
	case FileType::BMP:
		xclibAppendLogConsole ( "Saving in BMP: %d frames, Time elapsed: %.4f ms, average FPS: %.2f\n",
			numFrames, tl / 1000.0, 1000000.0 * UNITS * numFrames / tl );
		break;
	case FileType::TIFF:
		xclibAppendLogConsole ( "Saving in TIFF: %d frames, Time elapsed: %.4f ms, average FPS: %.2f\n",
			numFrames, tl / 1000.0, 1000000.0 * UNITS * numFrames / tl );
		break;
	case FileType::JPEG:
		xclibAppendLogConsole ( "Saving in JPEG: %d frames, Time elapsed: %.4f ms, average FPS: %.2f\n",
			numFrames, tl / 1000.0, 1000000.0 * UNITS * numFrames / tl );
		break;

	}

	return 0;
}

int CaptureLoopSnap ( UINT numFrames, FileType fileType ){
	int err = 0;
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );
	for ( UINT i = 1; i <= numFrames; i++ ){
		//xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		err = pxd_doSnap ( UNITSMAP, 1, 0 );
		if ( err < 0 ){
			xclibAppendLogConsole ( "pxd_doSnap error: %s\n", pxd_mesgErrorCode ( err ) );
			return PXD_DOSNAP_ERR;
		}

		switch ( fileType ){
		case FileType::BMP:
			err = savebmp ( i );
			break;
		case FileType::TIFF:
			err = savetiff ( i );
			break;
		case FileType::JPEG:
			err = savejpeg ( i );
			break;
		}
		if ( err < 0 ){
			xclibAppendLogConsole ( "Error while attempting to save JPEG file:\t" );
			switch ( err ){
			case PXERROR:
				xclibAppendLogConsole ( "Invalid parameters!!\n" );
				break;
			case PXERMALLOC:
				xclibAppendLogConsole ( "Memory allocation error!!\n" );
				break;
			case PXERNODATA:
				xclibAppendLogConsole ( "Pixel data type is not supported!!\n" );
				break;
			case PXERNOCOLOR:
				xclibAppendLogConsole ( "Pixel color is not supported!!\n" );
				break;
			case PXERNEWFILE:
				xclibAppendLogConsole ( "File can't be created!!\n" );
				break;
			case PXERDOSIO:
				xclibAppendLogConsole ( "DOS/Windows I/O write error!!\n" );
				break;
			case PXERBREAK:
				xclibAppendLogConsole ( "Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested)!!\n" );
				break;
			case SAVEJPEG_FILE_EXIST:
				xclibAppendLogConsole ( "File already exist!!\n" );
				break;
			default:
				xclibAppendLogConsole ( "pxio8_jpegwrite: %s\n", pxd_mesgErrorCode ( err ) );
				break;
			}
			return PXD_SAVEJPEG_ERR;
		}
	}
	return 0;
}
#undef PXD_DOSNAP_ERR
#undef PXD_SAVEJPEG_ERR

int initPIXCI (){
	int err = 0;

	err = do_open ();

	if ( err < 0 ){
		xclibAppendLogConsole ( "Error while attempting to initialize PIXCI frame grabber!!\n" );
		return -1;
	}
	else{
		xclibAppendLogConsole ( "Frame grabber open successful.\n" );
		return 0;
	}
}


/*
*  MAIN:
*
*  Each library function is demonstrated in its own subroutine,
*  the main calls each subroutine to produce the interactive demonstration.
*
*  It is suggested that this program source be read at the same time
*  as the compiled program is executed.
*
*/
int main (void)
{
	//
	// Say Hello
	//
	hello ();

	//
	// Open and set video format.
	//
	if ( initPIXCI () < 0 )
		return -1;
	//
	// Basic video operations
	//
	do_imsize ();
	do_vidsize ();

	//
	// Save image
	//

	UINT frames = 100;
	//TimeT tBegin, tEnd;

	//tBegin = TIME_NOW;

	//CaptureLoopLiveSeq ( frames, FileType::BMP );
	CaptureLoopLiveSeq ( frames, FileType::TIFF );
	//CaptureLoopLiveSeq ( frames, FileType::JPEG );

	//tEnd = TIME_NOW;
	//auto tl = TIME_MICROSEC ( tEnd - tBegin ).count ();
	//xclibAppendLogConsole ( "TIFF %d frames, Time elapsed: %.4f ms, average FPS: %.2f\n",
	//	frames, tl / 1000.0, 1000000.0 * frames / tl );

	//
	// All done
	//
	do_close ();

	return( 0 );
}
