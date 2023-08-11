#include "MyFrame.h"
CMyWinApp theApp;

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)

//---------------动态创建修改
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)
IMPLEMENT_DYNCREATE(CMyView, CView)

BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

void main()
{
	CWinApp* pApp = AfxGetApp();

	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();

	
	//测试动态创建
	CRuntimeClass* pRuntimeClass;
	CObject* pObj;
	while (true)
	{
		if ((pRuntimeClass = CRuntimeClass::Load()) == nullptr)
		{
			break;
		}
		pObj = pRuntimeClass->CreateObject();
		if (pObj)
			pObj->SayHello();
	}
}