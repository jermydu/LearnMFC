#pragma once
/**
* ��򵥵�MFC��д����
* ������������ CMyWinApp �� CMyFrameWnd
*/

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp()
	{
		//ͨ���˴���ϵ����CWinApp���캯��
	}
	BOOL InitInstance() override;			//ÿ��Ӧ�ó���Ӧ�ø�д�˺���
	BOOL OnIdle(LONG lCount) override;		//��������ʱ��
};

class CMyFrameWnd : public CFrameWnd
{
public:
	CMyFrameWnd();					//����
	afx_msg void OnPaint();			//for WM_PAINT
	afx_msg void OnAbout();			//for WM_COMMAND (IDM_ABOUT)
	void IdleTimeHander(LONG lCount);

private:
	DECLARE_MESSAGE_MAP()
	static VOID CALLBACK LineDDACallback(int, int ,LPARAM);  //callback ���������� static ����ȥ�����ص� this ָ��
};
