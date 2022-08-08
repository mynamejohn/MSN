#include "Define.h"
#include "Device.h"
#include "Looper.h"

float tick = 0;

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) // 윈도우 프로시저
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SETCURSOR:
		SetCursor(NULL);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT) // 프로그램 진입점
{
	CLooper Looper;

	DWORD first_time = 0;


	// 윈도우 클래스 정의,등록
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		L"MSN Games", NULL
	};

	RegisterClassEx(&wc);

	// 윈도우 생성SN Ga
	HWND hWnd = CreateWindow(L"MSN Games", L"Mmes",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		1600 + GetSystemMetrics(SM_CXFRAME) * 4, 900 + GetSystemMetrics(SM_CYFRAME) * 4 + GetSystemMetrics(SM_CYCAPTION),
		NULL, NULL, wc.hInstance, NULL);

	// Direct3D초기화
	if (SUCCEEDED(CDevice::GetInstance()->Init(hWnd, 1600, 900)))
	{
		// 윈도우 출력
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		Looper.Init();
		MSG msg;
		// 메시지 루프
		while (true)
		{
			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				first_time = GetTickCount();
				
				Looper.Inplay(tick);
				Looper.Render();

				tick = (float)(GetTickCount() - first_time) / (float)1000;
			}
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
	}

	UnregisterClass(L"MSN Games", wc.hInstance); // 등록된 클래스 소거

	return 0;
}