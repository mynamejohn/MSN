#include "Effect.h"

void CEffect::Init(CTexture t1, CTexture t2, CTexture t3,
	CTexture t4, CTexture t5, CTexture t6,
	CTexture t7, CTexture t8, CTexture t9,
	CTexture t10, CTexture t11, CTexture t12,
	CTexture t13, CTexture t14, CTexture t15, CTexture t16)
{
	m_pSprite = CDevice::GetSprite();

	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();
	m_pTexture3 = t3.GetTexture();

	m_pTexture4 = t4.GetTexture();
	m_pTexture5 = t5.GetTexture();
	m_pTexture6 = t6.GetTexture();

	m_pTexture7 = t7.GetTexture();
	m_pTexture8 = t8.GetTexture();
	m_pTexture9 = t9.GetTexture();

	m_pTexture10 = t10.GetTexture();
	m_pTexture11 = t11.GetTexture();
	m_pTexture12 = t12.GetTexture();

	m_pTexture13 = t13.GetTexture();
	m_pTexture14 = t14.GetTexture();
	m_pTexture15 = t15.GetTexture();

	m_pTexture16 = t16.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos_Tower_1 = D3DXVECTOR3(0, 0, 0);
	m_vPos_Tower_2 = D3DXVECTOR3(0, 0, 0);
	m_vPos_Tower_3 = D3DXVECTOR3(0, 0, 0);
	m_vPos_Tower_4 = D3DXVECTOR3(0, 0, 0);
	m_vPos_Tower_5 = D3DXVECTOR3(0, 0, 0);
	m_vPos_Tower_6 = D3DXVECTOR3(0, 0, 0);


	rect_top_Tower_1 = 0;
	rect_bottom_Tower_1 = 100;
	rect_left_Tower_1 = -100;
	rect_right_Tower_1 = 0;
	RECT_TOWER1 = { rect_left_Tower_1, rect_top_Tower_1, rect_right_Tower_1, rect_bottom_Tower_1 };


	rect_top_Tower_2 = 0;
	rect_bottom_Tower_2 = 120;
	rect_left_Tower_2 = 0;
	rect_right_Tower_2 = 120;
	RECT_TOWER2 = { rect_left_Tower_2, rect_top_Tower_2, rect_right_Tower_2, rect_bottom_Tower_2 };

	rect_top_Tower_3 = 0;
	rect_bottom_Tower_3 = 40;
	rect_left_Tower_3 = -40;
	rect_right_Tower_3 = 0;
	RECT_TOWER3 = { rect_left_Tower_3, rect_top_Tower_3, rect_right_Tower_3, rect_bottom_Tower_3 };

	rect_top_Tower_4 = 0;
	rect_bottom_Tower_4 = 40;
	rect_left_Tower_4 = -40;
	rect_right_Tower_4 = 0;
	RECT_TOWER4 = { rect_left_Tower_4, rect_top_Tower_4, rect_right_Tower_4, rect_bottom_Tower_4 };

	rect_top_Tower_5 = 0;
	rect_bottom_Tower_5 = 40;
	rect_left_Tower_5 = -40;
	rect_right_Tower_5 = 0;
	RECT_TOWER5 = { rect_left_Tower_5, rect_top_Tower_5, rect_right_Tower_5, rect_bottom_Tower_5 };

	rect_top_Tower_6 = 0;
	rect_bottom_Tower_6 = 70;
	rect_left_Tower_6 = -70;
	rect_right_Tower_6 = 0;
	RECT_TOWER6 = { rect_left_Tower_6, rect_top_Tower_6, rect_right_Tower_6, rect_bottom_Tower_6 };

	Effect_Time_Tower_1 = 0.5; // 이펙트 적용되는 시간 변수
	Effect_Time_Tower_2 = 0.5;
	Effect_Time_Tower_3 = 0.5;
	Effect_Time_Tower_4 = 0.5;
	Effect_Time_Tower_5 = 4.2; // 지속데미지 먹히는 시간만큼보다 약간 적게(왜 이래야하는지는 잘 모름 ㅎ)
	Effect_Time_Tower_6 = 5.5;

	Effect_delay_Tower_1 = 0.125; // 이펙트 스프라이트 딜레이 변수
	Effect_delay_Tower_2 = 0.125;
	Effect_delay_Tower_3 = 0.125;
	Effect_delay_Tower_4 = 0.125;
	Effect_delay_Tower_5 = 0.125;
	Effect_delay_Tower_6 = 0.125;

	Effect_delay_first_time = GetTickCount();
}

void CEffect::Run(CMonster* Monster)
{
	Effect_delay_tick = (float)(GetTickCount() - Effect_delay_first_time) / (float)1000; // 딜레이

	///////////////// 타워 1 //////////////////////////
	if (Monster->GetTower_1_Level_1_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_1)
		{
			m_vPos_Tower_1 = D3DXVECTOR3(Monster->m_vPos.x - 20, Monster->m_vPos.y - 20, 0);
			RECT_TOWER1 = { rect_left_Tower_1, rect_top_Tower_1, rect_right_Tower_1, rect_bottom_Tower_1 };

			if (Effect_delay_tick > Effect_delay_Tower_1)
			{
				if (rect_right_Tower_1 < 400)
				{
					rect_right_Tower_1 += 100;
					rect_left_Tower_1 += 100;
				}
				else if (rect_right_Tower_1 >= 400)
				{
					rect_right_Tower_1 = 100;
					rect_left_Tower_1 = 0;
				}
		
				Effect_delay_first_time = GetTickCount();
			}
			
		}
		else
		{
			Monster->SetTower_1_Level_1_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_1_Level_2_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_1)
		{	
			
			m_vPos_Tower_1 = D3DXVECTOR3(Monster->m_vPos.x - 20, Monster->m_vPos.y - 20, 0);
			RECT_TOWER1 = { rect_left_Tower_1, rect_top_Tower_1, rect_right_Tower_1, rect_bottom_Tower_1 };

			if (Effect_delay_tick > Effect_delay_Tower_1)
			{
				if (rect_right_Tower_1 < 400)
				{
					rect_right_Tower_1 += 100;
					rect_left_Tower_1 += 100;
				}
				else if (rect_right_Tower_1 >= 400)
				{
					rect_right_Tower_1 = 100;
					rect_left_Tower_1 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
	
		}
		else
		{
			Monster->SetTower_1_Level_2_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_1_Level_3_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_1)
		{
			m_vPos_Tower_1 = D3DXVECTOR3(Monster->m_vPos.x - 20, Monster->m_vPos.y - 20, 0);
			RECT_TOWER1 = { rect_left_Tower_1, rect_top_Tower_1, rect_right_Tower_1, rect_bottom_Tower_1 };

			if (Effect_delay_tick > Effect_delay_Tower_1)
			{
				if (rect_right_Tower_1 < 400)
				{
					rect_right_Tower_1 += 100;
					rect_left_Tower_1 += 100;
				}
				else if (rect_right_Tower_1 >= 400)
				{
					rect_right_Tower_1 = 100;
					rect_left_Tower_1 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}

		}
		else
		{
			Monster->SetTower_1_Level_3_Effect(false); // 이펙트 취소
		}
	}

	///////////////// 타워 2 //////////////////////////
	if (Monster->GetTower_2_Level_1_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_2)
		{
			m_vPos_Tower_2 = D3DXVECTOR3(Monster->m_vPos.x - 40, Monster->m_vPos.y - 30, 0);
			RECT_TOWER2 = { rect_left_Tower_2, rect_top_Tower_2, rect_right_Tower_2, rect_bottom_Tower_2 };			

			if (Effect_delay_tick > Effect_delay_Tower_2)
			{
				
				if (rect_right_Tower_2 < 840)
				{
					rect_right_Tower_2 += 120;
					rect_left_Tower_2 += 120;
				}
				else if (rect_right_Tower_2 >= 840)
				{
					rect_right_Tower_2 = 120;
					rect_left_Tower_2 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
		}
		else
		{
			Monster->SetTower_2_Level_1_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_2_Level_2_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_2)
		{
			m_vPos_Tower_2 = D3DXVECTOR3(Monster->m_vPos.x - 40, Monster->m_vPos.y - 30, 0);
			RECT_TOWER2 = { rect_left_Tower_2, rect_top_Tower_2, rect_right_Tower_2, rect_bottom_Tower_2 };

			if (Effect_delay_tick > Effect_delay_Tower_2)
			{
				

				if (rect_right_Tower_2 < 840)
				{
					rect_right_Tower_2 += 120;
					rect_left_Tower_2 += 120;
				}
				else if (rect_right_Tower_2 >= 840)
				{
					rect_right_Tower_2 = 120;
					rect_left_Tower_2 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}

		}
		else
		{
			Monster->SetTower_2_Level_2_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_2_Level_3_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_2)
		{
			m_vPos_Tower_2 = D3DXVECTOR3(Monster->m_vPos.x - 40, Monster->m_vPos.y - 30, 0);
			RECT_TOWER2 = { rect_left_Tower_2, rect_top_Tower_2, rect_right_Tower_2, rect_bottom_Tower_2 };

			if (Effect_delay_tick > Effect_delay_Tower_2)
			{
				

				if (rect_right_Tower_2 < 840)
				{
					rect_right_Tower_2 += 120;
					rect_left_Tower_2 += 120;
				}
				else if (rect_right_Tower_2 >= 840)
				{
					rect_right_Tower_2 = 120;
					rect_left_Tower_2 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}

		}
		else
		{
			Monster->SetTower_2_Level_3_Effect(false); // 이펙트 취소
		}
	}

	///////////////// 타워 3 //////////////////////////
	if (Monster->GetTower_3_Level_1_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_3)
		{
			if (Effect_delay_tick > Effect_delay_Tower_3)
			{
				if (rect_right_Tower_3 < 160)
				{
					rect_right_Tower_3 += 40;
					rect_left_Tower_3 += 40;
				}
				else if (rect_right_Tower_3 >= 160)
				{
					rect_right_Tower_3 = 40;
					rect_left_Tower_3 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_3 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER3 = { rect_left_Tower_3, rect_top_Tower_3, rect_right_Tower_3, rect_bottom_Tower_3 };
		}
		else
		{
			Monster->SetTower_3_Level_1_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_3_Level_2_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_3)
		{
			if (Effect_delay_tick > Effect_delay_Tower_3)
			{
				if (rect_right_Tower_3 < 160)
				{
					rect_right_Tower_3 += 40;
					rect_left_Tower_3 += 40;
				}
				else if (rect_right_Tower_3 >= 160)
				{
					rect_right_Tower_3 = 40;
					rect_left_Tower_3 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_3 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER3 = { rect_left_Tower_3, rect_top_Tower_3, rect_right_Tower_3, rect_bottom_Tower_3 };
		}
		else
		{
			Monster->SetTower_3_Level_2_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_3_Level_3_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_3)
		{
			if (Effect_delay_tick > Effect_delay_Tower_3)
			{
				if (rect_right_Tower_3 < 160)
				{
					rect_right_Tower_3 += 40;
					rect_left_Tower_3 += 40;
				}
				else if (rect_right_Tower_3 >= 160)
				{
					rect_right_Tower_3 = 40;
					rect_left_Tower_3 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_3 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER3 = { rect_left_Tower_3, rect_top_Tower_3, rect_right_Tower_3, rect_bottom_Tower_3 };
		}
		else
		{
			Monster->SetTower_3_Level_3_Effect(false); // 이펙트 취소
		}
	}

	///////////////// 타워 4 //////////////////////////
	if (Monster->GetTower_4_Level_1_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_4)
		{
			if (Effect_delay_tick > Effect_delay_Tower_4)
			{
				if (rect_right_Tower_4 < 200)
				{
					rect_right_Tower_4 += 50;
					rect_left_Tower_4 += 50;
				}
				else if (rect_right_Tower_4 >= 200)
				{
					rect_right_Tower_4 = 50;
					rect_left_Tower_4 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_4 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER4 = { rect_left_Tower_4, rect_top_Tower_4, rect_right_Tower_4, rect_bottom_Tower_4 };
		}
		else
		{
			Monster->SetTower_4_Level_1_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_4_Level_2_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_4)
		{
			if (Effect_delay_tick > Effect_delay_Tower_4)
			{
				if (rect_right_Tower_4 < 200)
				{
					rect_right_Tower_4 += 50;
					rect_left_Tower_4 += 50;
				}
				else if (rect_right_Tower_4 >= 200)
				{
					rect_right_Tower_4 = 50;
					rect_left_Tower_4 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_4 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER4 = { rect_left_Tower_4, rect_top_Tower_4, rect_right_Tower_4, rect_bottom_Tower_4 };
		}
		else
		{
			Monster->SetTower_4_Level_2_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_4_Level_3_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_4)
		{
			if (Effect_delay_tick > Effect_delay_Tower_4)
			{
				if (rect_right_Tower_4 < 200)
				{
					rect_right_Tower_4 += 50;
					rect_left_Tower_4 += 50;
				}
				else if (rect_right_Tower_4 >= 200)
				{
					rect_right_Tower_4 = 50;
					rect_left_Tower_4 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_4 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER4 = { rect_left_Tower_4, rect_top_Tower_4, rect_right_Tower_4, rect_bottom_Tower_4 };
		}
		else
		{
			Monster->SetTower_4_Level_3_Effect(false); // 이펙트 취소
		}
	}

	///////////////// 타워 5 //////////////////////////
	if (Monster->GetTower_5_Level_1_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_5)
		{
			if (Effect_delay_tick > Effect_delay_Tower_5)
			{
				if (rect_right_Tower_5 < 160)
				{
					rect_right_Tower_5 += 40;
					rect_left_Tower_5 += 40;
				}
				else if (rect_right_Tower_5 >= 160)
				{
					rect_right_Tower_5 = 40;
					rect_left_Tower_5 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_5 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER5 = { rect_left_Tower_5, rect_top_Tower_5, rect_right_Tower_5, rect_bottom_Tower_5 };
		}
		else
		{
			Monster->SetTower_5_Level_1_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_5_Level_2_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_5)
		{
			if (Effect_delay_tick > Effect_delay_Tower_5)
			{
				if (rect_right_Tower_5 < 160)
				{
					rect_right_Tower_5 += 40;
					rect_left_Tower_5 += 40;
				}
				else if (rect_right_Tower_5 >= 160)
				{
					rect_right_Tower_5 = 40;
					rect_left_Tower_5 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_5 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER5 = { rect_left_Tower_5, rect_top_Tower_5, rect_right_Tower_5, rect_bottom_Tower_5 };
		}
		else
		{
			Monster->SetTower_5_Level_2_Effect(false); // 이펙트 취소
		}
	}
	if (Monster->GetTower_5_Level_3_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_5)
		{
			if (Effect_delay_tick > Effect_delay_Tower_5)
			{
				if (rect_right_Tower_5 < 160)
				{
					rect_right_Tower_5 += 40;
					rect_left_Tower_5 += 40;
				}
				else if (rect_right_Tower_5 >= 160)
				{
					rect_right_Tower_5 = 40;
					rect_left_Tower_5 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_5 = D3DXVECTOR3(Monster->m_vPos.x, Monster->m_vPos.y, 0);
			RECT_TOWER5 = { rect_left_Tower_5, rect_top_Tower_5, rect_right_Tower_5, rect_bottom_Tower_5 };
		}
		else
		{
			Monster->SetTower_5_Level_3_Effect(false); // 이펙트 취소
		}
	}

	if (Monster->GetTower_6_Effect() == true)
	{
		Monster->Effect_tick = (float)(GetTickCount() - Monster->Effect_first_time) / (float)1000;
		if (Monster->Effect_tick < Effect_Time_Tower_6)
		{
			if (Effect_delay_tick > Effect_delay_Tower_6)
			{

				if (rect_right_Tower_6 < 1470)
				{
					rect_right_Tower_6 += 70;
					rect_left_Tower_6 += 70;
				}
				else if (rect_right_Tower_6 >= 1470)
				{
					rect_right_Tower_6 = 70;
					rect_left_Tower_6 = 0;
				}

				Effect_delay_first_time = GetTickCount();
			}
			m_vPos_Tower_6 = D3DXVECTOR3(Monster->m_vPos.x-10, Monster->m_vPos.y,0);
			RECT_TOWER6 = { rect_left_Tower_6, rect_top_Tower_6, rect_right_Tower_6, rect_bottom_Tower_6 };
		}
		else
		{
			Monster->SetTower_6_Effect(false); // 이펙트 취소
		}
	}

}

void CEffect::Draw(CMonster Monster)
{
	if (Monster.GetTower_1_Level_1_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &RECT_TOWER1, NULL, &m_vPos_Tower_1, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_1_Level_2_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture2, &RECT_TOWER1, NULL, &m_vPos_Tower_1, m_color);
		m_pSprite->End();
	}
	 if (Monster.GetTower_1_Level_3_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture3, &RECT_TOWER1, NULL, &m_vPos_Tower_1, m_color);
		m_pSprite->End();
	}

	if (Monster.GetTower_2_Level_1_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture4, &RECT_TOWER2, NULL, &m_vPos_Tower_2, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_2_Level_2_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture5, &RECT_TOWER2, NULL, &m_vPos_Tower_2, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_2_Level_3_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture6, &RECT_TOWER2, NULL, &m_vPos_Tower_2, m_color);
		m_pSprite->End();
	}

	if (Monster.GetTower_3_Level_1_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture7, &RECT_TOWER3, NULL, &m_vPos_Tower_3, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_3_Level_2_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture8, &RECT_TOWER3, NULL, &m_vPos_Tower_3, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_3_Level_3_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture9, &RECT_TOWER3, NULL, &m_vPos_Tower_3, m_color);
		m_pSprite->End();
	}

	if (Monster.GetTower_4_Level_1_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture10, &RECT_TOWER4, NULL, &m_vPos_Tower_4, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_4_Level_2_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture11, &RECT_TOWER4, NULL, &m_vPos_Tower_4, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_4_Level_3_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture12, &RECT_TOWER4, NULL, &m_vPos_Tower_4, m_color);
		m_pSprite->End();
	}

	if (Monster.GetTower_5_Level_1_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture13, &RECT_TOWER5, NULL, &m_vPos_Tower_5, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_5_Level_2_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture14, &RECT_TOWER5, NULL, &m_vPos_Tower_5, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_5_Level_3_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture15, &RECT_TOWER5, NULL, &m_vPos_Tower_5, m_color);
		m_pSprite->End();
	}
	if (Monster.GetTower_6_Effect() == true)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture16, &RECT_TOWER6, NULL, &m_vPos_Tower_6, m_color);
		m_pSprite->End();
	}
}
