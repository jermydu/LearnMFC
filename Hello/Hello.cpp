
#include "StdAfx.h"
#include "Hello.h"
#include "Resource.h"

CMyWinApp theApp;		//Ӧ�ó������

//CMyWinApp ��Ա����
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

//CMyFrameWnd ��Ա����
CMyFrameWnd::CMyFrameWnd()
{
	//�����˵� MainMenu ������ rc �ļ� 
	Create(NULL, //������
		("Hello MFC"),//��������
		WS_OVERLAPPEDWINDOW,//���ڷ��
		rectDefault,		//����λ�ô�С
		NULL,				//������
		("MainMenu"));		//ָ���˵� "MainMenu" RC�ж���
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
	//Ϊ���ӳ������ٶ�
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