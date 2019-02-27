#if !defined(AFX_BSCONNECTIONS_H__7D94AE76_FAA8_4FFE_82D6_FB21A1E7EAB7__INCLUDED_)
#define AFX_BSCONNECTIONS_H__7D94AE76_FAA8_4FFE_82D6_FB21A1E7EAB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BSConnections.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BSConnections dialog

class BSConnections : public CDialog
{
// Construction
public:
	BSConnections(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BSConnections)
	enum { IDD = IDD_BSSETDLG };
	CString	m_ipaddr;
	CString	m_comport;
	CString	m_portserv;
	CString	m_portcli;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BSConnections)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BSConnections)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BSCONNECTIONS_H__7D94AE76_FAA8_4FFE_82D6_FB21A1E7EAB7__INCLUDED_)
