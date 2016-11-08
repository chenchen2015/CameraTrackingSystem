/*
*
*	XCLIB Console FrameGrabber  03-09-2015
*
*	Chen Chen, MacIver Lab
*
*	Example program for the XCLIB 'CPP' Library.
*	Example works and tested in Windows 7 SP1 x64
*
*	Frame Grabber: PIXCI(R) E8
*	Can be used with other PIXCI(R) frame grabbers,
*	altho some controls may be meaningless.
*
*	Demonstrates XCLIB and/or PXIPL functions for capture and
*	display of imagery and graphics.  Also demonstrates access
*	to numeric pixel values, and saving of an image.
*	This Windows program must, of course, also make use of
*	various Windows GDI API functions; however, this is not
*	intended to serve as a Windows tutorial.
*
*	Also optionally demonstrates use of multiple PIXCI(R)
*	frame grabbers operating simultaneously.
*
*
*/


/*
*  INSTRUCTIONS:
*
*  1)	Set 'define' options below according to the intended camera
*	and video format.
*
*	For PIXCI(R) SV2, SV3, SV4, SV5, SV5A, SV5B, and SV5L frame grabbers
*	common choices are RS-170, NSTC, NTSC/YC, CCIR, PAL, or PAL/YC.
*	(The SV5A and SV5B do not support NTSC/YC or PAL/YC).
*	For PIXCI(R) SV7 frame grabbers
*	common choices are RS-170, NSTC, CCIR, or PAL.
*	For PIXCI(R) SV8 frame grabbers
*	common choices are RS-170, NSTC, NTSC/YC, CCIR, PAL, PAL/YC.
*
*	For PIXCI(R) A, CL1, CL2, CL3SD, D, D24, D32, D2X, D3X, D3XE, E1, E1DB, E4, E4DB, E8, E8CAM, E8DB, e104x4,
*	EB1, EB1-POCL, EB1mini, EC1, ECB1, ECB1-34, ECB2, EL1, EL1DB, ELS2, SI, SI1, SI2, and SI4
*	frame grabbers, use "default" to select the default format for the camera
*	for which the PIXCI(R) frame grabber is intended.
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
// For PIXCI(R) SV2, SV3, SV4, SV5, SV5A, SV5B, SV5L
//#define FORMAT  "RS-170"	    // RS-170 on input 2
//#define FORMAT  "NTSC"	    // NTSC on input 2
//#define FORMAT  "NTSC/YC"	    // NSTC S-Video on input 1		    (N/A on SV5A,SV5B)
//#define FORMAT  "CCIR"	    // CCIR on input 2
//#define FORMAT  "PAL"	    // PAL (B,D,G,H,I) on input 2
//#define FORMAT  "PAL/YC"	    // PAL (B,D,G,H,I) S-Video on input 1   (N/A on SV5A,SV5B)
//#define FORMAT  "default"	    // NSTC S-Video on input 1

// For PIXCI(R) SV7
//#define FORMAT  "RS-170"	  // RS-170
//#define FORMAT  "NTSC"	  // NTSC
//#define FORMAT  "CCIR"	  // CCIR
//#define FORMAT  "PAL"	  // PAL
//#define FORMAT  "default"	  // NSTC

// For PIXCI(R) SV8
//#define FORMAT  "RS-170"	  // RS-170 on BNC 0
//#define FORMAT  "NTSC"	  // NTSC on BNC 0
//#define FORMAT  "NTSC/YC"	  // NSTC S-Video
//#define FORMAT  "CCIR"	  // CCIR on BNC 0
//#define FORMAT  "PAL"	  // PAL on BNC 0
//#define FORMAT  "PAL/YC"	  // PAL (B,D,G,H,I) S-Video
//#define FORMAT  "default"	  // NSTC on BNC 0

// For PIXCI(R) A, CL1, CL2, CL3SD, D, D24, D32,
// D2X, D3X, D3XE, E1, E1DB, E4, E4DB, E8, E8CAM, E8DB, e104x4, EB1, EB1-POCL, EB1mini,
// EC1, ECB1, ECB1-34, ECB2, EL1, EL1DB,
// ELS2, SI, SI1, SI2, SI4
//#define FORMAT  "default"	  // as per board's intended camera

// For any PIXCI(R) frame grabber
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
#define UNIT2BITMASK	4	// 
#define UNIT3BITMASK	8	// Camera #3

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
*  6a) Compile with Watcom C/C++ V11.0 for Tenberry/Rational DOS as:
*
*	    wcl386 -mf xclibex1.c -k8k XCLBW1DF.lib		    (w/out PXIPL)
*	    wcl386 -mf xclibex1.c -k8k XCLBW1DF.lib PXPLW1DF.LIB    (w. PXIPL)
*	    4gwbind 4gwpro.exe xclibex1.exe xclibexb.exe -N -VMDEL
*	Run as:
*	    xclibexb
*
*	Or
*	    wcl386 -mf xclibex1.c -k8k XCLBW1DF.lib		    (w/out PXIPL)
*	    wcl386 -mf xclibex1.c -k8k XCLBW1DF.lib PXPLW1DF.LIB    (w. PXIPL)
*	Run as:
*	    dos4gw xclibex1.exe

*	Note: Don't use the -Za option to enforce ANSI compatibility;
*	it also disables several predefined identifiers which are needed
*	by XCLIB include'd macros to identify the Watcom compiler.
*
*  6b) Compile with Microsoft Visual C/C++ V6.0 for Windows 95/98/ME as:
*	    cl xclibex1.c -link  XCLIBW95.LIB
*
*  6c) Compile with Microsoft Visual C/C++ V6.0 for Windows NT/2000/XP/Vista/7/8 32-Bit as:
*	    cl xclibex1.c -link  XCLIBWNT.LIB
*
*  6d) Compile with Microsoft Visual C/C++ for Windows XP/Vista/7/8 64-Bit as:
*	    cl xclibex1.c -link  XCLIBW64.LIB
*
*
*/


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
#include "pxipl.h"         
#include "pxextras.h"           
#endif
#include "xcliball.h"		// function prototypes

#include "XCLIB_FrameGrabber_v2.hpp"
#include "CaptureLog.hpp"

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
* Capture
*/
void do_video1 (void)
{
	int err = 0;
	//
	// Capture image into buffer 1.
	//
	printf ("Field count before snap=%d\n", pxd_videoFieldCount (1));
	err = pxd_doSnap (UNITSMAP, 1, 0);
	printf ("pxd_doSnap: %s\n", err >= 0 ? "Ok" : pxd_mesgErrorCode (err));
	printf ("Field count after  snap=%d\n", pxd_videoFieldCount (1));

	//
	// Check for faults, such as erratic sync
	// or insufficient PCI bus bandwidth
	//
	pxd_mesgFault (UNITSMAP);
	user ("Image snapped into buffer 1");
}


/*
* Pixels are transferred to a PC buffer, and numerically displayed.
*/
#define AOI_XDIM    9
#define AOI_YDIM    10
uchar	monoimage_buf8[AOI_XDIM*AOI_YDIM];
ushort	monoimage_buf16[AOI_XDIM*AOI_YDIM];

void bw_display1 (void)
{
	int     i;
	int     cx = ( pxd_imageXdim () - AOI_XDIM ) / 2;	// left coordinate of centered AOI
	int     cy = ( pxd_imageYdim () - AOI_YDIM ) / 2;	// top	coordinate of centered AOI
	//
	// Transfer the monochrome data from a selected AOI of
	// the image buffer into the PC buffer, as 8 bit pixels.
	// Or,
	// Transfer the monochrome data from a selected AOI of
	// the image buffer into the PC buffer, as 8 to 16 bit pixels.
	//
	// The ushort array could be used for both for 8 bit pixels, but
	// users of 8 bit pixels commonly assume pixel<=>byte,
	// and is more efficient.
	//
	if ( pxd_imageBdim () <= 8 ) {
		if ( ( i = pxd_readuchar (UNITSMAP, 1, cx, cy, cx + AOI_XDIM, cy + AOI_YDIM, monoimage_buf8, sizeof (monoimage_buf8) / sizeof (uchar), "Grey") ) != AOI_XDIM*AOI_YDIM ) {
			if ( i < 0 )
				printf ("pxd_readuchar: %s\n", pxd_mesgErrorCode (i));
			else
				printf ("pxd_readuchar error: %d != %d\n", i, AOI_XDIM*AOI_YDIM);
			user ("");
			return;
		}
	}
	else {
		if ( i = pxd_readushort (UNITSMAP, 1, cx, cy, cx + AOI_XDIM, cy + AOI_YDIM, monoimage_buf16, sizeof (monoimage_buf16) / sizeof (ushort), "Grey") != AOI_XDIM*AOI_YDIM ) {
			if ( i < 0 )
				printf ("pxd_readushort: %s\n", pxd_mesgErrorCode (i));
			else
				printf ("pxd_readushort error: %d != %d\n", i, AOI_XDIM*AOI_YDIM);
			user ("");
			return;
		}
	}
	user ("Image area of interest transfered");
}
void bw_display2 (void)
{
	int     x, y;
	//
	// Display data from the PC buffer.
	//
	for ( y = 0; y < AOI_YDIM; y++ ) {
		printf ("Grey = ");
		for ( x = 0; x < AOI_XDIM; x++ )
			if ( pxd_imageBdim () <= 8 )
				printf ("%4d ", monoimage_buf8[y*AOI_XDIM + x]);
			else
				printf ("%4d ", monoimage_buf16[y*AOI_XDIM + x]);
		printf ("\n");
	}
	user ("");
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
* Save image in industry standard .tif format.
*/
void do_savetif ()
{
	int     u, err = 0;
	char    name[] = IMAGEFILE_DIR "/" "image0.tif";

	for ( u = 0; u < UNITS; u++ ) {
		name[strlen (name) - 5] = '0' + u;

		//
		// Don't overwrite existing file.
		//
		if ( checkexist (name) )
			return;

		//
		// Do save of entire image to disk in TIFF format.
		//
		if ( UNITS == 1 )
			printf ("Image buffer 1 being saved to file %s\n", name);
		else
			printf ("Unit %d Image buffer 1 being saved to file %s\n", u, name);
		err = pxd_saveTiff (1 << u, name, 1, 0, 0, -1, -1, 0, 0);
		if ( err < 0 ) {
			printf ("pxd_saveTiff: %s\n", pxd_mesgErrorCode (err));
			user ("");
			return;
		}
		user ("Image buffer saved");
	}
}



/*
* Save image in the Windows .bmp format.
* This feature is available under DOS as well.
*/
void do_savebmp ()
{
	int     u, err = 0;
	char    name[] = IMAGEFILE_DIR "/" "image0.bmp";

	for ( u = 0; u < UNITS; u++ ) {
		name[strlen (name) - 5] = '0' + u;

		//
		// Don't overwrite existing file.
		//
		if ( checkexist (name) )
			return;

		//
		// Do save of entire image to disk in Bitmap format.
		// Monochrome image buffers are saved as an 8 bit monochrome image,
		// color image buffers are saved as an 24 bit RGB color image.
		//
		if ( UNITS == 1 )
			printf ("Image buffer 1 being saved to file %s\n", name);
		else
			printf ("Unit %d Image buffer 1 being saved to file %s\n", u, name);
		err = pxd_saveBmp (1 << u, name, 1, 0, 0, -1, -1, 0, 0);
		if ( err < 0 ) {
			printf ("pxd_saveBmp: %s\n", pxd_mesgErrorCode (err));
			user ("");
			return;
		}
		user ("Image buffer saved");
	}
}

/*
* Save image in the JPEG format.
* This requires the PXIPL library.
* 
* Bug fixed: in pxd_defineImage(), the input for 
*			 Unit selection bit map should be
*			 "1 << u" rather than "u". 
*					Chen Chen 
*					3-10-2015
*/
void do_savejpeg ()
{
#if USE_PXIPL
	int	u, err = 0;
	char	name[] = IMAGEFILE_DIR "/Imgs/" "Unit0_Seq0.jpg";
	int xdim, ydim;

	for ( u = 0; u < UNITS; u++ ) {
		name[strlen (name) - 10] = '0' + u;

		xdim = pxd_imageXdim ();
		ydim = pxd_imageYdim ();
		//
		// Don't overwrite existing file.
		//
		if ( checkexist (name) )
			return;

		//
		// Do save of entire image to disk in JPEG format.
		//
		if ( UNITS == 1 )
			printf ("Image buffer 1 being saved to file %s\n", name);
		else
			printf ("Unit %d Image buffer 1 being saved to file %s\n", u, name);

		err = pxio8_jpegwrite (
			NULL,	// Premature termination function, or NULL
			pxd_defineImage (
				1 << u,	// Unit selection bit map (1 for single unit)
				1,		// Image frame buffer
				0,		// Upper left x coord. of area of interest
				0,		// Upper left y coord. of area of interest
				-1,		// Lower right x coord. exclusive of AOI
				-1,		// Lower right y coord. exclusive of AOI
				"RGB"	// Name of requested color representation
				),	// Image & AOI to save
			NULL,	// Reserved, must be NULL
			name,	// File path name
			8,		// Bits per pixie to save. Must be 8
			NULL);	// Additional parms, or NULL for default

		if ( err < 0 ) {
			switch ( err ){
			case PXERROR:
				printf ("Invalid parameters!!\n");
				break;
			case PXERMALLOC:
				printf ("Memory allocation error!!\n");
				break;
			case PXERNODATA:
				printf ("Pixel data type is not supported!!\n");
				break;
			case PXERNOCOLOR:
				printf ("Pixel color is not supported!!\n");
				break;
			case PXERNEWFILE:
				printf ("File can't be created!!\n");
				break;
			case PXERDOSIO:
				printf ("DOS/Windows I/O write error!!\n");
				break;
			case PXERBREAK:
				printf ("Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested)!!\n");
				break;
			default:
				printf ("pxio8_jpegwrite: %s\n", pxd_mesgErrorCode (err));
				break;
			}
			//printf ("pxio8_jpegwrite: %s\n", pxd_mesgErrorCode (err));
			user ("");
			return;
		}
		user ("Image buffer saved");
	}
#endif
}

/*
* Display image on the S/VGA, using the PXIPL Library.
* (Image display on S/VGA is available under Windows with or
* without the PXIPL library, but not shown in this command-line
* oriented example).
*/
#if !(defined(_WIN32) || defined(__WIN32__) || defined(_WIN64))
void do_vgadisplay ()
{
#if USE_PXIPL

	struct  pximage vga;

	//
	// Put S/VGA in graphics mode. The vga_open supports high resolution,
	// but it can't detect which monitor is connected. Use a (monitor) safe
	// 640x480 resolution.
	//
	vga_open (0, 640, 480, 24, 1, &vga, NULL);

	//
	// One way to check success is whether the `vga' access
	// has a nonzero dimension, or non zero number of pixies.
	//
	if ( !vga.d.pixies ) {
		user ("Can't put S/VGA into graphics mode");
		return;
	}

	for ( u = 0; u < UNITS; u++ ) {
		//
		// Show image buffer 1 in center 1/4 of screen.
		// Selecting 7 bits in certain modes reflects how vga_open()
		// optionally set up the vga palette, for 8 bit per pixel VGA modes.
		//
		vga.wind.nw.x = vga.wind.se.x / 4;
		vga.wind.nw.y = vga.wind.se.y / 4;
		vga.wind.se.x = 3 * vga.wind.se.x / 4;
		vga.wind.se.y = 3 * vga.wind.se.y / 4;
		( vga.xwind )( &vga, &vga.wind, 's' );
		err = pxio8_vgadisplay (NULL, pxd_defineImage (1 << u, 1, 0, 0, -1, -1, "Display"), NULL,
			( vga.d.pixies == 1 && vga.d.u.i.bitsused == 8 ) ? 7 : vga.d.u.i.bitsused,
			'n', 1, 0, &vga, NULL, NULL);
		if ( err < 0 )
			printf ("pxio8_vgadisplay: %s\n", pxd_mesgErrorCode (err));

		//
		// Show message.
		// Assume worst case, that S/VGA BIOS doesn't support printf in this mode.
		//
		{
			struct pxy xy = { 0, 0 };
			uint   forecolor[3] = { 255, 255, 0 };
			uint   backcolor[3] = { 0, 0, 0 };

			( vga.xwind )( &vga, NULL, 's' );   // set full window
			err = pxip8_drawchars (NULL, &vga, &xy,
				"S/VGA graphics mode set, and image displayed.",
				45, 8, 8, 0, 1, 0, backcolor, forecolor, 0);
			if ( err < 0 )
				printf ("pxip8_drawchars: %s\n", pxd_mesgErrorCode (err));
			xy.y += 10;
			err = pxip8_drawchars (NULL, &vga, &xy, "Continue (Key ENTER) ?",
				22, 8, 8, 0, 1, 0, backcolor, forecolor, 0);
			if ( err < 0 )
				printf ("pxip8_drawchars: %s\n", pxd_mesgErrorCode (err));
		}

		//
		// Wait for user
		//
		user ("");
	}

	//
	// Reset S/VGA so the remainder of this example,
	// which uses printf(), can proceed.
	//
	vga_close (&vga, NULL);

#endif
}
#endif


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
	printf ("PIXCI(R) Frame Grabber v2 - Based on XCLIB 'C' Library\n");
	printf ("\n");
	user ("");
}


const enum FileName{
	JPEG,
	BMP,
	TIFF
};

int savebmp ( UINT seq )
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
		if ( checkexist ( name ) )
			return -23;

		//
		// Do save of entire image to disk in Bitmap format.
		// Monochrome image buffers are saved as an 8 bit monochrome image,
		// color image buffers are saved as an 24 bit RGB color image.
		//
		err = pxd_saveBmp ( 1 << u, name, 1, 0, 0, -1, -1, 0, 0 );
		if ( err < 0 ){
			return err;
		}
	}
	return 0;
}

int savetiff ( UINT seq )
{
	int     u, err = 0;
	char name[] = IMAGEFILE_DIR "/Imgs/" "Unit#_Seq$$$$.tiff";
	char seqChar[] = "0000.tiff";

	for ( u = 0; u < UNITS; u++ ) {
		name[11] = '0' + u;  // Units #
		sprintf ( seqChar, "%04d.tiff", seq );
		strcpy ( &name[16], seqChar ); // Sequence $

		//
		// Don't overwrite existing file.
		//
		if ( checkexist ( name ) )
			return -23;

		//
		// Do save of entire image to disk in Bitmap format.
		// Monochrome image buffers are saved as an 8 bit monochrome image,
		// color image buffers are saved as an 24 bit RGB color image.
		//
		err = pxd_saveTiff ( 1 << u, name, 1, 0, 0, -1, -1, 0, 0 );
		if ( err < 0 ){
			return err;
		}
	}
	return 0;
}

int savejpeg (UINT seq)
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
		if ( checkexist ( name ) )
			return -23;

		//
		// Do save of entire image to disk in JPEG format.
		//
		//xclibAppendLog ( "Unit %d Image %d being saved to file %s\n", u, seq, name );

		err = pxio8_jpegwrite (
			NULL,	// Premature termination function, or NULL
			pxd_defineImage (
				1 << u,	// Unit selection bit map (1 for single unit)
				1,		// Image frame buffer
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
int CaptureLoopLive ( UINT numFrames, FileName fileType ){
	int err = 0;
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );

	err = pxd_goLive (
		UNITSMAP,	// unitmap: Unit selection bit map (1 for single unit)
		1			// buffer: Image frame buffer
		);
	if ( err < 0 ){
		xclibAppendLogConsole ( "pxd_doSnap error: %s\n", pxd_mesgErrorCode ( err ) );
		return PXD_DOSNAP_ERR;
	}

	for ( UINT i = 1; i <= numFrames; i++ ){
		xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		switch ( fileType ){
		case BMP:
			err = savebmp ( i );
			break;
		case TIFF:
			err = savetiff ( i );
			break;
		case JPEG:
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

int CaptureLoopLiveSeq ( UINT numFrames, FileName fileType ){
	int err = 0;
	UINT startBuf, endBuf, incBuf;
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );

	startBuf = 1;
	incBuf = 1;
	endBuf = startBuf + numFrames * incBuf - 1;

	err = pxd_goLiveSeq (
		UNITSMAP,	// unitmap: Unit selection bit map (1 for single unit)
		startBuf,	// startbuf: Starting image frame buffer
		endBuf,		// endbuf: Ending image frame buffer
		incBuf,		// incbuf: Image frame buffer number increment
		numFrames,	// numbuf: Number of captured images
		1			// videoperiod: Period between captured images
		);
	if ( err < 0 ){
		xclibAppendLogConsole ( "pxd_doSnap error: %s\n", pxd_mesgErrorCode ( err ) );
		return PXD_DOSNAP_ERR;
	}

	for ( UINT i = 1; i <= numFrames; i++ ){
		xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		switch ( fileType ){
		case BMP:
			err = savebmp ( i );
			break;
		case TIFF:
			err = savetiff ( i );
			break;
		case JPEG:
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

int CaptureLoopSnap ( UINT numFrames, FileName fileType ){
	int err = 0;
	LOG_LINE_SEG;
	xclibAppendLogConsole ( "Frame Capturing Loop\n" );
	for ( UINT i = 1; i <= numFrames; i++ ){
		xclibAppendLogConsole ( "Capturing frame #%d\n", i );

		err = pxd_doSnap ( UNITSMAP, 1, 0 );
		if ( err < 0 ){
			xclibAppendLogConsole ( "pxd_doSnap error: %s\n", pxd_mesgErrorCode ( err ) );
			return PXD_DOSNAP_ERR;
		}

		switch ( fileType ){
		case BMP:
			err = savebmp ( i );
			break;
		case TIFF:
			err = savetiff ( i );
			break;
		case JPEG:
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
#if USE_PXIPL
	//do_video1 ();
#endif

	//
	// Save image
	//
	//do_savetif ();
	//do_savebmp ();
#if USE_PXIPL
	//do_savejpeg ();
#endif

	//CaptureLoopSnap ( 10, FileName::TIFF );
	//CaptureLoopLiveSeq ( 10, FileName::TIFF );
	CaptureLoopLive ( 50, FileName::TIFF );

	//
	// All done
	//
	do_close ();

	return( 0 );
}
