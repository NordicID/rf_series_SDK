#ifndef _INC_YLEIS
#define _INC_YLEIS   

#include <afxdisp.h>

#define	SINGLE_UP	1100
#define SINGLE_DOWN	1101
#define DOUBLE_UP	1102
#define DOUBLE_DOWN	1103 


CString c(int luku); 
CString c(unsigned char luku);
CString c(UINT luku);
CString c(long luku);
CString c(double luku);
CString X(int luku);
CString X(unsigned char *txt,int size);
CString mk_style(CString txt);

int ipow(int x,int y);
void kehys(CDC *dc,CRect r,int mode);
void kehys(CDC *dc,int x,int y,int w,int h,int mode);	
void Viiva(CDC *dc,int x, int y,int pituus,BOOL vk_py);
float Pros(long luku,long luvusta);
long txt_to_long(CString txt);
short txt_to_int(CString txt);
CString luku_to_dec(short luku);
CString luku_to_dec(long luku);
	
	
#endif	