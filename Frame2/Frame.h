#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#include <iostream>

using namespace std;
/**
 * 从零开始模拟MFC程序
 * 继承结构
 * |CObject
 *		|CCmdTarget
 *			|CWinThread
 *				|CWinApp
 *					|MyWinApp
 *			|CWnd
 *				|CView
 *					|MyView
 *				|CFrameWnd
 *					|MyFrameWnd
 *			|CDocument
 *				|MyDoc
 */


class CObject
{
public:
	CObject(){}
	~CObject(){}
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
	CWinThread(){}
	~CWinThread(){}
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
		
	}
	~CWinApp(){}

	virtual BOOL InitApplication()
	{
		cout << "CWinApp::InitApplication()" << endl;
		return TRUE;
	}

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
	CWnd(){	}
	~CWnd(){}

};

class CView :public CWnd
{
public:
	CView(){}
	~CView(){}
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd(){}
	~CFrameWnd(){}
};

class CDocument :public CCmdTarget
{
public:
	CDocument(){}
	~CDocument(){}
};

//全局函数
CWinApp* AfxGetApp();



