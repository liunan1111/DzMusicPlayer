#include "DzMusicPlayerUIApp.h"

void DzMusicPlayerApp::InitWindow()
{
	RECT rc = { 0 };
	if( !::GetClientRect(m_hWnd, &rc) ) return;
	rc.right = rc.left + /*524*/380;
	rc.bottom = rc.top + 500/*500*/;
	if( !::AdjustWindowRectEx(&rc, GetWindowStyle(m_hWnd), (!(GetWindowStyle(m_hWnd) & WS_CHILD) && (::GetMenu(m_hWnd) != NULL)), GetWindowExStyle(m_hWnd)) ) return;
	int ScreenX = GetSystemMetrics(SM_CXSCREEN);
	int ScreenY = GetSystemMetrics(SM_CYSCREEN);

	::SetWindowPos(m_hWnd, NULL, (ScreenX - (rc.right - rc.left)) / 2, 
		(ScreenY - (rc.bottom - rc.top)) / 2, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_SHOWWINDOW);
}

void DzMusicPlayerApp::Notify( TNotifyUI& msg )
{

}

LRESULT DzMusicPlayerApp::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;

	if( uMsg == WM_CREATE )  
	{
		m_PaintManager.Init(m_hWnd);

		CDialogBuilder builder;
		STRINGorID xml(GetSkinRes());
		CControlUI* pRoot = builder.Create(xml, _T("xml"), 0, &m_PaintManager);
		ASSERT(pRoot && "Failed to parse XML");

		m_PaintManager.AttachDialog(pRoot);
		m_PaintManager.AddNotifier(this);
		InitWindow(); 

		return lRes;
	}
	else if (uMsg == WM_CLOSE)
	{
		OnClose(uMsg, wParam, lParam, bHandled);		
	}
	else if (uMsg == WM_DESTROY)
	{
		OnDestroy(uMsg, wParam, lParam, bHandled);		
	}

	//if( uMsg == WM_NCCALCSIZE)
	//{
	//	return 0;
	//}

	//if (uMsg == WM_NCPAINT)
	//{
	//	CWindowWnd::SendMessage(WM_PAINT);
	//}
	if( m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes) ) 
	{
		return lRes;
	}

	return __super::HandleMessage(uMsg, wParam, lParam);
}

LRESULT DzMusicPlayerApp::OnClose( UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/ )
{
	return 0;
}

LRESULT DzMusicPlayerApp::OnDestroy( UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/ )
{
	::PostQuitMessage(0);
	return 0;
}

DzMusicPlayerApp::DzMusicPlayerApp()
{

}

DzMusicPlayerApp::~DzMusicPlayerApp()
{

}