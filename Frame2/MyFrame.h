#pragma once
#include "Frame.h"

class MyFrameWnd : public CFrameWnd
{
public:
	MyFrameWnd()
	{
		cout << "MyFrameWnd ���캯��ִ����" << endl;
		Create();
	}
	~MyFrameWnd()
	{
		cout << "MyFrameWnd ��������ִ����" << endl;
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
	CWnd* m_pMainWnd;
	//������д
	BOOL InitInstance()override
	{
		cout << "MyWinApp::InitApplication()" << endl;
		m_pMainWnd = new MyFrameWnd;
		return TRUE;
	}
};