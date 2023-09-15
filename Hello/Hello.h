#pragma once
/**
* 最简单的MFC手写程序
* 声明两个类型 CMyWinApp 和 CMyFrameWnd
*/

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp()
	{
		//通过此处打断点进入CWinApp构造函数
	}
	BOOL InitInstance() override;			//每个应用程序都应该改写此函数
	BOOL OnIdle(LONG lCount) override;		//处理闲置时间
};

class CMyFrameWnd : public CFrameWnd
{
public:
	CMyFrameWnd();					//构造
	afx_msg void OnPaint();			//for WM_PAINT
	afx_msg void OnAbout();			//for WM_COMMAND (IDM_ABOUT)
	void IdleTimeHander(LONG lCount);

private:
	DECLARE_MESSAGE_MAP()
	static VOID CALLBACK LineDDACallback(int, int ,LPARAM);  //callback 函数必须是 static 才能去除隐藏的 this 指针
};
