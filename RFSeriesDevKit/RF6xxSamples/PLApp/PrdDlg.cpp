// PrdDlg.cpp : implementation file
// Programmed by Ari Pöyhönen 25.10.98
// Copyright© 1998 by Nordic Identification. All rights reserved.

#include "stdafx.h"
#include "PLApp.h"
#include "PrdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrdDlg dialog


CPrdDlg::CPrdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrdDlg)
	m_amount = 0;
	m_code = _T("");
	m_descr = _T("");
	m_price = 0.0;
	m_unit = _T("");
	//}}AFX_DATA_INIT
}


void CPrdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrdDlg)
	DDX_Text(pDX, IDC_AMOUNT_EDIT, m_amount);
	DDX_Text(pDX, IDC_CODE_EDIT, m_code);
	DDV_MaxChars(pDX, m_code, 16);
	DDX_Text(pDX, IDC_DESCR_EDIT, m_descr);
	DDV_MaxChars(pDX, m_descr, 34);
	DDX_Text(pDX, IDC_PRICE_EDIT, m_price);
	DDX_Text(pDX, IDC_UNIT_EDIT, m_unit);
	DDV_MaxChars(pDX, m_unit, 5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrdDlg, CDialog)
	//{{AFX_MSG_MAP(CPrdDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrdDlg message handlers
