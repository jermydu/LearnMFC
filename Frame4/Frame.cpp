
#include "MyFrame.h"

extern CMyWinApp theApp;


static char szCObject[] = "CObject";
struct CRuntimeClass CObject::classCObject
{
	szCObject,sizeof(CObject),0xffff,nullptr,nullptr
};
static AFX_CLASSINIT _init_CObject(&CObject::classCObject);
CRuntimeClass* CRuntimeClass::pFirstClass = nullptr;
AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNewClass)
{
	pNewClass->m_pNextClass = CRuntimeClass::pFirstClass;
	CRuntimeClass::pFirstClass = pNewClass;
}

CRuntimeClass* CObject::GetRuntimeClass() const 
{
	return &CObject::classCObject;
}

BOOL CObject::IsKindOf(const CRuntimeClass* pClass)const
{
	//循着链表 向上查找
	CRuntimeClass* pClassThis = GetRuntimeClass();
	while (pClassThis != nullptr)
	{
		if (pClassThis == pClass)
			return TRUE;
		pClassThis = pClassThis->m_pBaseClass;
	}
	return FALSE;
}

//---------------动态创建新增
CObject* CRuntimeClass::CreateObject()
{
	if (m_pfnCreateObject == nullptr)
	{
		std::cout << "尝试创建没有声明动态创建的类对象" << std::endl;
		return nullptr;
	}
	CObject* pObj = nullptr;
	pObj = (*m_pfnCreateObject)();

	return pObj;
}

CRuntimeClass* PASCAL CRuntimeClass::Load()
{
	char szClassName[64];
	CRuntimeClass* pRunTimeClass;

	std::cout << "输入类名：" << std::endl;
	std::cin >> szClassName;

	for (pRunTimeClass = pFirstClass; pRunTimeClass != nullptr; pRunTimeClass = pRunTimeClass->m_pNextClass)
	{
		if (strcmp(szClassName, pRunTimeClass->m_lpszClassName) == 0)
		{
			return pRunTimeClass;
		}
	}
	std::cout << "类名：" << szClassName << "没有找到" << std::endl;
	return nullptr;
}
//---------------动态创建新增

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

IMPLEMENT_DYNAMIC(CCmdTarget, CObject)
IMPLEMENT_DYNAMIC(CWinThread, CCmdTarget)
IMPLEMENT_DYNAMIC(CWinApp, CWinThread)
//---------------动态创建修改
IMPLEMENT_DYNCREATE(CWnd, CCmdTarget)
IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)
//---------------动态创建修改
IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)
IMPLEMENT_DYNAMIC(CView, CWnd)

CWinApp* AfxGetApp()
{
	return theApp.m_pCurrentWinApp;
}