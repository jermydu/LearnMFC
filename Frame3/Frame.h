#pragma once
#include <iostream>
/**
 * ����¼���� CRuntimeClass
 */

#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR  LPSTR
typedef char* LPSTR;
#define UINT int
#define PASCAL _stdcall

//��
class CObject;

//��¼�е�����Ϣ
struct CRuntimeClass
{
	LPCSTR	m_lpszClassName;							//����
	int		m_nObjectSize;
	UINT	m_wSchema;									//�������ģʽ��
	CObject* (PASCAL* m_pfnCreateObject)();				//����ָ��  ָ�������
	CRuntimeClass* m_pBaseClass;						//

	//CRuntimeClass���������ڼ��б���
	static CRuntimeClass* pFirstClass;					//����ͷ
	CRuntimeClass* m_pNextClass;						//ע���������
};

#define  DECLARE_DYNAMIC(class_name) \
public:	\
	static CRuntimeClass class##class_name;	\
	virtual CRuntimeClass* GetRuntimeClass() const;

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)

//DECLARE_DYNAMIC �ĺ��ľ�������� ������¼����Ĵ��ӹ���
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

#define IMPLEMENT_DYNAMIC(class_name,base_class_name) \
	_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,nullptr)

//���е�ͷ��������Ҫ�ر���Ĵ������ܹ�����һ��Ĵ�����Ϊģʽ�����ǵ����ԴCObject��
//���������ֳɵĺ�DECLARE_DYNAMIC ��IMPLEMENT_DYNAMIC�������ر����
class CObject
{
public:
	CObject() {};
	~CObject() {};
	virtual CRuntimeClass* GetRuntimeClass() const;
	static CRuntimeClass classCObject;
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
	DECLARE_DYNAMIC(CWnd)
public:
	CWnd() {};
	~CWnd() {};
	virtual BOOL Create();
	BOOL CreateEx();
	virtual BOOL PreCreateWindow();
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
	DECLARE_DYNAMIC(CFrameWnd)
public:
	CFrameWnd() {};
	~CFrameWnd() {};
	BOOL Create()override;
	virtual BOOL PreCreateWindow();
};

class CView : public CWnd
{
	DECLARE_DYNAMIC(CView)
public:
	CView() {};
	~CView() {};
};

//ȫ�ֺ���
CWinApp* AfxGetApp();


