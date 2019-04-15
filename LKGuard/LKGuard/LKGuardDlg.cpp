
// LKGuardDlg.cpp : ʵ���ļ�
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


// CLKGuardDlg �Ի���




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


// CLKGuardDlg ��Ϣ�������

BOOL CLKGuardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLKGuardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ



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

	// TODO: �ڴ˴������Ϣ����������
}


void CLKGuardDlg::OnBnClickedOk()
{
	KillTimer(1);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CLKGuardDlg::OnClose()
{
	KillTimer(1);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}
