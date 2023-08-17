#include "My.h"
#include "AFXMSG.h"
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}

BEGINE_MESSAGE_MAP(CMyWinApp, CWinApp)
ON_COMMAND(CMyWinAppid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
ON_COMMAND(CMyFrameWndid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CMyDoc, CDocument)
ON_COMMAND(CMyDocid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CMyView, CView)
ON_COMMAND(CMyViewid, 0)
END_MESSAGE_MAP()

void PrintClassInfo(AFX_MSGMAP_ENTRY* lpEntries)
{
	using ClassInfo  = struct _ClassInfo
	{
		int classid;
		const char* className;
	};
	ClassInfo classInfo[] = {
		CCmdTargetid,"CCmdTarget",
		CWndid,"CWnd",
		CDocumentid,"CDocument",
		CViewid,"CView",
		CFrameWndid,"CFrameWnd",
		CViewid,"CView",
		CWinAppid,"CWinApp",
		CMyWinAppid,"CMyWinApp",
		CMyFrameWndid,"CMyFrameWnd",
		CMyDocid,"CMyDoc",
		CMyViewid,"CMyView",
	};

	for (const auto& it : classInfo)
	{
		if (it.classid == lpEntries->nID)
		{
			std::cout << "[class]" << it.className << "[classid]" << it.classid << std::endl;
			break;
		}
	}
}

void PrintClassMessageMap(AFX_MSGMAP* lpMsg)
{
	for (lpMsg != nullptr; lpMsg = lpMsg->pBaseMessageMap;)
	{
		PrintClassInfo(lpMsg->lpEntries);
	}
}

void main()
{
	CWinApp* pApp = AfxGetApp();

	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();


	CMyView* pMyView = new CMyView();
	CMyDoc* pMyDoc = new CMyDoc();
	CMyFrameWnd* pMyFrame = new CMyFrameWnd();

	std::cout << ">>>>>>>>>>>>CMyView msg map" << std::endl;
	if (pMyView)
		PrintClassMessageMap(pMyView->GetMessageMap());
	std::cout << ">>>>>>>>>>>>CMyDoc msg map" << std::endl;
	if (pMyView)
		PrintClassMessageMap(pMyDoc->GetMessageMap());
	std::cout << ">>>>>>>>>>>>CMyFrameWnd msg map" << std::endl;
	if (pMyView)
		PrintClassMessageMap(pMyFrame->GetMessageMap());
}

