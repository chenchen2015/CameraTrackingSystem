// PXIPL functions and class
// Chen Chen
// Apr. 13, 2015
 

#include "PXIPLfun.hpp"
#include <array>
#include <time.h>

#pragma region PXIPL_Base_StructEnum
//---------- Structs and Enums -------------------------------------------------------------------
#pragma endregion

#pragma region PXIPL_Base_DefConstructor
//---------- Default Constructors -------------------------------------------------------------------

//************************************
// Method:    pxipl
// FullName:  pxipl::pxipl
// Usage:	  Default Constructor
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: pxbuffer_t sb
// Parameter: unsigned long nf
// Parameter: bool logSW
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::pxipl ( pxbuffer_t sb, unsigned long nf, bool logSW /*= false*/ ){
	units = 1; // default
	unitsmap = 1 << UNIT0BITMASK; // default

	strBuff = sb;
	numOfBuffers = nf;
	endBuff = sb + nf - 1;

	logSwitch = logSW;

	initPximPointerLv3 ();
}

//************************************
// Method:    pxipl
// FullName:  pxipl::pxipl
// Usage:	  Default Constructor
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: unsigned char ubm
// Parameter: pxbuffer_t sb
// Parameter: unsigned long nf
// Parameter: bool logSW
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, bool logSW /*= false*/ ){
	unitsmap = ubm;
	units = 0;

	if ( ubm & UNIT0BITMASK ) units++;
	if ( ubm & UNIT1BITMASK ) units++;
	if ( ubm & UNIT2BITMASK ) units++;
	if ( ubm & UNIT3BITMASK ) units++;

	strBuff = sb;
	numOfBuffers = nf;
	endBuff = sb + nf - 1;

	logSwitch = logSW;

	initPximPointerLv3 ();
}

//************************************
// Method:    pxipl
// FullName:  pxipl::pxipl
// Usage:	  Default Constructor
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: unsigned char ubm
// Parameter: pxbuffer_t sb
// Parameter: unsigned long nf
// Parameter: char * colorspace
// Parameter: bool logSW
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, char* colorspace, bool logSW /*= false*/ ) {
	unitsmap = ubm;
	units = 0;

	if ( ubm & UNIT0BITMASK ) units++;
	if ( ubm & UNIT1BITMASK ) units++;
	if ( ubm & UNIT2BITMASK ) units++;
	if ( ubm & UNIT3BITMASK ) units++;

	strBuff = sb;
	numOfBuffers = nf;
	endBuff = sb + nf - 1;

	imgSpec.colorspace = colorspace;
	
	logSwitch = logSW;

	initPximPointerLv3 ();
}

//************************************
// Method:    pxipl
// FullName:  pxipl::pxipl
// Usage:	  Default Constructor
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: unsigned char ubm
// Parameter: pxbuffer_t sb
// Parameter: unsigned long nf
// Parameter: int ulx
// Parameter: int uly
// Parameter: int lrx
// Parameter: int lry
// Parameter: bool logSW
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, int ulx, int uly, int lrx, int lry, bool logSW /*= false*/ ){
	unitsmap = ubm;
	units = 0;

	if ( ubm & UNIT0BITMASK ) units++;
	if ( ubm & UNIT1BITMASK ) units++;
	if ( ubm & UNIT2BITMASK ) units++;
	if ( ubm & UNIT3BITMASK ) units++;

	strBuff = sb;
	numOfBuffers = nf;
	endBuff = sb + nf - 1;

	imgSpec.ulx = ulx;
	imgSpec.uly = uly;
	imgSpec.lrx = lrx;
	imgSpec.lry = lry;

	logSwitch = logSW;

	initPximPointerLv3 ();
}

//************************************
// Method:    pxipl
// FullName:  pxipl::pxipl
// Usage:	  
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: unsigned char ubm
// Parameter: pxbuffer_t sb
// Parameter: unsigned long nf
// Parameter: int ulx
// Parameter: int uly
// Parameter: int lrx
// Parameter: int lry
// Parameter: char * colorspace
// Parameter: bool logSW
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, int ulx, int uly, int lrx, int lry, char* colorspace, bool logSW /*= false*/ ) {
	unitsmap = ubm;
	units = 0;

	if ( ubm & UNIT0BITMASK ) units++;
	if ( ubm & UNIT1BITMASK ) units++;
	if ( ubm & UNIT2BITMASK ) units++;
	if ( ubm & UNIT3BITMASK ) units++;

	strBuff = sb;
	numOfBuffers = nf;
	endBuff = sb + nf - 1;

	imgSpec.ulx = ulx;
	imgSpec.uly = uly;
	imgSpec.lrx = lrx;
	imgSpec.lry = lry;
	imgSpec.colorspace = colorspace;

	logSwitch = logSW;

	initPximPointerLv3 ();
}
#pragma endregion

#pragma region PXIPL_Base_Memory

//************************************
// Method:    initPximPointerLv2
// FullName:  pxipl::initPximPointerLv2
// Usage:	  Initialize Level 2 Pointer 
// Access:    protected 
// Returns:   pximage**
// Qualifier:
// Parameter: int unit
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pximage** pxipl::initPximPointerLv2 ( int unit ){

	// If memory already been allocated, free it
	if ( pxim_pl2 != nullptr ) {
		delete( pxim_pl2 );
		pxim_pl2 = nullptr;
	}

	// Allocate new memory
	pxim_pl2 = new pximage*[numOfBuffers];

	unsigned long index = 0;

	for ( long i = 0; i < numOfBuffers; i++ ){
		pxim_pl2[i++] = pxd_definePximage ( 1 << unit, i, imgSpec.ulx, imgSpec.uly, imgSpec.lrx, imgSpec.lry, imgSpec.colorspace );
	}

	return pxim_pl2;
}

//************************************
// Method:    initPximPointerLv3
// FullName:  pxipl::initPximPointerLv3
// Usage:	  Initialize Level 3 Pointer
// Access:    protected 
// Returns:   void
// Qualifier:
// By:        Chen Chen
// Date:      2015/04/14
//************************************
void pxipl::initPximPointerLv3 (){
	if ( logSwitch ) {
		xclibAppendLogConsole ( "Initializing Pxipl Buffer Memory...\t" );
	}

	// If memory already been allocated, free it
	if ( pxim_pl3 != nullptr ) {
		delete( pxim_pl3 );
		pxim_pl3 = nullptr;
	}

	// Allocate new memory
	pxim_pl3 = new pximage**[units];

	int index = 0;

	if ( unitsmap & UNIT0BITMASK ) pxim_pl3[index++] = initPximPointerLv2 ( 0 );
	if ( unitsmap & UNIT1BITMASK ) pxim_pl3[index++] = initPximPointerLv2 ( 1 );
	if ( unitsmap & UNIT2BITMASK ) pxim_pl3[index++] = initPximPointerLv2 ( 2 );
	if ( unitsmap & UNIT3BITMASK ) pxim_pl3[index++] = initPximPointerLv2 ( 3 );

	// Free Point Level 2 Memory
	delete( pxim_pl2 );
	pxim_pl2 = nullptr;

	if ( logSwitch ) {
		xclibAppendLogConsole ( "done! \n" );
	}
}

//************************************
// Method:    freePxiPointerMemory
// FullName:  pxipl::freePxiPointerMemory
// Usage:	  Free all the pointer memory
// Access:    protected 
// Returns:   void
// Qualifier:
// By:        Chen Chen
// Date:      2015/04/14
//************************************
void pxipl::freePxiPointerMemory (){
	long i = 0;
	int index = 0;

	if ( logSwitch ) {
		time_t tnow = time ( NULL );
		char* tdate = ctime ( &tnow );
		xclibAppendLogConsole ( "Freeing Pxipl Buffer Memory...\t" );
	}

	if ( unitsmap & UNIT0BITMASK ) {
		for ( i = 0; i < numOfBuffers; i++ ){
			pxd_definePximageFree ( ( *( pxim_pl3 + index ) )[i] );
		};
		index++;
	}
	if ( unitsmap & UNIT1BITMASK ) {
		for ( i = 0; i < numOfBuffers; i++ ){
			pxd_definePximageFree ( ( *( pxim_pl3 + index ) )[i] );
		};
		index++;
	}	
	if ( unitsmap & UNIT2BITMASK ) {
		for ( i = 0; i < numOfBuffers; i++ ){
			pxd_definePximageFree ( ( *( pxim_pl3 + index ) )[i] );
		};
		index++;
	}	
	if ( unitsmap & UNIT3BITMASK ) {
		for ( i = 0; i < numOfBuffers; i++ ){
			pxd_definePximageFree ( ( *( pxim_pl3 + index ) )[i] );
		};
		index++;
	}
	
	if ( pxim_pl1 != nullptr ){
		delete( pxim_pl1 );
		pxim_pl1 = nullptr;
	}
	if ( pxim_pl2 != nullptr ){
		delete( pxim_pl2 );
		pxim_pl2 = nullptr;
	}
	if ( pxim_pl3 != nullptr ){
		delete( pxim_pl3 );
		pxim_pl3 = nullptr;
	}

	if ( logSwitch ) {
		xclibAppendLogConsole ( "done! \n" );
	}
}
#pragma endregion


#pragma region PXIPL_Base_DefDestructor
//---------- Default Destructors -------------------------------------------------------------------

//************************************
// Method:    ~pxipl
// FullName:  pxipl::~pxipl
// Usage:	  Default Destructor, will free all the pointer memory
// Access:    public 
// Returns:   
// Qualifier:
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pxipl::~pxipl (){
	freePxiPointerMemory ();
}
#pragma endregion


#pragma region PXIPL_Base_LogDebugErr
//---------- Log, Debug and Error Handler functions -------------------------------------------------------------------

//************************************
// Method:    getErrMsg
// FullName:  pxipl::getErrMsg
// Usage:	  
// Access:    protected 
// Returns:   const char*
// Qualifier:
// Parameter: int err
// Parameter: funNames fname
// By:        Chen Chen
// Date:      2015/04/14
//************************************
const char* pxipl::getErrMsg ( int err, funNames fname ){
	switch ( fname ){
	case funNames::SOBEL3X3IMG:
		switch ( err ){
		case PXERROR:
			return "sobel3x3Img: Invalid parameters.";
			break;
		case PXERMALLOC:
			return "sobel3x3Img: Memory allocation error.";
			break;
		case PXERNODATA:
			return "sobel3x3Img: Pixel data type is not supported.";
			break;
		case PXERNOCOLOR:
			return "sobel3x3Img: Pixel color is not supported.";
			break;
		case PXERBREAK:
			return "sobel3x3Img: Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested).";
			break;
		default:
			return "sobel3x3Img: Unknown error.";
		}
		break;
	case funNames::SOBEL3X3BUF:
		switch ( err ){
		case PXERROR:
			return "sobel3x3Buff: Invalid parameters.";
			break;
		case PXERMALLOC:
			return "sobel3x3Buff: Memory allocation error.";
			break;
		case PXERNODATA:
			return "sobel3x3Buff: Pixel data type is not supported.";
			break;
		case PXERNOCOLOR:
			return "sobel3x3Buff: Pixel color is not supported.";
			break;
		case PXERBREAK:
			return "sobel3x3Buff: Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested).";
			break;
		default:
			return "sobel3x3Buff: Unknown error.";
		}
		break;
	default:
		return "Unknown error.";
	}
}

//************************************
// Method:    logErrMsg
// FullName:  pxipl::logErrMsg
// Usage:	  
// Access:    protected 
// Returns:   void
// Qualifier:
// Parameter: int errId
// Parameter: funNames fname
// By:        Chen Chen
// Date:      2015/04/14
//************************************
void pxipl::logErrMsg ( int errId, funNames fname ){
	if ( errId >= 0 ) return;

	const char* errMsg = getErrMsg ( errId, fname );

	xclibAppendLogConsole ( "Error in PXIPL function : \t%s\n", errMsg );
}
#pragma endregion


#pragma region PXIPL_Algorithm_Edge_LevPxImg
//---------- Child Class: edge -------------------------------------------------------------------
//---------- Image Level Functions -------------------------------------------------------------------


//************************************
// Method:    sobel3x3Img
// FullName:  pxipl::sobel3x3Img
// Usage:	  
// Access:    public 
// Returns:   pximage*
// Qualifier:
// Parameter: int unit
// Parameter: pxbuffer_t sib
// Parameter: int mode
// By:        Chen Chen
// Date:      2015/04/14
//************************************
pximage* pxipl::sobel3x3Img ( int unit, pxbuffer_t sib, int mode /*= 0*/ ){
	int errId = 0;

	errId = pxip8_3x3sobel (
		NULL,	// premature termination function, or NULL : pxabortfunc_t   **abortp;
		*( pxim_pl3 + unit )[sib - strBuff],	// source image
		pxim_pl1,	// destination image
		mode	// int mode;
		// 0: scaled magnitude
		// 1: old pixel - scaled magnitude
		// 2: 5 bit log magn. & 3 bit angle
		// 3: magnitude (unscaled)
		);

	logErrMsg ( errId, funNames::SOBEL3X3IMG );

	return pxim_pl1;
}
#pragma endregion

#pragma region PXIPL_Algorithm_Edge_LevBuffer

//************************************
// Method:    sobel3x3Buff
// FullName:  pxipl::sobel3x3Buff
// Usage:	  
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int unit
// Parameter: int mode = 0
// Parameter: int initialRun = 0
// By:        Chen Chen
// Date:      2015/04/14
//************************************
void pxipl::sobel3x3Buff ( int unit, int initialRun /*=0*/, int mode /*=0*/ ){
	pxbuffer_t curbBff = 1;
	static pxbuffer_t lastBuff = 1;
	int errId = 0;

	if ( initialRun ) lastBuff = 1;

	curbBff = pxd_capturedBuffer ( 1 << unit );

	//xclibAppendLogConsole ( "curBuff %d, \t lastBuff\n", pxd_capturedBuffer ( 1 << 0 ) );

	if ( curbBff <= lastBuff )	return;

	errId = pxip8_3x3sobel (
		NULL,	// premature termination function, or NULL : pxabortfunc_t   **abortp;
		*( pxim_pl3 + unit )[lastBuff - strBuff],	// source image
		*( pxim_pl3 + unit )[lastBuff - strBuff],	// destination image
		mode	// int mode;
		// 0: scaled magnitude
		// 1: old pixel - scaled magnitude
		// 2: 5 bit log magn. & 3 bit angle
		// 3: magnitude (unscaled)
		);

	lastBuff++;

	logErrMsg ( errId, funNames::SOBEL3X3BUF );
}

#pragma endregion



/*
// List of all available functions
enum funNames{
	SOBEL3X3BUF
};

const char* getErrMsg ( int err, funNames funName ){
	switch ( funName ){
	case funNames::SOBEL3X3BUF:
		switch ( err ){
		case PXERROR:
			return "Invalid parameters.";
			break;
		case PXERMALLOC:
			return "Memory allocation error.";
			break;
		case PXERNODATA:
			return "Pixel data type is not supported.";
			break;
		case PXERNOCOLOR:
			return "Pixel color is not supported.";
			break;
		case PXERBREAK:
			return "Operation aborted due to abortp (may return other values as determined by abortp, PXERBREAK is suggested).";
			break;
		default:
			return "Unknown error.";
		}
		break;
	default:
		return "Unknown error.";
	}
}


pxipl::pxImgReturn tmpPxi3x3sobel ( int unit, pxbuffer_t sib, int mode ){
	pxipl::pxImgReturn pxIm;
	pxipl::pxImgSpec spec;

	pximage * curImg = pxd_definePximage ( unit, sib, spec.ulx, spec.uly, spec.lrx, spec.lry, spec.colorspace );
	pxIm.errId = pxip8_3x3sobel (
		NULL,	// premature termination function, or NULL : pxabortfunc_t   **abortp;
		pxd_defineImage ( 1 << unit, sib, spec.ulx, spec.uly, spec.lrx, spec.lry, spec.colorspace ),	// source image
		&pxIm.img,	// destination image
		mode	// int mode;
				// 0: scaled magnitude
				// 1: old pixel - scaled magnitude
				// 2: 5 bit log magn. & 3 bit angle
				// 3: magnitude (unscaled)
		);
	if ( pxIm.errId < 0 ){
		//logErrInt ( err, "sobel3x3buf" );
		const char* errMsg = getErrMsg ( pxIm.errId, funNames::SOBEL3X3BUF );
		xclibAppendLogConsole ( "Error in PXIPL function ( sobel3x3bufTMP ):\t%s\n", errMsg );
	}

	return pxIm;
}

inline void tmpPxi3x3sobeli ( int unit, int mode ){
	pxbuffer_t curbBff = 0;
	static pxbuffer_t lastBuff = 0;
	pxipl::pxImgReturn pxIm;
	pxipl::pxImgSpec spec;

	curbBff = pxd_capturedBuffer ( 1 << unit );

	if ( curbBff <= lastBuff )	return;

	pximage * curImg = pxd_definePximage ( 1 << unit, lastBuff, spec.ulx, spec.uly, spec.lrx, spec.lry, spec.colorspace );

	pxIm.errId = pxip8_3x3sobel (
		NULL,	// premature termination function, or NULL : pxabortfunc_t   **abortp;
		curImg,	// source image
		curImg,	// destination image
		mode	// int mode;
				// 0: scaled magnitude
				// 1: old pixel - scaled magnitude
				// 2: 5 bit log magn. & 3 bit angle
				// 3: magnitude (unscaled)
		);
	if ( pxIm.errId < 0 ){
		//logErrInt ( err, "sobel3x3buf" );
		const char* errMsg = getErrMsg ( pxIm.errId, funNames::SOBEL3X3BUF );
		xclibAppendLogConsole ( "Error in PXIPL function ( sobel3x3bufTMP ):\t%s\n", errMsg );
		xclibAppendLog (
			"Parameters list:\n\t"
			"unitmap:\t%i \n\t"
			"buffer :\t%ld\n\t"
			"ulx	:\t%d \n\t"
			"uly	:\t%d \n\t"
			"lrx	:\t%d \n\t"
			"lry	:\t%d \n\t", 
			unit, lastBuff, spec.ulx, spec.uly, spec.lrx, spec.lry );
	}

	pxd_definePximageFree ( curImg );

	lastBuff++;
	//lastBuff = buff;
}


pxbuffer_t tmpPxi3x3sobelPre ( int unit, int mode, pxbuffer_t startBuff, pximage ** imgBuff ){
	pxbuffer_t curbBff = 1;
	static pxbuffer_t lastBuff = 1;
	//pxipl::pxImgReturn pxIm;
	pxipl::pxImgSpec spec;
	int errId = 0;

	curbBff = pxd_capturedBuffer ( 1 << unit );

	//xclibAppendLogConsole ( "curBuff %d, \t lastBuff\n", pxd_capturedBuffer ( 1 << 0 ) );

	if ( curbBff <= lastBuff )	return lastBuff;

	errId = pxip8_3x3sobel (
		NULL,	// premature termination function, or NULL : pxabortfunc_t   **abortp;
		imgBuff[lastBuff - startBuff],	// source image
		imgBuff[lastBuff - startBuff],	// destination image
		mode	// int mode;
		// 0: scaled magnitude
		// 1: old pixel - scaled magnitude
		// 2: 5 bit log magn. & 3 bit angle
		// 3: magnitude (unscaled)
		);
	if ( errId < 0 ){
		//logErrInt ( err, "sobel3x3buf" );
		const char* errMsg = getErrMsg ( errId, funNames::SOBEL3X3BUF );
		xclibAppendLogConsole ( "Error in PXIPL function ( sobel3x3bufTMP ):\t%s\n", errMsg );
		xclibAppendLog (
			"Parameters list:\n\t"
			"unitmap:\t%i \n\t"
			"buffer :\t%ld\n\t"
			"ulx	:\t%d \n\t"
			"uly	:\t%d \n\t"
			"lrx	:\t%d \n\t"
			"lry	:\t%d \n\t",
			unit, lastBuff, spec.ulx, spec.uly, spec.lrx, spec.lry );
	}

	lastBuff++;
	return lastBuff;
	//lastBuff = buff;
}


pximage ** initPxiBufferMemory ( int unit, pxbuffer_t startBuff, pxbuffer_t endBuff, pxbuffer_t incBuff ){
	pxipl::pxImgSpec spec;
	pximage ** curImg;

	curImg = new pximage*[endBuff - startBuff + 1];

	unsigned long index = 0;

	for ( long i = startBuff; i <= endBuff; i++ ){
		curImg[index++] = pxd_definePximage ( 1 << unit, i, spec.ulx, spec.uly, spec.lrx, spec.lry, spec.colorspace );
	}

	return curImg;
}

void freePxiBufferMemory ( pximage *** Img, long len ){

	for ( long i = 0; i < len; i++ ){
		pxd_definePximageFree ( (*Img)[i] );
	}

}

*/