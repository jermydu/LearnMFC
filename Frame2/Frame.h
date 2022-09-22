#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#include <iostream>

using namespace std;
/**
* ģ��MFC����ĳ�ʼ������
 */


class CObject
{
public:
	CObject()
	{
		cout << "CObject ���캯��ִ����" << endl;
	}
	~CObject()
	{
		cout << "CObject ��������ִ����" << endl;
	}
};

class CCmdTarget :public CObject
{
public:
	CCmdTarget()
	{
		cout << "CCmdTarget ���캯��ִ����" << endl;
	}
	~CCmdTarget()
	{
		cout << "CCmdTarget ��������ִ����" << endl;
	}
};

class CWinThread :public CCmdTarget
{
public:
	CWinThread()
	{
		cout << "CWinThread ���캯��ִ����" << endl;
	}
	~CWinThread()
	{
		cout << "CWinThread ��������ִ����" << endl;
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
		cout << "CWinApp ���캯��ִ����" << endl;
	}
	~CWinApp()
	{
		cout << "CWinApp ��������ִ����" << endl;
	}
	//��ÿһ������ֻ��һ�Ρ��Ķ���
	virtual BOOL InitApplication()
	{
		cout << "CWinApp::InitApplication()" << endl;
		return TRUE;
	}
	//����ÿһ��ִ�и��嶼����һ�Ρ��Ķ���
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
		cout << "CWnd ���캯��ִ����" << endl;
	}
	~CWnd()
	{
		cout << "CWnd ��������ִ����" << endl;
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
		cout << "CView ���캯��ִ����" << endl;
	}
	~CView()
	{
		cout << "CView ��������ִ����" << endl;
	}
};

class CFrameWnd :public CWnd
{
public:
	CFrameWnd()
	{
		cout << "CFrameWnd ���캯��ִ����" << endl;
	}
	~CFrameWnd()
	{
		cout << "CFrameWnd ��������ִ����" << endl;
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
		cout << "CDocument ���캯��ִ����" << endl;
	}
	~CDocument()
	{
		cout << "CDocument ��������ִ����" << endl;
	}
};

//ȫ�ֺ���
CWinApp* AfxGetApp();