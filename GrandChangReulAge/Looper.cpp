#include "Looper.h"


void CLooper::Init()
{
//	������ ó�� �����ϸ� ���θ޴� �ʱ�ȭ
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
		else //�������� ������ �� ���
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

	// ����۸� ����������
	CDevice::GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	if (SUCCEEDED(CDevice::GetDevice()->BeginScene())) // ������ ����
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
		CDevice::GetDevice()->EndScene(); // ������ ��

	}

	//����۸� ���̴� ȭ������
	CDevice::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void CLooper::SetStage(int stage)
{
	//�������� ����
	m_Stage = stage;

	//�������� �ʱ�ȭ
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