// Programmed by Ari Pöyhönen 25.10.98
// Copyright© 1998 by Nordic Identification. All rights reserved.

#ifndef _INC_YLEIS
#define _INC_YLEIS   



CString c(int luku); 
CString c(unsigned char luku);
CString c(UINT luku);
CString c(long luku);
CString c(double luku);
CString X(int luku);
CString X(unsigned char *txt,int size);
	
int ipow(int x,int y);
float Pros(long luku,long luvusta);
long txt_to_long(CString txt);
short txt_to_int(CString txt);
CString luku_to_dec(short luku);
CString luku_to_dec(long luku);
	
	
#endif	