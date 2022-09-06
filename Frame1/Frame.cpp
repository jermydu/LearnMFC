#include "Frame.h"
#include "MyFrame.h"  


extern MyWinApp theApp;
CWinApp* AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}
