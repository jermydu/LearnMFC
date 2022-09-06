#pragma once
#include "Frame.h"

class MyWinApp : public CWinApp
{
public:
	MyWinApp()
	{
		cout << "MyWinApp 构造函数执行了" << endl;
	}
	~MyWinApp()
	{
		cout << "MyWinApp 析构函数执行了" << endl;
	}
};

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
};

