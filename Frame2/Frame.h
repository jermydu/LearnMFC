#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#include <iostream>

using namespace std;
/**
* 模拟MFC程序的初始化过程
 */


class CObject
{
public:
	CObject()
	{
		cout << "CObject 构造函数执行了" << endl;
	}
	~CObject()
	{
		cout << "CObject 析构函数执行了" << endl;
	}
};

class CCmdTarget :public CObject
{
public:
	CCmdTarget()
	{
		cout << "CCmdTarget 构造函数执行了" << endl;
	}
	~CCmdTarget()
	{
		cout << "CCmdTarget 析构函数执行了" << endl;
	}
};

class CWinThread :public CCmdTarget
{
public:
	CWinThread()
	{
		cout << "CWinThread 构造函数执行了" << endl;
	}
	~CWinThread()
	{
		cout << "CWinThread 析构函数执行了" << endl;
	}
	virtual BOOL InitInstance()
	{
		cout << "CWinThread::InitInstance()" << endl;
		return TRUE;
	}
	virtual int Run()
	{
		cout << "CWinThread::Run()" << endl;
		return	1;
	}
};

class CWinApp :public CWinThread
{
public:
	CWinApp* m_pCurrentWinApp;
public:
	CWinApp()
	{
		m_pCurrentWinApp = this;
		cout << "CWinApp 构造函数执行了" << endl;
	}
	~CWinApp()
	{
		cout << "CWinApp 析构函数执行了" << endl;
	}
	//「每一个程序只做一次」的动作
	virtual BOOL InitApplication()
	{
		cout << "CWinApp::InitApplication()" << endl;
		return TRUE;
	}
	//负责「每一个执行个体都得做一次」的动作
	BOOL InitInstance()override
	{
		cout << "CWinApp::InitInstance()" << endl;
		return TRUE;
	}
	int Run()override
	{
		cout << "CWinApp::Run()" << endl;
		return	1;
	}
};

class CWnd :public CCmdTarget
{
public:
	CWnd()
	{
		cout << "CWnd 构造函数执行了" << endl;
	}
	~CWnd()
	{
		cout << "CWnd 析构函数执行了" << endl;
	}

	virtual BOOL Create()
	{
		cout << "CWnd::Create()" << endl;
		return TRUE;
	}
	BOOL CreateEx()
	{
		cout << "CWnd::CreateEx()" << endl;
		PreCreateWindow();
		return TRUE;
	}
	virtual BOOL PreCreateWindow()
	{
		cout << "CWnd::PreCreateWindow()" << endl;
		return TRUE;
	}
};

class CView :public CWnd
{
public:
	CView()
	{
		cout << "CView 构造函数执行了" << endl;
	}
	~CView()
	{
		cout << "CView 析构函数执行了" << endl;
	}
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd()
	{
		cout << "CFrameWnd 构造函数执行了" << endl;
	}
	~CFrameWnd()
	{
		cout << "CFrameWnd 析构函数执行了" << endl;
	}

	BOOL Create()override
	{
		cout << "CFrameWnd::Create()" << endl;
		CreateEx();
		return TRUE;
	}

	BOOL PreCreateWindow()override
	{
		cout << "CFrameWnd::PreCreateWindow()" << endl;
		return TRUE;
	}
};

class CDocument :public CCmdTarget
{
public:
	CDocument()
	{
		cout << "CDocument 构造函数执行了" << endl;
	}
	~CDocument()
	{
		cout << "CDocument 析构函数执行了" << endl;
	}
};

//全局函数
CWinApp* AfxGetApp();