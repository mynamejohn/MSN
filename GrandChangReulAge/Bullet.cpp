#include "Bullet.h"

void CBullet::Init(CTexture Tower_1_Level_1_Bullet, CTexture Tower_1_Level_2_Bullet, CTexture Tower_1_Level_3_Bullet,
				   CTexture Tower_2_Level_1_Bullet, CTexture Tower_2_Level_2_Bullet, CTexture Tower_2_Level_3_Bullet,
				   CTexture Tower_3_Level_1_Bullet, CTexture Tower_3_Level_2_Bullet, CTexture Tower_3_Level_3_Bullet,
				   CTexture Tower_4_Level_1_Bullet, CTexture Tower_4_Level_2_Bullet, CTexture Tower_4_Level_3_Bullet,
				   CTexture Tower_5_Level_1_Bullet, CTexture Tower_5_Level_2_Bullet, CTexture Tower_5_Level_3_Bullet,
				   CTexture Attack_Range_50, CTexture Attack_Range_75, CTexture Attack_Range_100, CTexture Attack_Range_150,
				   CTexture Attack_Range_200, CTexture Attack_Range_250, CTile Tile, int i, int j)
{
	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
	m_pTexture_Tower_1_Level_1_Bullet = Tower_1_Level_1_Bullet.GetTexture();
	m_pTexture_Tower_1_Level_2_Bullet = Tower_1_Level_2_Bullet.GetTexture();
	m_pTexture_Tower_1_Level_3_Bullet = Tower_1_Level_3_Bullet.GetTexture();
	m_pTexture_Tower_2_Level_1_Bullet = Tower_2_Level_1_Bullet.GetTexture();
	m_pTexture_Tower_2_Level_2_Bullet = Tower_2_Level_2_Bullet.GetTexture();
	m_pTexture_Tower_2_Level_3_Bullet = Tower_2_Level_3_Bullet.GetTexture();
	m_pTexture_Tower_3_Level_1_Bullet = Tower_3_Level_1_Bullet.GetTexture();
	m_pTexture_Tower_3_Level_2_Bullet = Tower_3_Level_2_Bullet.GetTexture();
	m_pTexture_Tower_3_Level_3_Bullet = Tower_3_Level_3_Bullet.GetTexture();
	m_pTexture_Tower_4_Level_1_Bullet = Tower_4_Level_1_Bullet.GetTexture();
	m_pTexture_Tower_4_Level_2_Bullet = Tower_4_Level_2_Bullet.GetTexture();
	m_pTexture_Tower_4_Level_3_Bullet = Tower_4_Level_3_Bullet.GetTexture();
	m_pTexture_Tower_5_Level_1_Bullet = Tower_5_Level_1_Bullet.GetTexture();
	m_pTexture_Tower_5_Level_2_Bullet = Tower_5_Level_2_Bullet.GetTexture();
	m_pTexture_Tower_5_Level_3_Bullet = Tower_5_Level_3_Bullet.GetTexture();

	m_pSprite = CDevice::GetSprite();
	m_rect = { 0, 0, Tower_1_Level_1_Bullet.GetWidth(), Tower_1_Level_1_Bullet.GetHeight() };
	m_alpha = 255;

	m_vPos.y = (float)50 * i + 15;
	m_vPos.x = (float)50 * j + 20;

	m_vPos2.y = (float)50 * i + 0;
	m_vPos2.x = (float)50 * j + 10;

	m_bDraw = false;
	m_bDraw2 = false;

	first_time = GetTickCount();
	Penetration_first_time = GetTickCount();
	TempDistance = 1000; // 가장 가까운 적의 거리를 계속 업데이트하는 변수
	OnFire = false; // 사정거리내에 있다고해서 발사랑 같게 해버리면 곤란... 그래서 별개로 발사라는 신호를 둠

	Impacted_X_Pos = 0;
	Impacted_Y_Pos = 0;
	Penetration_Attack = true;
	Quadrant = 0;
	turning_N = 0; // 회전타워 라디안 초기화

	ani_num = 0;

	// 사정거리
	Attack_Range_color = D3DCOLOR_ARGB(70, 255, 255, 255);
	m_pAttack_Range_50 = Attack_Range_50.GetTexture();
	m_pAttack_Range_75 = Attack_Range_75.GetTexture();
	m_pAttack_Range_100 = Attack_Range_100.GetTexture();
	m_pAttack_Range_150 = Attack_Range_150.GetTexture();
	m_pAttack_Range_200 = Attack_Range_200.GetTexture();
	m_pAttack_Range_250 = Attack_Range_250.GetTexture();

	Attack_Range_50_rect = { 0, 0, Attack_Range_50.GetWidth(), Attack_Range_50.GetHeight() };
	Attack_Range_75_rect = { 0, 0, Attack_Range_75.GetWidth(), Attack_Range_75.GetHeight() };
	Attack_Range_100_rect = { 0, 0, Attack_Range_100.GetWidth(), Attack_Range_100.GetHeight() };
	Attack_Range_150_rect = { 0, 0, Attack_Range_150.GetWidth(), Attack_Range_150.GetHeight() };
	Attack_Range_200_rect = { 0, 0, Attack_Range_200.GetWidth(), Attack_Range_200.GetHeight() };
	Attack_Range_250_rect = { 0, 0, Attack_Range_250.GetWidth(), Attack_Range_250.GetHeight() };

	turnrecttop = 0;
	turnrectright = 50;
	turnrectleft = 0;
	turnrectbottom = 50;
	turntime = GetTickCount();
	
	ani_time = 0;
}

void CBullet::Run_Level_Init(CTile Tile)
{

	/////////////////////////// 기본 //////////////////////////////////
	if (Tile.GetStatus() == WareHouse)
	{
		switch (Tile.level)
		{
			case 1:
			{
				Attack_Damage = 2.0; // 공격력
				Bullet_Speed = 7.0; // 총알의 스피드
				Attack_Speed = 1.0; // 타워의 공격속도
				Attack_Range = 150.0; // 사정거리
				break;
			}
			case 2:
			{
				Attack_Damage = 5; // 공격력
				Bullet_Speed = 9.0; // 총알의 스피드
				Attack_Speed = 0.75; // 타워의 공격속도
				Attack_Range = 200.0; // 사정거리
				break;
			}
			case 3:
			{
				Attack_Damage = 5.0; // 공격력
				Bullet_Speed = 11.0; // 총알의 스피드
				Attack_Speed = 0.5; // 타워의 공격속도
				Attack_Range = 250.0; // 사정거리
				break;
			}

			default:
			{

				break;
			}
		}
	}

	/////////////////////////// 스플 //////////////////////////////////
	if (Tile.GetStatus() == splash)
	{
		switch (Tile.level)
		{
			case 1:
			{
				splash_Attack_Damage = 1.0;
				splash_Bullet_Speed = 7.0;
				splash_Attack_Speed = 2.0;
				splash_Attack_Range = 150.0;
				splash_Range = 90.0;
				break;
			}
			case 2:
			{
				splash_Attack_Damage = 2.5;
				splash_Bullet_Speed = 9.0;
				splash_Attack_Speed = 1.5;
				splash_Attack_Range = 200.0;
				splash_Range = 120.0;
				break;
			}
			case 3:
			{
				splash_Attack_Damage = 4.0;
				splash_Bullet_Speed = 11.0;
				splash_Attack_Speed = 1.0;
				splash_Attack_Range = 250.0;
				splash_Range = 150.0;
				break;
			}

			default:
			{

				break;
			}
		}
	}
	ani_time += 1;
	

	/////////////////////////// 관통 //////////////////////////////////
	if (Tile.GetStatus() == penetration)
	{
		switch (Tile.level)
		{
			case 1:
			{
				Penetration_Attack_Damage = 3.0;
				Penetration_Bullet_Speed = 6.0; // 0~9  9넘어가면 안댐 절대
				Penetration_Attack_Speed = 2.0;
				Penetration_Attack_Range = 100.0;
				Penetration_Distance = 150.0; // 관통거리
				Penetration_Monster_Damage_Cooltime = 0.2; // 일정한 간격(쿨타임)마다 데미지 입힘
				Penetration_Impact_Range = 25.0; // 지나가면서 몬스터와의 충돌거리
				
				m_rect = { ani_num * 40, 0, (ani_num + 1) * 40, 40 };
				if ((int)ani_time > 1000 == 0)
				{
					ani_time = 0;
					ani_num += 1;
					ani_num = ani_num % 10;
				}

				break;
			}
			case 2:
			{
				Penetration_Attack_Damage = 9.0;
				Penetration_Bullet_Speed = 7.0; // 0~9  9넘어가면 안댐 절대
				Penetration_Attack_Speed = 1.66;
				Penetration_Attack_Range = 150.0;
				Penetration_Distance = 200.0; // 관통거리
				Penetration_Monster_Damage_Cooltime = 0.15; // 일정한 간격(쿨타임)마다 데미지 입힘
				Penetration_Impact_Range = 35.0; // 지나가면서 몬스터와의 충돌거리
				//m_rect = { 0, 0, 43, 43 };
				m_rect = { ani_num * 43, 0, (ani_num + 1) * 43, 43 };
				if ((int)ani_time > 1000 == 0)
				{
					ani_time = 0;
					ani_num += 1;
					ani_num = ani_num % 10;
				}
				break;
			}
			case 3:
			{
				Penetration_Attack_Damage = 18.0;
				Penetration_Bullet_Speed = 8.0; // 0~9  9넘어가면 안댐 절대
				Penetration_Attack_Speed = 1.33;
				Penetration_Attack_Range = 200.0;
				Penetration_Distance = 300.0; // 관통거리
				Penetration_Monster_Damage_Cooltime = 0.1; // 일정한 간격(쿨타임)마다 데미지 입힘
				Penetration_Impact_Range = 50.0; // 지나가면서 몬스터와의 충돌거리
				//m_rect = { 0, 0, 45, 45 };
				m_rect = { ani_num * 45, 0, (ani_num + 1) * 45, 45 };
				if ((int)ani_time > 1000 == 0)
				{
					ani_time = 0;
					ani_num += 1;
					ani_num = ani_num % 10;
				}
				break;
			}

			default:
			{

				break;
			}
		}
		
	}

	/////////////////////////// 회전 //////////////////////////////////
	if (Tile.GetStatus() == turning)
	{
		switch (Tile.level)
		{
			case 1:
			{
				turning_Attack_Damage = 1;
				turning_Bullet_Speed = 3.0; // 1~4 만 해야됨 4가 느린거 1이 제일빠름
				turning_Attack_Range = 90.0;
				turning_Distance = 50.0; // 회전반지름
				turning_Monster_Damage_Cooltime = 0.5; // 일정한 간격(쿨타임)마다 데미지 입힘
				turning_Impact_Range = 25.0; // 지나가면서 몬스터와의 충돌거리
				break;
			}
			case 2:
			{
				turning_Attack_Damage = 2.5;
				turning_Bullet_Speed = 2.5; // 1~4 만 해야됨 4가 느린거 1이 제일빠름
				turning_Attack_Range = 115.0;
				turning_Distance = 75.0; // 회전반지름
				turning_Monster_Damage_Cooltime = 0.4; // 일정한 간격(쿨타임)마다 데미지 입힘
				turning_Impact_Range = 30.0; // 지나가면서 몬스터와의 충돌거리
				break;
			}
			case 3:
			{
				turning_Attack_Damage = 4;
				turning_Bullet_Speed = 2.0; // 1~4 만 해야됨 4가 느린거 1이 제일빠름
				turning_Attack_Range = 140.0;
				turning_Distance = 100.0; // 회전반지름
				turning_Monster_Damage_Cooltime = 0.3; // 일정한 간격(쿨타임)마다 데미지 입힘
				turning_Impact_Range = 35.0; // 지나가면서 몬스터와의 충돌거리
				break;
			}

			default:
			{

				break;
			}
		}
	}

	/////////////////////////// 지속 //////////////////////////////////
	if (Tile.GetStatus() == persisttower)
	{
		switch (Tile.level)
		{
			case 1:
			{ // 무조건 5초동안 지속적으로 공격하며 중첩이안댐
				persist_Attack_Damage = 0.3; // 총데미지는 x 50 해야함
				persist_Bullet_Speed = 7.0;
				persist_Attack_Speed = 3.0;
				persist_Attack_Range = 150.0;
				break;
			}
			case 2:
			{
				persist_Attack_Damage = 0.9; // 총데미지는 x 50 해야함
				persist_Bullet_Speed = 11.0;
				persist_Attack_Speed = 2.5;
				persist_Attack_Range = 200.0;
				break;
			}
			case 3:
			{
				persist_Attack_Damage = 1.8; // 총데미지는 x 50 해야함
				persist_Bullet_Speed = 11.0;
				persist_Attack_Speed = 2.0;
				persist_Attack_Range = 250.0;
				break;
			}

			default:
			{

				break;
			}
		}
	}
}

void CBullet::Run(CTile Tile, CMonster Monster, int i, int j, int z)
{
	if (Tile.GetStatus() == WareHouse)
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함
	
		
		if (OnTarget[z] == true) // OnTarget이 타워의 공격우선순위를 가장 가까운 적으로 해놔서 하나만 true하고 나머진 false 
		{
			TempDistance = Distance; // 가장 가까운 적의 거리를 계속 업데이트
		}

		if (Bullet_tick == 0)
		{
			Tile.Setani(WareHouseStand);
		}

		if (Bullet_tick >= 2)
		{
			Tile.Setani(WareHouseStand);
		
			
		}
		
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (Distance <= Attack_Range) // 사정거리내에 들어가면
			{
				Tile.Setani(WareHouse);
				if (Distance <= TempDistance) // 근데 다른 적이 계속 업데이트한 가장 1순위 적과의 거리보다 작을시
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // 일단 다른거 다 false로 초기화하고
					}
					OnTarget[z] = true; //  그 적을 1순위로 정함
				}
				else
				{
					OnTarget[z] = false; // 크다면 그냥 false
				}
			}
			else // 사정거리내보다 크면 그냥 다 false인데
			{
				Target[z] = false; // 이것은 사정거리내에 적을 알아내기위해 해놨는데 아직 쓰진 않음 (두마리면 2개 true, 3마리면 3개 true 이렇게)
				OnTarget[z] = false;
			}
		}
		
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (OnFire == false) // 아직 발사가 안됐다면
			{
				if (OnTarget[z] == true) // 아직 발사가 안된상태에서 1순위가 true라면
				{
					if (Bullet_tick >= Attack_Speed) // 쿨타임이 찼다면
					{
						OnFire = true; // 발사
						m_bDraw = true; // 그리기
						if (Tile.level == 3)
						{
							m_bDraw2 = true;  // 2번총알 그리기
						}
						BulletFire[z] = true; // 총알의 발사허가

						first_time = GetTickCount(); // 쿨타임 초기화
					}
				}
			}
		}
		if (BulletFire[z] == true) // 총알날라가기
		{
			// 밑에는 그냥 이동하는거
			if ((Monster.m_vPos.x + 25) > (m_vPos.x + 10))
			{
				m_vPos.x += Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) < Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}
			}
			else
			{
				m_vPos.x -= Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) > -Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}

			}
			if ((Monster.m_vPos.y + 30) > (m_vPos.y + 10))
			{
				m_vPos.y += Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) < Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}
			else
			{
				m_vPos.y -= Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) > -Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}

			if (Tile.level == 3)
			{
				// 밑에는 그냥 이동하는거
				if ((Monster.m_vPos.x + 25) > (m_vPos2.x + 10))
				{
					m_vPos2.x += Bullet_Speed - 1;
					if ((Monster.m_vPos.x + 25) - (m_vPos2.x + 10) < Bullet_Speed - 1)
					{
						m_vPos2.x = Monster.m_vPos.x + 15;
					}
				}
				else
				{
					m_vPos2.x -= Bullet_Speed - 1;
					if ((Monster.m_vPos.x + 25) - (m_vPos2.x + 10) > -Bullet_Speed - 1)
					{
						m_vPos2.x = Monster.m_vPos.x + 15;
					}

				}
				if ((Monster.m_vPos.y + 30) > (m_vPos2.y + 10))
				{
					m_vPos2.y += Bullet_Speed - 1;
					if ((Monster.m_vPos.y + 30) - (m_vPos2.y + 10) < Bullet_Speed - 1)
					{
						m_vPos2.y = Monster.m_vPos.y + 20;
					}
				}
				else
				{
					m_vPos2.y -= Bullet_Speed - 1;
					if ((Monster.m_vPos.y + 30) - (m_vPos2.y + 10) > -Bullet_Speed - 1)
					{
						m_vPos2.y = Monster.m_vPos.y + 20;
					}
				}
			}
		}

		Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
		Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 다시 한번 더 총알과 몬스터거리 계산 

		if (Bullet_Distance <= 10 && m_bDraw == true) // 거리가 5이하이면
		{
			// 모두 초기화
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;

			Monster.SetHP(Monster.GetHP() - Attack_Damage); // 몬스터의 피가 데미지만큼 줄어든다.

			// 타격이펙트 시작
			if (Tile.level == 1)
			{
				Monster.SetTower_1_Level_1_Effect(true);
			}
			else if (Tile.level == 2)
			{
				Monster.SetTower_1_Level_2_Effect(true);
			}
			else if (Tile.level == 3)
			{
				Monster.SetTower_1_Level_3_Effect(true);
			}
			Monster.SetEffect_first_time(GetTickCount()); // 쿨타임 초기화

		}

		if (Tile.level == 3)
		{
			Bullet_X2 = (m_vPos2.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y2 = (m_vPos2.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance2 = sqrt((Bullet_X2 * Bullet_X2) + (Bullet_Y2 * Bullet_Y2)); // 다시 한번 더 총알과 몬스터거리 계산 

			if (Bullet_Distance2 <= 10 && m_bDraw2 == true) // 거리가 5이하이면
			{
				m_vPos2.x = (float)50 * j + 0;
				m_vPos2.y = (float)50 * i + 10;
				m_bDraw2 = false;

				Monster.SetHP(Monster.GetHP() - Attack_Damage);
			}
		}

		if (Tile.level != 3)
		{
			if (m_bDraw == false)
			{
				BulletFire[z] = false;
				OnFire = false;
			}
		}
		else if (Tile.level == 3)
		{
			if (m_bDraw == false && m_bDraw2 == false)
			{
				BulletFire[z] = false;
				OnFire = false;
			}
		}

	}

	//////////////////////////////////// 스플래시이이이이이이 /////////////////////////////////////////////
	if (Tile.GetStatus() == splash)
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함
		
		if (Bullet_tick == 0)
		{
			Tile.Setani(splashStand);
		}
		
		
		if (Bullet_tick > 2)
		{
			Tile.Setani(splashStand);
		
		}
		if (OnTarget[z] == true) // OnTarget이 타워의 공격우선순위를 가장 가까운 적으로 해놔서 하나만 true하고 나머진 false 
		{
			TempDistance = Distance; // 가장 가까운 적의 거리를 계속 업데이트
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (Distance <= splash_Attack_Range) // 사정거리내에 들어가면
			{
				Tile.Setani(splash);
				if (Distance <= TempDistance) // 근데 다른 적이 계속 업데이트한 가장 1순위 적과의 거리보다 작을시
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // 일단 다른거 다 false로 초기화하고
					}
					OnTarget[z] = true; //  그 적을 1순위로 정함
				}
				else
				{
					OnTarget[z] = false; // 크다면 그냥 false
				}
			}
			else // 사정거리내보다 크면 그냥 다 false인데
			{
				Target[z] = false; // 이것은 사정거리내에 적을 알아내기위해 해놨는데 아직 쓰진 않음 (두마리면 2개 true, 3마리면 3개 true 이렇게)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (OnFire == false) // 아직 발사가 안됐다면
			{
				if (OnTarget[z] == true) // 아직 발사가 안된상태에서 1순위가 true라면
				{
					if (Bullet_tick >= splash_Attack_Speed) // 쿨타임이 찼다면
					{
						OnFire = true; // 발사
						m_bDraw = true; // 그리기
						BulletFire[z] = true; // 총알의 발사허가

						first_time = GetTickCount(); // 쿨타임 초기화
					}
				}
			}
		}

		if (BulletFire[z] == true) // 총알날라가기
		{
			Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 총알과 몬스터의 거리계산

			// 밑에는 그냥 이동하는거
			if ((Monster.m_vPos.x + 25) > (m_vPos.x + 10))
			{
				m_vPos.x += splash_Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) < splash_Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}
			}
			else
			{
				m_vPos.x -= splash_Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) > -splash_Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}

			}
			if ((Monster.m_vPos.y + 30) > (m_vPos.y + 10))
			{
				m_vPos.y += splash_Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) < splash_Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}
			else
			{
				m_vPos.y -= splash_Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) > -splash_Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}

		}

		Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
		Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 다시 한번 더 총알과 몬스터거리 계산 

		if (Bullet_Distance <= 10) // 거리가 5이하이면
		{
			Impacted_X_Pos = m_vPos.x + 10;
			Impacted_Y_Pos = m_vPos.y + 10;
			for (int splash_Tempz = 0; splash_Tempz < MonsterNum * 3; splash_Tempz++)
			{
				splash_Impact_Switch[splash_Tempz] = true;
			}
			// 모두 초기화
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;
			BulletFire[z] = false;
			OnFire = false;
		}

		if (splash_Impact_Switch[z] == true)
		{
			splash_X = (Impacted_X_Pos - (Monster.m_vPos.x + 25));
			splash_Y = (Impacted_Y_Pos - (Monster.m_vPos.y + 30));
			splash_Bullet_Distance = sqrt((splash_X * splash_X) + (splash_Y * splash_Y));

			if (splash_Bullet_Distance < splash_Range)
			{
				Monster.SetHP(Monster.GetHP() - splash_Attack_Damage); // 몬스터의 피가 데미지만큼 줄어든다.
				// 타격이펙트 시작
				if (Tile.level == 1)
				{
					Monster.SetTower_2_Level_1_Effect(true);
				}
				else if (Tile.level == 2)
				{
					Monster.SetTower_2_Level_2_Effect(true);
				}
				else if (Tile.level == 3)
				{
					Monster.SetTower_2_Level_3_Effect(true);
				}
				Monster.SetEffect_first_time(GetTickCount()); // 쿨타임 초기화
			}
			splash_Impact_Switch[z] = false;
		}
	}

	///////////////////////////////////////// 관토오오오옹 ////////////////////////////////////////////////////
	if (Tile.GetStatus() == penetration) // 3번 관통타워
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함
		//m_rect = { 0, 0, 40, 40 };
		if (Bullet_tick == 0)
		{
			Tile.Setani(penetrationstand);
		}

		if (Bullet_tick > 2)
		{
			Tile.Setani(penetrationstand);
		}
		if (OnTarget[z] == true) // OnTarget이 타워의 공격우선순위를 가장 가까운 적으로 해놔서 하나만 true하고 나머진 false 
		{
			TempDistance = Distance; // 가장 가까운 적의 거리를 계속 업데이트
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (Distance <= Penetration_Attack_Range) // 사정거리내에 들어가면
			{
				Tile.Setani(penetration);
				if (Distance <= TempDistance) // 근데 다른 적이 계속 업데이트한 가장 1순위 적과의 거리보다 작을시
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // 일단 다른거 다 false로 초기화하고
					}
					OnTarget[z] = true; //  그 적을 1순위로 정함
				}
				else
				{
					OnTarget[z] = false; // 크다면 그냥 false
				}
			}
			else // 사정거리내보다 크면 그냥 다 false인데
			{
				Target[z] = false; // 이것은 사정거리내에 적을 알아내기위해 해놨는데 아직 쓰진 않음 (두마리면 2개 true, 3마리면 3개 true 이렇게)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (OnFire == false) // 아직 발사가 안됐다면
			{
				if (OnTarget[z] == true) // 아직 발사가 안된상태에서 1순위가 true라면
				{
					if (Bullet_tick >= Penetration_Attack_Speed) // 쿨타임이 찼다면
					{
						OnFire = true; // 발사
						m_bDraw = true; // 그리기
						BulletFire[z] = true; // 총알의 발사허가
						
						first_time = GetTickCount(); // 쿨타임 초기화
					}
				}
			}
		}

		if (BulletFire[z] == true) // 총알날라가기
		{
			if (Penetration_Attack == true)
			{
				Penetration_Attack = false;

				X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
				Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
				Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함

				Bullet_cos = (float)((float)(Tile.CollPos.x - (Monster.m_vPos.x + 25)) / (float)Distance);
				Bullet_sin = (float)((float)(Tile.CollPos.y - (Monster.m_vPos.y + 30)) / (float)Distance);

				if (Bullet_cos < 0)
				{
					Bullet_cos = -Bullet_cos;
				}
				if (Bullet_sin < 0)
				{
					Bullet_sin = -Bullet_sin;
				}

				Target_X_Interval = (float)(Penetration_Distance * Bullet_cos);
				Target_Y_Interval = (float)(Penetration_Distance * Bullet_sin);

				Penetration_Temp_Bullet_Speed = 100 - (10 * Penetration_Bullet_Speed); // 임시 스피드에 진짜스피드적용

				Temp_X_Bullet_Speed = (float)((float)Target_X_Interval / (float)Penetration_Temp_Bullet_Speed);
				Temp_Y_Bullet_Speed = (float)((float)Target_Y_Interval / (float)Penetration_Temp_Bullet_Speed);

				if ((Tile.CollPos.x) - (Monster.m_vPos.x + 25) < 0 && (Tile.CollPos.y) - (Monster.m_vPos.y + 30) > 0)
				{
					Quadrant = 1;
					Target_X_Pos = (Tile.CollPos.x) + Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y) - Target_Y_Interval;
				}
				else if ((Tile.CollPos.x) - (Monster.m_vPos.x + 25) > 0 && (Tile.CollPos.y) - (Monster.m_vPos.y + 30) > 0)
				{
					Quadrant = 2;
					Target_X_Pos = (Tile.CollPos.x) - Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y) - Target_Y_Interval;
				}
				else if ((Tile.CollPos.x) - (Monster.m_vPos.x + 25) > 0 && (Tile.CollPos.y) - (Monster.m_vPos.y + 30) < 0)
				{
					Quadrant = 3;
					Target_X_Pos = (Tile.CollPos.x) - Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y) + Target_Y_Interval;
				}
				else if ((Tile.CollPos.x) - (Monster.m_vPos.x + 25) < 0 && (Tile.CollPos.y) - (Monster.m_vPos.y + 30) < 0)
				{
					Quadrant = 4;
					Target_X_Pos = (Tile.CollPos.x) + Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y) + Target_Y_Interval;
				}
				else if (Tile.CollPos.x < (Monster.m_vPos.x + 25) && (Tile.CollPos.y) == (Monster.m_vPos.y + 30))
				{
					Quadrant = 5;
					Target_X_Pos = (Tile.CollPos.x) + Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y);
				}
				else if (Tile.CollPos.x == (Monster.m_vPos.x + 25) && (Tile.CollPos.y) >(Monster.m_vPos.y + 30))
				{
					Quadrant = 6;
					Target_X_Pos = (Tile.CollPos.x);
					Target_Y_Pos = (Tile.CollPos.y) - Target_Y_Interval;
				}
				else if (Tile.CollPos.x > (Monster.m_vPos.x + 25) && (Tile.CollPos.y) == (Monster.m_vPos.y + 30))
				{
					Quadrant = 7;
					Target_X_Pos = (Tile.CollPos.x) - Target_X_Interval;
					Target_Y_Pos = (Tile.CollPos.y);
				}
				else if (Tile.CollPos.x == (Monster.m_vPos.x + 25) && (Tile.CollPos.y) < (Monster.m_vPos.y + 30))
				{
					Quadrant = 8;
					Target_X_Pos = (Tile.CollPos.x);
					Target_Y_Pos = (Tile.CollPos.y) + Target_Y_Interval;
				}

			}

			switch (Quadrant)
			{
			case 1:
			{
				m_vPos.x += Temp_X_Bullet_Speed;
				m_vPos.y -= Temp_Y_Bullet_Speed;
				break;
			}

			case 2:
			{
				m_vPos.x -= Temp_X_Bullet_Speed;
				m_vPos.y -= Temp_Y_Bullet_Speed;
				break;
			}

			case 3:
			{
				m_vPos.x -= Temp_X_Bullet_Speed;
				m_vPos.y += Temp_Y_Bullet_Speed;
				break;
			}

			case 4:
			{
				m_vPos.x += Temp_X_Bullet_Speed;
				m_vPos.y += Temp_Y_Bullet_Speed;
				break;
			}

			case 5:
			{
				m_vPos.x += Temp_X_Bullet_Speed;
				break;
			}

			case 6:
			{
				m_vPos.y -= Temp_Y_Bullet_Speed;
				break;
			}

			case 7:
			{
				m_vPos.x -= Temp_X_Bullet_Speed;
				break;
			}

			case 8:
			{
				m_vPos.y += Temp_Y_Bullet_Speed;
				break;
			}
			default:
			{
				break;
			}
			}
		}

		Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
		Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 다시 한번 더 총알과 몬스터거리 계산 

		if (Bullet_Distance <= Penetration_Impact_Range) // 거리가 25이하이면
		{
			Penetration_Bullet_tick = (float)(GetTickCount() - Penetration_first_time) / (float)1000;
			if (Penetration_Bullet_tick > Penetration_Monster_Damage_Cooltime) // 쿨마다
			{
				Monster.SetHP(Monster.GetHP() - Penetration_Attack_Damage); // 몬스터의 피가 데미지만큼 줄어든다.
				Penetration_first_time = GetTickCount(); // 쿨타임 초기화

				// 타격이펙트 시작
				if (Tile.level == 1)
				{
					Monster.SetTower_3_Level_1_Effect(true);
				}
				else if (Tile.level == 2)
				{
					Monster.SetTower_3_Level_2_Effect(true);
				}
				else if (Tile.level == 3)
				{
					Monster.SetTower_3_Level_3_Effect(true);
				}
				Monster.SetEffect_first_time(GetTickCount()); // 쿨타임 초기화
			}
		}
		
		Penetration_Bullet_X = (m_vPos.x + 10) - (Target_X_Pos);
		Penetration_Bullet_Y = (m_vPos.y + 10) - (Target_Y_Pos);
		Penetration_Bullet_Distance = sqrt((Penetration_Bullet_X * Penetration_Bullet_X) + (Penetration_Bullet_Y * Penetration_Bullet_Y));

		if (Penetration_Bullet_Distance < 36)
		{
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;
			BulletFire[z] = false;
			OnFire = false;

			Penetration_Attack = true;
			Quadrant = 0;
		}

	}

//	cout << ani_time << endl;

	////////////////////////////////// 회저어어어어언 ////////////////////////////////////
	if (Tile.GetStatus() == turning) // 4번 회전타워
	{

		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함
		resettime = turntick = (float)(GetTickCount() - turntime) / (float)1000; // 딜레이
		if (resettime > 1)
		{
			Tile.Setani(turningstand);
		}

		if (resettime > 0.1)
		{
			m_bDraw = false;

		}
		m_rect = { turnrectleft, turnrecttop, turnrectright, turnrectbottom };
		m_vPos.y = (float)50 * i ;
		m_vPos.x = (float)50 * j+2;

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (Distance <= turning_Attack_Range) // 사정거리내에 들어가면
			{
				Tile.Setani(turningreturn);
				m_bDraw = true; // 그리기
				turntick = (float)(GetTickCount() - turntime) / (float)1000; // 딜레이
				m_rect = { turnrectleft, turnrecttop, turnrectright, turnrectbottom };
				if (turntick > 0.1)
				{
					if (turnrectright < 200)
					{
						turnrectright += 50;
						turnrectleft += 50;
						resettime = 0;
					}
					else if (turnrectright >= 200)
					{
						turnrectright = 50;
						turnrectleft = 0;
						resettime = 0;
					}
					turntime = GetTickCount();
				}
				Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
				if (Bullet_tick > turning_Monster_Damage_Cooltime) // 쿨마다
				{
					Monster.SetHP(Monster.GetHP() - turning_Attack_Damage); // 몬스터의 피가 데미지만큼 줄어든다.
					first_time = GetTickCount(); // 쿨타임 초기화
				}
				// 타격이펙트 시작
				if (Tile.level == 1)
				{
					Monster.SetTower_4_Level_1_Effect(true);

				}
				else if (Tile.level == 2)
				{
					Monster.SetTower_4_Level_2_Effect(true);
				}
				else if (Tile.level == 3)
				{
					Monster.SetTower_4_Level_3_Effect(true);
				}
				Monster.SetEffect_first_time(GetTickCount()); // 쿨타임 초기화
			}

		}




	}





	///////////////////////////////////////////////////////////////////////////////////지속데미지

	if (Tile.GetStatus() == persisttower)
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // 각 타일과 몬스터의 거리를 구함
		if (Bullet_tick > 3)
		{
			Tile.Setani(persisttowerstand);
		}
		if (Bullet_tick == 0)
		{
			Tile.Setani(persisttowerstand);
		}
		if (OnTarget[z] == true) // OnTarget이 타워의 공격우선순위를 가장 가까운 적으로 해놔서 하나만 true하고 나머진 false 
		{
			TempDistance = Distance; // 가장 가까운 적의 거리를 계속 업데이트
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (Distance <= persist_Attack_Range) // 사정거리내에 들어가면
			{
				Tile.Setani(persisttower);
				if (Distance <= TempDistance) // 근데 다른 적이 계속 업데이트한 가장 1순위 적과의 거리보다 작을시
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // 일단 다른거 다 false로 초기화하고
					}
					OnTarget[z] = true; //  그 적을 1순위로 정함
				}
				else
				{
					OnTarget[z] = false; // 크다면 그냥 false
				}
			}
			else // 사정거리내보다 크면 그냥 다 false인데
			{
				Target[z] = false; // 이것은 사정거리내에 적을 알아내기위해 해놨는데 아직 쓰진 않음 (두마리면 2개 true, 3마리면 3개 true 이렇게)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // 몬스터 피가 다 달으면 때리지 않고 그냥 지나가게 하고 터널안은 안때림
		{
			if (OnFire == false) // 아직 발사가 안됐다면
			{
				if (OnTarget[z] == true) // 아직 발사가 안된상태에서 1순위가 true라면
				{
					
					if (Bullet_tick >= persist_Attack_Speed) // 쿨타임이 찼다면
					{
						OnFire = true; // 발사
						m_bDraw = true; // 그리기
						BulletFire[z] = true; // 총알의 발사허가

						first_time = GetTickCount(); // 쿨타임 초기화
					}
				}
			}
		}
		if (BulletFire[z] == true) // 총알날라가기
		{
			Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 총알과 몬스터의 거리계산

			// 밑에는 그냥 이동하는거
			if ((Monster.m_vPos.x + 25) > (m_vPos.x + 10))
			{
				m_vPos.x += persist_Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) < persist_Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}
			}
			else
			{
				m_vPos.x -= persist_Bullet_Speed;
				if ((Monster.m_vPos.x + 25) - (m_vPos.x + 10) > -persist_Bullet_Speed)
				{
					m_vPos.x = Monster.m_vPos.x + 15;
				}

			}
			if ((Monster.m_vPos.y + 30) > (m_vPos.y + 10))
			{
				m_vPos.y += persist_Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) < persist_Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}
			else
			{
				m_vPos.y -= persist_Bullet_Speed;
				if ((Monster.m_vPos.y + 30) - (m_vPos.y + 10) > -persist_Bullet_Speed)
				{
					m_vPos.y = Monster.m_vPos.y + 20;
				}
			}

		}

		Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
		Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // 다시 한번 더 총알과 몬스터거리 계산 

		if (Bullet_Distance <= 10) // 거리가 5이하이면
		{
			// 모두 초기화
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;
			BulletFire[z] = false;
			OnFire = false;

			// 타격이펙트 시작
			if (Tile.level == 1)
			{
				Monster.SetTower_5_Level_1_Effect(true);
			}
			else if (Tile.level == 2)
			{
				Monster.SetTower_5_Level_2_Effect(true);
			}
			else if (Tile.level == 3)
			{
				Monster.SetTower_5_Level_3_Effect(true);
			}
			Monster.SetEffect_first_time(GetTickCount()); // 쿨타임 초기화
		}

		if (Bullet_Distance <= 10 && Monster.Getcheck() == false) // 거리가 5이하이면
		{
			if (Monster.GetPersistcheck() == false)
			{
				Monster.SetPersistcheck(true);
				Monster.SetPersisttime(49); // 결국 50번으로 0.1초마다이니 5초동안 데미지 입힘
				Monster.Setcooltime(49);
			}
		}

		if (Monster.GetPersistcheck() == true && Monster.GetPersisttime() >= 0)
		{
			Monster.SetPersist_tick((float)(GetTickCount() - Monster.GetPersist_first_time()) / (float)1000);
			if (Monster.GetPersist_tick() > 0.1) // 0.1초마다
			{
				Monster.SetHP(Monster.GetHP() - persist_Attack_Damage); // 몬스터의 피가 일정한 데미지만큼 줄어든다.
				Monster.SetPersist_first_time(GetTickCount()); // 쿨타임 초기화
				Monster.Setcooltime(Monster.Getcooltime() - 1.0);
				Monster.SetPersisttime(Monster.GetPersisttime() - 1.0);
			}
			Monster.Setcheck(true);
		}
		if (Monster.GetPersisttime() < 0)
		{
			Monster.SetPersisttime(0);
			Monster.SetPersistcheck(false);
			Monster.Setcheck(false);
		}

	}
	if (Tile.GetStatus() == slowTower)
	{



	}




}

void CBullet::Draw(CTile Tile)
{
	switch (Tile.GetStatus())
	{
		case WareHouse:
		{
			switch (Tile.level)
			{
				case 1:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_1_Level_1_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 2:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_1_Level_2_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 3:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_1_Level_3_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					if (m_bDraw2)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_1_Level_3_Bullet, &m_rect, NULL, &m_vPos2, m_color);
						m_pSprite->End();
					}
					break;
				}
			}
			break;
		}

		case splash:
		{
			switch (Tile.level)
			{
				case 1:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_2_Level_1_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 2:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_2_Level_2_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 3:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_2_Level_3_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}
			}
			break;
		}

		case penetration:
		{
			switch (Tile.level)
			{
				case 1:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_3_Level_1_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 2:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_3_Level_2_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 3:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_3_Level_3_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}
			}
			break;
		}

		case turning:
		{
			switch (Tile.level)
			{
				case 1:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_4_Level_1_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 2:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_4_Level_2_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 3:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_4_Level_3_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}
			}
			break;
		}

		case persisttower:
		{
			switch (Tile.level)
			{
				case 1:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_5_Level_1_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 2:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_5_Level_2_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}

				case 3:
				{
					if (m_bDraw)
					{
						m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
						m_pSprite->Draw(m_pTexture_Tower_5_Level_3_Bullet, &m_rect, NULL, &m_vPos, m_color);
						m_pSprite->End();
					}
					break;
				}
			}
			break;
		}
	}

	if (Tile.MouseHover == true)
	{
		if (Tile.GetStatus() == WareHouse)
		{
			if (Tile.level == 1)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_150, &Attack_Range_150_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 125, Tile.m_vPos.y - 120, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 2)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_200, &Attack_Range_200_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 175, Tile.m_vPos.y - 170, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 3)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_250, &Attack_Range_250_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 225, Tile.m_vPos.y - 220, 0), Attack_Range_color);
				m_pSprite->End();
			}
		}

		if (Tile.GetStatus() == splash)
		{
			if (Tile.level == 1)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_150, &Attack_Range_150_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 125, Tile.m_vPos.y - 120, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 2)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_200, &Attack_Range_200_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 175, Tile.m_vPos.y - 170, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 3)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_250, &Attack_Range_250_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 225, Tile.m_vPos.y - 220, 0), Attack_Range_color);
				m_pSprite->End();
			}
		}

		if (Tile.GetStatus() == penetration)
		{
			if (Tile.level == 1)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_100, &Attack_Range_100_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 75, Tile.m_vPos.y - 70, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 2)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_150, &Attack_Range_150_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 125, Tile.m_vPos.y - 120, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 3)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_200, &Attack_Range_200_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 175, Tile.m_vPos.y - 170, 0), Attack_Range_color);
				m_pSprite->End();
			}
		}

		if (Tile.GetStatus() == turning)
		{
			if (Tile.level == 1)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_50, &Attack_Range_50_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 20, Tile.m_vPos.y - 15, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 2)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_75, &Attack_Range_75_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 45, Tile.m_vPos.y - 40, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 3)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_100, &Attack_Range_100_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 70, Tile.m_vPos.y - 65, 0), Attack_Range_color);
				m_pSprite->End();
			}
		}

		if (Tile.GetStatus() == persisttower)
		{
			if (Tile.level == 1)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_150, &Attack_Range_150_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 125, Tile.m_vPos.y - 120, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 2)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_200, &Attack_Range_200_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 175, Tile.m_vPos.y - 170, 0), Attack_Range_color);
				m_pSprite->End();
			}
			else if (Tile.level == 3)
			{
				m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
				m_pSprite->Draw(m_pAttack_Range_250, &Attack_Range_250_rect, NULL, &D3DXVECTOR3(Tile.m_vPos.x - 225, Tile.m_vPos.y - 220, 0), Attack_Range_color);
				m_pSprite->End();
			}
		}
	}
}