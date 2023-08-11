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
	DECLARE_DYNAMIC(CMyFrameWnd)
public:
	CMyFrameWnd() { Create(); };
	~CMyFrameWnd() {};
};

class CMyDoc : public CDocument
{
	DECLARE_DYNAMIC(CMyDoc)
public:
	CMyDoc() {};
	~CMyDoc() {};
};

class CMyView : public CView
{
	DECLARE_DYNAMIC(CMyView)
public:
	CMyView() {};
	~CMyView() {};
};

//È«¾Öº¯Êý
void PrintAllClasses();
