
// LKGuard.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLKGuardApp:
// �йش����ʵ�֣������ LKGuard.cpp
//

class CLKGuardApp : public CWinApp
{
public:
	CLKGuardApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLKGuardApp theApp;