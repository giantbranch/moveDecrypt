// moveDecryptDlg.h : header file
//

#if !defined(AFX_MOVEDECRYPTDLG_H__DA5E1EBC_04A6_4C05_B684_BF556D752171__INCLUDED_)
#define AFX_MOVEDECRYPTDLG_H__DA5E1EBC_04A6_4C05_B684_BF556D752171__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMoveDecryptDlg dialog

class CMoveDecryptDlg : public CDialog
{
// Construction
public:
	int GetId(int num);
	VOID Decrypt(char* szWord);
	CMoveDecryptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMoveDecryptDlg)
	enum { IDD = IDD_MOVEDECRYPT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveDecryptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMoveDecryptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDecrypt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEDECRYPTDLG_H__DA5E1EBC_04A6_4C05_B684_BF556D752171__INCLUDED_)
