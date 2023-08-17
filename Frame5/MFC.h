#pragma once
// 消息映射

#define TRUE 1
#define FALSE 0

typedef char* LPSTR;
typedef const char* LPCSTR;

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned int  UINT;
typedef int  INT;
typedef long LONG;
typedef int  BOOL;

#define WM_COMMAND								0x0111
#define CObjectid								0xffff
#define  CCmdTargetid							1
#define		CWndThreadid						11
#define			CWinAppid						111
#define				CMyWinAppid					1111
#define		CWndid								12
#define			CFrameWndid						121
#define				CMyFrameWndid				1211
#define			CViewid							122
#define				CMyViewid					1221
#define		CDocumentid							13
#define		CMyDocid							131

#include <iostream>

extern struct AFX_MSGMAP_ENTRY;

struct AFX_MSGMAP
{
	AFX_MSGMAP* pBaseMessageMap;
	AFX_MSGMAP_ENTRY* lpEntries;
};

#define DECLARE_MESSAGE_MAP() \
	static AFX_MSGMAP_ENTRY _messageEntries[];\
	static AFX_MSGMAP messageMap;\
	virtual AFX_MSGMAP* GetMessageMap() const;

#define BEGINE_MESSAGE_MAP(theClass, baseClass)\
	AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return &theClass::messageMap;}\
	AFX_MSGMAP theClass::messageMap = \
		{ &(baseClass::messageMap),(AFX_MSGMAP_ENTRY*)&(theClass::_messageEntries)};\
	AFX_MSGMAP_ENTRY theClass::_messageEntries[] = \
		{

#define END_MESSAGE_MAP() \
	{ 0, 0 ,0,0, AfxSig_end,(AFX_PMSG)0}\
	};

class CObject
{
public:
	CObject() {}
	~CObject() {}
};

class CCmdTarget : public CObject
{
public:
	CCmdTarget() {}
	~CCmdTarget() {}

	DECLARE_MESSAGE_MAP()
};

//消息映射宏
typedef void (CCmdTarget::*AFX_PMSG)(void);

struct AFX_MSGMAP_ENTRY
{
	UINT nMessage;				//windows 消息
	UINT nCode;					//Control code or WM_NOTIFY code
	UINT nID;					//Control id(windows 消息则为0)
	UINT nLastID;				//用于指定控件id范围
	UINT nSig;					//信号或者action 
	AFX_PMSG pfn;				//函数调用或者特定值
};

class CDocument : public CCmdTarget
{
public:
	CDocument() {}
	~CDocument() {}
	DECLARE_MESSAGE_MAP()
};

class CWinThread : public CCmdTarget
{
public:
	CWinThread() {}
	~CWinThread() {}
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
		return 1;
	}
};

class CWnd : public CCmdTarget
{
public:
	CWnd() {}
	~CWnd() {}
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
	DECLARE_MESSAGE_MAP()
};

class CWinApp : public CWinThread
{
public:
	CWinApp* m_pCurrentWinApp;
	CWnd* m_pMainWnd;
	CWinApp() { m_pCurrentWinApp = this; }
	~CWinApp() {}
	BOOL InitInstance()override
	{
		std::cout << "CWinApp::InitInstance" << std::endl;
		return TRUE;
	}

	int Run()override
	{
		return CWinThread::Run();
	}
	virtual BOOL InitApplication()
	{
		return TRUE;
	}
	DECLARE_MESSAGE_MAP()
};

class CFrameWnd : public CWnd
{
public:
	CFrameWnd() {}
	~CFrameWnd() {}
	BOOL Create()override;
	virtual BOOL PreCreateWindow();

	DECLARE_MESSAGE_MAP()
};

class CView : public CWnd
{
public:
	CView() {}
	~CView() {}

	DECLARE_MESSAGE_MAP()
};

extern CWinApp* AfxGetApp();