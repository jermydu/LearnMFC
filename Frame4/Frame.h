#pragma once
#include <iostream>
/**
 * 动态创建
 */

#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR  LPSTR
typedef char* LPSTR;
#define UINT int
#define PASCAL _stdcall

//类
class CObject;

//型录中的类信息
struct CRuntimeClass
{
	LPCSTR	m_lpszClassName;							//类名
	int		m_nObjectSize;
	UINT	m_wSchema;									//加载类的模式号
	CObject* (PASCAL* m_pfnCreateObject)();				//函数指针  指向抽象类
	CRuntimeClass* m_pBaseClass;						//

	//---------------动态创建新增
	CObject* CreateObject();							//构建对象
	static CRuntimeClass* PASCAL Load();
	//---------------动态创建新增

	//CRuntimeClass对象链接在链表中
	static CRuntimeClass* pFirstClass;					//链表头 first 指针 全局变量
	CRuntimeClass* m_pNextClass;						//链表next指针
};

#pragma region 类型录网宏定义
//CRuntimeClass 对象和获取对象地址的函数
#define  DECLARE_DYNAMIC(class_name) \
public:	\
	static CRuntimeClass class##class_name;	\
	virtual CRuntimeClass* GetRuntimeClass() const;

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

//DECLARE_DYNAMIC 的核心就是这个类 负责型录链表的串接工作
struct AFX_CLASSINIT
{
	AFX_CLASSINIT(CRuntimeClass* pNewClass);
};

#define _IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,wSchema,pfnNew)\
	static char _lpsz##class_name[] = #class_name;\
	CRuntimeClass class_name::class##class_name = \
	{ \
		_lpsz##class_name,sizeof(class_name),wSchema,pfnNew,RUNTIME_CLASS(base_class_name),nullptr\
	};\
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name);\
	CRuntimeClass* class_name::GetRuntimeClass()const \
	{ \
		return &class_name::class##class_name;\
	}


//各个CRuntimeClass 对象连接
#define IMPLEMENT_DYNAMIC(class_name,base_class_name) \
	_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,nullptr)
#pragma endregion

#pragma region 动态创建宏定义

#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name)	\
	static CObject* PASCAL CreateObject();	

#define IMPLEMENT_DYNCREATE(class_name,base_class_name)\
	CObject* PASCAL class_name::CreateObject()\
	{	return new class_name;}\
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, class_name::CreateObject)


#pragma endregion


class CObject
{
public:
	CObject() {};
	~CObject() {};
	virtual CRuntimeClass* GetRuntimeClass() const;
	static CRuntimeClass classCObject;

	BOOL  IsKindOf(const CRuntimeClass* pClass)const;

	//---------------动态创建增加
	virtual void SayHello()
	{
		std::cout << "hello CObject" << std::endl;
	}
};

class CCmdTarget : public CObject
{
	DECLARE_DYNAMIC(CCmdTarget)
public:
	CCmdTarget() {};
	~CCmdTarget() {};
};

class CDocument : public CCmdTarget
{
	DECLARE_DYNAMIC(CDocument)
public:
	CDocument() {};
	~CDocument() {};
};

class CWinThread : public CCmdTarget
{
	DECLARE_DYNAMIC(CWinThread)
public:
	CWinThread() {};
	~CWinThread() {};
	virtual BOOL InitInstance()
	{
		return TRUE;
	}
	virtual int Run()
	{
		return 1;
	}
};

class CWnd : public CCmdTarget
{
	//---------------动态创建修改
	DECLARE_DYNCREATE(CWnd)
public:
	CWnd() {};
	~CWnd() {};
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();

	//---------------动态创建增加
	void SayHello() override
	{
		std::cout << "hello CWnd" << std::endl;
	}
};

class CWinApp : public CWinThread
{
	DECLARE_DYNAMIC(CWinApp)
public:
	CWinApp* m_pCurrentWinApp;
	CWnd* m_pMainWnd;
	CWinApp() { m_pCurrentWinApp = this; };
	~CWinApp() {};
	BOOL InitInstance()override
	{
		std::cout << "CWinApp::InitInstance" << std::endl;
		return TRUE;
	}
	
	int Run()override
	{
		return CWinThread::Run();
	}
	virtual BOOL InitApplication()
	{
		return TRUE;
	}
};

class CFrameWnd : public CWnd
{
	//---------------动态创建新增
	DECLARE_DYNCREATE(CFrameWnd)
public:
	CFrameWnd() {};
	~CFrameWnd() {};
	BOOL Create()override;
	virtual BOOL PreCreateWindow();

	//---------------动态创建增加
	void SayHello() override
	{
		std::cout << "hello CFrameWnd" << std::endl;
	}
};

class CView : public CWnd
{
	DECLARE_DYNAMIC(CView)
public:
	CView() {};
	~CView() {};
};

//全局函数
CWinApp* AfxGetApp();


