#include "Mainmenu.h"

void CMainMenu::StageInit()
{
	m_bChangeStage = false;
	m_StageTime = 0;

	//�ؽ��� �ʱ�ȭ
	m_tBG.Init(L"Image/mainmenu.png");

	//������Ʈ �ʱ�ȭ

	m_BG.Init(m_tBG);


}

void CMainMenu::StageRun(float tick)
{
	m_BG.Run(tick);

	//���͸� ������ �������� ����
	if (KeyInput(VK_RETURN)) //KeyDown�� �ƴ϶� KeyInput�ΰ� �߿�.
	{
		ChangeStage(TestStage);
	}

}

void CMainMenu::StageDraw()
{
	m_BG.Draw();

}