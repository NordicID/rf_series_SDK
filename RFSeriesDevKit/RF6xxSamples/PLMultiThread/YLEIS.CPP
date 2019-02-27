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


CString mk_style(CString txt)
{                
  
  int pit=txt.GetLength();
  int add=pit;
  
  if(pit > 9) return txt;
  if(pit >=7) add=pit+2;
  if(pit >=4 && pit <=6) add=pit+1;
  if(add==pit) return txt;
                
  CString uusi(' ',add);
  
  int cnt=0;
  while (pit>0)
  {  
    cnt++;       
    char mrk=txt.GetAt(pit-1);
    if(mrk == '.' || mrk == ',') cnt=0;
    if(cnt < 4) uusi.SetAt(add-1,mrk);
    else
    {
     cnt=1;
     add--;
     uusi.SetAt(add-1,mrk);
    } 
    pit--;
    add--;           
  }
  return uusi;
}
	
int ipow(int x,int y)
{ 
  int retval=1;
  for(int k=0;k<y;k++) retval*=x;
  return retval;                                          
}

void kehys(CDC *dc,CRect r,int mode)
{  
   CBrush black(RGB(128,128,128));
   CPen whitepen(PS_SOLID,1,RGB(255,255,255));  
   
   CPen *oldpen=dc->SelectObject(&whitepen);   
   dc->FrameRect(r,&black);//Ensin musta kehys
   dc->MoveTo(r.left,r.bottom-1);
   if(mode==SINGLE_UP || mode==DOUBLE_UP) dc->LineTo(r.left,r.top);
   else dc->LineTo(r.right-1,r.bottom-1);   
   dc->LineTo(r.right-1,r.top);    
   
   dc->SelectObject(oldpen);
   
}

void kehys(CDC *dc,int x,int y,int w,int h,int mode)
{  
   CRect r(x,y,x+w,y+h);
   CBrush black(RGB(0,0,0));
   CPen whitepen(PS_SOLID,1,RGB(255,255,255));  
   
   CPen *oldpen=dc->SelectObject(&whitepen);   
   dc->FrameRect(r,&black);//Ensin musta kehys
   dc->MoveTo(r.left,r.bottom-1);
   if(mode==SINGLE_UP || mode==DOUBLE_UP) dc->LineTo(r.left,r.top);
   else dc->LineTo(r.right-1,r.bottom-1);   
   dc->LineTo(r.right-1,r.top);    
   
   dc->SelectObject(oldpen);
 
}

void Viiva(CDC *dc,int x, int y,int pituus,BOOL vk_py)
{
    CPen Wpen(PS_SOLID,1,RGB(255,255,255));
    CPen Bpen(PS_SOLID,1,RGB(0,0,0));
   	CPen *oldpen;
   	
   	oldpen=dc->SelectObject(&Wpen);//Valkoinen kynä käyttöön
        
	dc->MoveTo(x,y);//Asetetaan kynä alkupisteeseen
	  
	if(vk_py)//Jos piirretään vaaka suoraan
    {
	  dc->LineTo(x+pituus,y);
	  dc->SelectObject(&Bpen);//Musta kynä käyttöön
	  dc->MoveTo(x,y+1);
	  dc->LineTo(x+pituus,y+1);
	}
	else//Jos piirretään pystysuoraan
	{ 	  
	  dc->LineTo(x,y+pituus);
	  dc->SelectObject(&Bpen);//Musta kynä käyttöön
	  dc->MoveTo(x+1,y);
	  dc->LineTo(x+1,y+pituus);
	}	
	
   	dc->SelectObject(oldpen);
}

float Pros(long luku,long luvusta)
{ 
  if(luvusta == 0) return (float)0.0;//Tutkitaan ennen jos jaetaan 0:lla
  
  float a= (float)luku;
  float b= (float)luvusta;
  float cd = 100*(a/b);
  
  return cd;
  
}  

