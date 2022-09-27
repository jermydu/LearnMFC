#pragma once
#include <iostream>
#include "Frame.h"

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp() {};
	~CMyWinApp() {};
	BOOL InitInstance()override;
};

class CMyFrameWnd : public CFrameWnd
{
public:
	CMyFrameWnd() { Create(); };
	~CMyFrameWnd() {};
};

class CMyDoc : public CDocument
{
public:
	CMyDoc() {};
	~CMyDoc() {};
};

class CMyView : public CView
{
public:
	CMyView() {};
	~CMyView() {};
};

//È«¾Öº¯Êý
void PrintAllClasses();
