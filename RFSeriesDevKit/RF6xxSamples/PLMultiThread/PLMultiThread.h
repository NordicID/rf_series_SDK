// PLMultiThread.h : main header file for the PLMULTITHREAD application
//

#if !defined(AFX_PLMULTITHREAD_H__3E9B81E4_D11A_42C4_B0E2_55CC0881438F__INCLUDED_)
#define AFX_PLMULTITHREAD_H__3E9B81E4_D11A_42C4_B0E2_55CC0881438F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPLMultiThreadApp:
// See PLMultiThread.cpp for the implementation of this class
//

class CPLMultiThreadApp : public CWinApp
{
public:
	CPLMultiThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPLMultiThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPLMultiThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLMULTITHREAD_H__3E9B81E4_D11A_42C4_B0E2_55CC0881438F__INCLUDED_)
