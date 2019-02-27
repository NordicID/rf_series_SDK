//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

// PLMultiThreadDlg.h : header file
//
//{{AFX_INCLUDES()
#include "CDPLServer.h"
//}}AFX_INCLUDES

#if !defined(AFX_PLMULTITHREADDLG_H__775E79BD_EBD1_4DB7_9BC7_B8EF005338F2__INCLUDED_)
#define AFX_PLMULTITHREADDLG_H__775E79BD_EBD1_4DB7_9BC7_B8EF005338F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class DataProcessing;

 
typedef struct tagHSSTATUS
{
	long hsid;
	int status;	
}HSSTATUS;
/////////////////////////////////////////////////////////////////////////////
// CPLMultiThreadDlg dialog

class CPLMultiThreadDlg : public CDialog
{
// Construction
public:
	CPLMultiThreadDlg(CWnd* pParent = NULL);	// standard constructor

	DataProcessing* m_DataProcessingThread;

	void UpDateDlgField();
	int GetStatusIndex(long hsid);
	void SendWaitScreen(long id);
	void SendScanScreen(long id);

	int m_counter;

	HSSTATUS hsStatus[50];//50 hand terminal should be enough for this demo

// Dialog Data
	//{{AFX_DATA(CPLMultiThreadDlg)
	enum { IDD = IDD_PLMULTITHREAD_DIALOG };
	CListBox	m_list;
	CDPLServer	m_pl;
	int		m_prosTime;
	BOOL	m_waitchk;
	int		m_whattime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPLMultiThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPLMultiThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDataArrivedPlserverctrl1(long id, short frameid);
	afx_msg void OnWhatPlserverctrl1(long id);
	afx_msg void OnBsConnectionsBut();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLMULTITHREADDLG_H__775E79BD_EBD1_4DB7_9BC7_B8EF005338F2__INCLUDED_)
