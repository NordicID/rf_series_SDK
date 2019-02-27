// PrdDlg.h : header file
// Programmed by Ari Pöyhönen 6.1.99
// Copyright© 1999 by Nordic Identification. All rights reserved.

/////////////////////////////////////////////////////////////////////////////
// CPrdDlg dialog

class CPrdDlg : public CDialog
{
// Construction
public:
	CPrdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrdDlg)
	enum { IDD = IDD_PRDADDEDIT_DLG };
	int		m_amount;
	CString	m_code;
	CString	m_descr;
	double	m_price;
	CString	m_unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrdDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
