#pragma once
#include "Frame.h"

class MyFrameWnd : public CFrameWnd
{
public:
	MyFrameWnd() 
	{
		cout << "MyFrameWnd ���캯��ִ����" << endl;
	}
	~MyFrameWnd() 
	{
		cout << "MyFrameWnd ��������ִ����" << endl;
	}
	BOOL Create()override
	{
		cout << "MyFrameWnd::Create()" << endl;
		CreateEx();
		return TRUE;
	}

	BOOL PreCreateWindow()override
	{
		cout << "MyFrameWnd::PreCreateWindow()" << endl;
		return TRUE;
	}
};


class MyWinApp : public CWinApp
{
public:
	MyWinApp() {
		delete m_pMainWnd;
		m_pMainWnd = nullptr;
		cout << "MyWinApp ���캯��ִ����" << endl;
	}
	~MyWinApp()
	{
		cout << "MyWinApp ��������ִ����" << endl;
	}
	CWnd *m_pMainWnd;
	BOOL InitApplication()override
	{
		cout << "MyWinApp::InitApplication()" << endl;
		m_pMainWnd = new MyFrameWnd;
		m_pMainWnd->Create();
		return TRUE;
	}
};



