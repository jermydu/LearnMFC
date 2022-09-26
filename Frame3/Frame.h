#pragma once

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

#define DECLARE_DYNAMIC(class_name) \
	public:\	
static CRuntimeClass class##class_name;	\
