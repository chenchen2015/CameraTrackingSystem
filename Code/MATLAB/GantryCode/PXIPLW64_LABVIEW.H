'                                                          
'   PXIPLW64_LABVIEW.H  External     09-Jul-2014    
'   Copyright (C)  2007-2014   EPIX, Inc.  All rights reserved.
'                                                          
'   PXIPL Declarations for LabView 64-Bit                  
'                                                          

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memory(pximage_s*tp,void*imagep,const pxy_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memory2(pximage_s*tp,void*imagep,const pxy_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memory3(pximage_s*tp,void*imagep,pxim3size_t imagesize,const pxy_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memdata(pximage_s*tp,void*imagep,pxim3size_t imagesize,
// const pxy_s*dimp,pxim1size_t ypitch,const pximagedata_s*datap,
// const pximagehints_s*hintp,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memmalloc(pximage_s*tp,void**bufpp,
// const pxy_s*dimp,int pixtype,int bitsused,int pixies,int pixelhint);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_memfree(pximage_s*tp,void**bufpp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport) ,__stdcall,pximage_s*)pximage_memmalloc2(void*bufp,
// int pixtype,int bitsused,int pixies,int pixelhint,
// pxcoord_t xdim,pxcoord_t ydim,float pixelwidth,float pixelheight,int pixelwhunits);
void* __stdcall pximage_memmalloc2(void* bufp, int pixtype, int bitsused, int pixies, int pixelhint, 
int xdim, int ydim, float pixelwidth, float pixelheight, int pixelwhunits);

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage_memfree2(pximage_s*tp,void*bufp);
int __stdcall pximage_memfree2(void* tp, void* bufp);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_fmemory(pximage_s*tp,void*imagep,const pxy_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_fmemory2(pximage_s*tp,void*imagep,const pxy_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_fmemdata(pximage_s*tp,void*imagep,pxim3size_t imagesize,
// const pxy_s*dimp,pxim1size_t ypitch,const pximagedata_s*datap,
// const pximagehints_s*hintp,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_memory(pximage3_s*tp,void*imagep,const pxyz_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_memory2(pximage3_s*tp,void*imagep,const pxyz_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits,float pixeldepth,int pixelzunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_memory3(pximage3_s*tp,void*imagep,pxim3size_t imagesize,const pxyz_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits,float pixeldepth,int pixelzunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_memdata(pximage3_s*tp,void*imagep,pxim3size_t imagesize,
// const pxyz_s*dimp,pxim1size_t ypitch,pxim2size_t zpitch,const pximagedata_s*datap,
// const pximagehints_s*hintp,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage3_memmalloc(pximage3_s*tp,void* *bufpp,
// const pxyz_s*dimp,int pixtype,int bitsused,int pixies,int pixelhint);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage3_memfree(pximage3_s*tp,void* *bufpp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport) ,__stdcall,pximage3_s*)pximage3_memmalloc2(void*bufp,
// int pixtype,int bitsused,int pixies,int pixelhint,
// pxcoord_t xdim,pxcoord_t ydim,float pixelwidth,float pixelheight,int pixelwhunits,
// pxcoord_t zdim,float pixeldepth,int pixeldunits);
void* __stdcall pximage3_memmalloc2(void* bufp, int pixtype, int bitsused, int pixies, int pixelhint, 
int xdim, int ydim, float pixelwidth, float pixelheight, int pixelwhunits, int zdim, float pixeldepth, int pixeldunits);

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage3_memfree2(pximage3_s*tp,void*bufp);
int __stdcall pximage3_memfree2(void* tp, void* bufp);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_fmemory(pximage3_s*tp,void*imagep,const pxyz_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_fmemory2(pximage3_s*tp,void*imagep,const pxyz_s*dimp,
// pxim1size_t ypitch,int pixtype,int bitsused,int pixies,int pixelhint,uint accflags,
// float pixelwidth,float pixelheight,int pixelwhunits,float pixeldepth,int pixelzunits);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_fmemdata(pximage3_s*tp,void*imagep,pxim3size_t imagesize,
// const pxyz_s*dimp,pxim1size_t ypitch,pxim2size_t zpitch,const pximagedata_s*datap,
// const pximagehints_s*hintp,uint accflags);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_converter(pximage_s*tp,pximage_s*up,
// pximagedata_s*dp,int windpassthru,int forcedirtyread,
// int forcebitsused,int fltmode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_converter(pximage3_s*tp,pximage3_s*up,
// pximagedata_s*dp,int windpassthru,int forcedirtyread,
// int forcebitsused,int fltmode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pximage_defnull(pximage_s*tp);
void __stdcall pximage_defnull(void* tp);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_defnop(pximage_s*tp,const pxy_s*dimp,
// const pximagedata_s*datap,const pximagehints_s*hintp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pximage3_defnull(pximage3_s*tp);
void __stdcall pximage3_defnull(void* tp);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_def3from2(pximage3_s*ip3,pximage_s*ip2,int windpassthru);
int __stdcall pximage_def3from2(void* ip3, void* ip2, int windpassthru);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_def2from3(pximage_s*ip2,pximage3_s*ip3,
// int xaxis,int yaxis,pxcoord_t slice,int windpassthru);
int __stdcall pximage_def2from3(void* ip2, void* ip3, int xaxis, int yaxis, int slice, int windpassthru);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_def3from3(pximage3_s*tp,pximage3_s*fip,int coefa,int coefb,int coefc,int windpassthru);
int __stdcall pximage3_def3from3(void* tp, void* fip, int coefa, int coefb, int coefc, int windpassthru);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_colorslice(pximage_s*ip3,pximage_s*ip2,int windpassthru,uint colormap,int rsvd);
int __stdcall pximage_colorslice(void* ip3, void* ip2, int windpassthru, int colormap, int rsvd);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_colorslice(pximage3_s*ip3,pximage3_s*ip2,int windpassthru,uint colormap,int rsvd);
int __stdcall pximage3_colorslice(void* ip3, void* ip2, int windpassthru, int colormap, int rsvd);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_colorconverter(pximage_s*tp,pximage_s*up,int newhint,int windpassthru);
int __stdcall pximage_colorconverter(void* tp, void* up, int newhint, int windpassthru);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage3_colorconverter(pximage3_s*tp,pximage3_s*up,int newhint,int windpassthru);
int __stdcall pximage3_colorconverter(void* tp, void* up, int newhint, int windpassthru);

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage_setwind(pximage_s*ip,pxcoord_t ulx,pxcoord_t uly,pxcoord_t lrx,pxcoord_t lry);
int __stdcall pximage_setwind(void* ip, int ulx, int uly, int lrx, int lry);

// _cDcl(__declspec(dllexport) ,__stdcall,int)pximage3_setwind(pximage3_s*ip,pxcoord_t ulx,pxcoord_t uly,pxcoord_t ulz,pxcoord_t lrx,pxcoord_t lry,pxcoord_t lrz);
int __stdcall pximage3_setwind(void* ip, int ulx, int uly, int ulz, int lrx, int lry, int lrz);

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_file(pximage_s*tp,void**handlep,const char*filename,const char*filemode,
// const pxy_s*dimp,int pixtype,int bitsused,
// int pixies,int pixelhint,uint buffersize);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_filedone(pximage_s*tp,void**handlep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximage_filebufio(pximage_s*tp,void*statep,
// const pxy_s*dimp,const pximagedata_s*datap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,char*)pxerrnomesg(int err);
char* __stdcall pxerrnomesg(int err);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixmap(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uchar*map,size_t nmap);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `map' parameter has been declared expecting a dimensioned unsigned char array to be passed
int __stdcall pxip8_pixmap(int , void* sip, void* dip, unsigned char* map, __int64 nmap);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixmaps(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint16*map,size_t nmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixmapl(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint32*map,size_t nmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixmaplut(pxabortfunc_t**,pximage_s*lutip,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `lutip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixmaplut(int , void* lutip, void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixshr(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint cnt);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixshr(int , void* sip, void* dip, int cnt);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixshl(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint cnt);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixshl(int , void* sip, void* dip, int cnt);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixand(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint mask);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixand(int , void* sip, void* dip, int mask);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixor(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint mask);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixor(int , void* sip, void* dip, int mask);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixxor(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint mask);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixxor(int , void* sip, void* dip, int mask);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixneg(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixneg(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixadd(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int constant,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixadd(int , void* sip, void* dip, int constant, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixscale(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint numerator,uint denominator);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixscale(int , void* sip, void* dip, int numerator, int denominator);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixthreshold(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uint lowbound,uint highbound,uint newvalue);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixthreshold(int , void* sip, void* dip, int lowbound, int highbound, int newvalue);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixthreshold2(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uint lowbound,uint highbound,uint newvalue,uint altvalue);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixthreshold2(int , void* sip, void* dip, int lowbound, int highbound, int newvalue, 
int altvalue);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixcontrast(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint lowbound,uint highbound);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixcontrast(int , void* sip, void* dip, int lowbound, int highbound);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pixcontrast(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double lowbound,double highbound);
// The `noname1' parameter has been declared expecting a 0 to be passed
int __stdcall pxipf_pixcontrast(int , void* sip, void* dip, double lowbound, double highbound);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixcontrastpivot(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint pivot2,double coef);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixcontrastpivot(int , void* sip, void* dip, int pivot2, double coef);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixthreshold3(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uint lowbound[],uint highbound[],uint invalue[],uint outvalue[],int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lowbound' parameter has been declared expecting a dimensioned int array to be passed
// The `highbound' parameter has been declared expecting a dimensioned int array to be passed
// The `invalue' parameter has been declared expecting a dimensioned int array to be passed
// The `outvalue' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pixthreshold3(int , void* sip, void* dip, unsigned int lowbound[], unsigned int highbound[], unsigned int invalue[], 
unsigned int outvalue[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixgamma(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double gamma);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixgamma(int , void* sip, void* dip, double gamma);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pixadd(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double constant,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
int __stdcall pxipf_pixadd(int , void* sip, void* dip, double constant, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pixscale(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double constant,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
int __stdcall pxipf_pixscale(int , void* sip, void* dip, double constant, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixmsb(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixmsb(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixiemin(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixiemin(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixiemax(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixiemax(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixieave(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixieave(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixiecopy(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint pixiesrc,uint pixiedstmap);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixiecopy(int , void* sip, void* dip, int pixiesrc, int pixiedstmap);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixcontrastperc(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uint lowperc,uint highperc,uint*lowboundp,uint*highboundp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixset(pxabortfunc_t**,pximage_s*dip,uint32 value);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pixset(int , void* dip, int value);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixset3(pxabortfunc_t**,pximage_s*dip,uint values[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `values' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pixset3(int , void* dip, unsigned int values[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pixset3(pxabortfunc_t**,pximage_s*dip,double values[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `values' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxipf_pixset3(int , void* dip, double values[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_halftsum(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_halftsum(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_halftonedot(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int dotsize);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_halftonedot(int , void* sip, void* dip, int dotsize);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_dither(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint ditherbits);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_dither(int , void* sip, void* dip, int ditherbits);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_dithernormal(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double variance);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_dithernormal(int , void* sip, void* dip, double variance);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_noiseadd(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int type,uint32 seed,double mean,double variance,double parm0,double parm1);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_noiseadd(int , void* sip, void* dip, int type, int seed, double mean, double variance, double parm0, 
double parm1);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copy(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copy(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyexchange(pxabortfunc_t**,pximage_s*ip1,pximage_s*ip2);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip1' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `ip2' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyexchange(int , void* ip1, void* ip2);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyreverse(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyreverse(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyshift(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int xshift,int yshift);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyshift(int , void* sip, void* dip, int xshift, int yshift);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyconvert(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int xsb,int xflt,int rsvd3,int rsvd4);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyconvert(int , void* sip, void* dip, int xsb, int xflt, int rsvd3, int rsvd4);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyslice(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int spixie,int dpixie);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyslice(int , void* sip, void* dip, int spixie, int dpixie);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copycolorconvert(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int rsvd1,int newhint,int rsvd2,int rsvd3);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copycolorconvert(int , void* sip, void* dip, int rsvd1, int newhint, int rsvd2, int rsvd3);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairadd(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairadd(int , void* s1p, void* s2p, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairsub(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairsub(int , void* s1p, void* s2p, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairave(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairave(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairxor(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairxor(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairand(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairand(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairor(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairor(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairinsdiff(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairinsdiff(int , void* s1p, void* s2p, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairinsert(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairinsert(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairprod(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,int coef[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `coef' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pairprod(int , void* s1p, void* s2p, void* dip, int mode, int coef[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairratio(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,int coef[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `coef' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pairratio(int , void* s1p, void* s2p, void* dip, int mode, int coef[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairmin(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairmin(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairmax(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairmax(int , void* s1p, void* s2p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairoverlay(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,uint key[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `key' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pairoverlay(int , void* s1p, void* s2p, void* dip, int mode, unsigned int key[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pairratio(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,double coef[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `coef' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxipf_pairratio(int , void* s1p, void* s2p, void* dip, int mode, double coef[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pairprod(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,double coef[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `coef' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxipf_pairprod(int , void* s1p, void* s2p, void* dip, int mode, double coef[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pairoverlay(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*dip,int mode,double key[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `key' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxipf_pairoverlay(int , void* s1p, void* s2p, void* dip, int mode, double key[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pairblend(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*s3p,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s3p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_pairblend(int , void* s1p, void* s2p, void* s3p, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_tripletnormalize(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pximage_s*s3p,pximage_s*dip,uint32 targetvalue,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s3p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_tripletnormalize(int , void* s1p, void* s2p, void* s3p, void* dip, int targetvalue, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_contrastmatch(pxabortfunc_t**,pximage_s*ip,pximage_s*jp,pximage_s*op);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `jp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_contrastmatch(int , void* ip, void* jp, void* op);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawchars(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,char*cp,
// size_t cn,int width,int height,int hlead,int vlead,
// int groundtype,uint background[],uint foreground[],int antialias);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `background' parameter has been declared expecting a dimensioned int array to be passed
// The `foreground' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_drawchars(int , void* ip, int xyp[], char* cp, __int64 cn, int width, int height, int hlead, 
int vlead, int groundtype, unsigned int background[], unsigned int foreground[], int antialias);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawchars3(pxabortfunc_t**abortp,pximage_s*ip,pxy_s*xyp,
// double angle,char cp[],size_t cn,int width,int height,int hlead,int vlead,
// int mode,uint values[],uint backvalues[],pximage_s*bufip,pxim2size_t*cntp);
// The `abortp' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cp' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `backvalues' parameter has been declared expecting a dimensioned int array to be passed
// The `bufip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawchars3(int abortp, void* ip, int xyp[], double angle, char cp[], __int64 cn, int width, 
int height, int hlead, int vlead, int mode, unsigned int values[], unsigned int backvalues[], void* bufip, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawchars4(pxabortfunc_t**abortp,pximage_s*ip,pxy_s*xyp,double angle,
// char*charbuf,int width,int height,int baseline,int hlead,int vlead,
// int mode,uint values[],uint backvalues[],pximage_s*bufip,pxim2size_t*cntp);
// The `abortp' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `backvalues' parameter has been declared expecting a dimensioned int array to be passed
// The `bufip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawchars4(int abortp, void* ip, int xyp[], double angle, char* charbuf, int width, int height, 
int baseline, int hlead, int vlead, int mode, unsigned int values[], unsigned int backvalues[], void* bufip, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawchars5(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,
// double angle,HFONT hFont,char cp[],size_t cn,int awidth,int aheight,
// int hlead,int vlead,int mode,uint values[],uint backvalues[],pximage_s*bufip,pxim2size_t*cntp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_patterncos(pxabortfunc_t**,pximage_s*ip,pxip8pat_s*p);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_patterngaussian(pxabortfunc_t**,pximage_s*ip,pxip8pat_s*p);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_patternfiducial(pxabortfunc_t**,pximage_s*ip,pxip8pat_s*pp,
// uint background[],uint foreground[],int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_patterns(pxabortfunc_t**,pximage_s*ip,pxip8pat_s*p,int type);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_patternalign(pxabortfunc_t**,pximage_s*ip,int type);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_patternalign(int , void* ip, int type);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_testpattern(pxabortfunc_t**,pximage_s*ip,int type,int amplitude);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_testpattern(int , void* ip, int type, int amplitude);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_spatialquantize(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int xsiz,int ysiz,int shrink);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_spatialquantize(int , void* ip, void* op, int xsiz, int ysiz, int shrink);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizeintensity(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int xgran,int ygran,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_normalizeintensity(int , void* ip, void* op, int xgran, int ygran, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_masscenterbin(pxabortfunc_t**,pximregion_s*rp,ulong*area,ulong*xsum,ulong*ysum,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_masscenter(pxabortfunc_t**,pximregion_s*rp,double*mass,double*xcenter,double*ycenter);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_masscenterpow(pxabortfunc_t**,pximregion_s*rp,double*mass,double*xcenter,double*ycenter,double pow,int rsvd);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_masscenterbin(pxabortfunc_t**,pximage_s*ip,ulong*area,ulong*xsum,ulong*ysum);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `area' parameter has been declared expecting a dimensioned long array to be passed
// The `xsum' parameter has been declared expecting a dimensioned long array to be passed
// The `ysum' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_masscenterbin(int , void* ip, unsigned long area[], unsigned long xsum[], unsigned long ysum[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_masscenter(pxabortfunc_t**,pximage_s*ip,double*mass,double*xcenter,double*ycenter);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `mass' parameter has been declared expecting a dimensioned double array to be passed
// The `xcenter' parameter has been declared expecting a dimensioned double array to be passed
// The `ycenter' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxip8_masscenter(int , void* ip, double mass[], double xcenter[], double ycenter[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_masscenterpow(pxabortfunc_t**,pximage_s*ip,double*mass,double*xcenter,double*ycenter,double pow,int rsvd);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `mass' parameter has been declared expecting a dimensioned double array to be passed
// The `xcenter' parameter has been declared expecting a dimensioned double array to be passed
// The `ycenter' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxip8_masscenterpow(int , void* ip, double mass[], double xcenter[], double ycenter[], double pow, 
int rsvd);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_moments(pxabortfunc_t**,pximage_s*ip,int aoiorigin,
// pxip8moments_s*momp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_momentsf(pxabortfunc_t**,pximage_s*ip,int aoiorigin,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void(__stdcall*mapxyhvfunc)(void*,pxyd_s*,pxyd_s*),
// void*mapzirefp,void*mapxyhvrefp,pxip8moments_s*momp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_moments(pxabortfunc_t**,pximregion_s*rp,int rsvd,
// pxip8moments_s*momp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_momentsf(pxabortfunc_t**,pximregion_s*rp,int rsvd,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void(__stdcall*mapxyhvfunc)(void*,pxyd_s*,pxyd_s*),
// void*mapzirefp,void*mapxyhvrefp,pxip8moments_s*momp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3kirsch(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3kirsch(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_2x2roberts(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_2x2roberts(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3sobel(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3sobel(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3sobela(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3sobela(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3ksrthin(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3ksrthin(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3median(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3median(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3medianw(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3medianw(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3binmedian(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3binmedian(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3ranklow(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3ranklow(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3rankhigh(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3rankhigh(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3life(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3life(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3lowpass(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint weight);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3lowpass(int , void* sip, void* dip, int weight);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3lowpassf(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3lowpassf(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3sharpenl(pxabortfunc_t**,pximage_s*sip,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3sharpenl(int , void* sip, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3lowpassmear(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,uint threshold);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3lowpassmear(int , void* sip, void* dip, int threshold);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_NxNdynthreshold(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int N,int low,int high,uint npv);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_NxNdynthreshold(int , void* sip, void* dip, int N, int low, int high, int npv);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_NxNcontrastinvert(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int N);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_NxNcontrastinvert(int , void* sip, void* dip, int N);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_NxNconvolve(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int N,
// int*coef,int offset,int divisor,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_NxNconvolvef(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int N,
// float*coef,double add,double div,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `coef' parameter has been declared expecting a dimensioned float array to be passed
int __stdcall pxip8_NxNconvolvef(int , void* sip, void* dip, int N, float coef[], double add, double div, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histab(pxabortfunc_t**,pximage_s*ip,pxip8histab_s*hp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histab2(pxabortfunc_t**,pximage_s*ip,pxim2size_t*count,size_t ncount);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `count' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_histab2(int , void* ip, long count[], __int64 ncount);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histab3(pxabortfunc_t**,pximage_s*ip,pxim2size_t*count,size_t ncount,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `count' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_histab3(int , void* ip, long count[], __int64 ncount, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histabpair(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,pxim2size_t*count,size_t ncount,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `count' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_histabpair(int , void* s1p, void* s2p, long count[], __int64 ncount, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histstat(pxip8histab_s*hp,pxip8histstat_s*sp,
// pxip8histperc_s*pp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histstatf(pxip8histab_s*hp,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void*mapfuncrefp,pxip8histstat_s*sp,
// pxip8histperc_s*pp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histstat2(pximage_s*ip,pxim2size_t*count,size_t ncount,
// pxip8histstat_s*sp,pxip8histperc_s*pp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histstat2f(pximage_s*ip,pxim2size_t*count,size_t ncount,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void*mapfuncrefp,pxip8histstat_s*sp,
// pxip8histperc_s*pp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawline(pxabortfunc_t**,pximage_s*ip,pxy_s*sxyp,pxy_s*exyp,
// int dotspace,int thickness,int mode,uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `exyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawline(int , void* ip, int sxyp[], int exyp[], int dotspace, int thickness, int mode, 
unsigned int values[], void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawbox(pxabortfunc_t**,pximage_s*ip,pxywindow_s*wp,
// int dotspace,int thickness,int mode,uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `wp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawbox(int , void* ip, int wp[], int dotspace, int thickness, int mode, unsigned int values[], 
void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawcoord(pxabortfunc_t**,pximage_s*ip,pximage_s*cp,
// int dotspace,int thickness,int mode,uint values[],pximage_s*pixibuf,pxim2size_t skip,pxim2size_t cnt,int dir);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_drawcoord(int , void* ip, void* cp, int dotspace, int thickness, int mode, unsigned int values[], 
void* pixibuf, long skip, long cnt, int dir);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawarrow(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,double length,
// double angle,double aspect,int hform,double hlength,
// double hangle,int tform,double tlength,double tangle,
// int dotspace,int thickness,int mode,uint values[],
// pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawarrow(int , void* ip, int xyp[], double length, double angle, double aspect, int hform, 
double hlength, double hangle, int tform, double tlength, double tangle, int dotspace, int thickness, int mode, unsigned int values[], 
void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawpincushionbox(pxabortfunc_t**,pximage_s*ip,pxywindow_s*wp,pxy_s*xyp,
// double factor,int order,int dotspace,int thickness,int mode,uint values[],
// pximage_s*bufip,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `wp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `bufip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawpincushionbox(int , void* ip, int wp[], int xyp[], double factor, int order, int dotspace, 
int thickness, int mode, unsigned int values[], void* bufip, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawellipse(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,int xr,int yr,
// double theta,int dotspace,int thickness,int mode,uint values[],
// pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawellipse(int , void* ip, int xyp[], int xr, int yr, double theta, int dotspace, int thickness, 
int mode, unsigned int values[], void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawellipsesect(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,int xr,int yr,
// double theta,double starta,double enda,int dotspace,int thickness,int mode,uint values[],
// pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawellipsesect(int , void* ip, int xyp[], int xr, int yr, double theta, double starta, double enda, 
int dotspace, int thickness, int mode, unsigned int values[], void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyinterpolate(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// double xsupport,double ysupport,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyinterpolate(int , void* ip, void* op, double xsupport, double ysupport, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyinterpbilinear(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int mode,int orient);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyinterpbilinear(int , void* ip, void* op, int mode, int orient);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morperode(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uchar*msearray,int msearraydim,int rotation,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `msearray' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_morperode(int , void* sip, void* dip, unsigned char* msearray, int msearraydim, int rotation, 
int resultmap, long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morpdilate(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uchar*msearray,int msearraydim,int rotation,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `msearray' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_morpdilate(int , void* sip, void* dip, unsigned char* msearray, int msearraydim, int rotation, 
int resultmap, long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morpopen(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uchar*msearray,int msearraydim,int rotation,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `msearray' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_morpopen(int , void* sip, void* dip, unsigned char* msearray, int msearraydim, int rotation, 
int resultmap, long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morpclose(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uchar*msearray,int msearraydim,int rotation,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `msearray' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_morpclose(int , void* sip, void* dip, unsigned char* msearray, int msearraydim, int rotation, 
int resultmap, long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morphitmiss(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uchar*msearray,int msearraydim,int rotation,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `msearray' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_morphitmiss(int , void* sip, void* dip, unsigned char* msearray, int msearraydim, int rotation, 
int resultmap, long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_binmaxisthin(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// void*unused0,int unused1,int unused2,
// int resultmap,pxim2size_t*pixcountp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `pixcountp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_binmaxisthin(int , void* sip, void* dip, void* unused0, int unused1, int unused2, int resultmap, 
long pixcountp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacelinetofield(pxabortfunc_t**,pximage_s*ip,pximage_s*op);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacelinetofield(int , void* ip, void* op);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacefieldtoline(pxabortfunc_t**,pximage_s*ip,pximage_s*op);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacefieldtoline(int , void* ip, void* op);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacepairave(pxabortfunc_t**,pximage_s*ip,pximage_s*op);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacepairave(int , void* ip, void* op);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacemodsingular(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int mode,int threshold,int midwt,int endwt);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacemodsingular(int , void* ip, void* op, int mode, int threshold, int midwt, int endwt);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacepairswap(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacepairswap(int , void* ip, void* op, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacepairdup(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacepairdup(int , void* ip, void* op, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacelineshift(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int dir,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacelineshift(int , void* ip, void* op, int dir, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilacelinetoNfield(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int nfield);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilacelinetoNfield(int , void* ip, void* op, int nfield);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ilaceNfieldtoline(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int nfield);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ilaceNfieldtoline(int , void* ip, void* op, int nfield);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_geotranrotate(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// double angle,double saspect,double daspect,pxy_s*origin,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `origin' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxip8_geotranrotate(int , void* sip, void* dip, double angle, double saspect, double daspect, int origin[], 
int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_geotranrotate2(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// double angle,double saspect,double daspect,pxyd_s*origin,double xoffset,double yoffset,
// int rsvd1,int rsvd2,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_geotranwarp(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// size_t nfiduc,pxy_s*sfiduc,pxy_s*dfiduc,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sfiduc' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `dfiduc' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxip8_geotranwarp(int , void* sip, void* dip, __int64 nfiduc, int sfiduc[], int dfiduc[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_geotranwarp2(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// size_t nfiduc,pxyd_s*sfiduc,pxyd_s*dfiduc,int mode,int order,int rsvd);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_geotranpincushion(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// int order,double coef[],double aspect,pxyd_s*originp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fftsizes(pximage_s*gip,pxy_s*dimp,int*typep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fft(pxabortfunc_t**,pximage_s*gip,pximage_s*cip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `gip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_fft(int , void* gip, void* cip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ffti(pxabortfunc_t**,pximage_s*cip,pximage_s*gip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `cip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `gip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_ffti(int , void* cip, void* gip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fftlogmag(pxabortfunc_t**,pximage_s*cip,pximage_s*gip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `cip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `gip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_fftlogmag(int , void* cip, void* gip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fftlmagscale(pxabortfunc_t**,pximage_s*gip,pximage_s*cip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `gip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_fftlmagscale(int , void* gip, void* cip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fftfilterz(pxabortfunc_t**,pximage_s*gip,pximage_s*cip,int mode,double arg);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `gip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_fftfilterz(int , void* gip, void* cip, int mode, double arg);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_timefreqanalysis(pxabortfunc_t**,pximage3_s*si3p,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `si3p' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_timefreqanalysis(int , void* si3p, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fftcimage(pximage_s*tp,pximage_s*ip,pxy_s*dimp);
// The `tp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dimp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxip8_fftcimage(void* tp, void* ip, int dimp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawiconinit(pximage_s*imp,pxy_s*imxy,uchar*iconbit,
// pxy_s*icondim,pxy_s*iconorg,int iconmode,
// void**handlepp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawiconhit(pximage_s*imp,void*handlep,
// int mode,uint values[],pximage_s*pixibuf);
// The `imp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_drawiconhit(void* imp, void* handlep, int mode, unsigned int values[], void* pixibuf);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawiconhitw(pximage_s*imp,void*handlep,
// int wait,int mode,pximage_s*pixibuf);
// The `imp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_drawiconhitw(void* imp, void* handlep, int wait, int mode, void* pixibuf);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawiconfree(pximage_s*imp,void**handlepp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawicon(pximage_s*imp,pxy_s*imxy,uchar*iconbit,
// pxy_s*icondim,pxy_s*iconorg,int iconmode,
// int mode,uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// The `imp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `imxy' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `iconbit' parameter has been declared expecting a dimensioned unsigned char array to be passed
// The `icondim' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `iconorg' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawicon(void* imp, int imxy[], unsigned char* iconbit, int icondim[], int iconorg[], int iconmode, 
int mode, unsigned int values[], void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_signature(pxabortfunc_t**,pximage_s*ip,uint16*sigp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_paintregion(pxabortfunc_t**,pximregion_s*rp,int pattern,int*patparm,
// int groundtype,uint background[],uint foreground[],int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_drawboundary(pxabortfunc_t**,pximregion_s*rp,int rsvd,int dotspace,int thickness,
// int mode,uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_drawbezier(pxabortfunc_t**,pximage_s*ip,int m,pxy_s*xyp,
// int dotspace,int thickness,int mode,uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `values' parameter has been declared expecting a dimensioned int array to be passed
// The `pixibuf' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_drawbezier(int , void* ip, int m, int xyp[], int dotspace, int thickness, int mode, 
unsigned int values[], void* pixibuf, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyskewlr(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int mode,int skewtop,int skewbot);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyskewlr(int , void* ip, void* op, int mode, int skewtop, int skewbot);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyskewud(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// int mode,int skewleft,int skewright);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyskewud(int , void* ip, void* op, int mode, int skewleft, int skewright);

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_xlatetoscanlist(pxabortfunc_t**,pximregion_s*rp,pximregion_s**npp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_xlaterecttopoly(pximregion_s*rp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_regionbounds(pximregion_s*rp,pxywindow_s*wp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_regionarea(pximregion_s*rp,pxim2size_t*areap,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_xlatetopath(pxabortfunc_t**,pximregion_s*rp,pximregion_s**npp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxirp_regionfree(pximregion_s**npp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_regionexport(pxabortfunc_t**,pximregion_s*srp,const char*pathname,const char*filemode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_regionimport(pxabortfunc_t**,pximregion_s**srpp,const char*pathname,const char*filemode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_connectregion(pxabortfunc_t**,pximage_s*mip,pxy_s*xyp,
// uchar*testmap,size_t nmap,int testbit,pximregion_s**npp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_connectregionv(pxabortfunc_t**,pximage_s*mip,pxy_s*xyp,
// int cond,uint value,pximregion_s**npp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_followregionv(pxabortfunc_t**,pximage_s*ip,pxy_s*,pxy_s*xyp,
// int cond,uint value,int mode,pximregion_s**npp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_connectregion2v(pxabortfunc_t**,pximage_s*sip,pxy_s*xyp,
// int cond,uint value,int clear,int mode,pximregion_s**npp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximpxirprectacc(pximage_s*tp,pximregion_s*rp,uint pad);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pximpxirprectacc2(pximage_s*tp,pximregion_s*rp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_histab(pxabortfunc_t**,pximregion_s*rp,pxip8histab_s*hp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_histab2(pxabortfunc_t**,pximregion_s*rp,pxim2size_t*count,size_t ncount);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_histab3(pxabortfunc_t**,pximregion_s*rp,pxim2size_t*count,size_t ncount,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_histabpair(pxabortfunc_t**,pximregion_s*r1p,pximregion_s*r2p,pxim2size_t*count,size_t ncount,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixmap(pxabortfunc_t**,pximregion_s*srp,pximregion_s*drp,uchar*map,size_t nmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixmaps(pxabortfunc_t**,pximregion_s*srp,pximregion_s*drp,uint16*map,size_t nmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixmapl(pxabortfunc_t**,pximregion_s*srp,pximregion_s*drp,uint32*map,size_t nmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixshr(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint cnt);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixshl(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint cnt);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixand(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint mask);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixor(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint mask);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixxor(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint mask);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixneg(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixadd(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,int constant,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixscale(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint numerator,uint denominator);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixthreshold(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint lowbound,uint highbound,uint newvalue);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixthreshold2(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint lowbound,uint highbound,uint newvalue,uint altvalue);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixcontrast(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint lowbound,uint highbound);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirpf_pixcontrast(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// double lowbound,double highbound);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixcontrastpivot(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint pivot2,double coef);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixthreshold3(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint lowbound[],uint highbound[],uint invalue[],uint outvalue[],int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixgamma(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,double gamma);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirpf_pixadd(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,double constant,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirpf_pixscale(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,double constant,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixmsb(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixiemin(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixiemax(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixieave(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixiecopy(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,uint pixiesrc,uint pixiedstmap);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixcontrastperc(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip,
// uint lowperc,uint highperc,uint*lowboundp,uint*highboundp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixset(pxabortfunc_t**,pximregion_s*dip,uint32 value);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixset3(pxabortfunc_t**,pximregion_s*dip,uint values[]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirpf_pixset3(pxabortfunc_t**,pximregion_s*dip,double values[]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_copy(pxabortfunc_t**,pximregion_s*sip,pximregion_s*dip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_drawpath(pxabortfunc_t**,pximregion_s*rp,uint skipN,uint drawN,
// pxy_s*fxy,pxy_s*exy,int dotspace,int thickness,int mode,
// uint values[],pximage_s*pixibuf,pxim2size_t*cntp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_pathcreate(pximregion_s**rpp,pxy_s*start);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_pathextend(pximregion_s**rpp,pxy_s*exy);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_pathextend1(pximregion_s**rpp,pxy_s*exy);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_pathcompress(pximregion_s*rp,pximregion_s**rpp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_findpixel(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,
// uchar*testmap,size_t nmap,int testbit,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `testmap' parameter has been declared expecting a dimensioned unsigned char array to be passed
int __stdcall pxip8_findpixel(int , void* ip, int xyp[], unsigned char* testmap, __int64 nmap, int testbit, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_findpixelv(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,
// int cond,uint value,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxip8_findpixelv(int , void* ip, int xyp[], int cond, int value, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_histfit(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// pxip8histab_s*hp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binread(pxabortfunc_t**,pximage_s*ip,const char*pathname,off_t skip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_binread(int , void* ip, char* pathname, long skip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binwrite(pxabortfunc_t**,pximage_s*ip,const char*pathname);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_binwrite(int , void* ip, char* pathname);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bin1read(pxabortfunc_t**,pximage_s*ip,const char*pathname,int mode,off_t skip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_bin1read(int , void* ip, char* pathname, int mode, long skip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bin1write(pxabortfunc_t**,pximage_s*ip,const char*pathname,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_bin1write(int , void* ip, char* pathname, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binreadseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,int mode,off_t skip1,off_t skip2);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_binreadseq(int , void* ip, char* pathname, int mode, long skip1, long skip2);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binwriteseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,int emode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_binwriteseq(int , void* ip, char* pathname, int emode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bin1writeseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_bin1writeseq(int , void* ip, char* pathname, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bin1readseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,int mode,off_t skip1,off_t skip2);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_bin1readseq(int , void* ip, char* pathname, int mode, long skip1, long skip2);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binwriteseqinit(pxabortfunc_t**,void**handlep,const char*pathname,pximage_s*ip,int mode,int rsvd1,int rsvd2,long nimages);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binwriteseqadd(pxabortfunc_t**,void**handlep,const char*pathname,pximage_s*ip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_binwriteseqdone(pxabortfunc_t**,void**handlep,const char*pathname);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_hexread(pxabortfunc_t**,pximage_s*ip,const char*pathname);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_hexread(int , void* ip, char* pathname);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_hexwrite(pxabortfunc_t**,pximage_s*ip,const char*pathname,char linedelim);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_hexwrite(int , void* ip, char* pathname, int linedelim);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_fileinfo(const char*pathname,pximfileinfo_s*infop,long subfile,int mode);
// The `infop' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_fileinfo(char* pathname, void* infop, long subfile, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_fileinfoN(const char*pathname,pximfileinfo_s info[],size_t infoN,long subfile,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxio8_fileinfodone(pximfileinfo_s*infop);
// The `infop' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
void __stdcall pxio8_fileinfodone(void* infop);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifwrite(pxabortfunc_t**,pximage_s*ip,pximage_s*lip,
// const char*pathname,int bits,int lutbits,long subfile,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_tifwrite(int , void* ip, void* lip, char* pathname, int bits, int lutbits, long subfile, 
void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifread(pxabortfunc_t**,pximage_s*ip,pximage_s*lip,
// const char*pathname,long subfile,pxywindow_s*windp,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_tifread(int , void* ip, void* lip, char* pathname, long subfile, int windp[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifwriteseq(pxabortfunc_t**,pximage3_s*ip,pximage_s*lip,
// const char*pathname,int bits,int lutbits,long subfile,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_tifwriteseq(int , void* ip, void* lip, char* pathname, int bits, int lutbits, long subfile, 
void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifreadseq(pxabortfunc_t**,pximage3_s*ip,pximage_s*lip,
// const char*pathname,long subfile,pxywindow_s*windp,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_tifreadseq(int , void* ip, void* lip, char* pathname, long subfile, int windp[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifwriteseqinit(pxabortfunc_t**,void**handlep,const char*pathname,pximage_s*ip,
// pximage_s*lutip,int ipbits,int lutbits,pximfileinfo_s*parmp,long nimages);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifwriteseqadd(pxabortfunc_t**,void**handlep,const char*pathname,pximage_s*ip,
// pximage_s*lutip,int ipbits,int lutbits,pximfileinfo_s*parmp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tifwriteseqdone(pxabortfunc_t**,void**handlep,const char*pathname);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bmpwrite(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lip,const char*pathname,int bits,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_bmpwrite(int , void* ip, void* lip, char* pathname, int bits, void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_bmpread(pxabortfunc_t**,pximage_s*ip,pximage_s*lip,
// const char*pathname,pxywindow_s*windp,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_bmpread(int , void* ip, void* lip, char* pathname, int windp[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviwriteseq(pxabortfunc_t**,pximage3_s*ip,
// pximage_s*lip,const char*pathname,int bits,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_aviwriteseq(int , void* ip, void* lip, char* pathname, int bits, void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviodmlwriteseq(pxabortfunc_t**,pximage3_s*ip,
// pximage_s*lip,const char*pathname,int bits,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_aviodmlwriteseq(int , void* ip, void* lip, char* pathname, int bits, void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviwriteseq2(pxabortfunc_t**,pximage3_s*ip,
// pximage_s*lip,const char*pathname,int bits,
// uint framecnt,uint framesecs,long biXPelsPerMeter,long biYPelsPerMeter,
// int rsvd1,int rsvd2,int rsvd3,int rsvd4);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_aviwriteseq2(int , void* ip, void* lip, char* pathname, int bits, int framecnt, int framesecs, 
long biXPelsPerMeter, long biYPelsPerMeter, int rsvd1, int rsvd2, int rsvd3, int rsvd4);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_avireadseq(pxabortfunc_t**,pximage3_s*ip,pximage_s*lip,
// const char*pathname,long subfile,pxywindow_s*windp,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_avireadseq(int , void* ip, void* lip, char* pathname, long subfile, int windp[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviwriteseqinit(pxabortfunc_t**,void**handlep,const char*pathname,
// pximage_s*ip,pximage_s*lip,int bits,pximfileinfo_s*parmp,long nimages);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviodmlwriteseqinit(pxabortfunc_t**,void**handlep,const char*pathname,
// pximage_s*ip,pximage_s*lip,int bits,pximfileinfo_s*parmp,long nimages);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviwriteseqadd(pxabortfunc_t**,void**handlep,const char*pathname,
// pximage_s*ip,pximage_s*lip,int bits,pximfileinfo_s*parmp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_aviwriteseqdone(pxabortfunc_t**,void**handlep,const char*pathname);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_pcxwrite(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lip,const char*pathname,int bits,int rsvd);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_pcxwrite(int , void* ip, void* lip, char* pathname, int bits, int rsvd);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_fitswrite(pxabortfunc_t**,pximage_s*ip,
// pximage_s*rsvd1,const char*pathname,int bits,int rsvd2,long rsvd3,long rsvd4,
// pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `rsvd1' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_fitswrite(int , void* ip, void* rsvd1, char* pathname, int bits, int rsvd2, long rsvd3, 
long rsvd4, void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_fitsread(pxabortfunc_t**,pximage_s*ip,pximage_s*rsvd1,
// const char*pathname,long rsvd2,long rsvd3,pxywindow_s*windp,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `rsvd1' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_fitsread(int , void* ip, void* rsvd1, char* pathname, long rsvd2, long rsvd3, int windp[], 
int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_tgawrite(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lip,const char*pathname,int rsvd2,int rsvd);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_tgawrite(int , void* ip, void* lip, char* pathname, int rsvd2, int rsvd);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_jpegwrite(pxabortfunc_t**,pximage_s*ip,
// void*rsvd1,const char*pathname,int bits,pximfileinfo_s*parmp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `parmp' parameter can't be easily used, but some some functions consider it optional and will accept passing a 0
int __stdcall pxio8_jpegwrite(int , void* ip, void* rsvd1, char* pathname, int bits, void* parmp);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_jpegread(pxabortfunc_t**abortp,pximage_s*ip,
// void*rsvd1,const char*pathname,pxywindow_s*windp,int mode);
// The `abortp' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxio8_jpegread(int abortp, void* ip, void* rsvd1, char* pathname, int windp[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_jpegwrite2(pxabortfunc_t**,pximage_s*ip,void*rsvd,const char*pathname,
// int bits,uint dotsUnits,uint dotsPerHUnit,uint dotsPerVUnit,int quality,
// int rsvd1,int rsvd2,int rsvd3,int rsvd4,char*comment,char*rsvd5,char*rsvd6);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_jpegwrite2(int , void* ip, void* rsvd, char* pathname, int bits, int dotsUnits, int dotsPerHUnit, 
int dotsPerVUnit, int quality, int rsvd1, int rsvd2, int rsvd3, int rsvd4, char* comment, char* rsvd5, char* rsvd6);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciiwrite(pxabortfunc_t**,pximage_s*ip,const char*pathname,char coldelim,char linedelim,int maxpixline);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_asciiwrite(int , void* ip, char* pathname, int coldelim, int linedelim, int maxpixline);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciiread(pxabortfunc_t**,pximage_s*ip,const char*pathname,char linedelim);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_asciiread(int , void* ip, char* pathname, int linedelim);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciiwriteseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,char coldelim,char linedelim,char imagedelim,int maxpixline);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_asciiwriteseq(int , void* ip, char* pathname, int coldelim, int linedelim, int imagedelim, 
int maxpixline);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciireadseq(pxabortfunc_t**,pximage3_s*ip,const char*pathname,char linedelim,char imagedelim);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
int __stdcall pxio8_asciireadseq(int , void* ip, char* pathname, int linedelim, int imagedelim);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciiwritecoord(pxabortfunc_t**,pximage_s*ip,const char*pathname,char*header,uint mask,char coldelim,char linedelim,int aoiorigin,int mode,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxio8_asciiwritecoord(int , void* ip, char* pathname, char* header, int mask, int coldelim, 
int linedelim, int aoiorigin, int mode, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_asciireadcoord(pxabortfunc_t**,pximage_s*ip,const char*pathname,uint mask,char commentdelim,char linedelim,int aoiorigin,int mode,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxio8_asciireadcoord(int , void* ip, char* pathname, int mask, int commentdelim, int linedelim, 
int aoiorigin, int mode, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyreplic(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// int xsiz,int ysiz,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyreplic(int , void* sip, void* dip, int xsiz, int ysiz, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlaceshuffle(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlaceshuffle(int , void* ip, void* op, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlaceunshuffle(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlaceunshuffle(int , void* ip, void* op, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlacecolumntohalves(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlacecolumntohalves(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlacehalvestocolumn(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlacehalvestocolumn(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlacecolumntoNsection(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode,int nsection);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlacecolumntoNsection(int , void* sip, void* dip, int mode, int nsection);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_xlaceNsectiontocolumn(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode,int nsection);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_xlaceNsectiontocolumn(int , void* sip, void* dip, int mode, int nsection);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_smptevitcdecode(pxabortfunc_t**,pximage_s*sip,ulong pixfreq,
// int mode,struct pxip8smptevitc*vitcp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp_regionshapef(pxabortfunc_t**,pximregion_s*rp,
// void(__stdcall*mapxyhvfunc)(void*,pxyd_s*,pxyd_s*),
// void(__stdcall*maphvxyfunc)(void*,pxyd_s*,pxyd_s*),
// void*mapfuncrefp,pxirpshape_s*sp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_calibxyhv(int mode,int order,pxyd_s*xy,pxyd_s*hv,void**spp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_calibxyhvdone(void**spp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_calibzi(int mode,int order,double*z,double*zi,void**spp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_calibzidone(void**spp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,double)pxip_calibzimap(void*vp,pxyd_s*xyp,double z);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_calibxyhvmap(void*vp,pxyd_s*xyp,pxyd_s*hvp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_calibhvxymap(void*vp,pxyd_s*hvp,pxyd_s*xyp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport) ,__stdcall,int)
// pximpxipmapi(pximage_s*tp,pximage_s*fip,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),void*mapzirefp,
// int windpassthru);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_xxmapxyhvnull(void*refp,pxyd_s*xyp,pxyd_s*hvp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,double)pxip_xxmapzinull(void*refp,pxyd_s*xyp,double i);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_copyinterpnearest(pxabortfunc_t**,pximage_s*ip,pximage_s*op,int mode,
// int orient);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_copyinterpnearest(int , void* ip, void* op, int mode, int orient);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizebackground(pxabortfunc_t**,pximage_s*sip,pximage_s*sjp,
// pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sjp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_normalizebackground(int , void* sip, void* sjp, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizespecklemask(pxabortfunc_t**,pximage_s*sip,pximage_s*sjp,
// pximage_s*dip,uchar*testmap,size_t nmap,int testbit,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sjp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `testmap' parameter has been declared expecting a dimensioned unsigned char array to be passed
int __stdcall pxip8_normalizespecklemask(int , void* sip, void* sjp, void* dip, unsigned char* testmap, __int64 nmap, int testbit, 
int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizespecklemask2(pxabortfunc_t**,pximage_s*sip,pximage_s*sjp,
// pximage_s*dip,uint testvalue,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sjp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_normalizespecklemask2(int , void* sip, void* sjp, void* dip, int testvalue, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_fractedges(double pixbuf[],int pixbufsize,int pixregion,
// int esthreshold,int mode,int edges,double edgepos[],double edgestrength[]);
// The `pixbuf' parameter has been declared expecting a dimensioned double array to be passed
// The `edgepos' parameter has been declared expecting a dimensioned double array to be passed
// The `edgestrength' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxip_fractedges(double pixbuf[], int pixbufsize, int pixregion, int esthreshold, 
int mode, int edges, double edgepos[], double edgestrength[]);

// _cDcl(__declspec(dllexport),__stdcall,void)pxip_xxfractedges(double*pix,int window,double*posp,double*sdp);
// The `pix' parameter has been declared expecting a dimensioned double array to be passed
// The `posp' parameter has been declared expecting a dimensioned double array to be passed
// The `sdp' parameter has been declared expecting a dimensioned double array to be passed
void __stdcall pxip_xxfractedges(double pix[], int window, double posp[], double sdp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_fitconic(pxyd_s points[],size_t npoints,int mode,double coniccoef[6]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_fitellipse(pxyd_s points[],size_t npoints,int mode,pxyd_s ellipse[3],double coniccoef[6]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_fithyperbola(pxyd_s points[],size_t npoints,int mode,pxyd_s ellipse[3],double coniccoef[6]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pixthresholdcnt(pxabortfunc_t**,pximage_s*ip,uint32 threshold,int mode,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_pixthresholdcnt(int , void* ip, int threshold, int mode, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxipf_pixthresholdcnt(pxabortfunc_t**,pximage_s*ip,double threshold,int mode,pxim2size_t*cntp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `cntp' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxipf_pixthresholdcnt(int , void* ip, double threshold, int mode, long cntp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxirp8_pixthresholdcnt(pxabortfunc_t**,pximregion_s*rp,uint32 threshold,int mode,pxim2size_t*cntp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxirpf_pixthresholdcnt(pxabortfunc_t**,pximregion_s*rp,double threshold,int mode,pxim2size_t*cntp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morperode3x3(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_morperode3x3(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_morpdilate3x3(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_morpdilate3x3(int , void* sip, void* dip, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_volequintensity(pxabortfunc_t**,pximage_s*ip,int threshold,int mode,
// double*sump,double*np);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `sump' parameter has been declared expecting a dimensioned double array to be passed
// The `np' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxip8_volequintensity(int , void* ip, int threshold, int mode, double sump[], double np[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_print(pxabortfunc_t**,pximage_s*ip,struct pxio8print*pp,
// int(__stdcall*printfunc)(void*statep,uchar*datap,size_t n),
// void*funcstatep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizemeanline(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// uint numerator,uint denominator,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_normalizemeanline(int , void* ip, void* op, int numerator, int denominator, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_normalizemeancolumn(pxabortfunc_t**,pximage_s*ip,pximage_s*op,
// uint numerator,uint denominator,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `op' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_normalizemeancolumn(int , void* ip, void* op, int numerator, int denominator, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_averagebufs(pxabortfunc_t**,pximage3_s*si3p,pximage_s*dip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `si3p' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_averagebufs(int , void* si3p, void* dip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_integratebufs(pxabortfunc_t**,pximage3_s*si3p,pximage_s*dip,
// pxcoord_t divisor,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `si3p' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_integratebufs(int , void* si3p, void* dip, int divisor, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_recursiveaverage(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// pximage_s*dap,int divisor,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dap' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_recursiveaverage(int , void* sip, void* dip, void* dap, int divisor, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_fifoaverage(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// pximage_s*djp,pximage_s*dsp,int divisor,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `djp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dsp' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_fifoaverage(int , void* sip, void* dip, void* djp, void* dsp, int divisor, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_multispectralaverage(pxabortfunc_t**,
// pximage_s*s1p,pximage_s*s2p,pximage_s*s3p,pximage_s*dip,
// uint values1[],uint values2[],uint values3[],int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s3p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `values1' parameter has been declared expecting a dimensioned int array to be passed
// The `values2' parameter has been declared expecting a dimensioned int array to be passed
// The `values3' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_multispectralaverage(int , void* s1p, void* s2p, void* s3p, void* dip, unsigned int values1[], 
unsigned int values2[], unsigned int values3[], int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_correlateprof(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,
// pximage_s*dip,int xsubsam,int ysubsam,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_correlateprof(int , void* s1p, void* s2p, void* dip, int xsubsam, int ysubsam, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_correlatefind(pxabortfunc_t**,pximage_s*s1p,pximage_s*s2p,
// int xsubsam,int ysubsam,int mode,size_t nrslt,struct pxip8corr*rsltp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `s1p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `s2p' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `rsltp' parameter has been declared expecting a dimensioned double array to be passed
//   with 3 array elements per desired result
//   with the  0,  3,  6, ...  elements containing the result's 'xy.xd' value
//   with the  1,  4,  7, ...  elements containing the result's 'xy.xy' value
//   with the  2,  5,  8, ...  elements containing the result's 'r' value
int __stdcall pxip8_correlatefind(int , void* s1p, void* s2p, int xsubsam, int ysubsam, int mode, __int64 nrslt, 
double rsltp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_bloblist(pxabortfunc_t**,pximage_s*ip,pxy_s*findxyp,int findcond,uint findvalue,
// int mode,pxywindow_s*bounds,uint clearvalue,struct pxip8blob*proto,
// size_t nblobs,struct pxip8blob results[],pxim2size_t*nbadblobs);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_bloblist3(pxabortfunc_t**,pximage_s*ip,pxy_s*findxyp,int findcond,uint findvalue,
// int mode,pxywindow_s*bounds,uint clearvalue,struct pxip8blob3*proto,
// size_t nblobs,struct pxip8blob3 results[],pxim2size_t*nbadblobs);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `findxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `bounds' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `proto' parameter has been declared expecting a dimensioned double array to be passed
//   with 9 array elements per desired blob result
//   with the  0,  9, 18, ...  elements containing the result's 'seed.xd' value
//   with the  1, 10, 19, ...  elements containing the result's 'seed.yd' value
//   with the  2, 11, 20, ...  elements containing the result's 'wind.nw.xd' value
//   with the  3, 12, 21, ...  elements containing the result's 'wind.nw.yd' value
//   with the  4, 13, 22, ...  elements containing the result's 'wind.se.xd' value
//   with the  5, 14, 23, ...  elements containing the result's 'wind.se.yd' value
//   with the  6, 15, 24, ...  elements containing the result's 'xyarea' value
//   with the  7, 16, 25, ...  elements containing the result's 'ucom.xd' value
//   with the  8, 17, 26, ...  elements containing the result's 'ucom.yd' value
// The `results' parameter has been declared expecting a dimensioned double array to be passed
//   with 9 array elements per desired blob result
//   with the  0,  9, 18, ...  elements containing the result's 'seed.xd' value
//   with the  1, 10, 19, ...  elements containing the result's 'seed.yd' value
//   with the  2, 11, 20, ...  elements containing the result's 'wind.nw.xd' value
//   with the  3, 12, 21, ...  elements containing the result's 'wind.nw.yd' value
//   with the  4, 13, 22, ...  elements containing the result's 'wind.se.xd' value
//   with the  5, 14, 23, ...  elements containing the result's 'wind.se.yd' value
//   with the  6, 15, 24, ...  elements containing the result's 'xyarea' value
//   with the  7, 16, 25, ...  elements containing the result's 'ucom.xd' value
//   with the  8, 17, 26, ...  elements containing the result's 'ucom.yd' value
// The `nbadblobs' parameter has been declared expecting a dimensioned long array to be passed
int __stdcall pxip8_bloblist3(int , void* ip, int findxyp[], int findcond, int findvalue, int mode, 
int bounds[], int clearvalue, double proto[], __int64 nblobs, double results[], long nbadblobs[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_bloblist2(pxabortfunc_t**,pximage_s*ip,pximage_s*gip,pxy_s*findxyp,int findcond,uint findvalue,
// int mode,pxywindow_s*bounds,uint clearvalue,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void(__stdcall*mapxyhvfunc)(void*,pxyd_s*,pxyd_s*),
// void(__stdcall*maphvxyfunc)(void*,pxyd_s*,pxyd_s*),
// void*mapzirefp,void*mapxyhvrefp,struct pxip8blob2*proto,
// size_t nblobs,struct pxip8blob2 results[],pxim2size_t*nbadblobs);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_seqtile(pxabortfunc_t**,pximage3_s*sip,pximage_s*dip,
// pxcoord_t overlap,pxy_s*framesize,pxy_s*bordersize,
// uint framevalues[],uint bordervalues[],double aspect,int mode,int zdim);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `framesize' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `bordersize' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `framevalues' parameter has been declared expecting a dimensioned int array to be passed
// The `bordervalues' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_seqtile(int , void* sip, void* dip, int overlap, int framesize[], int bordersize[], 
unsigned int framevalues[], unsigned int bordervalues[], double aspect, int mode, int zdim);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_seqtilecoord(pxabortfunc_t**,pximage3_s*sip,pximage_s*dip,
// pxy_s*framesize,pxy_s*bordersize,
// double aspect,int zdim,int which,pxywindow_s*windp);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE3/PXD_DEFINEIMAGE3 to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `framesize' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `bordersize' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `windp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
int __stdcall pxip8_seqtilecoord(int , void* sip, void* dip, int framesize[], int bordersize[], double aspect, 
int zdim, int which, int windp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_ckeygraphics(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// uint ipkey[],int mode,uint opvalues[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `ipkey' parameter has been declared expecting a dimensioned int array to be passed
// The `opvalues' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_ckeygraphics(int , void* sip, void* dip, unsigned int ipkey[], int mode, unsigned int opvalues[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_particleflow(pxabortfunc_t**,int ant,struct pxip8blob*ablobs[],size_t anblob[],
// size_t firstblob,size_t results[],size_t nresults,size_t*nextblob,
// double aminV,double amaxV,double amaxdeltaV,
// ulong minA,ulong maxA,long deltaA,int trackV,int trackA);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_radialmass(pxabortfunc_t**p,pximage_s*ip,
// pxy_s*xyp,double data[],size_t ndata,double scalex,double scaley);
// The `p' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `data' parameter has been declared expecting a dimensioned double array to be passed
int __stdcall pxip8_radialmass(int p, void* ip, int xyp[], double data[], __int64 ndata, double scalex, double scaley);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_radialmassf(pxabortfunc_t**p,pximage_s*ip,
// pxyd_s*xyp,double data[],size_t ndata,
// double(__stdcall*mapzifunc)(void*,pxyd_s*,double),
// void(__stdcall*mapxyhvfunc)(void*,pxyd_s*,pxyd_s*),
// void*mapzirefp,void*mapxyhvrefp,double scaled);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip_particleflow2(pxabortfunc_t**,
// struct pxip8blob3 blob0[],struct pxip8blob3 blob1[],
// size_t nblob0,size_t nblob1,struct pxipparticleflow2*p,int options);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_vgadisplay(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lutip,int bits,int mode,
// int options,int yignore,pximage_s*vgaip,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lutip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `vgaip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_vgadisplay(int , void* ip, void* lutip, int bits, int mode, int options, int yignore, 
void* vgaip, int cursxyp[], void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_vgacoord(pximage_s*ip,int mode,int yignore,
// pximage_s*vgaip,pxy_s*cursxyp);
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `vgaip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxio8_vgacoord(void* ip, int mode, int yignore, void* vgaip, int cursxyp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_vgacoord1(pximage_s*ip,int mode,int yignore,
// pximage_s*vgaip,pxy_s*cursxyp);
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `vgaip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxio8_vgacoord1(void* ip, int mode, int yignore, void* vgaip, int cursxyp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_vgacursor(pxabortfunc_t**,pximage_s*ip,
// int resizemode,int yignore,pximage_s*vgaip,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `vgaip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_vgacursor(int , void* ip, int resizemode, int yignore, void* vgaip, int cursxyp[], 
void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_CopyToDevice(pxabortfunc_t**,pximage_s*ip,void*rsvd,void*rsvd2,
// int vgapalettebits,int mode,int options,int yignore,HDC hDC,
// WORD nX,WORD nY,WORD nWidth,WORD nHeight,pxy_s*cursp,
// COLORREF(__stdcall*cursfunc)(void*,int,int,COLORREF),
// void*cursfuncrefp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_CopyToDeviceCoord(pximage_s*ip,int mode,
// int yignore,HDC hDC,WORD nX,WORD nY,WORD nWidth,
// WORD nHeight,pxy_s*cursxyp);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDIDisplay(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int resizemode,int options,
// int yignore,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lutip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `hDCwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_GDIDisplay(int , void* ip, void* lutip, int vgapalettebits, int resizemode, int options, 
int yignore, void* hDC, int hDCwindp[], int cursxyp[], void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_DCIDisplay(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int resizemode,int options,
// int yignore,HWND wnd,HDC hDC,pxywindow_s*wndwindp,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lutip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `wnd' parameter has been declared expecting a Windows handle to a window (hWnd) to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `wndwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_DCIDisplay(int , void* ip, void* lutip, int vgapalettebits, int resizemode, int options, 
int yignore, void* wnd, void* hDC, int wndwindp[], int cursxyp[], void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_DirectXDisplay(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int resizemode,int options,
// int yignore,void*ddrs,pxywindow_s*wndwindp,HWND wnd,HDC hDC,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `lutip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `wndwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `wnd' parameter has been declared expecting a Windows handle to a window (hWnd) to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_DirectXDisplay(int , void* ip, void* lutip, int vgapalettebits, int resizemode, 
int options, int yignore, void* ddrs, int wndwindp[], void* wnd, void* hDC, int cursxyp[], void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_DrawDibDisplay(pxabortfunc_t**,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int resizemode,int options,
// int yignore,HDRAWDIB hDrawDib,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*cursxyp,pximage_s*cursip);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDICursor(pxabortfunc_t**,pximage_s*ip,
// int resizemode,int yignore,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*cursxyp,pximage_s*cursip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `hDCwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `cursip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_GDICursor(int , void* ip, int resizemode, int yignore, void* hDC, int hDCwindp[], 
int cursxyp[], void* cursip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDICursor2(pxabortfunc_t**,pximage_s*ip,
// int resizemode,int yignore,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*curs1xyp,pxy_s*curs2xyp,pximage_s*curs1ip,pximage_s*curs2ip);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `hDCwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `curs1xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `curs2xyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `curs1ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `curs2ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxio8_GDICursor2(int , void* ip, int resizemode, int yignore, void* hDC, int hDCwindp[], 
int curs1xyp[], int curs2xyp[], void* curs1ip, void* curs2ip);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDICoord(pximage_s*ip,int resizemode,
// int yignore,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*cursxyp);
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `hDCwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxio8_GDICoord(void* ip, int resizemode, int yignore, void* hDC, int hDCwindp[], int cursxyp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDICoord1(pximage_s*ip,int resizemode,
// int yignore,HDC hDC,pxywindow_s*hDCwindp,
// pxy_s*cursxyp);
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hDC' parameter has been declared expecting a Windows handle to a device context (hDC) to be passed
// The `hDCwindp' parameter has been declared expecting a dimensioned int array with four elements to be passed
//   with array element 0 the upper left X coordinate, array element 1 the upper left Y coordinate
//   with array element 2 the lower right X coordinate, array element 3 the lower right Y coordinate
// The `cursxyp' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
int __stdcall pxio8_GDICoord1(void* ip, int resizemode, int yignore, void* hDC, int hDCwindp[], int cursxyp[]);

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_DIBCreate(pximage_s*ip,pximage_s*lutip,
// int mode,HGLOBAL*handlep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxio8_DIBCreateDone(HGLOBAL*handlep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_findpixelmax(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,
// uint*valuep,pxim2size_t*countp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_findpixelmin(pxabortfunc_t**,pximage_s*ip,pxy_s*xyp,
// uint*valuep,pxim2size_t*countp,int mode);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_vgawaterfall(pxabortfunc_t**,
// uint32(__stdcall*vbtimefunc)(void*),void*vbtimefuncrefp,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int mode,int options,
// int bottomup,pximage_s*vgaip,int scrollfactor,void(__stdcall*scrollfunc)(void*sp,pximage_s*vgaip,int bottomup,int scrollfactor),
// void*scrollstate,uint32 results[3]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_WaterfallToDevice(pxabortfunc_t**,
// uint32(__stdcall*vbtimefunc)(void*),void*vbtimefuncrefp,pximage_s*ip,
// void*rsvd,void*rsvd2,int vgapalettebits,int mode,int options,int bottomup,int scrollfact,
// HDC hdc,WORD nX,WORD nY,WORD nWidth,WORD nHeight,uint32 results[3]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxio8_GDIWaterfall(pxabortfunc_t**,
// uint32(__stdcall*vbtimefunc)(void*),void*vbtimefuncrefp,pximage_s*ip,
// pximage_s*lutip,int vgapalettebits,int resizemode,int diffuse,int bottomup,
// HDC hdc,pxywindow_s*hdcwindp,int scrollfactor,uint32 results[3]);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_hsbtweak(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,
// int huebands,int satbands,int brtbands,
// float hueoffset[],float satscale[],float brtscale[],float satoffset[],float brtoffset[],
// float satkill,float rsvd1,float rsvd2,float rsvd3,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `hueoffset' parameter has been declared expecting a dimensioned float array to be passed
// The `satscale' parameter has been declared expecting a dimensioned float array to be passed
// The `brtscale' parameter has been declared expecting a dimensioned float array to be passed
// The `satoffset' parameter has been declared expecting a dimensioned float array to be passed
// The `brtoffset' parameter has been declared expecting a dimensioned float array to be passed
int __stdcall pxip8_hsbtweak(int , void* sip, void* dip, int huebands, int satbands, int brtbands, float hueoffset[], 
float satscale[], float brtscale[], float satoffset[], float brtoffset[], float satkill, float rsvd1, float rsvd2, 
float rsvd3, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_3x3dpcsi(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,double threshold,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_3x3dpcsi(int , void* sip, void* dip, double threshold, int mode);

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pclfontload(char*filename,void**fonthandlep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_pclfontdraw(pxabortfunc_t**,pximage_s*ip,void*fonthandle,
// pxy_s*xy,char*cp,int cn,int xscale,int yscale,
// int hlead,int vlead,int groundtype,uint background[],uint foreground[]);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `ip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `xy' parameter has been declared expecting a dimensioned int array with two elements to be passed
//   with array element 0 the X coordinate or dimension, array element 1 the Y coordinate or dimension
// The `background' parameter has been declared expecting a dimensioned int array to be passed
// The `foreground' parameter has been declared expecting a dimensioned int array to be passed
int __stdcall pxip8_pclfontdraw(int , void* ip, void* fonthandle, int xy[], char* cp, int cn, int xscale, int yscale, 
int hlead, int vlead, int groundtype, unsigned int background[], unsigned int foreground[]);

// _cDcl(__declspec(dllexport),__stdcall,struct pxip8pclfont*)
// pxip8_pclfontinfo(void*fonthandle);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,struct pxip8pclchar*)
// pxip8_pclfontcinfo(void*fonthandle,int c);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,void)pxip8_pclfontunload(void**fonthandlep);
// Uses advanced or unrecognized C constructs

// _cDcl(__declspec(dllexport),__stdcall,int)pxip8_blend(pxabortfunc_t**,pximage_s*sip,pximage_s*dip,int mode);
// The `noname1' parameter has been declared expecting a 0 to be passed
// The `sip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
// The `dip' parameter has been declared expecting the return value of PXD_DEFIMAGE/PXD_DEFINEIMAGE to be passed
int __stdcall pxip8_blend(int , void* sip, void* dip, int mode);
