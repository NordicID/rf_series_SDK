// BSConnections.cpp : implementation file
//

#include "stdafx.h"
#include "PLMultiThread.h"
#include "BSConnections.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BSConnections dialog


BSConnections::BSConnections(CWnd* pParent /*=NULL*/)
	: CDialog(BSConnections::IDD, pParent)
{
	//{{AFX_DATA_INIT(BSConnections)
	m_ipaddr = _T("");
	m_comport = _T("");
	m_portserv = _T("");
	m_portcli = _T("");
	//}}AFX_DATA_INIT
}


void BSConnections::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BSConnections)
	DDX_Text(pDX, IDC_IPADDREDIT, m_ipaddr);
	DDV_MaxChars(pDX, m_ipaddr, 15);
	DDX_Text(pDX, IDC_COMNUMBEREDIT, m_comport);
	DDV_MaxChars(pDX, m_comport, 2);
	DDX_Text(pDX, IDC_PORTEDIT, m_portserv);
	DDX_Text(pDX, IDC_PORTNOEDIT, m_portcli);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BSConnections, CDialog)
	//{{AFX_MSG_MAP(BSConnections)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BSConnections message handlers
