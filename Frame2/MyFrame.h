#pragma once
#include "Frame.h"

class MyFrameWnd : public CFrameWnd
{
public:
	MyFrameWnd()
	{
		cout << "MyFrameWnd 构造函数执行了" << endl;
		Create();
	}
	~MyFrameWnd()
	{
		cout << "MyFrameWnd 析构函数执行了" << endl;
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
	CWnd* m_pMainWnd;
	//子类重写
	BOOL InitInstance()override
	{
		cout << "MyWinApp::InitApplication()" << endl;
		m_pMainWnd = new MyFrameWnd;
		return TRUE;
	}
};