// moveDecryptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "moveDecrypt.h"
#include "moveDecryptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoveDecryptDlg dialog

CMoveDecryptDlg::CMoveDecryptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMoveDecryptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMoveDecryptDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoveDecryptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoveDecryptDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMoveDecryptDlg, CDialog)
	//{{AFX_MSG_MAP(CMoveDecryptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT, OnButtonDecrypt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoveDecryptDlg message handlers

BOOL CMoveDecryptDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//设置标题
	SetWindowText("移位密码解密工具（by giantbranch）");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMoveDecryptDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMoveDecryptDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMoveDecryptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMoveDecryptDlg::OnButtonDecrypt() 
{
	// TODO: Add your control notification handler code here
	char szWord[100];
	GetDlgItem(IDC_EDIT_WORD)->GetWindowText(szWord, 100);	//获取输入框的字符串
	Decrypt(szWord);//调用解密函数
}


VOID CMoveDecryptDlg::Decrypt(char *szWord)
{
	CString str;
	int id;
	for (int j = 1; j <= 25; j++)//1-25次移位
	{
		id = GetId(j-1);
		for (int i = 0; i < strlen(szWord); i++)//根据字符串长度，依次移位，只处理大小写字母
		{
			if (szWord[i]>='a'&&szWord[i]<='z')//如果是小写字母
			{
				szWord[i] = (szWord[i] - 'a' + 1) % 26 +'a'; //szWord[i] - 'a'就是距离a的距离，+1就是每次循环移动一位，当然还要在26的范围内，最后还要加上a的ASCII码97，因为与a的距离再加97才能获得其最终的ASCII码
			}else if (szWord[i]>='A'&&szWord[i]<='Z')//如果是大写字母
			{
				szWord[i] = (szWord[i] - 'A' + 1) % 26 +'A';
			}
		}
		str.Format("%s",szWord);		//获取字符串并转化成Cstring
		GetDlgItem(id)->SetWindowText(str);	//放到对应的ID的框里
	}	
}



int CMoveDecryptDlg::GetId(int num)
{
	const DWORD MyIdcGroup[] = {
		IDC_EDIT_DECRYPT1,
		IDC_EDIT_DECRYPT2,
		IDC_EDIT_DECRYPT3,
		IDC_EDIT_DECRYPT4,
		IDC_EDIT_DECRYPT5,
		IDC_EDIT_DECRYPT6,
		IDC_EDIT_DECRYPT7,
		IDC_EDIT_DECRYPT8,
		IDC_EDIT_DECRYPT9,
		IDC_EDIT_DECRYPT10,
		IDC_EDIT_DECRYPT11,
		IDC_EDIT_DECRYPT12,
		IDC_EDIT_DECRYPT13,
		IDC_EDIT_DECRYPT14,
		IDC_EDIT_DECRYPT15,
		IDC_EDIT_DECRYPT16,
		IDC_EDIT_DECRYPT17,
		IDC_EDIT_DECRYPT18,
		IDC_EDIT_DECRYPT19,
		IDC_EDIT_DECRYPT20,
		IDC_EDIT_DECRYPT21,
		IDC_EDIT_DECRYPT22,
		IDC_EDIT_DECRYPT23,
		IDC_EDIT_DECRYPT24,
		IDC_EDIT_DECRYPT25,
	};
	return MyIdcGroup[num];
}
