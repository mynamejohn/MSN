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
	TempDistance = 1000; // ���� ����� ���� �Ÿ��� ��� ������Ʈ�ϴ� ����
	OnFire = false; // �����Ÿ����� �ִٰ��ؼ� �߻�� ���� �ع����� ���... �׷��� ������ �߻��� ��ȣ�� ��

	Impacted_X_Pos = 0;
	Impacted_Y_Pos = 0;
	Penetration_Attack = true;
	Quadrant = 0;
	turning_N = 0; // ȸ��Ÿ�� ���� �ʱ�ȭ

	ani_num = 0;

	// �����Ÿ�
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

	/////////////////////////// �⺻ //////////////////////////////////
	if (Tile.GetStatus() == WareHouse)
	{
		switch (Tile.level)
		{
			case 1:
			{
				Attack_Damage = 2.0; // ���ݷ�
				Bullet_Speed = 7.0; // �Ѿ��� ���ǵ�
				Attack_Speed = 1.0; // Ÿ���� ���ݼӵ�
				Attack_Range = 150.0; // �����Ÿ�
				break;
			}
			case 2:
			{
				Attack_Damage = 5; // ���ݷ�
				Bullet_Speed = 9.0; // �Ѿ��� ���ǵ�
				Attack_Speed = 0.75; // Ÿ���� ���ݼӵ�
				Attack_Range = 200.0; // �����Ÿ�
				break;
			}
			case 3:
			{
				Attack_Damage = 5.0; // ���ݷ�
				Bullet_Speed = 11.0; // �Ѿ��� ���ǵ�
				Attack_Speed = 0.5; // Ÿ���� ���ݼӵ�
				Attack_Range = 250.0; // �����Ÿ�
				break;
			}

			default:
			{

				break;
			}
		}
	}

	/////////////////////////// ���� //////////////////////////////////
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
	

	/////////////////////////// ���� //////////////////////////////////
	if (Tile.GetStatus() == penetration)
	{
		switch (Tile.level)
		{
			case 1:
			{
				Penetration_Attack_Damage = 3.0;
				Penetration_Bullet_Speed = 6.0; // 0~9  9�Ѿ�� �ȴ� ����
				Penetration_Attack_Speed = 2.0;
				Penetration_Attack_Range = 100.0;
				Penetration_Distance = 150.0; // ����Ÿ�
				Penetration_Monster_Damage_Cooltime = 0.2; // ������ ����(��Ÿ��)���� ������ ����
				Penetration_Impact_Range = 25.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
				
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
				Penetration_Bullet_Speed = 7.0; // 0~9  9�Ѿ�� �ȴ� ����
				Penetration_Attack_Speed = 1.66;
				Penetration_Attack_Range = 150.0;
				Penetration_Distance = 200.0; // ����Ÿ�
				Penetration_Monster_Damage_Cooltime = 0.15; // ������ ����(��Ÿ��)���� ������ ����
				Penetration_Impact_Range = 35.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
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
				Penetration_Bullet_Speed = 8.0; // 0~9  9�Ѿ�� �ȴ� ����
				Penetration_Attack_Speed = 1.33;
				Penetration_Attack_Range = 200.0;
				Penetration_Distance = 300.0; // ����Ÿ�
				Penetration_Monster_Damage_Cooltime = 0.1; // ������ ����(��Ÿ��)���� ������ ����
				Penetration_Impact_Range = 50.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
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

	/////////////////////////// ȸ�� //////////////////////////////////
	if (Tile.GetStatus() == turning)
	{
		switch (Tile.level)
		{
			case 1:
			{
				turning_Attack_Damage = 1;
				turning_Bullet_Speed = 3.0; // 1~4 �� �ؾߵ� 4�� ������ 1�� ���Ϻ���
				turning_Attack_Range = 90.0;
				turning_Distance = 50.0; // ȸ��������
				turning_Monster_Damage_Cooltime = 0.5; // ������ ����(��Ÿ��)���� ������ ����
				turning_Impact_Range = 25.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
				break;
			}
			case 2:
			{
				turning_Attack_Damage = 2.5;
				turning_Bullet_Speed = 2.5; // 1~4 �� �ؾߵ� 4�� ������ 1�� ���Ϻ���
				turning_Attack_Range = 115.0;
				turning_Distance = 75.0; // ȸ��������
				turning_Monster_Damage_Cooltime = 0.4; // ������ ����(��Ÿ��)���� ������ ����
				turning_Impact_Range = 30.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
				break;
			}
			case 3:
			{
				turning_Attack_Damage = 4;
				turning_Bullet_Speed = 2.0; // 1~4 �� �ؾߵ� 4�� ������ 1�� ���Ϻ���
				turning_Attack_Range = 140.0;
				turning_Distance = 100.0; // ȸ��������
				turning_Monster_Damage_Cooltime = 0.3; // ������ ����(��Ÿ��)���� ������ ����
				turning_Impact_Range = 35.0; // �������鼭 ���Ϳ��� �浹�Ÿ�
				break;
			}

			default:
			{

				break;
			}
		}
	}

	/////////////////////////// ���� //////////////////////////////////
	if (Tile.GetStatus() == persisttower)
	{
		switch (Tile.level)
		{
			case 1:
			{ // ������ 5�ʵ��� ���������� �����ϸ� ��ø�̾ȴ�
				persist_Attack_Damage = 0.3; // �ѵ������� x 50 �ؾ���
				persist_Bullet_Speed = 7.0;
				persist_Attack_Speed = 3.0;
				persist_Attack_Range = 150.0;
				break;
			}
			case 2:
			{
				persist_Attack_Damage = 0.9; // �ѵ������� x 50 �ؾ���
				persist_Bullet_Speed = 11.0;
				persist_Attack_Speed = 2.5;
				persist_Attack_Range = 200.0;
				break;
			}
			case 3:
			{
				persist_Attack_Damage = 1.8; // �ѵ������� x 50 �ؾ���
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
		Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����
	
		
		if (OnTarget[z] == true) // OnTarget�� Ÿ���� ���ݿ켱������ ���� ����� ������ �س��� �ϳ��� true�ϰ� ������ false 
		{
			TempDistance = Distance; // ���� ����� ���� �Ÿ��� ��� ������Ʈ
		}

		if (Bullet_tick == 0)
		{
			Tile.Setani(WareHouseStand);
		}

		if (Bullet_tick >= 2)
		{
			Tile.Setani(WareHouseStand);
		
			
		}
		
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (Distance <= Attack_Range) // �����Ÿ����� ����
			{
				Tile.Setani(WareHouse);
				if (Distance <= TempDistance) // �ٵ� �ٸ� ���� ��� ������Ʈ�� ���� 1���� ������ �Ÿ����� ������
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // �ϴ� �ٸ��� �� false�� �ʱ�ȭ�ϰ�
					}
					OnTarget[z] = true; //  �� ���� 1������ ����
				}
				else
				{
					OnTarget[z] = false; // ũ�ٸ� �׳� false
				}
			}
			else // �����Ÿ������� ũ�� �׳� �� false�ε�
			{
				Target[z] = false; // �̰��� �����Ÿ����� ���� �˾Ƴ������� �س��µ� ���� ���� ���� (�θ����� 2�� true, 3������ 3�� true �̷���)
				OnTarget[z] = false;
			}
		}
		
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (OnFire == false) // ���� �߻簡 �ȵƴٸ�
			{
				if (OnTarget[z] == true) // ���� �߻簡 �ȵȻ��¿��� 1������ true���
				{
					if (Bullet_tick >= Attack_Speed) // ��Ÿ���� á�ٸ�
					{
						OnFire = true; // �߻�
						m_bDraw = true; // �׸���
						if (Tile.level == 3)
						{
							m_bDraw2 = true;  // 2���Ѿ� �׸���
						}
						BulletFire[z] = true; // �Ѿ��� �߻��㰡

						first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ
					}
				}
			}
		}
		if (BulletFire[z] == true) // �Ѿ˳��󰡱�
		{
			// �ؿ��� �׳� �̵��ϴ°�
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
				// �ؿ��� �׳� �̵��ϴ°�
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
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �ٽ� �ѹ� �� �Ѿ˰� ���ͰŸ� ��� 

		if (Bullet_Distance <= 10 && m_bDraw == true) // �Ÿ��� 5�����̸�
		{
			// ��� �ʱ�ȭ
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;

			Monster.SetHP(Monster.GetHP() - Attack_Damage); // ������ �ǰ� ��������ŭ �پ���.

			// Ÿ������Ʈ ����
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
			Monster.SetEffect_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ

		}

		if (Tile.level == 3)
		{
			Bullet_X2 = (m_vPos2.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y2 = (m_vPos2.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance2 = sqrt((Bullet_X2 * Bullet_X2) + (Bullet_Y2 * Bullet_Y2)); // �ٽ� �ѹ� �� �Ѿ˰� ���ͰŸ� ��� 

			if (Bullet_Distance2 <= 10 && m_bDraw2 == true) // �Ÿ��� 5�����̸�
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

	//////////////////////////////////// ���÷��������������� /////////////////////////////////////////////
	if (Tile.GetStatus() == splash)
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����
		
		if (Bullet_tick == 0)
		{
			Tile.Setani(splashStand);
		}
		
		
		if (Bullet_tick > 2)
		{
			Tile.Setani(splashStand);
		
		}
		if (OnTarget[z] == true) // OnTarget�� Ÿ���� ���ݿ켱������ ���� ����� ������ �س��� �ϳ��� true�ϰ� ������ false 
		{
			TempDistance = Distance; // ���� ����� ���� �Ÿ��� ��� ������Ʈ
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (Distance <= splash_Attack_Range) // �����Ÿ����� ����
			{
				Tile.Setani(splash);
				if (Distance <= TempDistance) // �ٵ� �ٸ� ���� ��� ������Ʈ�� ���� 1���� ������ �Ÿ����� ������
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // �ϴ� �ٸ��� �� false�� �ʱ�ȭ�ϰ�
					}
					OnTarget[z] = true; //  �� ���� 1������ ����
				}
				else
				{
					OnTarget[z] = false; // ũ�ٸ� �׳� false
				}
			}
			else // �����Ÿ������� ũ�� �׳� �� false�ε�
			{
				Target[z] = false; // �̰��� �����Ÿ����� ���� �˾Ƴ������� �س��µ� ���� ���� ���� (�θ����� 2�� true, 3������ 3�� true �̷���)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (OnFire == false) // ���� �߻簡 �ȵƴٸ�
			{
				if (OnTarget[z] == true) // ���� �߻簡 �ȵȻ��¿��� 1������ true���
				{
					if (Bullet_tick >= splash_Attack_Speed) // ��Ÿ���� á�ٸ�
					{
						OnFire = true; // �߻�
						m_bDraw = true; // �׸���
						BulletFire[z] = true; // �Ѿ��� �߻��㰡

						first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ
					}
				}
			}
		}

		if (BulletFire[z] == true) // �Ѿ˳��󰡱�
		{
			Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �Ѿ˰� ������ �Ÿ����

			// �ؿ��� �׳� �̵��ϴ°�
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
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �ٽ� �ѹ� �� �Ѿ˰� ���ͰŸ� ��� 

		if (Bullet_Distance <= 10) // �Ÿ��� 5�����̸�
		{
			Impacted_X_Pos = m_vPos.x + 10;
			Impacted_Y_Pos = m_vPos.y + 10;
			for (int splash_Tempz = 0; splash_Tempz < MonsterNum * 3; splash_Tempz++)
			{
				splash_Impact_Switch[splash_Tempz] = true;
			}
			// ��� �ʱ�ȭ
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
				Monster.SetHP(Monster.GetHP() - splash_Attack_Damage); // ������ �ǰ� ��������ŭ �پ���.
				// Ÿ������Ʈ ����
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
				Monster.SetEffect_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ
			}
			splash_Impact_Switch[z] = false;
		}
	}

	///////////////////////////////////////// ����������� ////////////////////////////////////////////////////
	if (Tile.GetStatus() == penetration) // 3�� ����Ÿ��
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����
		//m_rect = { 0, 0, 40, 40 };
		if (Bullet_tick == 0)
		{
			Tile.Setani(penetrationstand);
		}

		if (Bullet_tick > 2)
		{
			Tile.Setani(penetrationstand);
		}
		if (OnTarget[z] == true) // OnTarget�� Ÿ���� ���ݿ켱������ ���� ����� ������ �س��� �ϳ��� true�ϰ� ������ false 
		{
			TempDistance = Distance; // ���� ����� ���� �Ÿ��� ��� ������Ʈ
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (Distance <= Penetration_Attack_Range) // �����Ÿ����� ����
			{
				Tile.Setani(penetration);
				if (Distance <= TempDistance) // �ٵ� �ٸ� ���� ��� ������Ʈ�� ���� 1���� ������ �Ÿ����� ������
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // �ϴ� �ٸ��� �� false�� �ʱ�ȭ�ϰ�
					}
					OnTarget[z] = true; //  �� ���� 1������ ����
				}
				else
				{
					OnTarget[z] = false; // ũ�ٸ� �׳� false
				}
			}
			else // �����Ÿ������� ũ�� �׳� �� false�ε�
			{
				Target[z] = false; // �̰��� �����Ÿ����� ���� �˾Ƴ������� �س��µ� ���� ���� ���� (�θ����� 2�� true, 3������ 3�� true �̷���)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (OnFire == false) // ���� �߻簡 �ȵƴٸ�
			{
				if (OnTarget[z] == true) // ���� �߻簡 �ȵȻ��¿��� 1������ true���
				{
					if (Bullet_tick >= Penetration_Attack_Speed) // ��Ÿ���� á�ٸ�
					{
						OnFire = true; // �߻�
						m_bDraw = true; // �׸���
						BulletFire[z] = true; // �Ѿ��� �߻��㰡
						
						first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ
					}
				}
			}
		}

		if (BulletFire[z] == true) // �Ѿ˳��󰡱�
		{
			if (Penetration_Attack == true)
			{
				Penetration_Attack = false;

				X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
				Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
				Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����

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

				Penetration_Temp_Bullet_Speed = 100 - (10 * Penetration_Bullet_Speed); // �ӽ� ���ǵ忡 ��¥���ǵ�����

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
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �ٽ� �ѹ� �� �Ѿ˰� ���ͰŸ� ��� 

		if (Bullet_Distance <= Penetration_Impact_Range) // �Ÿ��� 25�����̸�
		{
			Penetration_Bullet_tick = (float)(GetTickCount() - Penetration_first_time) / (float)1000;
			if (Penetration_Bullet_tick > Penetration_Monster_Damage_Cooltime) // �𸶴�
			{
				Monster.SetHP(Monster.GetHP() - Penetration_Attack_Damage); // ������ �ǰ� ��������ŭ �پ���.
				Penetration_first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ

				// Ÿ������Ʈ ����
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
				Monster.SetEffect_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ
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

	////////////////////////////////// ȸ�������� ////////////////////////////////////
	if (Tile.GetStatus() == turning) // 4�� ȸ��Ÿ��
	{

		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����
		resettime = turntick = (float)(GetTickCount() - turntime) / (float)1000; // ������
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

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (Distance <= turning_Attack_Range) // �����Ÿ����� ����
			{
				Tile.Setani(turningreturn);
				m_bDraw = true; // �׸���
				turntick = (float)(GetTickCount() - turntime) / (float)1000; // ������
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
				if (Bullet_tick > turning_Monster_Damage_Cooltime) // �𸶴�
				{
					Monster.SetHP(Monster.GetHP() - turning_Attack_Damage); // ������ �ǰ� ��������ŭ �پ���.
					first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ
				}
				// Ÿ������Ʈ ����
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
				Monster.SetEffect_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ
			}

		}




	}





	///////////////////////////////////////////////////////////////////////////////////���ӵ�����

	if (Tile.GetStatus() == persisttower)
	{
		X = Tile.CollPos.x - (Monster.m_vPos.x + 25);
		Y = Tile.CollPos.y - (Monster.m_vPos.y + 30);
		Distance = sqrt((X * X) + (Y * Y)); // �� Ÿ�ϰ� ������ �Ÿ��� ����
		if (Bullet_tick > 3)
		{
			Tile.Setani(persisttowerstand);
		}
		if (Bullet_tick == 0)
		{
			Tile.Setani(persisttowerstand);
		}
		if (OnTarget[z] == true) // OnTarget�� Ÿ���� ���ݿ켱������ ���� ����� ������ �س��� �ϳ��� true�ϰ� ������ false 
		{
			TempDistance = Distance; // ���� ����� ���� �Ÿ��� ��� ������Ʈ
		}

		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (Distance <= persist_Attack_Range) // �����Ÿ����� ����
			{
				Tile.Setani(persisttower);
				if (Distance <= TempDistance) // �ٵ� �ٸ� ���� ��� ������Ʈ�� ���� 1���� ������ �Ÿ����� ������
				{
					for (int TempZ = 0; TempZ < MonsterNum * 3; TempZ++)
					{
						OnTarget[TempZ] = false; // �ϴ� �ٸ��� �� false�� �ʱ�ȭ�ϰ�
					}
					OnTarget[z] = true; //  �� ���� 1������ ����
				}
				else
				{
					OnTarget[z] = false; // ũ�ٸ� �׳� false
				}
			}
			else // �����Ÿ������� ũ�� �׳� �� false�ε�
			{
				Target[z] = false; // �̰��� �����Ÿ����� ���� �˾Ƴ������� �س��µ� ���� ���� ���� (�θ����� 2�� true, 3������ 3�� true �̷���)
				OnTarget[z] = false;
			}
		}
		Bullet_tick = (float)(GetTickCount() - first_time) / (float)1000;
		if (Monster.GetHP() > 0 && Monster.In_tunnel == false) // ���� �ǰ� �� ������ ������ �ʰ� �׳� �������� �ϰ� �ͳξ��� �ȶ���
		{
			if (OnFire == false) // ���� �߻簡 �ȵƴٸ�
			{
				if (OnTarget[z] == true) // ���� �߻簡 �ȵȻ��¿��� 1������ true���
				{
					
					if (Bullet_tick >= persist_Attack_Speed) // ��Ÿ���� á�ٸ�
					{
						OnFire = true; // �߻�
						m_bDraw = true; // �׸���
						BulletFire[z] = true; // �Ѿ��� �߻��㰡

						first_time = GetTickCount(); // ��Ÿ�� �ʱ�ȭ
					}
				}
			}
		}
		if (BulletFire[z] == true) // �Ѿ˳��󰡱�
		{
			Bullet_X = (m_vPos.x + 10) - (Monster.m_vPos.x + 25);
			Bullet_Y = (m_vPos.y + 10) - (Monster.m_vPos.y + 30);
			Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �Ѿ˰� ������ �Ÿ����

			// �ؿ��� �׳� �̵��ϴ°�
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
		Bullet_Distance = sqrt((Bullet_X * Bullet_X) + (Bullet_Y * Bullet_Y)); // �ٽ� �ѹ� �� �Ѿ˰� ���ͰŸ� ��� 

		if (Bullet_Distance <= 10) // �Ÿ��� 5�����̸�
		{
			// ��� �ʱ�ȭ
			m_vPos.x = (float)50 * j + 15;
			m_vPos.y = (float)50 * i + 20;
			m_bDraw = false;
			BulletFire[z] = false;
			OnFire = false;

			// Ÿ������Ʈ ����
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
			Monster.SetEffect_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ
		}

		if (Bullet_Distance <= 10 && Monster.Getcheck() == false) // �Ÿ��� 5�����̸�
		{
			if (Monster.GetPersistcheck() == false)
			{
				Monster.SetPersistcheck(true);
				Monster.SetPersisttime(49); // �ᱹ 50������ 0.1�ʸ����̴� 5�ʵ��� ������ ����
				Monster.Setcooltime(49);
			}
		}

		if (Monster.GetPersistcheck() == true && Monster.GetPersisttime() >= 0)
		{
			Monster.SetPersist_tick((float)(GetTickCount() - Monster.GetPersist_first_time()) / (float)1000);
			if (Monster.GetPersist_tick() > 0.1) // 0.1�ʸ���
			{
				Monster.SetHP(Monster.GetHP() - persist_Attack_Damage); // ������ �ǰ� ������ ��������ŭ �پ���.
				Monster.SetPersist_first_time(GetTickCount()); // ��Ÿ�� �ʱ�ȭ
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