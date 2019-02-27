//NORDIC ID DEMO SOFTWARE DISCLAIMER

//You are about to use Nordic ID Demo Software (“Software”).
//It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
//Software is provided “as is” and with all faults.
//Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
//The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
//IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.

// PLAppView.h : interface of the CPLAppView class
//
/////////////////////////////////////////////////////////////////////////////
#include "plserver.h"



class CPLAppView : public CFormView
{
protected: // create from serialization only
	CPLAppView();
	DECLARE_DYNCREATE(CPLAppView)

	BOOL isinit;
	CPLServer m_pl;
	CString m_addcode;
	
	int  FindRow(CString codekey);
	void UpdateRow(CStringArray *txt_array,int row);
	void AddRow(CStringArray *txt_array);
	void AddCol(int col_index,TCHAR *header,int width,int align);
	void UpdatePrdList();
	void AddOrUpdateProductToList(PRODUCT addPrd,int add_update=1);
	void SendMenu(long id);
	void DataFromMenu(long id);
	void SendProductFrame(long id);	
	void DataFromProductFrame(long id,int frameid);
	void SendInventoryFrame(long id);
	void DataFromInventoryFrame(long id);
	void DataFromFuncOrInitScreen(long id);

public:
	//{{AFX_DATA(CPLAppView)
	enum{ IDD = IDD_PLAPP_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CPLAppDoc* GetDocument();	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPLAppView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPLAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void OnDataArrived(long id, short frameid);

	//{{AFX_MSG(CPLAppView)
	afx_msg void OnCom1();
	afx_msg void OnCom2();
	afx_msg void OnCom3();
	afx_msg void OnCom4();
	afx_msg void OnDisconnect();
	afx_msg void OnDblclkPrdlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedPrdlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFileStartserver();
	afx_msg void OnFileStopserver();
	afx_msg void OnCom10();
	afx_msg void OnCom11();
	afx_msg void OnCom12();
	afx_msg void OnCom13();
	afx_msg void OnCom14();
	afx_msg void OnCom15();
	afx_msg void OnCom16();
	afx_msg void OnCom17();
	afx_msg void OnCom18();
	afx_msg void OnCom19();
	afx_msg void OnCom20();
	afx_msg void OnCom5();
	afx_msg void OnCom6();
	afx_msg void OnCom7();
	afx_msg void OnCom8();
	afx_msg void OnCom9();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PLAppView.cpp
inline CPLAppDoc* CPLAppView::GetDocument()
   { return (CPLAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
