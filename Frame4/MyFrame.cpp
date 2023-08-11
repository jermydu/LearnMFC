#include "MyFrame.h"
CMyWinApp theApp;

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)

//---------------��̬�����޸�
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

	
	//���Զ�̬����
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