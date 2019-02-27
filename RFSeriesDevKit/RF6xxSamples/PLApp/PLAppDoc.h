// PLAppDoc.h : interface of the CPLAppDoc class
//
/////////////////////////////////////////////////////////////////////////////
// Programmed by Ari Pöyhönen 6.1.99
// Copyright© 1999 by Nordic Identification. All rights reserved.

#include <afxtempl.h>

struct PRODUCT
{
	char code[14];//EAN code
	char descr[35];//Description of product
	char unit[6];//Unit of product
	double price;
	int amount;
};


class CPLAppDoc : public CDocument
{
protected: // create from serialization only
	CPLAppDoc();
	DECLARE_DYNCREATE(CPLAppDoc)

// Attributes
public:
	CMap<CString,LPCTSTR,PRODUCT,PRODUCT&> m_prd;
	CString m_curcode;//currently selected line at product list
	BOOL isauto;
// Operations
public:

	void OpenAddEditDlg(CString code);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPLAppDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPLAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPLAppDoc)
	afx_msg void OnAddprd();
	afx_msg void OnEditprd();
	afx_msg void OnRemoveprd();
	afx_msg void OnUpdateEditprd(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRemoveprd(CCmdUI* pCmdUI);
	afx_msg void OnAutoadd();
	afx_msg void OnUpdateAutoadd(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
