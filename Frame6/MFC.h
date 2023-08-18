#pragma once
// 消息流转  子消息映射基础上修改

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

typedef UINT WPARAM;
typedef LONG LPARAM;
typedef LONG LRESULT;
typedef int HWND;

#define WM_COMMAND								0x0111
#define WM_CREATE								0x0001
#define WM_PAINT								0x000F
#define WM_NOTIFY								0x004E


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

	//>>>>>>>>>>>消息流转新增
	virtual BOOL OnCmdMsg(UINT nID, int nCode);
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

	//>>>>>>>>>>>消息流转新增
	BOOL OnCmdMsg(UINT nID, int nCode) override;
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

	//>>>>>>>>>>>消息流转新增
	virtual LRESULT WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
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
extern class CView;
class CFrameWnd : public CWnd
{
public:
	CFrameWnd() {}
	~CFrameWnd() {}
	BOOL Create()override;
	virtual BOOL PreCreateWindow();

	DECLARE_MESSAGE_MAP()

	//>>>>>>>>>>>消息流转新增
	CView* m_pCurActiveView;				//当前活动view

	CView* GetCurActiveView()const;
	BOOL OnCmdMsg(UINT nID, int nCode) override;
	BOOL OnCommand(WPARAM wParam, LPARAM lParam)override;

	friend CView;
};

class CView : public CWnd
{
public:
	CView() {}
	~CView() {}

	DECLARE_MESSAGE_MAP()

	//>>>>>>>>>>>消息流转新增
	CDocument* m_pDocument;			
	BOOL OnCmdMsg(UINT nID, int nCode)override;

	friend CFrameWnd;
};

extern CWinApp* AfxGetApp();

//>>>>>>>>>>>消息流转新增
LRESULT AfxWndProc(HWND hwnd,UINT nMsg,WPARAM wParam,LPARAM lParam,CWnd* pWnd);
LRESULT AfxCallWndProc(CWnd* pWnd,HWND hwnd,UINT nMsg,WPARAM wParam,LPARAM lParam);