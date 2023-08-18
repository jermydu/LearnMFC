#include "My.h"
#include "AFXMSG.h"
extern CMyWinApp theApp;
//>>>>>>>>>>>��Ϣ��ת����
extern void PrintClassInfo(AFX_MSGMAP_ENTRY* lpEntries);
BOOL CWnd::Create()
{
	return TRUE;
}

BOOL CWnd::CreateEx()
{
	PreCreateWindow();
	return TRUE;
}

BOOL CWnd::PreCreateWindow()
{
	return TRUE;
}

BOOL CFrameWnd::Create()
{
	CreateEx();
	return TRUE;
}

BOOL CFrameWnd::PreCreateWindow()
{
	return TRUE;
}

CWinApp* AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}

//>>>>>>����ͷ���⴦�� ��ֵ CCmdTarget
AFX_MSGMAP* CCmdTarget::GetMessageMap() const
{
	return &CCmdTarget::messageMap;
}

AFX_MSGMAP CCmdTarget::messageMap = {
	NULL,
	& CCmdTarget::_messageEntries[0]
};

AFX_MSGMAP_ENTRY CCmdTarget::_messageEntries[] = {
	{0,0,CCmdTargetid,0,AfxSig_end,0}
};
//<<<<<����ͷ���⴦�� ��ֵ CCmdTarget

//>>>>>>>>>>>��Ϣ��ת����
BOOL CCmdTarget::OnCmdMsg(UINT nID, int nCode)
{
	std::cout << "CCmdTarget::OnCmdMsg" << std::endl;
	AFX_MSGMAP* pMessageMap;
	AFX_MSGMAP_ENTRY* pEntry;

	for (pMessageMap = GetMessageMap(); pMessageMap != NULL; pMessageMap = pMessageMap->pBaseMessageMap)
	{
		
		pEntry = pMessageMap->lpEntries;
		PrintClassInfo(pEntry);
	}

	return FALSE;
}

LRESULT CWnd::WindowProc(UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	AFX_MSGMAP* pMessageMap;
	AFX_MSGMAP_ENTRY* pEntry;
	std::cout << "WindowProc" << std::endl;
	if (nMsg == WM_COMMAND)
	{
		//OnCommand �麯�� this
		if (OnCommand(wParam, lParam))
			return 1L;
		else
		{
			return (LRESULT)DefWindowProc(nMsg, wParam, lParam);
		}
	}
	//������� WM_COMMAND ��Ϣ���α���������Ϣ
	for (pMessageMap = GetMessageMap(); pMessageMap != NULL; pMessageMap = pMessageMap->pBaseMessageMap)
	{
		pEntry = pMessageMap->lpEntries;
		PrintClassInfo(pEntry);
	}
	return 0;
}
LRESULT CWnd::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}
BOOL CWnd::OnCommand(WPARAM wParam, LPARAM lParam)
{
	//�麯�� CCmdTarget::OnCmdMsg
	std::cout << "CWnd::OnCommand" << std::endl;
	return OnCmdMsg(0,0);
}

BOOL CFrameWnd::OnCommand(WPARAM wParam, LPARAM lParam)
{
	std::cout << "CFrameWnd::OnCommand" << std::endl;
	return CWnd::OnCommand(wParam,lParam);
}

CView* CFrameWnd::GetCurActiveView()const 
{
	return m_pCurActiveView;
}

BOOL CFrameWnd::OnCmdMsg(UINT nID, int nCode)
{
	std::cout << "CFrameWnd::OnCmdMsg" << std::endl;
	CView* pView = GetCurActiveView();
	if (pView->OnCmdMsg(nID, nCode))
		return TRUE;
	if (CWnd::OnCmdMsg(nID, nCode))
		return TRUE;
	CWinApp* pApp = AfxGetApp();
	if (pApp->OnCmdMsg(nID, nCode))
		return TRUE;

	return FALSE;
}

BOOL CDocument::OnCmdMsg(UINT nID, int nCode)
{
	std::cout << "CDocument::OnCmdMsg" << std::endl;
	if (CCmdTarget::OnCmdMsg(nID, nCode))
		return TRUE;
	return FALSE;
}

BOOL CView::OnCmdMsg(UINT nID, int nCode)
{
	std::cout << "CView::OnCmdMsg" << std::endl;
	if (CWnd::OnCmdMsg(nID, nCode))
		return TRUE;

	BOOL bHandle = FALSE;
	bHandle = m_pDocument->OnCmdMsg(nID,nCode);
	return bHandle;
}

LRESULT AfxWndProc(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam, CWnd* pWnd)
{
	return AfxCallWndProc(pWnd,hwnd,nMsg,wParam,lParam);
}

LRESULT AfxCallWndProc(CWnd* pWnd, HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	//WindowProc Ϊ�麯��
	std::cout << "AfxCallWndProc" << std::endl;
	LRESULT lResult = pWnd->WindowProc(nMsg, wParam,lParam);

	return lResult;
}


//<<<<<<<<<<<<��Ϣ��ת����

BEGINE_MESSAGE_MAP(CWnd, CCmdTarget)
ON_COMMAND(CWndid,0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CDocument, CCmdTarget)
ON_COMMAND(CDocumentid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CFrameWnd, CWnd)
ON_COMMAND(CFrameWndid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CView, CWnd)
ON_COMMAND(CViewid, 0)
END_MESSAGE_MAP()

BEGINE_MESSAGE_MAP(CWinApp, CCmdTarget)
ON_COMMAND(CWinAppid, 0)
END_MESSAGE_MAP()