#include "Monster.h"


void CMonster::Run(float tick, int *Score,int* Monster_cnt)
{
	
	if (m_bDraw)
	{
		MoveSpeed = (BaseMoveSpeed + slowSpeed);

		//패턴별로 이동하는 방식을 다르게 설정
		switch (m_Pattern)
		{
		case 0: //첫번쨰웨이브
			if (abc == 0)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 500)				abc = 1;
	
			}


			else if (abc == 1)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x > 300)					abc = 2;
			}
			else if (abc == 2)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y > 700)					abc = 3;

			}
			else if (abc == 3)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x < 150)					abc = 4;

			}
			else if (abc == 4)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 150)					abc = 5;

			}
			else if (abc == 5)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x > 300)					abc = 6;

			}
			else if (abc == 6)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y > 350)					abc = 7;

			}
			else if (abc == 7)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 600)				abc = 8;

			}
			else if (abc == 8)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 250)					abc = 9;
			}
			else if (abc == 9)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 750)				abc = 10;
			}
			else if (abc == 10)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 0)					abc = 11;
			}

			else if (abc == 11 && m_MHP <= 0)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;   if (m_vPos.x >= 1600)   abc = 12;

			}
			else 	if (abc == 11 && m_MHP > 0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;   if (m_vPos.x <= 0)   abc = 13;
			}
			else if (abc == 12)
			{
				*Score += (Entire_HP - m_MHP) * wave_num;
				abc = 14;
			}
			else if (abc == 13 || abc == 14)
			{
				*Monster_cnt += 1;
				m_bDraw = false;
				die = true;
			}

	
			
			break;

		case 1:
			if (abc == 0)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 500)				abc = 1;
				
			}


			else if (abc == 1)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x > 300)					abc = 2;
			}
			else if (abc == 2)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y > 700)					abc = 3;

			}
			else if (abc == 3)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x < 150)					abc = 4;

			}
			else if (abc == 4)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 150)					abc = 5;

			}
			else if (abc == 5)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x > 300)					abc = 6;

			}
			else if (abc == 6)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y > 350)					abc = 7;

			}
			else if (abc == 7)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 450)				abc = 8;

			}
			else if (abc == 8)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y > 700)					abc = 9;
			}
			else if (abc == 9)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 700)				abc = 10;
			}
			else if (abc == 10)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 550)					abc = 11;
			}
			else if (abc == 11)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x < 600)					abc = 12;
			}
			else if (abc == 12)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 250)					abc = 13;
			}
			else if (abc == 13)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x > 750)					abc = 14;
			}
			else if (abc == 14)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y < 0)					abc = 15;
			}

			else if (abc == 15 && m_MHP <= 0)
			{
				
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;   if (m_vPos.x >= 1600)   abc = 16;

			}
			else 	if (abc == 15 && m_MHP >0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;   if (m_vPos.x <= 0)   abc = 17;
			}
			else if (abc == 16)
			{
				*Score += (Entire_HP - m_MHP) * wave_num;
				abc = 18;
			}
			else if (abc == 17 || abc == 18)
			{
				*Monster_cnt += 1;
				m_bDraw = false;
				die = true;
				
			}


			break;

		case 2:
			if (abc == 0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 1250)				abc = 1;
			}
			else if (abc == 1)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 300)				abc = 2;
			}
			else if (abc == 2)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 1100)				abc = 3;
			}
			else if (abc == 3)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 150)				abc = 4;
			}
			else if (abc == 4)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 1400)				abc = 5;
			}
			else if (abc == 5)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y >= 400)				abc = 6;
			}
			else if (abc == 6)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 950)				abc = 7;
			}
			else if (abc == 7)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 250)				abc = 8;
			}
			else if (abc == 8)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 800)				abc = 9;
			}
			else if (abc == 9)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 0)				abc = 10;
			}
			else if (abc == 10 && m_MHP <= 0)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;   if (m_vPos.x >= 1600)   abc = 11;
			}
			else 	if (abc == 10 && m_MHP > 0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;   if (m_vPos.x <= 0)   abc = 12;
			}
			else if (abc == 11)
			{
				*Score += (Entire_HP - m_MHP) * wave_num;
				abc = 13;
			}
			else if (abc == 12 || abc == 13)
			{
				*Monster_cnt += 1;
				m_bDraw = false;
				die = true;
			}

			break;
		case 3:
			if (abc == 0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 1250)				abc = 1;
			}
			else if (abc == 1)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 300)				abc = 2;
			}
			else if (abc == 2)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 1100)				abc = 3;
			}
			else if (abc == 3)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 150)				abc = 4;
			}
			else if (abc == 4)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 1400)				abc = 5;
			}
			else if (abc == 5)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y >= 350)				abc = 6;
			}
			else if (abc == 6)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 1500)				abc = 7;
			}
			else if (abc == 7)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y >= 550)				abc = 8;
			}
			else if (abc == 8)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 1100)				abc = 9;
			}
			else if (abc == 9)
			{
				m_vPos.y += MoveSpeed; m_pTexture_Direction = Direction_front;				if (m_vPos.y >= 700)				abc = 10;
			}
			else if (abc == 10)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 900)				abc = 11;
			}
			else if (abc == 11)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 550)				abc = 12;
			}
			else if (abc == 12)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;				if (m_vPos.x >= 950)				abc = 13;
			}
			else if (abc == 13)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 250)				abc = 14;
			}
			else if (abc == 14)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;				if (m_vPos.x <= 800)				abc = 15;
			}
			else if (abc == 15)
			{
				m_vPos.y -= MoveSpeed; m_pTexture_Direction = Direction_behind;				if (m_vPos.y <= 0)				abc = 16;
			}

			else if (abc == 16 && m_MHP <= 0)
			{
				m_vPos.x += MoveSpeed; m_pTexture_Direction = Direction_right;   if (m_vPos.x >= 1600)   abc = 17;
			}
			else 	if (abc == 16 && m_MHP > 0)
			{
				m_vPos.x -= MoveSpeed; m_pTexture_Direction = Direction_left;   if (m_vPos.x <= 0)   abc = 18;

			}
			else if (abc == 17)
			{
				*Score += (Entire_HP - m_MHP) * wave_num;
				abc = 19;
			}
			else if (abc == 18 || abc == 19)
			{
				*Monster_cnt += 1;
				m_bDraw = false;
				die = true;
			}


		}
	}




	CollPos.x = m_vPos.x + 25.0;
	CollPos.y = m_vPos.y + 25.0;
	
	m_vPos_HP_Bar.x = m_vPos.x ;
	m_vPos_HP_Bar.y = m_vPos.y - 3;

	//HP 떨어지면 주금
	if (m_HP == 0)
	{
		m_bDraw = false;
	}
	
	if (m_MHP <= 0 && resourcecheck == false)
	{
		resource = 10;
	}
	if (m_MHP <= 0)
	{
		BaseMoveSpeed = 15;
	}
	HP_Bar();
	Tunnel();


}


bool CMonster::resourceplus()
{
	if (resource == 10)
	{
		resource = 0;
		resourcecheck = true;
		
		return true;
	}
	else
		return false;




}








void CMonster::HP_Bar()
{
	float A = (float)m_MHP / (float)Entire_HP; // 남은HP/전체HP 비율

	if (m_MHP <= 0)
	{
		A = 0;
	}

	
	m_rect_HP_Bar = { 0, 0, A*50, 10 };
	
	if (m_MHP <= 0)
	{
		m_color = D3DCOLOR_ARGB(255, 100, 100, 100);
		
	}
}

void CMonster::Tunnel()
{
	In_tunnel = false;

	if (100 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 260 && 490 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 590) // 왼쪽 수평 터널
	{
		In_tunnel = true;
	}
	if (1210 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1330 && 360 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 500) // 오른쪽 수직 터널
	{
		In_tunnel = true;
	}
	if (1220 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1360 && 520 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 620) // 오른쪽 수평 터널
	{
		In_tunnel = true;
	}

	// 바구니 들어갔을때도 공격 못하도록 그냥 In_tunnel = true로 하겠음
	if (0 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 300 && 0 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 150)
	{
		In_tunnel = true;
	}

	// 그리기를 위한 장치
	if (280 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 300 && 490 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 590) // 왼쪽 수평 터널 오른출구
	{
		tunnel_end = true;
	}
	if (1210 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1330 && 320 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 340) // 오른쪽 수직 터널 위출구
	{
		tunnel_end = true;
	}
	if (1220 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1360 && 640 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 660) // 오른쪽 수평 터널 아래 지나가는길
	{
		tunnel_end = true;
	}

	if (1236 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1316 && 515 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 525) // 오른쪽 수직 터널 아래입구
	{
		tunnel_end = false;
	}
	if (1380 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 1400 && 520 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 620) // 오른쪽 수평 터널 오른입구
	{
		tunnel_end = false;
	}
	if (700 <= (m_vPos.x + 25) && (m_vPos.x + 25) <= 900 && 0 <= (m_vPos.y + 30) && (m_vPos.y + 30) <= 100) // 팩토리 입구
	{
		tunnel_end = false;
	}
}

void CMonster::Init(CTexture t1, CTexture t2, CTexture t3, CTexture t4, CTexture t5, CTexture HP)
{
	m_pSprite = CDevice::GetSprite();

	m_pTexture_nyang_cup = t1.GetTexture();
	m_pTexture_gitar = t2.GetTexture();
	m_pTexture_sangza = t3.GetTexture();
	m_pTexture_bongzi_1 = t4.GetTexture();
	m_pTexture_bongzi_2 = t5.GetTexture();

	m_pTexture_HP_Bar = HP.GetTexture();

	m_alpha = 255;

	m_color_HP_Bar = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_vPos_HP_Bar = D3DXVECTOR3(1500, 1500, 0);
	m_rect_HP_Bar = { 0, 0, HP.GetWidth(), HP.GetHeight() };

	m_vPos = D3DXVECTOR3(1500, 1500, 0); // 여깁니다 여기!!!!!!!!! 여기가 문제였어!!!
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 50, 50 };
	m_radius = 37.0;
	m_aniTimer = 0;
	m_aniNum = 0;
	Coll_Radius = 60;
	die = false;
	m_bDraw = false;
	abc = 0;
	
	wave_num = 1;
	BaseMoveSpeed = 5;

	In_tunnel = false;
	tunnel_end = false;

	slowtime = 0;

	m_MHP = 1000; // 총알과의 충돌 HP



	Persistcheck = false;
	Persisttime = 0;
	check = false;
	P_check = &check;
	cooltime = 0;
	resourcecheck = false;
	resource = 0;
	Tower_1_Level_1_Effect = false;
	P_Tower_1_Level_1_Effect = &Tower_1_Level_1_Effect;
	Tower_1_Level_2_Effect = false;
	P_Tower_1_Level_2_Effect = &Tower_1_Level_2_Effect;
	Tower_1_Level_3_Effect = false;
	P_Tower_1_Level_3_Effect = &Tower_1_Level_3_Effect;

	Tower_2_Level_1_Effect = false;
	P_Tower_2_Level_1_Effect = &Tower_2_Level_1_Effect;
	Tower_2_Level_2_Effect = false;
	P_Tower_2_Level_2_Effect = &Tower_2_Level_2_Effect;
	Tower_2_Level_3_Effect = false;
	P_Tower_2_Level_3_Effect = &Tower_2_Level_3_Effect;

	Tower_3_Level_1_Effect = false;
	P_Tower_3_Level_1_Effect = &Tower_3_Level_1_Effect;
	Tower_3_Level_2_Effect = false;
	P_Tower_3_Level_2_Effect = &Tower_3_Level_2_Effect;
	Tower_3_Level_3_Effect = false;
	P_Tower_3_Level_3_Effect = &Tower_3_Level_3_Effect;

	Tower_4_Level_1_Effect = false;
	P_Tower_4_Level_1_Effect = &Tower_4_Level_1_Effect;
	Tower_4_Level_2_Effect = false;
	P_Tower_4_Level_2_Effect = &Tower_4_Level_2_Effect;
	Tower_4_Level_3_Effect = false;
	P_Tower_4_Level_3_Effect = &Tower_4_Level_3_Effect;

	Tower_5_Level_1_Effect = false;
	P_Tower_5_Level_1_Effect = &Tower_5_Level_1_Effect;
	Tower_5_Level_2_Effect = false;
	P_Tower_5_Level_2_Effect = &Tower_5_Level_2_Effect;
	Tower_5_Level_3_Effect = false;
	P_Tower_5_Level_3_Effect = &Tower_5_Level_3_Effect;

	Tower_6_Effect = false;
	P_Tower_6_Effect = &Tower_6_Effect;



	P_Effect_first_time = &Effect_first_time;

	P_cooltime = &cooltime;

	P_Persistcheck = &Persistcheck;
	P_Persisttime = &Persisttime;
	P_Persist_tick = &Persist_tick;
	P_Persist_first_time = &Persist_first_time;

	rect_left = 0;
	rect_top = 0;
	rect_right = 50;
	rect_bottom = 50;
	
	pm_HP = &m_MHP; // MHP 포인터
}

void CMonster::Draw()
{
	if (m_bDraw)
	{
		Animation(&m_aniTimer, &m_aniNum, 110, 81, 5, 10, 0.25f);

		Spriting();

		switch (Monster_State)
		{
			case nyang_cup:
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTexture_nyang_cup, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			}

			case gitar:
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTexture_gitar, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			}

			case sangza:
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTexture_sangza, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			}

			case bongzi_1:
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTexture_bongzi_1, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			}

			case bongzi_2:
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pTexture_bongzi_2, &m_rect, NULL, &m_vPos, m_color);
				m_pSprite->End();
				break;
			}
		}

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture_HP_Bar, &m_rect_HP_Bar, NULL, &m_vPos_HP_Bar, m_color_HP_Bar);
		m_pSprite->End();
	}
}

void CMonster::slow(int Tilex, int Tiley, bool Cslowcheck,int level)
{
	switch (level)
	{
	case 1:
		if (Cslowcheck == true)
		{
			slowSpeed = -(BaseMoveSpeed /4);
			slowx = Tilex;
			slowy = Tiley;
			Tower_6_Effect = true;
			*P_Effect_first_time = GetTickCount();
		}
		if (Cslowcheck == false)
		{
			if (slowx == Tilex && slowy == Tiley)
			{
				slowSpeed = 0;
				//	slowcheck = false;
			}
		}
		
		break;
	case 2:
		
		if (Cslowcheck == true)
		{
			slowSpeed = -(BaseMoveSpeed / 3);
		
			slowx = Tilex;
			slowy = Tiley;
			Tower_6_Effect = true;
			*P_Effect_first_time = GetTickCount();
		}
		if (Cslowcheck == false)
		{
			if (slowx == Tilex && slowy == Tiley)
			{
				slowSpeed = 0;
				//	slowcheck = false;
			}

		}
		break;
	case 3:
		if (Cslowcheck == true)
		{
			slowSpeed = -(BaseMoveSpeed / 2);
			
			slowx = Tilex;
			slowy = Tiley;
			Tower_6_Effect = true;
			*P_Effect_first_time = GetTickCount();
		}
		if (Cslowcheck == false)
		{
			if (slowx == Tilex && slowy == Tiley)
			{
				slowSpeed = 0;
				
			}

		}

		break;
	}


}

void CMonster::Start(int type, int pattern,int HP ,int speed)
{
	m_Type = type;
	m_Pattern = pattern;
	m_bDraw = true;
	die = false;
	abc = 0;
	//타입마다 텍스쳐, HP, 반지름 등을 다르게 설정
	switch (m_Type)
	{
	case firstwave:
		Monster_State = nyang_cup;
		m_HP = 20;
		m_MHP = HP;
		BaseMoveSpeed = speed;
		break;
		

	case secondwave:
		Monster_State = gitar;
		m_HP = 20;
		m_MHP = HP;
		BaseMoveSpeed = speed;
		break;
		

	case thirdwave:
		Monster_State = sangza;
		m_HP = 20;
		m_MHP = HP;
		BaseMoveSpeed = speed;
		break;

	case fourthwave:
		Monster_State = bongzi_1;
		m_HP = 20;
		m_MHP = HP;
		BaseMoveSpeed = speed;
		break;

	case fifthwave:
		Monster_State = bongzi_2;
		m_HP = 20;
		m_MHP = HP;
		BaseMoveSpeed = speed;
		break;
	}
	Entire_HP = m_MHP;
	//패털별로 처음 시작 위치를 다르게 설정
	switch (m_Pattern)
	{
	case 0:
		m_vPos = D3DXVECTOR3(50,950, 0);
		break;

	case 1:
		m_vPos = D3DXVECTOR3(50,950 , 0);
		break;

	case 2:
		m_vPos = D3DXVECTOR3(1650, 700, 0);
		break;
	case 3://여긴또 뭘하면 ...
		m_vPos = D3DXVECTOR3(1650, 700, 0);
		break;
	}
}

void CMonster::Spriting()
{
	// 기타 8개
	// 냥컵 14개

	Sprite_tick = (float)(GetTickCount() - Sprite_first_time) / (float)1000;
	// m_rect = { left, top, right, bottom };
	switch (Monster_State)
	{
		case nyang_cup:
		{
			if (Sprite_tick > 0.05) // 0.01 빠름 0.05 적당
			{
				switch (m_pTexture_Direction)
				{
					case Direction_front:
					{
						if (rect_right < 700)
						{
							rect_top = 0;
							rect_bottom = 50;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 700)
						{
							rect_top = 0;
							rect_bottom = 50;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_behind:
					{
						if (rect_right < 700)
						{
							rect_top = 50;
							rect_bottom = 100;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 700)
						{
							rect_top = 50;
							rect_bottom = 100;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_left:
					{
						if (rect_right < 700)
						{
							rect_top = 100;
							rect_bottom = 150;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 700)
						{
							rect_top = 100;
							rect_bottom = 150;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_right:
					{
						if (rect_right < 700)
						{
							rect_top = 150;
							rect_bottom = 200;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 700)
						{
							rect_top = 150;
							rect_bottom = 200;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
				}
				
				m_rect = { rect_left, rect_top, rect_right, rect_bottom };
				Sprite_first_time = GetTickCount();
			}
			break;
		}

		case gitar:
		{
			if (Sprite_tick > 0.05) // 0.01 빠름 0.05 적당
			{
				switch (m_pTexture_Direction)
				{
					case Direction_front:
					{
						if (rect_right < 400)
						{
							rect_top = 0;
							rect_bottom = 50;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 400)
						{
							rect_top = 0;
							rect_bottom = 50;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_behind:
					{
						if (rect_right < 400)
						{
							rect_top = 50;
							rect_bottom = 100;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 400)
						{
							rect_top = 50;
							rect_bottom = 100;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_left:
					{
						if (rect_right < 400)
						{
							rect_top = 100;
							rect_bottom = 150;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 400)
						{
							rect_top = 100;
							rect_bottom = 150;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
					case Direction_right:
					{
						if (rect_right < 400)
						{
							rect_top = 150;
							rect_bottom = 200;
							rect_right += 50;
							rect_left += 50;
						}
						else if (rect_right >= 400)
						{
							rect_top = 150;
							rect_bottom = 200;
							rect_right = 50;
							rect_left = 0;
						}
						break;
					}
				}
				m_rect = { rect_left, rect_top, rect_right, rect_bottom };
				Sprite_first_time = GetTickCount();
			}
			break;
		}

		case sangza:
		{
			if (Sprite_tick > 0.05) // 0.01 빠름 0.05 적당
			{
				switch (m_pTexture_Direction)
				{
				case Direction_front:
				{
					if (rect_right < 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_behind:
				{
					if (rect_right < 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_left:
				{
					if (rect_right < 400)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_right:
				{
					if (rect_right < 400)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				}
				m_rect = { rect_left, rect_top, rect_right, rect_bottom };
				Sprite_first_time = GetTickCount();
			}
			break;
		}

		case bongzi_1:
		{
			if (Sprite_tick > 0.05) // 0.01 빠름 0.05 적당
			{
				switch (m_pTexture_Direction)
				{
				case Direction_front:
				{
					if (rect_right < 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_behind:
				{
					if (rect_right < 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_left:
				{
					if (rect_right < 350)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 350)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_right:
				{
					if (rect_right < 350)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 350)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				}
				m_rect = { rect_left, rect_top, rect_right, rect_bottom };
				Sprite_first_time = GetTickCount();
			}
			break;
		}

		case bongzi_2:
		{
			if (Sprite_tick > 0.05) // 0.01 빠름 0.05 적당
			{
				switch (m_pTexture_Direction)
				{
				case Direction_front:
				{
					if (rect_right < 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 0;
						rect_bottom = 50;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_behind:
				{
					if (rect_right < 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 50;
						rect_bottom = 100;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_left:
				{
					if (rect_right < 400)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 100;
						rect_bottom = 150;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				case Direction_right:
				{
					if (rect_right < 400)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right += 50;
						rect_left += 50;
					}
					else if (rect_right >= 400)
					{
						rect_top = 150;
						rect_bottom = 200;
						rect_right = 50;
						rect_left = 0;
					}
					break;
				}
				}
				m_rect = { rect_left, rect_top, rect_right, rect_bottom };
				Sprite_first_time = GetTickCount();
			}
			break;
		}
	}



}