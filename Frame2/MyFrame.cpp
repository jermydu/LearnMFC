#include "MyFrame.h"

//ȫ�ֶ���
MyWinApp theApp;

void main()
{
	CWinApp* pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
}
