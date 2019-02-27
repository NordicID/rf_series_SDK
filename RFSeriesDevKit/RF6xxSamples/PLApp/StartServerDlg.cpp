//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.


// StartServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PLApp.h"
#include "StartServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// StartServerDlg dialog


StartServerDlg::StartServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(StartServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(StartServerDlg)
	m_port = 0;
	//}}AFX_DATA_INIT
}


void StartServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(StartServerDlg)
	DDX_Text(pDX, IDC_PORTEDIT, m_port);
	DDV_MinMaxInt(pDX, m_port, 1024, 32767);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(StartServerDlg, CDialog)
	//{{AFX_MSG_MAP(StartServerDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// StartServerDlg message handlers
