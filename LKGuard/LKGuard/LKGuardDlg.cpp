
// LKGuardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LKGuard.h"
#include "LKGuardDlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <TlHelp32.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLKGuardDlg 对话框




CLKGuardDlg::CLKGuardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLKGuardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CLKGuardDlg::~CLKGuardDlg()
{
}

void CLKGuardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLKGuardDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDOK, &CLKGuardDlg::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLKGuardDlg 消息处理程序

BOOL CLKGuardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLKGuardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLKGuardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD GetProcessIdFromName(LPCTSTR name)
{
	PROCESSENTRY32 pe;
	DWORD id = 0;	
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	pe.dwSize = sizeof(PROCESSENTRY32);
	if( !Process32First(hSnapshot,&pe) )
		return 0;	
	while(1)
	{
		pe.dwSize = sizeof(PROCESSENTRY32);
		if( Process32Next(hSnapshot,&pe)==FALSE )
			break;
		if(strcmp(pe.szExeFile,name) == 0)
		{
			id = pe.th32ProcessID;
			break;
		}

	};
	CloseHandle(hSnapshot);	
	return id;
}


void CLKGuardDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值



// 	int nRet = GetProcessIdFromName("KoKoonSync.exe");
// 
// 	if(0 == nRet)
// 	{
// 		//WinExec("KoKoonSync.exe",SW_SHOW);
// 		ShellExecute(NULL, "open", "KoKoonSync.exe", NULL, NULL, SW_SHOW);
// 	}

	int nRet = GetProcessIdFromName("LKBDS.exe");

	if(0 == nRet)
	{
		//WinExec("KoKoonSync.exe",SW_SHOW);
		ShellExecute(NULL, "open", "LKBDS.exe", NULL, NULL, SW_SHOW);
	}

	

	CDialogEx::OnTimer(nIDEvent);
}


void CLKGuardDlg::OnDestroy()
{
	KillTimer(1);
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


void CLKGuardDlg::OnBnClickedOk()
{
	KillTimer(1);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CLKGuardDlg::OnClose()
{
	KillTimer(1);
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}
