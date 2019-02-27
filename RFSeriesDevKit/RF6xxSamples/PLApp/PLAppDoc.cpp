//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

// PLAppDoc.cpp : implementation of the CPLAppDoc class
// Programmed by Ari Pöyhönen 25.10.98
// Copyright© 1998 by Nordic Identification. All rights reserved.

#include "stdafx.h"
#include "PLApp.h"

#include "PLAppDoc.h"
#include "PrdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPLAppDoc

IMPLEMENT_DYNCREATE(CPLAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CPLAppDoc, CDocument)
	//{{AFX_MSG_MAP(CPLAppDoc)
	ON_COMMAND(ID_ADDPRD, OnAddprd)
	ON_COMMAND(ID_EDITPRD, OnEditprd)
	ON_COMMAND(ID_REMOVEPRD, OnRemoveprd)
	ON_UPDATE_COMMAND_UI(ID_EDITPRD, OnUpdateEditprd)
	ON_UPDATE_COMMAND_UI(ID_REMOVEPRD, OnUpdateRemoveprd)
	ON_COMMAND(ID_AUTOADD, OnAutoadd)
	ON_UPDATE_COMMAND_UI(ID_AUTOADD, OnUpdateAutoadd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPLAppDoc construction/destruction

CPLAppDoc::CPLAppDoc()
{
	// TODO: add one-time construction code here

}

CPLAppDoc::~CPLAppDoc()
{
}

BOOL CPLAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
		m_curcode.Empty();
		m_prd.RemoveAll();
		isauto=FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPLAppDoc serialization

void CPLAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	m_prd.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CPLAppDoc diagnostics

#ifdef _DEBUG
void CPLAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPLAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPLAppDoc commands

void CPLAppDoc::OnAddprd() 
{
	OpenAddEditDlg("");
	
}
void CPLAppDoc::OpenAddEditDlg(CString code)
{
	PRODUCT prd;
	CPrdDlg dlg;

	memset(&prd,0,sizeof(PRODUCT));

	if(!code.IsEmpty())//if we want edit
	{
		m_prd.Lookup(code,prd);
		dlg.m_code=code;
		dlg.m_descr=prd.descr;
		dlg.m_unit=prd.unit;
		dlg.m_price=prd.price;
		dlg.m_amount=prd.amount;
	}
	
	if(dlg.DoModal()==IDOK)
	{
		strcpy(prd.code,dlg.m_code);
		strcpy(prd.descr,dlg.m_descr);//Description of product
		strcpy(prd.unit,dlg.m_unit);//Unit of product
		prd.price=dlg.m_price;
		prd.amount=dlg.m_amount;

		m_prd.SetAt(dlg.m_code,prd);//Save to Map

		UpdateAllViews(NULL);
		SetModifiedFlag(TRUE);

	}

}
void CPLAppDoc::OnEditprd() 
{
	OpenAddEditDlg(m_curcode);
	
}

void CPLAppDoc::OnRemoveprd() 
{
	//REMOVE selected code from list
	PRODUCT prd;
	if(m_prd.Lookup(m_curcode,prd))
	{
		m_prd.RemoveKey(m_curcode);
		UpdateAllViews(NULL);
	}
	
}

BOOL CPLAppDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	m_curcode.Empty();
	UpdateAllViews(NULL);
	MessageBeep(-1);
	return TRUE;
}

void CPLAppDoc::DeleteContents() 
{
	m_prd.RemoveAll();
	m_curcode.Empty();	

	CDocument::DeleteContents();
}

void CPLAppDoc::OnUpdateEditprd(CCmdUI* pCmdUI) 
{
	if(m_curcode.IsEmpty()) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);
	
}

void CPLAppDoc::OnUpdateRemoveprd(CCmdUI* pCmdUI) 
{
	if(m_curcode.IsEmpty()) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);
	
}

void CPLAppDoc::OnAutoadd() 
{
	if(isauto) isauto=FALSE;
	else isauto=TRUE;
	
}

void CPLAppDoc::OnUpdateAutoadd(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(isauto);
	
}
