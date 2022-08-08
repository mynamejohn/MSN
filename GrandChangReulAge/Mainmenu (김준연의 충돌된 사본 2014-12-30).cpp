#include "Mainmenu.h"

void CMainMenu::StageInit()
{
	m_bChangeStage = false;
	m_StageTime = 0;

	//텍스쳐 초기화
	m_tBG.Init(L"Image/mainmenu.png");

	//오브젝트 초기화

	m_BG.Init(m_tBG);


}

void CMainMenu::StageRun(float tick)
{
	m_BG.Run(tick);

	//엔터를 누르면 스테이지 변경
	if (KeyInput(VK_RETURN)) //KeyDown이 아니라 KeyInput인게 중요.
	{
		ChangeStage(TestStage);
	}

}

void CMainMenu::StageDraw()
{
	m_BG.Draw();

}