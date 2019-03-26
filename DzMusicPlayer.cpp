// DzMusicPlayer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DzMusicPlayer.h"
#include ".\h\libzplay.h"
#include "UIlib.h"
#include "DzMusicPlayerUIApp.h"
//using namespace libZPlay;


using namespace DuiLib;
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	//ZPlay* play = CreateZPlay();
	//play->Close();
	//play->Release();
	DzMusicPlayerApp _app;
	CPaintManagerUI::SetInstance(hInstance);
	_app.Create(NULL, _T("Dz Music Player"), UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE);
//	_app.SetIcon(IDI_ICON_LOGO);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (WM_QUIT == msg.message)
		{
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


