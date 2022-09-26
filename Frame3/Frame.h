#pragma once

/**
 * 类型录网与 CRuntimeClass
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

	//CRuntimeClass对象链接在简单列表中
	static CRuntimeClass* pFirstClass;					//链表头
	CRuntimeClass* m_pNextClass;						//注册类的链表
};

#define DECLARE_DYNAMIC(class_name) \
	public:\	
static CRuntimeClass class##class_name;	\
