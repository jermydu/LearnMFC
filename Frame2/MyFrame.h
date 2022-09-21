#pragma once
#include "Frame.h"

class MyFrameWnd : public CFrameWnd
{
public:
	MyFrameWnd() 
	{
		cout << "MyFrameWnd 构造函数执行了" << endl;
	}
	~MyFrameWnd() 
	{
		cout << "MyFrameWnd 析构函数执行了" << endl;
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
		cout << "MyWinApp 构造函数执行了" << endl;
	}
	~MyWinApp()
	{
		cout << "MyWinApp 析构函数执行了" << endl;
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



