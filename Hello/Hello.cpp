
#include "StdAfx.h"
#include "Hello.h"
#include "Resource.h"

CMyWinApp theApp;		//应用程序对象

//CMyWinApp 成员函数
BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BOOL CMyWinApp::OnIdle(LONG lCount)
{
	CMyFrameWnd* pWnd = (CMyFrameWnd*)m_pMainWnd;
	pWnd->IdleTimeHander(lCount);

	return TRUE;
}

//CMyFrameWnd 成员函数
CMyFrameWnd::CMyFrameWnd()
{
	//创建菜单 MainMenu 定义与 rc 文件 
	Create(NULL, //窗口类
		("Hello MFC"),//窗口名称
		WS_OVERLAPPEDWINDOW,//窗口风格
		rectDefault,		//窗口位置大小
		NULL,				//父窗口
		("MainMenu"));		//指定菜单 "MainMenu" RC中定义
}

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(IDM_ABOUT, OnAbout)
END_MESSAGE_MAP()

VOID CALLBACK CMyFrameWnd::LineDDACallback(int x, int y, LPARAM lpDc)
{
	CString str = ("Hello Dujinwei");
	CDC* pDc = (CDC*)lpDc;
	if (pDc)
	{
		pDc->TextOut(x,y, str);
	}
	//为了延迟下落速度
	for (int i = 1; i < 5000000; i++);
}

void CMyFrameWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect rt;
	GetClientRect(rt);
	dc.SetTextAlign(TA_BOTTOM | TA_CENTER);

	::LineDDA(rt.right / 2, 0, rt.right / 2, rt.bottom / 2, (LINEDDAPROC)LineDDACallback, (LPARAM)(LPVOID)&dc);
}

void CMyFrameWnd::OnAbout()
{
	CDialog dlgAbout("AboutBox", this);
	dlgAbout.DoModal();
}

void CMyFrameWnd::IdleTimeHander(LONG lCount)
{
	CString str;
	CRect rt(10,10,200,30);
	CDC* pDc = new CClientDC(this);

	str.Format(("%010d"), lCount);
	pDc->DrawText(str,&rt,DT_LEFT | DT_TOP);
}