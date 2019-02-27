#if !defined(AFX_STARTSERVERDLG_H__CD6BD2D0_56D7_4664_998C_A7BD11EB1667__INCLUDED_)
#define AFX_STARTSERVERDLG_H__CD6BD2D0_56D7_4664_998C_A7BD11EB1667__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StartServerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// StartServerDlg dialog

class StartServerDlg : public CDialog
{
// Construction
public:
	StartServerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(StartServerDlg)
	enum { IDD = IDD_STARTSERVER_DLG };
	int		m_port;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(StartServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(StartServerDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARTSERVERDLG_H__CD6BD2D0_56D7_4664_998C_A7BD11EB1667__INCLUDED_)
