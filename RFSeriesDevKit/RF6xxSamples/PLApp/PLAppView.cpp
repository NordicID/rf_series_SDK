//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

// PLAppView.cpp : implementation of the CPLAppView class
// Programmed by Ari Pöyhönen 6.1.99
// Copyright© 1999 by Nordic Identification. All rights reserved.

#include "stdafx.h"
#include "PLApp.h"
#include "const.h"

#include "PLAppDoc.h"
#include "PLAppView.h"
#include "yleis.h"
#include "StartServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPLAppView

IMPLEMENT_DYNCREATE(CPLAppView, CFormView)

BEGIN_MESSAGE_MAP(CPLAppView, CFormView)
	//{{AFX_MSG_MAP(CPLAppView)
	ON_COMMAND(ID_COM1, OnCom1)
	ON_COMMAND(ID_COM2, OnCom2)
	ON_COMMAND(ID_COM3, OnCom3)
	ON_COMMAND(ID_COM4, OnCom4)
	ON_COMMAND(ID_DISCONNECT, OnDisconnect)
	ON_NOTIFY(NM_DBLCLK, IDC_PRDLIST, OnDblclkPrdlist)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_PRDLIST, OnItemchangedPrdlist)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_FILE_STARTSERVER, OnFileStartserver)
	ON_COMMAND(ID_FILE_STOPSERVER, OnFileStopserver)
	ON_COMMAND(ID_COM10, OnCom10)
	ON_COMMAND(ID_COM11, OnCom11)
	ON_COMMAND(ID_COM12, OnCom12)
	ON_COMMAND(ID_COM13, OnCom13)
	ON_COMMAND(ID_COM14, OnCom14)
	ON_COMMAND(ID_COM15, OnCom15)
	ON_COMMAND(ID_COM16, OnCom16)
	ON_COMMAND(ID_COM17, OnCom17)
	ON_COMMAND(ID_COM18, OnCom18)
	ON_COMMAND(ID_COM19, OnCom19)
	ON_COMMAND(ID_COM20, OnCom20)
	ON_COMMAND(ID_COM5, OnCom5)
	ON_COMMAND(ID_COM6, OnCom6)
	ON_COMMAND(ID_COM7, OnCom7)
	ON_COMMAND(ID_COM8, OnCom8)
	ON_COMMAND(ID_COM9, OnCom9)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPLAppView construction/destruction

CPLAppView::CPLAppView()
	: CFormView(CPLAppView::IDD)
{
	//{{AFX_DATA_INIT(CPLAppView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	isinit=FALSE;
}

CPLAppView::~CPLAppView()
{
}

void CPLAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPLAppView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CPLAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPLAppView printing

BOOL CPLAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPLAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPLAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPLAppView::OnPrint(CDC* pDC, CPrintInfo*)
{
	// TODO: add code to print the controls
}

/////////////////////////////////////////////////////////////////////////////
// CPLAppView diagnostics

#ifdef _DEBUG
void CPLAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPLAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPLAppDoc* CPLAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPLAppDoc)));
	return (CPLAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPLAppView message handlers
void CPLAppView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	//Headers for list control
	if(isinit) return;//only once init

	TCHAR hdr[5][15]={_T("Code"),_T("Description"),_T("Price"),_T("Unit"),_T("Amount")};
	
	AddCol(0,hdr[0],90,1);//Code
	AddCol(1,hdr[1],170,0);//Description
	AddCol(2,hdr[2],70,0);//Price
	AddCol(3,hdr[3],50,0);//Unit
	AddCol(4,hdr[4],60,0);//Amount

	isinit=TRUE;
	
}
int CPLAppView::FindRow(CString codekey)
{
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	LV_FINDINFO info;

    info.flags=LVFI_STRING;
    info.psz=codekey;
    
	return m_prdlist->FindItem(&info);
}
void CPLAppView::UpdateRow(CStringArray *txt_array,int row)
{
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	LV_ITEM   item;
	TCHAR buf[50]; 
	CString str; 	
	
	for(int subi=0;subi<5;subi++)
	{
		str=txt_array->GetAt(subi);
		_tcscpy(buf,str);
		item.mask=LVIF_TEXT;
		item.iItem=row;
		item.iSubItem=subi;		
		item.pszText=buf;		
		m_prdlist->SetItem(&item);
	}

	//Let's make sure that updated row is visible
	
	m_prdlist->SetItemState(row,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_prdlist->EnsureVisible(row,0);

}
void CPLAppView::AddRow(CStringArray *txt_array)
{
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	LV_ITEM   item;
	TCHAR buf[50]; 
	CString str;
	int act;
	
		for(int subi=0;subi<5;subi++)
		{
			str=txt_array->GetAt(subi);
			_tcscpy(buf,str);
			item.mask=LVIF_TEXT;
			item.iItem=(subi==0) ? m_prdlist->GetItemCount() : act;
			item.iSubItem=subi;		
			item.pszText=buf;		
			if(subi==0) act=m_prdlist->InsertItem(&item);
			else m_prdlist->SetItem(&item);
		}

		//Let's make sure that new row is visible
	int items=m_prdlist->GetItemCount();
	m_prdlist->SetItemState(items-1,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	m_prdlist->EnsureVisible(items-1,0);
		
}

void CPLAppView::AddCol(int col_index,TCHAR *header,int width,int align)
{
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	LV_COLUMN col;

	col.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;
	col.fmt=LVCFMT_LEFT;
	col.pszText=header;
	col.cx=width;
	m_prdlist->InsertColumn(col_index,&col);
        		
}

void CPLAppView::OnCom1() 
{	
	m_pl.Connect(1);
}

void CPLAppView::OnCom2() 
{
	m_pl.Connect(2);
	
}

void CPLAppView::OnCom3() 
{
	m_pl.Connect(3);
	
}

void CPLAppView::OnCom4() 
{
	m_pl.Connect(4);
	
}

void CPLAppView::OnDisconnect() 
{
	m_pl.Connect(0);
	
}							

void CPLAppView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{	
	UpdatePrdList();//Redraw all	
}

void CPLAppView::UpdatePrdList()
{

	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);
	m_prdlist->DeleteAllItems();

	POSITION pos=GetDocument()->m_prd.GetStartPosition();

	//iterating Map
	while(pos != NULL)
	{
		PRODUCT prod;
		CString key;
		GetDocument()->m_prd.GetNextAssoc(pos,key,prod);
		AddOrUpdateProductToList(prod);		
	}


}
void CPLAppView::AddOrUpdateProductToList(PRODUCT addPrd,int add_update)
{
	CStringArray txtarray;

	//Add row to list
	txtarray.Add(addPrd.code);		
	txtarray.Add(addPrd.descr);		
	txtarray.Add(c(addPrd.price));
	txtarray.Add(addPrd.unit);
	txtarray.Add(c(addPrd.amount));	
		
	if(add_update==1) AddRow(&txtarray); 
	else UpdateRow(&txtarray,FindRow(addPrd.code));//update modified row
}

void CPLAppView::OnDblclkPrdlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);
	int item=m_prdlist->GetNextItem(-1,LVNI_SELECTED);
	GetDocument()->m_curcode=m_prdlist->GetItemText(item,0);
	GetDocument()->OpenAddEditDlg(GetDocument()->m_curcode);	
	
	*pResult = 0;
}

void CPLAppView::OnItemchangedPrdlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	int item=m_prdlist->GetNextItem(-1,LVNI_SELECTED);
	GetDocument()->m_curcode=m_prdlist->GetItemText(item,0);
	
	*pResult = 0;
}

BEGIN_EVENTSINK_MAP(CPLAppView, CFormView)
    //{{AFX_EVENTSINK_MAP(CPLAppView)
	ON_EVENT(CPLAppView, 0, 1 /* DataArrived */, OnDataArrived, VTS_I4 VTS_I2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

//DataArrived Event From PLServer
void CPLAppView::OnDataArrived(long id, short frameid)
{
	switch(frameid)
	{
		case -1:			DataFromFuncOrInitScreen(id);
							break;
		case MENU:			DataFromMenu(id);
							break;
		case PRODUCT_FRAME:	DataFromProductFrame(id,frameid);
							break;
		case INVENTORY:		DataFromInventoryFrame(id);
							break;
		default:			SendMenu(id);
	}	
}	

void CPLAppView::SendMenu(long id)
{			

	m_pl.ClearForm(id);//Clears handterminal virtual display from texts and fields
	m_pl.Text(id,1,"*Demo Application*");
	
	m_pl.Button(id,20,"(F1) Product Inquiry");
	m_pl.Button(id,40,"(F2) Inventory");

	m_pl.Send(id,MENU);	

}

void CPLAppView::DataFromMenu(long id)
{ 
	if(m_pl.IsData(id,20))//Product Inquiry
		SendProductFrame(id);

	if(m_pl.IsData(id,40))//Inventory
		SendInventoryFrame(id);
}

void CPLAppView::SendProductFrame(long id)
{ 
	m_pl.ClearForm(id);
	m_pl.Text(id,0,"*Product Inquiry*");
	m_pl.Button(id,18,"\xa4\xa5");

	m_pl.Text(id,20,"C:");
	m_pl.NewField(id,22,16,SND_ENTER|FLD_LINE|FLD_READER|FLD_ACTIVE);

	m_pl.Text(id,40,"DESCR:");
	m_pl.NewField(id,46,34,FLD_LINE|FLD_READER);

	m_pl.Text(id,80,"PRICE:");
	m_pl.NewField(id,86,10,FLD_LINE|FLD_READER);

	m_pl.Text(id,100,"UNIT :");
	m_pl.NewField(id,106,7,FLD_LINE|FLD_READER);		

	m_pl.Text(id,120,"AMOUNT:");
	m_pl.NewField(id,127,8,FLD_LINE|FLD_READER);

	//Create "button" with SND_ALL feature	
	m_pl.NewField(id,140,6,FLD_LINE|SND_ENTER|FLD_LOCK|SND_ALL|NO_SEND);
	m_pl.FldTxt(id,140,"<SAVE>");

	m_pl.NewField(id,147,8,FLD_LINE|SND_ENTER|FLD_LOCK|SND_ALL|NO_SEND);
	m_pl.FldTxt(id,147,"<REMOVE>");
	
	m_pl.Send(id,PRODUCT_FRAME);	
	
}	  

void CPLAppView::DataFromProductFrame(long id,int frameid)
{
	PRODUCT prd;

	CListCtrl* m_prdlist=(CListCtrl*)GetDlgItem(IDC_PRDLIST);

	//When data is coming from Product Inquiry frame
	//it could be one of the four: <<,CODE,SAVE,REMOVE

	 if(m_pl.IsData(id,18))//[<<]
		SendMenu(id);

	CString code=m_pl.GetData(id,22);//Get Code
	BOOL isold=GetDocument()->m_prd.Lookup(code,prd);
	if(m_pl.IsData(id,140))//<SAVE>
	{
		strcpy(prd.code,code);//get code
		strcpy(prd.descr,m_pl.GetData(id,46));//get descr
		prd.price=atof(m_pl.GetData(id,86));//get price
		strcpy(prd.unit,m_pl.GetData(id,106));//get unit
		prd.amount=atol(m_pl.GetData(id,127));//get amount

		GetDocument()->m_prd.SetAt(code,prd);//Save to list
		if(isold) AddOrUpdateProductToList(prd,2);//if old
		else AddOrUpdateProductToList(prd);//if new
		m_pl.PopMessage(id,26,"*SAVE OK*");
		m_pl.Send(id,PRODUCT_FRAME);
		return;
	}

	if(m_pl.IsData(id,147))//<REMOVE>
	{
		m_pl.ClearCmd(id,CLEAR_FLDDATA,22,139);
		if(GetDocument()->m_prd.Lookup(code,prd))
		{
			GetDocument()->m_prd.RemoveKey(code);
			m_prdlist->DeleteItem(FindRow(code));
			m_pl.PopMessage(id,22,"*Product Removed*");			
		}
		else
		{
			CString mess1="Code: ";
			CString mess2="not found";
			m_pl.PopMessage(id,0,mess1+code+mess2);
		}
		m_pl.Send(id,PRODUCT_FRAME);

	}		   			
	
	if(m_pl.IsData(id,22))//CODE:
	{			 		
		if(GetDocument()->m_prd.Lookup(code,prd))
		{
			//if product found, send rest of product data
			m_pl.FldTxt(id,46,prd.descr);
			m_pl.FldTxt(id,86,c(prd.price));
			m_pl.FldTxt(id,106,prd.unit);
			m_pl.FldTxt(id,127,c(prd.amount));
			m_pl.FieldCmd(id,22,FLD_ACTIVE|FLD_LINE);//Keep it active
			m_pl.Send(id,PRODUCT_FRAME);
			int row=FindRow(code);
			m_prdlist->SetItemState(row,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
			m_prdlist->EnsureVisible(row,0);

		}
		else//it is a new product
		{
			m_pl.ClearCmd(id,CLEAR_FLDDATA,46,139);
			m_pl.PopMessage(id,22,"*New Product*");

			m_pl.Send(id,PRODUCT_FRAME);
		}	
	}		

}

void CPLAppView::DataFromFuncOrInitScreen(long id)
{ 	

	CString data=m_pl.GetData(id,-1);
	
	if(data=="F1")
	{
		SendProductFrame(id);
		return;
	}
	if(data=="F2")
	{
		SendInventoryFrame(id);
		return;
	}

	if(GetDocument()->isauto)//if Auto Edit is checked Add/Edit Dialog will displayed
	{						//if data is not in the list
		PRODUCT prd;
		memset(&prd,0,sizeof(PRODUCT));
		if(!GetDocument()->m_prd.Lookup(data,prd))
		{//If data was not in the list
			m_addcode=data;//used later in WM_TIMER
			m_pl.PopMessage(id,20,"Edit product on PC");
			m_pl.Send(id,-1);
			SetTimer(1,50,NULL);
			return;
		}
	}

	SendMenu(id);	

}
void CPLAppView::SendInventoryFrame(long id)
{	
	m_pl.ClearForm(id);
	m_pl.Text(id,0,"*Inventory*");
	m_pl.Button(id,18,"\xa4\xa5");									   	

	m_pl.Text(id,20,"CODE:");
	m_pl.Text(id,40,"DESCR:");
	m_pl.Text(id,60,"QTY:");
	m_pl.Text(id,70,"NEW:");
	m_pl.NewField(id,25,13,SND_ENTER|FLD_LINE|FLD_READER|FLD_ACTIVE);
	m_pl.NewField(id,74,13,SND_ENTER|FLD_LINE|SND_ALL);
	
	m_pl.Send(id,INVENTORY);
	
}
void CPLAppView::DataFromInventoryFrame(long id)
{	
	PRODUCT prd;

	if(m_pl.IsData(id,18))//[<<]
		SendMenu(id);

	CString code=m_pl.GetData(id,25);//Get Code	

	if(!m_pl.IsData(id,74))//Data only from Code field
	{
		if(GetDocument()->m_prd.Lookup(code,prd))//If product is list
		{
			//SHOW INVENTORY DETAILS OF SPESIFIC PRODUCT
			CString description=prd.descr;
			if(description.GetLength()>13) description.GetBufferSetLength(13);
			m_pl.Text(id,46,description);
			m_pl.Text(id,64,c(prd.amount));
			m_pl.FieldCmd(id,74,FLD_CLEAR|FLD_ACTIVE|FLD_LINE);
			m_pl.Send(id,INVENTORY);
			return;
		}
		else//product is not in the list
		{
			m_pl.FieldCmd(id,25,FLD_ACTIVE|FLD_LINE);//Set code field active
			m_pl.PopMessage(id,20,"Product not found");
			m_pl.Send(id,INVENTORY);
			return;
		}
	}
	//Data from QTY
	CString qty=m_pl.GetData(id,74);//Get QTY
	if(GetDocument()->m_prd.Lookup(code,prd))//If product is list
	{
		CString description=prd.descr;
		if(description.GetLength()>13) description.GetBufferSetLength(13);
		CString popmsg="CODE:";
		popmsg+=code;
		popmsg+="\x0d";
		popmsg+="DESCR:";
		popmsg+=description;
		popmsg+="\x0d";
		popmsg+="AMOUNT WAS: ";
		popmsg+=c(prd.amount);
		popmsg+="\x0d";
		popmsg+="AMOUNT NOW: ";
		popmsg+=c(atol(qty));
		m_pl.PopMessage(id,0,popmsg);		
		SendInventoryFrame(id);
		
		prd.amount=atol(qty);
		GetDocument()->m_prd.SetAt(code,prd);//save to map
		AddOrUpdateProductToList(prd,2);//update product in list
	}
	else//product is not in the list
	{
		m_pl.FieldCmd(id,25,FLD_ACTIVE|FLD_LINE);//Set code field active
		m_pl.PopMessage(id,20,"Product not found");
		m_pl.Send(id,INVENTORY);
		return;
	}
		
}	

int CPLAppView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//Create PLServer control
	m_pl.Create(NULL, WS_VISIBLE, 
		CRect(0,0,463,70), this, 0);	   

	m_pl.SetBoxPerRow(12);
	return 0;
}

void CPLAppView::OnTimer(UINT nIDEvent) 
{
	KillTimer(nIDEvent);
	if(nIDEvent==1)
		GetDocument()->OpenAddEditDlg(m_addcode);
	
	CFormView::OnTimer(nIDEvent);
}

void CPLAppView::OnFileStartserver() 
{
	StartServerDlg dlg;

	if(dlg.DoModal()==IDOK)
	{
		UpdateData(TRUE);
		m_pl.StartServer(dlg.m_port);
	}
}

void CPLAppView::OnFileStopserver() 
{
	m_pl.StopServer();
	
}

void CPLAppView::OnCom10() 
{
	m_pl.Connect(10);
	
}

void CPLAppView::OnCom11() 
{
	m_pl.Connect(11);
	
}

void CPLAppView::OnCom12() 
{
	m_pl.Connect(12);
	
}

void CPLAppView::OnCom13() 
{
	m_pl.Connect(13);
	
}

void CPLAppView::OnCom14() 
{
	m_pl.Connect(14);
	
}

void CPLAppView::OnCom15() 
{
	m_pl.Connect(15);
	
}

void CPLAppView::OnCom16() 
{
	m_pl.Connect(16);
	
}

void CPLAppView::OnCom17() 
{
	m_pl.Connect(17);
	
}

void CPLAppView::OnCom18() 
{
	m_pl.Connect(18);
	
}

void CPLAppView::OnCom19() 
{
	m_pl.Connect(19);
	
}

void CPLAppView::OnCom20() 
{
	m_pl.Connect(20);
	
}

void CPLAppView::OnCom5() 
{
	m_pl.Connect(5);
	
}

void CPLAppView::OnCom6() 
{
	m_pl.Connect(6);
	
}

void CPLAppView::OnCom7() 
{
	m_pl.Connect(7);
	
}

void CPLAppView::OnCom8() 
{
	m_pl.Connect(8);
	
}

void CPLAppView::OnCom9() 
{
	m_pl.Connect(9);
	
}
