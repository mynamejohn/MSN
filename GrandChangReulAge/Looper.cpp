#include "Looper.h"


void CLooper::Init()
{
//	게임을 처음 시작하면 메인메뉴 초기화
	SetStage(MainMenu);
	total_score = 0;
//	m_tMouse.Init(L"Image/mouse.png");
//	mouse.Init(m_tMouse);

}

void CLooper::Inplay(float tick)
{
	switch (m_Stage)
	{
	case MainMenu:
		if (m_MainMenu.GetChangeStage() == false)
			m_MainMenu.StageRun(tick);
		else //스테이지 변경을 할 경우
			SetStage(m_MainMenu.GetNextStage());
		break;

	case TestStage:
		if (m_TestStage.GetChangeStage() == false)
			m_TestStage.StageRun(tick,&total_score);
		else
			SetStage(m_TestStage.GetNextStage());
		break;

	case Clear:
		if (m_Clear.GetChangeStage() == false)
			m_Clear.StageRun(tick);
		else
			SetStage(m_Clear.GetNextStage());
		break;

	}

}

void CLooper::Render()
{
	if (NULL == g_pDevice)
		return;

	// 백버퍼를 검은색으로
	CDevice::GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	if (SUCCEEDED(CDevice::GetDevice()->BeginScene())) // 렌더링 시작
	{
		switch (m_Stage)
		{
		case MainMenu:
			m_MainMenu.StageDraw();
			break;
		case TestStage:
			m_TestStage.StageDraw();
			break;
		case Clear:
			m_Clear.StageDraw();
			break;
		}
//		mouse.Draw();
		CDevice::GetDevice()->EndScene(); // 렌더링 끝

	}

	//백버퍼를 보이는 화면으로
	CDevice::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void CLooper::SetStage(int stage)
{
	//스테이지 변경
	m_Stage = stage;

	//스테이지 초기화
	switch (m_Stage)
	{
	case MainMenu:
		m_MainMenu.StageInit();
		break;
	case TestStage:
		m_TestStage.StageInit();
		break;
	case Clear:
		m_Clear.StageInit(&total_score);
		break;
	}
}