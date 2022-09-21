#include "MyFrame.h"

//全局对象
MyWinApp theApp;

void main()
{
	cout << "进入 main函数" << endl;
	CWinApp* pApp = AfxGetApp();
	cout << "退出 main函数" << endl;
}
