#ifndef _PXIPL_FUN_HPP
#define _PXIPL_FUN_HPP	1

#include <stdio.h>
extern "C" {
#include "pxipl.h"
}
#include "pxextras.h"           
#include "xcliball.h"		// function prototypes
#include "CaptureLog.hpp"

#define UNIT0BITMASK	1	// Camera #1
#define UNIT1BITMASK	2	// Camera #2
#define UNIT2BITMASK	4	// Camera #3
#define UNIT3BITMASK	8	// Camera #4


class pxipl{

#pragma region PXIPL_Base_StructEnum
public:
	/// <summary>
	/// AOI struct, fields: 
	/// ulx = 0, uly = 0, lrx = -1, lry = -1, colorspace = "Default"
	/// </summary>
	struct pxImgSpec{
		int	ulx = 0;
		int uly = 0;
		int lrx = -1;
		int lry = -1;
		char* colorspace = "Default";
	} imgSpec;
#pragma endregion

#pragma region PXIPL_Base_Var_Public
public:
	/// <summary>
	/// Number of Units used
	/// </summary>
	unsigned char units;
	/// <summary>
	/// Units map for the Unit #
	/// </summary>
	unsigned char unitsmap;
	/// <summary>
	/// Start Buffer #
	/// </summary>
	pxbuffer_t strBuff;
	/// <summary>
	/// Number of buffers used
	/// </summary>
	unsigned long numOfBuffers;
	/// <summary>
	/// End Buffer #
	/// </summary>
	pxbuffer_t endBuff;
	/// <summary>
	/// Switch for log functions
	/// </summary>
	bool logSwitch = false;


#pragma endregion

#pragma region PXIPL_Base_Var_Protected
protected:
	/// <summary>
	/// Function names
	/// </summary>
	enum funNames{
		SOBEL3X3BUF,
		SOBEL3X3IMG
	};
	/// <summary>
	/// Level 1 pointer to pximage struct
	/// </summary>
	pximage*   pxim_pl1 = nullptr;
	/// <summary>
	/// Level 2 pointer to pximage struct
	/// </summary>
	pximage**  pxim_pl2 = nullptr;
	/// <summary>
	/// Level 3 pointer to pximage struct
	/// </summary>
	pximage*** pxim_pl3 = nullptr;
#pragma endregion

#pragma region PXIPL_Base_Var_Private
private:
#pragma endregion

#pragma region PXIPL_Base_Memory
protected:
	pximage** initPximPointerLv2 ( int unit );
	void initPximPointerLv3 ();
	void freePxiPointerMemory ();
#pragma endregion

#pragma region PXIPL_Base_DefConstructor
public:
	// Default constructors	
	pxipl ( pxbuffer_t sb, unsigned long nf, bool logSW = false );
	pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, bool logSW = false );
	pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, char* colorspace, bool logSW = false );
	pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, int ulx, int uly, int lrx, int lry, bool logSW = false );
	pxipl ( unsigned char ubm, pxbuffer_t sb, unsigned long nf, int ulx, int uly, int lrx, int lry, char* colorspace, bool logSW = false );
#pragma endregion

#pragma region PXIPL_Base_DefDestructor
public:
	// Default deconstructors
	~pxipl ();
#pragma endregion


#pragma region PXIPL_Base_LogDebugErr
protected:
	const char* getErrMsg ( int err, funNames funName );
	void logErrMsg ( int errId, funNames fname );
#pragma endregion

#pragma region PXIPL_Algorithm_Edge
public:
	pximage* sobel3x3Img ( int unit, pxbuffer_t sib, int mode = 0 );

	void sobel3x3Buff ( int unit, int initialRun = 0, int mode = 0 );
#pragma endregion

};// Class pxipl



/*
extern pxipl::pxImgReturn tmpPxi3x3sobel ( int unit, pxbuffer_t sib, int mode = 0 );
extern inline void tmpPxi3x3sobeli ( int unit = 0, int mode = 0 );
extern pximage ** initPxiBufferMemory ( int unit, pxbuffer_t startBuff, pxbuffer_t endBuff, pxbuffer_t incBuff );
extern void freePxiBufferMemory ( pximage *** Img, long len );
extern pxbuffer_t tmpPxi3x3sobelPre ( int unit, int mode, pxbuffer_t startBuff, pximage ** imgBuff );
*/

#endif