#include "TestStage.h"

void CTestStage::StageInit()
{
	m_bChangeStage = false;
	tickcnt = false;

	Monster_cnt = 0;

	m_StageTime = 0;

	//텍스쳐 초기화
	m_tBG.Init(L"Image/Stage/BackGround.png");

	t_PauseScreen.Init(L"Image/Pause.png");
	t_Option.Init(L"Image/Pause-Set.png");

	m_tHouseHover.Init(L"Image/Stage/MouseHover.png");

	m_tTower_1_Level_1_Bullet.Init(L"Image/Bullet/Tower_1/Tower_1_Level_1_Bullet.png");
	m_tTower_1_Level_2_Bullet.Init(L"Image/Bullet/Tower_1/Tower_1_Level_2_Bullet.png");
	m_tTower_1_Level_3_Bullet.Init(L"Image/Bullet/Tower_1/Tower_1_Level_3_Bullet.png");
	m_tTower_2_Level_1_Bullet.Init(L"Image/Bullet/Tower_2/Tower_2_Level_1_Bullet.png");
	m_tTower_2_Level_2_Bullet.Init(L"Image/Bullet/Tower_2/Tower_2_Level_2_Bullet.png");
	m_tTower_2_Level_3_Bullet.Init(L"Image/Bullet/Tower_2/Tower_2_Level_3_Bullet.png");
	m_tTower_3_Level_1_Bullet.Init(L"Image/Bullet/Tower_3/Tower_3_Level_1_Bullet.png");
	m_tTower_3_Level_2_Bullet.Init(L"Image/Bullet/Tower_3/Tower_3_Level_2_Bullet.png");
	m_tTower_3_Level_3_Bullet.Init(L"Image/Bullet/Tower_3/Tower_3_Level_3_Bullet.png");
	m_tTower_4_Level_1_Bullet.Init(L"Image/Bullet/Tower_4/Tower_4_Level_1_Bullet.png");
	m_tTower_4_Level_2_Bullet.Init(L"Image/Bullet/Tower_4/Tower_4_Level_2_Bullet.png");
	m_tTower_4_Level_3_Bullet.Init(L"Image/Bullet/Tower_4/Tower_4_Level_3_Bullet.png");
	m_tTower_5_Level_1_Bullet.Init(L"Image/Bullet/Tower_5/Tower_5_Level_1_Bullet.png");
	m_tTower_5_Level_2_Bullet.Init(L"Image/Bullet/Tower_5/Tower_5_Level_2_Bullet.png");
	m_tTower_5_Level_3_Bullet.Init(L"Image/Bullet/Tower_5/Tower_5_Level_3_Bullet.png");

	m_tTower_1.Init(L"Image/Tower/Tower_1.png");
	m_tTower_2.Init(L"Image/Tower/Tower_2.png");
	m_tTower_3.Init(L"Image/Tower/Tower_3.png");
	m_tTower_4.Init(L"Image/Tower/Tower_4.png");
	m_tTower_5.Init(L"Image/Tower/Tower_5.png");
	m_tTower_6.Init(L"Image/Tower/Tower_6.png");

	m_tTower_1_Stand.Init(L"Image/Tower/Tower_1_Stand.png");
	m_tTower_2_Stand.Init(L"Image/Tower/Tower_2_Stand.png");
	m_tTower_3_Stand.Init(L"Image/Tower/Tower_3_Stand.png");
	m_tTower_4_Stand.Init(L"Image/Tower/Tower_4_Stand.png");
	m_tTower_5_Stand.Init(L"Image/Tower/Tower_5_Stand.png");




	m_tAttack_Range_50.Init(L"Image/Tower/Attack_Range_50.png");
	m_tAttack_Range_75.Init(L"Image/Tower/Attack_Range_75.png");
	m_tAttack_Range_100.Init(L"Image/Tower/Attack_Range_100.png");
	m_tAttack_Range_150.Init(L"Image/Tower/Attack_Range_150.png");
	m_tAttack_Range_200.Init(L"Image/Tower/Attack_Range_200.png");
	m_tAttack_Range_250.Init(L"Image/Tower/Attack_Range_250.png");

	m_tMouse.Init(L"Image/mouse.png");

	tScore.Init(L"Image/Stage/score_sprite.png");
	tResources.Init(L"Image/Stage/number_sprite.png");

	m_tfactory.Init(L"Image/Stage/Factory_Tunnel.png");
	m_ttunnel_vertical.Init(L"Image/Stage/tunnel_vertical.png");
	m_ttunnel_horizon_1.Init(L"Image/Stage/tunnel_horizon_1.png");
	m_ttunnel_horizon_2.Init(L"Image/Stage/tunnel_horizon_2.png");

	m_tnyang_cup.Init(L"Image/Monster/nyang_cup.png");
	m_tgitar.Init(L"Image/Monster/gitar_1.png");
	m_tsangza.Init(L"Image/Monster/sangza.png");
	m_tbongzi_1.Init(L"Image/Monster/bongzi_1.png");
	m_tbongzi_2.Init(L"Image/Monster/bongzi_2.png");
	

	m_tHP_Bar.Init(L"Image/Stage/HP_Bar.png");

	m_tower_1_active.Init(L"Image/TowerSelection/1ac.png");
	m_tower_1_inactive.Init(L"Image/TowerSelection/1inac.png");
	m_tower_2_active.Init(L"Image/TowerSelection/2ac.png");
	m_tower_2_inactive.Init(L"Image/TowerSelection/2inac.png");
	m_tower_3_active.Init(L"Image/TowerSelection/3ac.png");
	m_tower_3_inactive.Init(L"Image/TowerSelection/3inac.png");
	m_tower_4_active.Init(L"Image/TowerSelection/4ac.png");
	m_tower_4_inactive.Init(L"Image/TowerSelection/4inac.png");
	m_tower_5_active.Init(L"Image/TowerSelection/5ac.png");
	m_tower_5_inactive.Init(L"Image/TowerSelection/5inac.png");
	m_tower_6_active.Init(L"Image/TowerSelection/6ac.png");
	m_tower_6_inactive.Init(L"Image/TowerSelection/6inac.png");

	m_tower_1_mouse.Init(L"Image/TowerSelection/1mouse.png");
	m_tower_2_mouse.Init(L"Image/TowerSelection/2mouse.png");
	m_tower_3_mouse.Init(L"Image/TowerSelection/3mouse.png");
	m_tower_4_mouse.Init(L"Image/TowerSelection/4mouse.png");
	m_tower_5_mouse.Init(L"Image/TowerSelection/5mouse.png");
	m_tower_6_mouse.Init(L"Image/TowerSelection/6mouse.png");

	m_tower_1_info.Init(L"Image/TowerSelection/Info_1.png");
	m_tower_2_info.Init(L"Image/TowerSelection/Info_2.png");
	m_tower_3_info.Init(L"Image/TowerSelection/Info_3.png");
	m_tower_4_info.Init(L"Image/TowerSelection/Info_4.png");
	m_tower_5_info.Init(L"Image/TowerSelection/Info_5.png");
	m_tower_6_info.Init(L"Image/TowerSelection/Info_6.png");
	
	m_tPause_Play.Init(L"Image/Stage/Play.png");

	t_Button.Init(L"Image/Button.png");

	t_Point.Init(L"Image/Point.png");

	m_tReGame.Init(L"Image/GameOver/Regame_mouse.png");

	m_tReturn_to_Title.Init(L"Image/GameOver/Title_mouse.png");

	m_tGameOver.Init(L"Image/GameOver/GameOver.png");

	m_tTower_1_Level_1_Effect.Init(L"Image/Effect/Tower_1/Tower_1_Level_1_Effect.png");
	m_tTower_1_Level_2_Effect.Init(L"Image/Effect/Tower_1/Tower_1_Level_2_Effect.png");
	m_tTower_1_Level_3_Effect.Init(L"Image/Effect/Tower_1/Tower_1_Level_3_Effect.png");

	m_tTower_2_Level_1_Effect.Init(L"Image/Effect/Tower_2/Tower_2_Level_1_Effect.png");
	m_tTower_2_Level_2_Effect.Init(L"Image/Effect/Tower_2/Tower_2_Level_2_Effect.png");
	m_tTower_2_Level_3_Effect.Init(L"Image/Effect/Tower_2/Tower_2_Level_3_Effect.png");

	m_tTower_3_Level_1_Effect.Init(L"Image/Effect/Tower_3/Tower_3_Level_1_Effect.png");
	m_tTower_3_Level_2_Effect.Init(L"Image/Effect/Tower_3/Tower_3_Level_2_Effect.png");
	m_tTower_3_Level_3_Effect.Init(L"Image/Effect/Tower_3/Tower_3_Level_3_Effect.png");

	m_tTower_4_Level_1_Effect.Init(L"Image/Effect/Tower_4/Tower_4_Level_1_Effect.png");
	m_tTower_4_Level_2_Effect.Init(L"Image/Effect/Tower_4/Tower_4_Level_2_Effect.png");
	m_tTower_4_Level_3_Effect.Init(L"Image/Effect/Tower_4/Tower_4_Level_3_Effect.png");

	m_tTower_5_Level_1_Effect.Init(L"Image/Effect/Tower_5/Tower_5_Level_1_Effect.png");
	m_tTower_5_Level_2_Effect.Init(L"Image/Effect/Tower_5/Tower_5_Level_2_Effect.png");
	m_tTower_5_Level_3_Effect.Init(L"Image/Effect/Tower_5/Tower_5_Level_3_Effect.png");

	m_tTower_6_Effect.Init(L"Image/Effect/Tower_6/Tower_6_Effect.png");

	t_Help_screen.Init(L"Image/Help.png");
	t_StartButton.Init(L"Image/Help_Start_Normal.png");
	t_StartButton_Hover.Init(L"Image/Help_Start_Mouse.png");

	m_tWaveNumber.Init(L"Image/WaveNumber.png");

	//오브젝트 초기화
	m_WaveNumber.Init(m_tWaveNumber, m_tWaveNumber);

	m_BG.Init(m_tBG);
	Mouse.Init(m_tMouse);

	Score.Init(tScore);
	Resources.Init(tResources);
	Factory.Init(m_ttunnel_horizon_1, m_ttunnel_horizon_2, m_ttunnel_vertical, m_tfactory);

	PauseScreen.Init(t_PauseScreen, t_Option, t_Point, t_Button);

	m_TowerSelection.Init(m_tower_1_active, m_tower_1_inactive,
		m_tower_2_active, m_tower_2_inactive,
		m_tower_3_active, m_tower_3_inactive,
		m_tower_4_active, m_tower_4_inactive,
		m_tower_5_active, m_tower_5_inactive,
		m_tower_6_active, m_tower_6_inactive,
		m_tower_1_mouse, m_tower_2_mouse, m_tower_3_mouse, m_tower_4_mouse, m_tower_5_mouse, m_tower_6_mouse,
		m_tower_1_info, m_tower_2_info, m_tower_3_info, m_tower_4_info, m_tower_5_info, m_tower_6_info);


	for (int i = 0; i < Tilerow; i++)
	{
		for (int j = 0; j < Tilecol; j++)
		{
			m_Tile[i][j].Init(m_tHouseHover, m_tTower_1, m_tTower_2, m_tTower_3,
				m_tTower_4, m_tTower_5, m_tTower_6, m_tTower_1_Stand, m_tTower_2_Stand,
				m_tTower_3_Stand, m_tTower_4_Stand, m_tTower_5_Stand,i, j);

			m_WBullet[i][j].Init(m_tTower_1_Level_1_Bullet, m_tTower_1_Level_2_Bullet, m_tTower_1_Level_3_Bullet,
								 m_tTower_2_Level_1_Bullet, m_tTower_2_Level_2_Bullet, m_tTower_2_Level_3_Bullet,
								 m_tTower_3_Level_1_Bullet, m_tTower_3_Level_2_Bullet, m_tTower_3_Level_3_Bullet,
								 m_tTower_4_Level_1_Bullet, m_tTower_4_Level_2_Bullet, m_tTower_4_Level_3_Bullet,
								 m_tTower_5_Level_1_Bullet, m_tTower_5_Level_2_Bullet, m_tTower_5_Level_3_Bullet,
								 m_tAttack_Range_50, m_tAttack_Range_75, m_tAttack_Range_100, m_tAttack_Range_150,
								 m_tAttack_Range_200, m_tAttack_Range_250, m_Tile[i][j], i, j);				//총알
			m_Tile[i][j].SetStage1(i, j);
		}
	}
	for (int i = 0; i < MonsterNum; i++)
	{
		m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
		m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
		m_TMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
	}
	CreateMonster();

	sound.Init();
	sound.PlayBGM();

	Pausechk = false;
	GameOverCheck = false;

	Pause_Play.Pause_PlayInit(m_tPause_Play);
	GameOver.GOInit(m_tGameOver);
	ReGame.RGInit(m_tReGame);
	Return_to_Title.RTInit(m_tReturn_to_Title);

	// 이펙트 //
	for (int i = 0; i < MonsterNum * 3; i++)
	{
		Effect[i].Init(m_tTower_1_Level_1_Effect, m_tTower_1_Level_2_Effect, m_tTower_1_Level_3_Effect,
					   m_tTower_2_Level_1_Effect, m_tTower_2_Level_2_Effect, m_tTower_2_Level_3_Effect,
					   m_tTower_3_Level_1_Effect, m_tTower_3_Level_2_Effect, m_tTower_3_Level_3_Effect, 
					   m_tTower_4_Level_1_Effect, m_tTower_4_Level_2_Effect, m_tTower_4_Level_3_Effect, 
					   m_tTower_5_Level_1_Effect, m_tTower_5_Level_2_Effect, m_tTower_5_Level_3_Effect,
					   m_tTower_6_Effect);
	}

	Help_screen.Init(t_Help_screen, t_StartButton, t_StartButton_Hover);

	abcd = 0;
	start = 0;

}

void CTestStage::StageRun(float tick,int* total_score)
{
	Mouse.Run(tick);
	Pause_Play.Run(tick, GameOverCheck, Mouse.getMousePosx(), Mouse.getMousePosy(), &Pausechk);

	if (Pausechk == false && GameOverCheck == false)
	{
		if (start == 0)
		{
			Help_screen.Run(Mouse.getMousePosx(),Mouse.getMousePosy(),&start);
		}
		if (tickcnt == false)
		{
			m_SFtageTime = GetTickCount();
			tickcnt = true;
		}
		m_StageTime = (float)(GetTickCount() - m_SFtageTime) / (float)1000;		//< - 이게 스테이지가 시작하고 난 뒤부터 증가하는 시간초.
		CreateMonster();
		m_BG.Run(tick);
		m_TowerSelection.Run(tick, Mouse.getMousePosx(), Mouse.getMousePosy());


		if (start == 1)
		{
			time += 1;
			for (int i = 0; i < MonsterNum; i++)
			{
				m_TMonster[i].Run(tick, Score.GetScore(), &Monster_cnt);
				m_SMonster[i].Run(tick, Score.GetScore(), &Monster_cnt);
				m_FMonster[i].Run(tick, Score.GetScore(), &Monster_cnt);
				if (m_FMonster[i].resourceplus() == true || m_SMonster[i].resourceplus() == true || m_TMonster[i].resourceplus() == true)
				{
					Resources.setRecources(*(Resources.getRecources()) + (abcd / 3) + 2);
					
				}


			}
			for (int i = 0; i < Tilerow; i++)
			{
				for (int j = 0; j < Tilecol; j++)
				{
					m_WBullet[i][j].Run_Level_Init(m_Tile[i][j]);
					if (m_Tile[i][j].GetStatus() != Road && m_Tile[i][j].GetStatus() != Normal)			//충돌
					{
						for (int z = 0; z < MonsterNum; z++)
						{
							m_WBullet[i][j].Run(m_Tile[i][j], m_FMonster[z], i, j, z);
							m_WBullet[i][j].Run(m_Tile[i][j], m_SMonster[z], i, j, z + (MonsterNum * 1)); // z로 각 몬스터를 구별함
							m_WBullet[i][j].Run(m_Tile[i][j], m_TMonster[z], i, j, z + (MonsterNum * 2));
						}
						if (m_Tile[i][j].GetStatus() == slowTower)
						{
							for (int z = 0; z < MonsterNum; z++)
							{
								if (m_Tile[i][j].Check(m_FMonster[z].CollPos, tick) == true)
								{
									m_FMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), true, m_Tile[i][j].level);
								}
								if (m_Tile[i][j].Check(m_FMonster[z].CollPos, tick) == false) // 10번째 몬스터가 트루임 그럼그 10번째 몬스터만 펄스로 바꿔줌 만약에 10번쨰 몬스터가 충돌을 하지않고 
								{
									m_FMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), false, m_Tile[i][j].level);
								}

								if (m_Tile[i][j].Check(m_SMonster[z].CollPos, tick) == true)
								{
									m_SMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), true, m_Tile[i][j].level);
								}
								if (m_Tile[i][j].Check(m_SMonster[z].CollPos, tick) == false) // 10번째 몬스터가 트루임 그럼그 10번째 몬스터만 펄스로 바꿔줌 만약에 10번쨰 몬스터가 충돌을 하지않고 
								{
									m_SMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), false, m_Tile[i][j].level);
								}
								if (m_Tile[i][j].Check(m_TMonster[z].CollPos, tick) == true)
								{
									m_TMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), true, m_Tile[i][j].level);
								}
								if (m_Tile[i][j].Check(m_TMonster[z].CollPos, tick) == false) // 10번째 몬스터가 트루임 그럼그 10번째 몬스터만 펄스로 바꿔줌 만약에 10번쨰 몬스터가 충돌을 하지않고 
								{
									m_TMonster[z].slow(m_Tile[i][j].Getcheckx(), m_Tile[i][j].Getchecky(), false, m_Tile[i][j].level);
								}
							}
						}


					}


					else
					{
						m_WBullet[i][j].Init(m_tTower_1_Level_1_Bullet, m_tTower_1_Level_2_Bullet, m_tTower_1_Level_3_Bullet,
							m_tTower_2_Level_1_Bullet, m_tTower_2_Level_2_Bullet, m_tTower_2_Level_3_Bullet,
							m_tTower_3_Level_1_Bullet, m_tTower_3_Level_2_Bullet, m_tTower_3_Level_3_Bullet,
							m_tTower_4_Level_1_Bullet, m_tTower_4_Level_2_Bullet, m_tTower_4_Level_3_Bullet,
							m_tTower_5_Level_1_Bullet, m_tTower_5_Level_2_Bullet, m_tTower_5_Level_3_Bullet,
							m_tAttack_Range_50, m_tAttack_Range_75, m_tAttack_Range_100, m_tAttack_Range_150,
							m_tAttack_Range_200, m_tAttack_Range_250, m_Tile[i][j], i, j);
					}

				}




				for (int i = 0; i < Tilerow; i++)
				{
					for (int j = 0; j < Tilecol; j++)
					{
						if (m_Tile[i][j].GetStatus() != Road)
						{
							for (int z = 0; z < MonsterNum; z++)
							{

								m_Tile[i][j].Run(tick, Mouse.getMousePosx(), Mouse.getMousePosy(), Resources.getRecources(), m_TowerSelection.SelectedTower, &sound);
							}
						}
					}
				}

		}

		
		}
		
		Resources.Run(m_StageTime);
		Score.Run(m_StageTime);
		*total_score = Score.Get_totale_Score();
		// 이펙트 
		for (int i = 0; i < MonsterNum; i++)
		{
			Effect[i].Run(&m_FMonster[i]);
			Effect[i + (MonsterNum * 1)].Run(&m_SMonster[i]);
			Effect[i + (MonsterNum * 2)].Run(&m_TMonster[i]);
		}



	}
	m_WaveNumber.Run(abcd);

	// 게임오버 게임오버 게임오버!!!!
	if (KeyInput(VK_Y) == true)
	{
		GameOverCheck = true;
		sound.StageStop(); // BGM 끄고
		sound.PlayGameOver_BGM(); // 게임오버 사운드 시작
		rank.OutputSave(Score.Get_totale_Score());
		rank.OutputLoad();
	}

	PauseScreen.Run(&Pausechk,Mouse.getMousePosx(),Mouse.getMousePosy());

	if (PauseScreen.getBackSoundchk() == false)						// 사운드 설정 (음소거)
	{
		sound.SetBGMMute();
	}
	else
	{
		sound.SetBGMPlay();
	}
	if (PauseScreen.getEffectSoundchk() == false)
	{
		sound.SetEffectMute();
	}
	else
	{
		sound.SetEffectPlay();
	}

	if (PauseScreen.ChangeChk)
	{
		sound.StageStop();
		PauseScreen.ChangeChk = false;
		ChangeStage(MainMenu);
	}

	if (abcd == 10 /*||KeyInput(VK_X)*/)
	{
		sound.StageStop();
		ChangeStage(Clear);
	}

}

void CTestStage::StageDraw()
{
	//배경오브젝트를 먼저 그림. 순서 조심.
	m_BG.Draw();
		for (int i = 0; i < MonsterNum; i++)
		{
			m_FMonster[i].Draw();
			m_SMonster[i].Draw();
			m_TMonster[i].Draw();
			Effect[i].Draw(m_FMonster[i]);
			Effect[i + (MonsterNum * 1)].Draw(m_SMonster[i]);
			Effect[i + (MonsterNum * 2)].Draw(m_TMonster[i]);
		}
		Factory.Draw();

		for (int i = 0; i < MonsterNum; i++)
		{
			if (m_FMonster[i].tunnel_end == true)
			{
				m_FMonster[i].Draw();
				Effect[i].Draw(m_FMonster[i]);
			}
			if (m_SMonster[i].tunnel_end == true)
			{
				m_SMonster[i].Draw();
				Effect[i + (MonsterNum * 1)].Draw(m_SMonster[i]);
			}
			if (m_TMonster[i].tunnel_end == true)
			{
				m_TMonster[i].Draw();
				Effect[i + (MonsterNum * 2)].Draw(m_TMonster[i]);
			}
		}

		for (int i = 0; i < Tilerow; i++)
		{
			for (int j = 0; j < Tilecol; j++)
			{
				m_Tile[i][j].Draw();
				m_WBullet[i][j].Draw(m_Tile[i][j]);

			}
		}
		Resources.Draw();
		Score.Draw();
		m_TowerSelection.Draw();
		m_WaveNumber.Draw();
		//////// 게임오버 !!!!//////////////
		if (GameOverCheck == true)
		{
			GameOver.Draw_GameOver();
			Score.GameOverDraw();
			Score.Draw();

			if (460 <= Mouse.getMousePosx() && Mouse.getMousePosx() < 751 && 615 <= Mouse.getMousePosy() && Mouse.getMousePosy() < 731)
			{
				ReGame.Draw_GameOver();
				if (KeyInput(VK_LBUTTON)) // 초기화가 잘 돼야함
				{
					sound.GameOverStop(); // 게임오버 사운드 정지
					StageInit(); // 초기화
					for (int i = 0; i < MonsterNum; i++)
					{
						for (int i = 0; i < MonsterNum; i++)
						{
							m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
							m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
							m_TMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
						}
					}
					abcd = 0;
					start = 0;
				}
			}
			if (875 <= Mouse.getMousePosx() && Mouse.getMousePosx() < 1166 && 615 <= Mouse.getMousePosy() && Mouse.getMousePosy() < 731)
			{
				Return_to_Title.Draw_GameOver();
				if (KeyInput(VK_LBUTTON))  // 초기화가 잘 돼야함
				{
					sound.GameOverStop(); // 게임오버 사운드 정지
					ChangeStage(MainMenu); // 타이틀로
					start = 0;
				}
			}

			// 닫기 버튼
			if (1244 <= Mouse.getMousePosx() && Mouse.getMousePosx() < 1270 && 108 <= Mouse.getMousePosy() && Mouse.getMousePosy() < 137)
			{
				if (KeyInput(VK_LBUTTON))
				{
					PostQuitMessage(WM_QUIT); // 나가기
				}
			}
		}

		PauseScreen.Draw();

		Pause_Play.Pause_PlayDraw();

	Help_screen.Draw();
	Mouse.Draw();
}

void CTestStage::CreateMonster()
{
	if (start == 1)
	{
		
		/*switch (abcd)
		{
		case 0:
			if (Monster_cnt == 15)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				abcd++;
			}
			if (m_SMonster[MonsterNum - 1].GetDie() == true)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);

				}
				m_SMonster[MonsterNum - 1].SetDie(false);

			}
			if (m_TMonster[MonsterNum - 1].GetDie() == true)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_TMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				m_TMonster[MonsterNum - 1].SetDie(false);

			}
		}*/
		switch (abcd)
		{
		case 0:
			if (time % 20 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{	
						m_FMonster[i].Start(1, 0, 100, 3);
						break;
					}

				}
			}
			if (Monster_cnt == 15)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd += 1;
			}
			break;
		case 1:
			if (time % 40 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(3, 1, 300, 2);
						break;
					}
				}
			}
			if (Monster_cnt == 15)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;
		case 2:
			if (time % 80 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(0, 2, 200, 5);
					
						break;
					}
				}
			}
			if (Monster_cnt == 15)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;
		case 3:
			if (time % 20 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(2, 3, 400, 3);
					
						break;
					}
				}
			}
			if (Monster_cnt == 15)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}

			break;
		case 4:
			if (time % 40 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(1, 0, 250, 3);
						m_SMonster[i].Start(3, 2, 200, 4);
						break;
					}
				}
			}
			if (Monster_cnt == 30)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;
		case 5:
			if (time % 40 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(0, 3, 200, 7);
						m_SMonster[i].Start(2, 1, 700, 2);
						break;
					}
				}
			}
			if (Monster_cnt == 30)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;
		case 6:
			if (time % 80 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(2, 3, 300, 10);
						m_SMonster[i].Start(4, 3, 800, 4);
						break;
					}
				}
			}
			if (Monster_cnt == 30)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;
			break;
		case 7:
			if (time % 60 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(1, 0, 1200, 3);
						m_SMonster[i].Start(2, 1, 800, 5);
						break;
					}
				}
			}
			if (Monster_cnt == 30)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}

			break;

		case 8:
			if (time % 50 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(3, 1, 900, 6);
						m_SMonster[i].Start(4, 3, 1300, 5);
						break;
					}
				}
			}
			if (Monster_cnt == 30)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;

		case 9:
			if (time % 50 == 0)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					if (m_SMonster[i].GetLive() == false && m_SMonster[i].GetDie() == false && m_FMonster[i].GetLive() == false && m_FMonster[i].GetDie() == false && m_TMonster[i].GetLive() == false && m_TMonster[i].GetDie() == false)
					{
						m_FMonster[i].Start(2, 1, 4000, 2);
						m_SMonster[i].Start(4, 3, 500, 15);
						m_TMonster[i].Start(0, 2, 1500, 5);
						break;
					}
				}
			}
			if (Monster_cnt == 45)
			{
				for (int i = 0; i < MonsterNum; i++)
				{
					m_FMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
					m_SMonster[i].Init(m_tnyang_cup, m_tgitar, m_tsangza, m_tbongzi_1, m_tbongzi_2, m_tHP_Bar);
				}
				Monster_cnt = 0;
				abcd++;
			}
			break;

		case 10:
			


			break;

		}

	}

}
