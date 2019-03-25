#pragma once
#include "Resource.h"
#include "UIlib.h"
using namespace DuiLib;
class DzMusicPlayerApp:
	public CWindowWnd,
	public INotifyUI
{
public:
	DzMusicPlayerApp();
	virtual ~DzMusicPlayerApp();

public:
	virtual LPCTSTR GetWindowClassName() const {return _T("zMusicPlayerUI");};
	UINT GetClassStyle() const { return UI_CLASSSTYLE_FRAME | CS_DBLCLKS ; };
	virtual UINT		GetSkinRes(){return IDXML_MAIN_PAGE;};
	UILIB_RESOURCETYPE GetResourceType() const{	return UILIB_RESOURCE; }

	virtual void		InitWindow();
	virtual void		OnFinalMessage(HWND)   {}

	virtual void		Notify( TNotifyUI& msg );
	virtual LRESULT		HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

protected:
	CPaintManagerUI m_PaintManager;
};
