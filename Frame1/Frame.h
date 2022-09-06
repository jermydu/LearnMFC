#pragma once
#include <iostream>

using namespace std;
/**
 * ���㿪ʼģ��MFC����
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



