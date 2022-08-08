#include "Tile.h"


void CTile::Run(float tick, float posX, float posY, float* resourcesnum, int SelectedTower, CSound* sound)
{
	if ((posX - m_vPos.x < 50 && posX - m_vPos.x > 0) && (posY - m_vPos.y < 60 && posY - m_vPos.y>10))
	{
		if (status != Road)
		{
			MouseHover = true;
		}

		if (status != Road)
		{
			if (KeyDown(VK_LBUTTON)/*&& status == Normal*/)
			{
				Tile_tick = (float)(GetTickCount() - Tile_first_time) / (float)1000;

				if (level < 3)
				{
					switch (level)
					{
					case 0:
						if (*resourcesnum >= 1)
						{
							sound->PlayUpgrade();
							status = SelectedTower;
							level++;
							*resourcesnum -= 1;
							Tile_first_time = GetTickCount(); // 쿨타임 초기화
						}
						break;
					case 1:
						if (Tile_tick > 0.25) // 쿨마다
						{
							
							if (*resourcesnum >= 2)
							{
								sound->PlayUpgrade();
								level++;
								*resourcesnum -= 2;
							}
							Tile_first_time = GetTickCount(); // 쿨타임 초기화
						}
						break;
					case 2:
						if (Tile_tick > 0.25) // 쿨마다
						{
							if (*resourcesnum >= 3)
							{
								sound->PlayUpgrade();
								level++;
								*resourcesnum -= 3;
							}
							Tile_first_time = GetTickCount(); // 쿨타임 초기화
						}
						break;
					}

				}
			}
			if (KeyDown(VK_RBUTTON) && KeyDown(VK_LBUTTON) == false)
			{
				/*
				Tile_tick = (float)(GetTickCount() - Tile_first_time) / (float)1000;

				if (level > 0)
				{
					switch (level)
					{
					case 3:
						level--;
						*resourcesnum += 3;
						Tile_first_time = GetTickCount(); // 쿨타임 초기화
						break;
					case 2:
						if (Tile_tick > 0.25) // 쿨마다
						{
							level--;
							*resourcesnum += 2;
							Tile_first_time = GetTickCount(); // 쿨타임 초기화
						}
						break;
					case 1:
						if (Tile_tick > 0.25) // 쿨마다
						{
							level--;
							*resourcesnum += 1;
							status = Normal;
							Tile_first_time = GetTickCount(); // 쿨타임 초기화
						}
						break;
					}
				}
				*/
				if (level > 0)
				{
					switch (level)
					{
						case 1:
						{
							*resourcesnum += 1;
							break;
						}
						case 2:
						{
							*resourcesnum += 1 + 2;
							break;
						}
						case 3:
						{
							*resourcesnum += 1 + 2 + 3;
							break;
						}
					}
					sound->PlayDowngrade();
					status = Normal;
					level = 0;
				}
			}
		}
	}
	else
	{
		MouseHover = false;		//기본상태
	}
	AttackDelay += tick;
	Spriting();
}

void CTile::Init(CTexture Hover, CTexture Tower_1, CTexture Tower_2, CTexture Tower_3,
	CTexture Tower_4, CTexture Tower_5, CTexture Tower_6, CTexture Tower_1_Stand, CTexture Tower_2_Stand, CTexture Tower_3_Stand,
	CTexture Tower_4_Stand, CTexture Tower_5_Stand, int i, int j)
{
	m_pSprite = CDevice::GetSprite();

	m_pTexture = Hover.GetTexture();
	m_pTower_1 = Tower_1.GetTexture();
	m_pTower_2 = Tower_2.GetTexture();
	m_pTower_3 = Tower_3.GetTexture();
	m_pTower_4 = Tower_4.GetTexture();
	m_pTower_5 = Tower_5.GetTexture();
	m_pTower_6 = Tower_6.GetTexture();

	m_pTower_1_Stand = Tower_1_Stand.GetTexture();
	m_pTower_2_Stand = Tower_2_Stand.GetTexture();
	m_pTower_3_Stand = Tower_3_Stand.GetTexture();
	m_pTower_4_Stand = Tower_4_Stand.GetTexture();
	m_pTower_5_Stand = Tower_5_Stand.GetTexture();






	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	//m_rect = { 0, 0, Hover.GetWidth(), Hover.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	MouseHover_rect = { 0, 0, Hover.GetWidth(), Hover.GetHeight() };
	status = Normal;	//0은 평지
	Tile_first_time = GetTickCount();

	level = 0;
	//타일깔기s

	m_vPos.y = (float)50 * i-10;
	m_vPos.x = (float)50 * j;

	Tower_first_time = GetTickCount();

	checkx = i;
	checky = j;
	d = m_vPos.y - 20.0;
	CollPos.x = m_vPos.x + 25.0;
	CollPos.y = m_vPos.y + 30.0;
	
	AttackSt = false;
	abc = 1;
	x = 0;
	y = 0;

	rect_left = 0;
	rect_top = 0;
	rect_right = 50;
	rect_bottom = 60;

	ani = 0;
	P_ani = &ani;

	


}

void CTile::SetStage1(int i, int j)
{
	if (i == 0)
	{
		status = Road;
	}
	if (i == 1)
	{
		status = Road;
	}
	if (i == 2)
	{
		if (j < 2 || (j>7 && j < 21) || j>29)
			status = Road;
	}
	if (i == 3)
	{
		if (j < 2 || (j>2 && j < 7) || (j>7 && j < 21) || (j>21 && j < 29) || j>29)
			status = Road;
	}
	if (i == 4)
	{
		if (j < 2 || j == 3 || j == 6 || (j>7 && j < 11) || j == 15 || j == 16 || j == 22 || j == 28 || j>29)
			status = Road;
	}
	if (i == 5)
	{
		if (j < 2 || j == 3 || j == 6 || (j>11 && j < 20) || j == 22 || j == 28 || j>29)
			status = Road;
	}
	if (i == 6)
	{
		if (j < 2 || j == 3 || j == 6 || j == 12 || j == 19 || (j>21 && j < 26) || j == 28)
			status = Road;
	}
	if (i == 7)
	{
		if (j < 2 || j == 3 || (j>5 && j < 13) || (j>13 && j < 18) || j == 19 || (j>27 && j < 31))
			status = Road;
	}
	if (i == 8)
	{
		if (j < 2 || j == 3 || j == 9 || j == 12 || (j>13 && j < 18) || (j>18 && j < 29) || j == 30)
			status = Road;
	}
	if (i == 9)
	{
		if (j==3||j == 9 || j == 12 || (j > 13 && j < 18) || j == 19 || j == 30)
			status = Road;
	}
	if (i == 10)
	{
		if (j == 1 || j == 3 || j == 5 || j == 6 || j == 9 || j == 12 || j == 19 || j == 25 || j == 30 )
			status = Road;
	}
	if (i == 11)
	{
		if (j == 1 || j == 3 || j == 6 || j == 9 || (j > 11 && j < 20) || j == 22 || j == 23 || j == 25 || (j>26 && j < 31))
			status = Road;
	}
	if (i == 12)
	{
		if (j == 1 || j == 3 || j == 6 || j == 9 || j == 14 || j == 18 || j == 22 || j == 25)
			status = Road;
	}
	if (i == 13)
	{
		if (j == 1 || j == 3 || j == 6 || j == 9 || j == 14 || j == 18 || j == 22 || j == 25 || j == 16)
			status = Road;
	}
	if (i == 14)
	{
		if (j == 1 || (j>2 && j < 7) || (j>8 && j < 15) || j == 16 || (j>17 && j < 23) || j>24)
			status = Road;
	}
	if (i == 15)
	{
		if (j == 1 || j == 16)
			status = Road;
	}


};

void CTile::Collision(int* m_Hp, D3DXVECTOR3 MonsterPos, float tick)
{
	//	m_bDraw = false;
	//if ((int)AttackDelay % 20 == 0 && AttackSt == false)			//공격에 딜레이를 ??주기
	//{
		AttackSt = true;
	//}

}

bool CTile::Check(D3DXVECTOR3 MonsterPos, float tick)
{
	if (status == slowTower)
	{
		x = CollPos.x - MonsterPos.x;
		y = CollPos.y - MonsterPos.y;

		distance = sqrt((x*x) + (y*y));
		if (distance < 100.0)
		{
			return true;
		}
		else
		{
			AttackSt = false;
			return false;
		}
	}
	
	
}

void CTile::Spriting()
{
	Tower_tick = (float)(GetTickCount() - Tower_first_time) / (float)1000;
	
	if (status == splash || status == penetration || status == persisttower || status == slowTower || status == turning || status == WareHouse)
	{
		if (level == 1)
		{
			rect_top = 0;
			rect_bottom = 60;
		}
		if (level == 2)
		{
			rect_top = 60;
			rect_bottom = 120;
		}
		if (level == 3)
		{
			rect_top = 120;
			rect_bottom = 180;
		}
	}

	else
	{
		if (level == 1)
		{
			rect_top = 0;
			rect_bottom = 50;
		}
		if (level == 2)
		{
			rect_top = 50;
			rect_bottom = 100;
		}
		if (level == 3)
		{
			rect_top = 100;
			rect_bottom = 150;
		}
	}

	if (Tower_tick > 0.1)
	{
		if (status == slowTower)
		{
			if (rect_right < 550)
			{
				rect_right += 50;
				rect_left += 50;
			}
			else if (rect_right >= 550)
			{
				rect_right = 50;
				rect_left = 0;
			}
		}
	}



	if (Tower_tick > 0.1)
	{
		switch (ani)
		{
		case WareHouse:
		{
			if (rect_right < 450)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 450)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;
			}
			case splash:
			{

				if (rect_right < 350)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 350)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;
			}
			case penetration:
			{
				if (rect_right < 350)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 350)
				{
					rect_right = 50;
					rect_left = 0;
				}

				break;
			}
			case turning:
			{
				if (rect_right < 1500)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 1500)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;
			}
			case persisttower:
			{
				if (rect_right < 350)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 350)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;
			}
			
			case WareHouseStand:
			{
				if (rect_right < 500)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 500)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}
			case splashStand:
			{
				if (rect_right < 250)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 250)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}

			case penetrationstand:
			{
				if (rect_right < 250)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 250)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}

			case turningstand:
			{
				if (rect_right < 500)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 500)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}

			case persisttowerstand:
			{
				if (rect_right < 250)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 250)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}
			case slowTowerstand:
			{
				if (rect_right < 500)
				{
					rect_right += 50;
					rect_left += 50;
				}
				else if (rect_right >= 500)
				{
					rect_right = 50;
					rect_left = 0;
				}
				break;

			}
			case turningreturn:
			{
				
				if (rect_right < 750)
				{
					rect_right += 50;
					rect_left += 50;
				}
				if (rect_right >=750)
				{
					rect_right = 550;
					rect_left = 500;
				}
			}



			default:
			{
				break;
			}
		}
		m_rect = { rect_left, rect_top, rect_right, rect_bottom };
		Tower_first_time = GetTickCount();
	}
}

void CTile::Draw()
{
	if (m_bDraw)
	{
		if (WareHouse <= status && status <= slowTower)
		{
			switch (status)
			{
			case WareHouse:
				if (ani == WareHouseStand)
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_1_Stand, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				else
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_1, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				
			case splash:
				if (ani == splashStand)
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_2_Stand, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTower_2, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			case penetration:
				if (ani == penetrationstand)
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_3_Stand, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTower_3, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			case turning:
				if (ani == turningstand)
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_4_Stand, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTower_4, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			case persisttower:
				if (ani == persisttowerstand)
				{
					m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
					m_pSprite->Draw(m_pTower_5_Stand, &m_rect, NULL, &m_vPos, m_color);
					m_pSprite->End();
					break;
				}
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTower_5, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			case slowTower:
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTower_6, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			

			default:
				break;
			}

		}
	}
	if (MouseHover)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &MouseHover_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
	}
}