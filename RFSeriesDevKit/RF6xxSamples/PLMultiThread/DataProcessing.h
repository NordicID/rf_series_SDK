//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

#if !defined(AFX_DATAPROCESSING_H__DCAB6D87_52C9_4289_90A8_9EA45BC4835A__INCLUDED_)
#define AFX_DATAPROCESSING_H__DCAB6D87_52C9_4289_90A8_9EA45BC4835A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataProcessing.h : header file
//

class CPLMultiThreadDlg;

/////////////////////////////////////////////////////////////////////////////
// DataProcessing thread

class DataProcessing : public CWinThread
{
	DECLARE_DYNCREATE(DataProcessing)
protected:
	DataProcessing();           // protected constructor used by dynamic creation
	
	void DataFromScanScreen();

	long id;//Hand terminal ID
	short frameid;
	int ind;//Index to HSSTATUS struct
// Attributes
public:

	CPLMultiThreadDlg* m_dlg;
	void SetOwner(CPLMultiThreadDlg* dlg) { m_dlg=dlg; };
	void DataToProcess(long hsid,short hsframeid,int hsIndex);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DataProcessing)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~DataProcessing();

	// Generated message map functions
	//{{AFX_MSG(DataProcessing)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAPROCESSING_H__DCAB6D87_52C9_4289_90A8_9EA45BC4835A__INCLUDED_)
