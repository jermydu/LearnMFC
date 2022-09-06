#pragma once
#include <iostream>

using namespace std;
/**
 * 从零开始模拟MFC程序
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



