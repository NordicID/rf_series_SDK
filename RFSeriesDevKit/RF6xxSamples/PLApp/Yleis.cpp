// Programmed by Ari Pöyhönen 25.10.98
// Copyright© 1998 by Nordic Identification. All rights reserved.
#include "stdafx.h"
#include "yleis.h"


CString c(int luku)
{ 

  CString str;
  char buf[10]="";
  _itoa(luku,buf,10);
  str+=buf;
  return str;  
  
}    
CString c(unsigned char luku)
{ 

  CString str;
  char buf[10]="";
  _itoa(luku,buf,10);
  str+=buf;
  return str;  
  
} 
CString c(UINT luku)
{ 

  CString str;
  char buf[10]="";
  _ltoa(luku,buf,10);
  str+=buf;
  return str;  
  
}
CString c(long luku)
{ 

  CString str;
  char buf[15]="";
  _ltoa(luku,buf,10);
  str+=buf;
  return str;  
  
}

CString c(double luku)
{
  char buf[30];
  sprintf(buf,"%0.2lf",luku);
  CString txt=buf;
  return txt;
}
CString X(int luku)
{
 char buf[5];                          
 
 sprintf(buf,"%.2X",luku);
 CString txt=buf;
 return txt;        
}  

CString X(unsigned char *txt,int size)
{              
 char buf[50];
 char hex[2];             
 
 for(int x=0;x<size;x++)
 {
   	sprintf(hex,"%.2X ",txt[x]);
   	strcat(buf,hex);
 }
   	
 CString ret=buf;
 return ret;  	   	
}               

long txt_to_long(CString txt)
{
	double luku=atof(txt);
	luku*=100;
	return (long)luku;
	
}
short txt_to_int(CString txt)
{
	double luku=atof(txt);
	luku*=100;
	return (int)luku;
}
CString luku_to_dec(short luku)
{
  char buf[30];
  double x=luku/100.0;
  sprintf(buf,"%0.1lf",x);
  CString txt=buf;
  return txt;
}

CString luku_to_dec(long luku)
{
  char buf[30];
  double x=luku/100.0;
  sprintf(buf,"%0.2lf",x);
  CString txt=buf;
  return txt;
}

float Pros(long luku,long luvusta)
{ 
  if(luvusta == 0) return (float)0.0;//Tutkitaan ennen jos jaetaan 0:lla
  
  float a= (float)luku;
  float b= (float)luvusta;
  float cd = 100*(a/b);
  
  return cd;
  
}  

