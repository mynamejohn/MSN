#include "TowerSelection.h"



void CTowerSelection::Run(float tick, float posX, float posY)
{
	if (KeyDown(VK_1))
	{
		SelectedTower = WareHouse;
	}

	if (KeyDown(VK_2))
	{
		SelectedTower = splash;
	}

	if (KeyDown(VK_3))
	{
		SelectedTower = penetration;
	}

	if (KeyDown(VK_4))
	{
		SelectedTower = turning;
	}

	if (KeyDown(VK_5))
	{
		SelectedTower = persisttower;
	}

	if (KeyDown(VK_6))
	{
		SelectedTower = slowTower;
	}




	if (500 <= posX && posX < 600 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = WareHouse;
		}
		TowerInfo = 1;
	}

	else if (600 <= posX && posX < 700 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = splash;
		}
		TowerInfo = 2;
	}
	else if (700 <= posX && posX < 800 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = penetration;
		}
		TowerInfo = 3;
	}
	else if (800 <= posX && posX < 900 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = turning;
		}
		TowerInfo = 4;
	}
	else if (900 <= posX && posX < 1000 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = persisttower;
		}
		TowerInfo = 5;
	}
	else if (1000 <= posX && posX < 1100 && 800 <= posY && posY < 900)
	{
		if (KeyInput(VK_LBUTTON))
		{
			SelectedTower = slowTower;
		}
		TowerInfo = 6;
	}
	else
		TowerInfo = 0;/*
					  if (350 > posX || posX >= 1250)
					  {
					  if (800 > posY || posY <= 900)
					  {
					  타워정보 = 0;
					  }
					  }*/
	m_vPos_tower_info.x = posX - 100;
	m_vPos_tower_info.y = posY - 220;
}

void CTowerSelection::Init(CTexture tower_1_active,
	CTexture tower_1_inactive,
	CTexture tower_2_active,
	CTexture tower_2_inactive,
	CTexture tower_3_active,
	CTexture tower_3_inactive,
	CTexture tower_4_active,
	CTexture tower_4_inactive,
	CTexture tower_5_active,
	CTexture tower_5_inactive,
	CTexture tower_6_active,
	CTexture tower_6_inactive,

	CTexture tower_1_mouse,
	CTexture tower_2_mouse,
	CTexture tower_3_mouse,
	CTexture tower_4_mouse,
	CTexture tower_5_mouse,
	CTexture tower_6_mouse,

	CTexture tower_1_info,
	CTexture tower_2_info,
	CTexture tower_3_info,
	CTexture tower_4_info,
	CTexture tower_5_info,
	CTexture tower_6_info

	)
{
	m_pSprite = CDevice::GetSprite();

	m_tower_1_active = tower_1_active.GetTexture();
	m_tower_1_inactive = tower_1_inactive.GetTexture();
	m_tower_2_active = tower_2_active.GetTexture();
	m_tower_2_inactive = tower_2_inactive.GetTexture();
	m_tower_3_active = tower_3_active.GetTexture();
	m_tower_3_inactive = tower_3_inactive.GetTexture();
	m_tower_4_active = tower_4_active.GetTexture();
	m_tower_4_inactive = tower_4_inactive.GetTexture();
	m_tower_5_active = tower_5_active.GetTexture();
	m_tower_5_inactive = tower_5_inactive.GetTexture();
	m_tower_6_active = tower_6_active.GetTexture();
	m_tower_6_inactive = tower_6_inactive.GetTexture();

	m_tower_1_mouse = tower_1_mouse.GetTexture();
	m_tower_2_mouse = tower_2_mouse.GetTexture();
	m_tower_3_mouse = tower_3_mouse.GetTexture();
	m_tower_4_mouse = tower_4_mouse.GetTexture();
	m_tower_5_mouse = tower_5_mouse.GetTexture();
	m_tower_6_mouse = tower_6_mouse.GetTexture();

	m_tower_1_info = tower_1_info.GetTexture();
	m_tower_2_info = tower_2_info.GetTexture();
	m_tower_3_info = tower_3_info.GetTexture();
	m_tower_4_info = tower_4_info.GetTexture();
	m_tower_5_info = tower_5_info.GetTexture();
	m_tower_6_info = tower_6_info.GetTexture();


	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
	m_color2 = D3DCOLOR_ARGB(255, 255, 255, 255);
	m_rect = { 0, 0, tower_1_active.GetWidth(), tower_1_active.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_rect2 = { 0, 0, tower_1_info.GetWidth(), tower_1_info.GetHeight() };

	m_vPos_tower_1.x = 500;
	m_vPos_tower_1.y = 800;
	m_vPos_tower_2.x = 600;
	m_vPos_tower_2.y = 800;
	m_vPos_tower_3.x = 700;
	m_vPos_tower_3.y = 800;
	m_vPos_tower_4.x = 800;
	m_vPos_tower_4.y = 800;
	m_vPos_tower_5.x = 900;
	m_vPos_tower_5.y = 800;
	m_vPos_tower_6.x = 1000;
	m_vPos_tower_6.y = 800;


	SelectedTower = WareHouse;
}

void CTowerSelection::Draw()
{
	if (SelectedTower == WareHouse)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_1_active, &m_rect, NULL, &m_vPos_tower_1, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_1_inactive, &m_rect, NULL, &m_vPos_tower_1, m_color);
		m_pSprite->End();
	}

	if (SelectedTower == splash)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_2_active, &m_rect, NULL, &m_vPos_tower_2, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_2_inactive, &m_rect, NULL, &m_vPos_tower_2, m_color);
		m_pSprite->End();
	}
	if (SelectedTower == penetration)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_3_active, &m_rect, NULL, &m_vPos_tower_3, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_3_inactive, &m_rect, NULL, &m_vPos_tower_3, m_color);
		m_pSprite->End();
	}
	if (SelectedTower == turning)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_4_active, &m_rect, NULL, &m_vPos_tower_4, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_4_inactive, &m_rect, NULL, &m_vPos_tower_4, m_color);
		m_pSprite->End();
	}
	if (SelectedTower == persisttower)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_5_active, &m_rect, NULL, &m_vPos_tower_5, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_5_inactive, &m_rect, NULL, &m_vPos_tower_5, m_color);
		m_pSprite->End();
	}
	if (SelectedTower == slowTower)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_6_active, &m_rect, NULL, &m_vPos_tower_6, m_color);
		m_pSprite->End();
	}
	else
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_6_inactive, &m_rect, NULL, &m_vPos_tower_6, m_color);
		m_pSprite->End();
	}



	switch (TowerInfo)
	{
	case 1:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_1_mouse, &m_rect, NULL, &m_vPos_tower_1, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_1_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}
	case 2:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_2_mouse, &m_rect, NULL, &m_vPos_tower_2, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_2_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}
	case 3:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_3_mouse, &m_rect, NULL, &m_vPos_tower_3, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_3_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}
	case 4:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_4_mouse, &m_rect, NULL, &m_vPos_tower_4, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_4_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}
	case 5:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_5_mouse, &m_rect, NULL, &m_vPos_tower_5, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_5_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}
	case 6:
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_6_mouse, &m_rect, NULL, &m_vPos_tower_6, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tower_6_info, &m_rect2, NULL, &m_vPos_tower_info, m_color2);
		m_pSprite->End();
		break;
	}

	}

}