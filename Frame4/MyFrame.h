#pragma once
#include <iostream>
#include "Frame.h"

class CMyWinApp : public CWinApp
{
	DECLARE_DYNAMIC(CMyWinApp)
public:
	CMyWinApp() {};
	~CMyWinApp() {};
	BOOL InitInstance()override;
};

class CMyFrameWnd : public CFrameWnd
{
	//---------------动态创建新增
	DECLARE_DYNCREATE(CMyFrameWnd)
public:
	CMyFrameWnd() { Create(); };
	~CMyFrameWnd() {};

	void SayHello() override
	{
		std::cout << "hello CFrameWnd" << std::endl;
	}
};

class CMyDoc : public CDocument
{
	//---------------动态创建新增
	DECLARE_DYNCREATE(CMyDoc)
public:
	CMyDoc() {};
	~CMyDoc() {};

	void SayHello() override
	{
		std::cout << "hello CMyDoc" << std::endl;
	}
};

class CMyView : public CView
{
	//---------------动态创建新增
	DECLARE_DYNCREATE(CMyView)
public:
	CMyView() {};
	~CMyView() {};

	void SayHello() override
	{
		std::cout << "hello CMyView" << std::endl;
	}
};
