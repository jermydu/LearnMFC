#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#include <iostream>

using namespace std;
/**
 * ���㿪ʼģ��MFC����
 * �̳нṹ
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

//ȫ�ֺ���
CWinApp* AfxGetApp();



