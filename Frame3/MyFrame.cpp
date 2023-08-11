#include "MyFrame.h"
CMyWinApp theApp;

IMPLEMENT_DYNAMIC(CMyWinApp, CWinApp)
IMPLEMENT_DYNAMIC(CMyFrameWnd, CFrameWnd)
IMPLEMENT_DYNAMIC(CMyDoc, CDocument)
IMPLEMENT_DYNAMIC(CMyView, CView)

BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

void PrintAllClasses()
{
	CRuntimeClass* pClass;

	for (pClass = CRuntimeClass::pFirstClass; pClass != nullptr; pClass = pClass->m_pNextClass)
	{
		std::cout << pClass->m_lpszClassName << std::endl;
		std::cout << pClass->m_nObjectSize << std::endl;
		std::cout << pClass->m_wSchema << std::endl;
	}
}

void main()
{
	CWinApp* pApp = AfxGetApp();

	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();

	PrintAllClasses();

	CMyView* pMyView = new CMyView;
	std::cout << "--------------------------------" << std::endl;
	std::cout << pMyView->IsKindOf(RUNTIME_CLASS(CView)) << std::endl;
	std::cout << pMyView->IsKindOf(RUNTIME_CLASS(CWnd)) << std::endl;
	std::cout << pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd)) << std::endl;
	std::cout << pMyView->IsKindOf(RUNTIME_CLASS(CWinApp)) << std::endl;
}