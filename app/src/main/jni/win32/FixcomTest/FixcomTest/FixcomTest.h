// FixcomTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CFixcomTestApp:
// �йش����ʵ�֣������ FixcomTest.cpp
//

class CFixcomTestApp : public CWinApp
{
public:
	CFixcomTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFixcomTestApp theApp;
