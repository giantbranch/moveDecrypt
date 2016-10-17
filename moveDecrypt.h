// moveDecrypt.h : main header file for the MOVEDECRYPT application
//

#if !defined(AFX_MOVEDECRYPT_H__47902DC2_1769_4DF7_A3C6_4D11FA383550__INCLUDED_)
#define AFX_MOVEDECRYPT_H__47902DC2_1769_4DF7_A3C6_4D11FA383550__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMoveDecryptApp:
// See moveDecrypt.cpp for the implementation of this class
//

class CMoveDecryptApp : public CWinApp
{
public:
	CMoveDecryptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveDecryptApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMoveDecryptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEDECRYPT_H__47902DC2_1769_4DF7_A3C6_4D11FA383550__INCLUDED_)
