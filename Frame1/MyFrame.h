#pragma once
#include "Frame.h"

class MyWinApp : public CWinApp
{
public:
	MyWinApp()
	{
		cout << "MyWinApp ���캯��ִ����" << endl;
	}
	~MyWinApp()
	{
		cout << "MyWinApp ��������ִ����" << endl;
	}
};

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
};

