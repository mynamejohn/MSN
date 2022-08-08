#include "TestStage.h"

void CTestStage::StageInit()
{
	m_bChangeStage = false;

	m_StageTime = 0;

	CreateMonster();
	//텍스쳐 초기화
	m_tBG.Init(L"Image/BackGround.png");

	m_tHouseHover.Init(L"Image/MouseHover.png");

	m_tWareHouse.Init(L"Image/WareHouse.png");
	m_tChocolete.Init(L"Image/Chocolete.png");
	m_tGaspard.Init(L"Image/Gaspard.png");
	m_tMakang.Init(L"Image/Makang.png");
	m_tNuddara.Init(L"Image/Nuddara.png");
	m_rPockerchip.Init(L"Image/Pockerchip.png");
	m_tSkkibbi.Init(L"Image/Skkibbi.png");

	m_tMouse.Init(L"Image/mouse.png");
	tResources.Init(L"Image/number_sprite.png");


	//오브젝트 초기화

	m_BG.Init(m_tBG);
	Mouse.Init(m_tMouse);
	Resources.Init(tResources, tResources);

	for (int i = 0; i < Tilesum; i++)
	{
		m_Tile[i].Init(m_tHouseHover, m_tWareHouse, m_tChocolete, m_tGaspard, m_tMakang, m_tNuddara, m_rPockerchip, m_tSkkibbi, i);
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_Monster[i].Init(m_tGaspard, m_rPockerchip, m_tMakang);
	}

	for (int i = 0; i < MonsterNum; i++)
	{
		m_FMonster[i].Init(m_tGaspard, m_rPockerchip, m_tMakang);
	}

	for (int i = 0; i < MonsterNum; i++)
	{
		m_SMonster[i].Init(m_tGaspard, m_rPockerchip, m_tMakang);
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_TMonster[i].Init(m_tGaspard, m_rPockerchip, m_tMakang);
	}
}
int in = 0;
void CTestStage::StageRun(float tick)
{
	m_StageTime += tick;
	time += 1;
	CreateMonster();
	m_BG.Run(tick);
	for (int i = 0; i < Tilesum; i++)
	{
		m_Tile[i].Run(tick, Mouse.getMousePosx(), Mouse.getMousePosy(), Resources.getRecources());
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_Monster[i].Run(tick);
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_FMonster[i].Run(tick);
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_SMonster[i].Run(tick);
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_TMonster[i].Run(tick);
	}
	Mouse.Run(tick);
	Resources.Run(tick);
}

void CTestStage::StageDraw()
{
	//배경오브젝트를 먼저 그림. 순서 조심.
	m_BG.Draw();
	for (int i = 0; i < Tilesum; i++)
	{
		m_Tile[i].Draw();
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_Monster[i].Draw();
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_FMonster[i].Draw();
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_SMonster[i].Draw();
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_TMonster[i].Draw();
	}
	Resources.Draw();
	Mouse.Draw();
	
}

void CTestStage::CreateMonster()
{
	if (time <=600 &&time % 40 == 0)
	{
		for (int i = 0; i < MonsterNum; i++)
		{
			if (m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
			{
			m_FMonster[i].Start(0,0);
				break;
			}
		}			
	}
	if (time >1300&&time <= 1900 &&time % 40 == 0)
	{
		for (int i = 0; i < MonsterNum; i++)
		{
			if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false)
			{
				m_SMonster[i].Start(1, 1);
				break;
			}
		}

	}
	if (time >2300 &&time <=2900 &&time % 40 == 0)
	{
		for (int i = 0; i < MonsterNum; i++)
		{
			if (m_TMonster[i].GetLive() == false && m_TMonster[i].GetDie() == false)
			{
				m_TMonster[i].Start(2, 2);
				break;
			}
		}

	}
}