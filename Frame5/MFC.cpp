#include "My.h"
#include "AFXMSG.h"
extern CMyWinApp theApp;
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

//>>>>>>链表头特殊处理 赋值 CCmdTarget
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
//<<<<<链表头特殊处理 赋值 CCmdTarget

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