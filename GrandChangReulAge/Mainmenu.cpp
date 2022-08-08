#include "Mainmenu.h"

void CMainMenu::StageInit()
{
	m_bChangeStage = false;
	m_StageTime = 0;

	//텍스쳐 초기화
	m_tBG.Init(L"Image/Title/mainmenu.png");

	m_tMT.Init(L"Image/Title/Main_Title.png");

	m_start_ac.Init(L"Image/Title/start_mouse.png");
	m_exit_ac.Init(L"Image/Title/end_normal.png");
	m_maker_ac.Init(L"Image/Title/maker_mouse.png");
	m_start_inac.Init(L"Image/Title/start_normal.png");
	m_exit_inac.Init(L"Image/Title/end_mouse.png");
	m_maker_inac.Init(L"Image/Title/maker_normal.png");
	

	m_tOP.Init(L"Image/Title/Open_Maker.png");

	m_tMouse.Init(L"Image/mouse.png");
	//오브젝트 초기화

	Title_first_time = GetTickCount();

	Mouse.Init(m_tMouse);
	m_BG.Init(m_tBG);

	Title_Sound.Init();
	Title_Sound.PlayTitle_BGM();

	m_MT.MTInit(m_tMT);
	m_GS.GSInit(m_start_ac, m_start_inac);
	m_MA.MAInit(m_maker_ac, m_maker_inac);
	m_GE.GEInit(m_exit_ac, m_exit_inac);
	m_OP.Open_MakerInit(m_tOP);
}


void CMainMenu::CTitlerun(float tick, int posX, int posY)
{

	if (670 <= posX && posX < 930 && 490 <= posY && posY < 570)
	{
		TitleNum = 1;
	}
	else if (670 <= posX && posX < 930 && 576 <= posY && posY < 656)
	{
		TitleNum = 2;
	}
	else if (670 <= posX && posX < 930 && 663 <= posY && posY < 740)
	{
		TitleNum = 3;
	}

	else
		TitleNum = 0;

	if (1408 <= posX && posX < 1437 && 136 <= posY && posY < 166)
	{
		TitleNum = 5;
	}

	
}

void CMainMenu::StageRun(float tick)
{

	m_BG.Run(tick);
	Mouse.Run(tick);
	CTitlerun(tick, Mouse.getMousePosx(), Mouse.getMousePosy());
	
	if (OpenMaker == false)
	{
		switch (TitleNum)
		{
		case 1:
			if (KeyInput(VK_LBUTTON))
			{
				Title_Sound.PlayButton();
				ChangeStage(TestStage);
				Title_Sound.TitleStop();
			}
			break;
		case 2:
			if (KeyInput(VK_LBUTTON))
			{
				Title_Sound.PlayButton();
				OpenMaker = true;
			}
			break;
		case 3:
			if (KeyInput(VK_LBUTTON))
			{
				Title_Sound.PlayButton();
				PostQuitMessage(WM_QUIT);
				//ChangeStage(stop);
			}
			break;

		default:
			break;
		}
	}

	if (TitleNum == 5)
	{
		if (OpenMaker == true)
		{
			if (KeyInput(VK_LBUTTON))
			{
				Title_Sound.PlayButton();
				OpenMaker = false;
			}
		}
	}

}

void CMainMenu::StageDraw() //엔터를 누르면 스테이지 변경
{

	if (KeyDown(VK_RETURN))
	{
		ChangeStage(TestStage);
		Title_Sound.TitleStop();
	}

	if (OpenMaker == false)
	{
		m_BG.Draw();
		m_MT.Draw();
		m_GS.Draw_inac();
		m_MA.Draw_inac();
		m_GE.Draw_inac();

		if (TitleNum == 1)
		{
			m_GS.Draw_ac();
		}
		else if (TitleNum == 2)
		{
			m_MA.Draw_ac();
		}
		else if (TitleNum == 3)
		{
			m_GE.Draw_ac();
		}
	}
	else
	{
		m_OP.Draw();
	}
	Mouse.Draw();
}
