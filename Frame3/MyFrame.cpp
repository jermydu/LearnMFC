#include "MyFrame.h"
CMyWinApp theApp;

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
}