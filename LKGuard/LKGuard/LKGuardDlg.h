
// LKGuardDlg.h : ͷ�ļ�
//

#pragma once


// CLKGuardDlg �Ի���
class CLKGuardDlg : public CDialogEx
{
// ����
public:
	CLKGuardDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CLKGuardDlg();

// �Ի�������
	enum { IDD = IDD_LKGUARD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
