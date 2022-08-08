#pragma once
#include "BaseStage.h"
#include "Background.h"
#include "Tile.h"
#include "Cursor.h"
#include "Resources.h"
#include "Monster.h"
#include "Bullet.h"
#include "Picture.h"
#include "TowerSelection.h"
#include "score.h"
#include "Effect.h"
#include "PauseScreen.h"
#include "rank.h"


class CTestStage :
	public CBaseStage
{
private:

	Crank rank;



	int start = 0;
	int time;
	int abc = 0;
	CBackground m_BG;
	CTexture m_tBG;

	CTile m_Tile[Tilerow][Tilecol];		//타일 객체



	CTexture m_tTower_1;		//타워 텍스쳐
	CTexture m_tTower_2;
	CTexture m_tTower_3;
	CTexture m_tTower_4;
	CTexture m_tTower_5;
	CTexture m_tTower_6;

	CTexture m_tTower_1_Stand;
	CTexture m_tTower_2_Stand;
	CTexture m_tTower_3_Stand;
	CTexture m_tTower_4_Stand;
	CTexture m_tTower_5_Stand;
	



	CTexture m_tHouseHover;			//마우스를 올렸을때 나타나는 사각형

	int abcd;

	CHelp	Help_screen;
	CTexture t_Help_screen;
	CTexture t_StartButton;
	CTexture t_StartButton_Hover;


	CTexture m_tnyang_cup;			//적 텍스쳐
	CTexture m_tgitar;
	CTexture m_tsangza;
	CTexture m_tbongzi_1;
	CTexture m_tbongzi_2;

	CTexture m_tHP_Bar;				//HP바 텍스쳐

	CSound sound;					//사운드


	int a = 0;
	int j = 0;

	int resource;					//자원

	CMonster m_Monster[MonsterNum];			//적 객체
	CMonster m_FMonster[MonsterNum];
	CMonster m_SMonster[MonsterNum];
	CMonster m_TMonster[MonsterNum];

	Cursor Mouse;							//마우스 객체
	CTexture m_tMouse;						//마우스 텍스쳐

	CTowerSelection    m_TowerSelection;		//타워 선택 객체

	CTexture	m_tower_1_active;				//타워 선택 텍스쳐
	CTexture	m_tower_1_inactive;
	CTexture	m_tower_2_active;
	CTexture	m_tower_2_inactive;
	CTexture	m_tower_3_active;
	CTexture	m_tower_3_inactive;
	CTexture	m_tower_4_active;
	CTexture	m_tower_4_inactive;
	CTexture	m_tower_5_active;
	CTexture	m_tower_5_inactive;
	CTexture	m_tower_6_active;
	CTexture	m_tower_6_inactive;

	CTexture	m_tower_1_mouse;				//타워 선택 마우스 올렸을때 텍스쳐
	CTexture	m_tower_2_mouse;
	CTexture	m_tower_3_mouse;
	CTexture	m_tower_4_mouse;
	CTexture	m_tower_5_mouse;
	CTexture	m_tower_6_mouse;

	CTexture	m_tower_1_info;					//타워 정보 텍스쳐
	CTexture	m_tower_2_info;
	CTexture	m_tower_3_info;
	CTexture	m_tower_4_info;
	CTexture	m_tower_5_info;
	CTexture	m_tower_6_info;
	



	CBullet m_WBullet[Tilerow][Tilecol];			//총알 객체

	CTexture m_tTower_1_Level_1_Bullet;				//총알 텍스쳐
	CTexture m_tTower_1_Level_2_Bullet;
	CTexture m_tTower_1_Level_3_Bullet;
	CTexture m_tTower_2_Level_1_Bullet;
	CTexture m_tTower_2_Level_2_Bullet;
	CTexture m_tTower_2_Level_3_Bullet;
	CTexture m_tTower_3_Level_1_Bullet;
	CTexture m_tTower_3_Level_2_Bullet;
	CTexture m_tTower_3_Level_3_Bullet;
	CTexture m_tTower_4_Level_1_Bullet;
	CTexture m_tTower_4_Level_2_Bullet;
	CTexture m_tTower_4_Level_3_Bullet;
	CTexture m_tTower_5_Level_1_Bullet;
	CTexture m_tTower_5_Level_2_Bullet;
	CTexture m_tTower_5_Level_3_Bullet;

	CTexture m_tAttack_Range_50;					//공격범위 텍스쳐
	CTexture m_tAttack_Range_75;
	CTexture m_tAttack_Range_100;
	CTexture m_tAttack_Range_150;
	CTexture m_tAttack_Range_200;
	CTexture m_tAttack_Range_250;

	Cscore Score;									//점수 객체
	CTexture tScore;								//점수 텍스쳐
		
	CResources Resources;							//자원 객체
	CTexture tResources;							//자원 텍스쳐

	CTexture m_tfactory;							//공장 텍스쳐
	CPicture Factory;								//공장 객체

	CTexture m_ttunnel_vertical;					//터널 텍스쳐
	CTexture m_ttunnel_horizon_1;
	CTexture m_ttunnel_horizon_2;

	CPicture Pause_Play;							//일시정지 객체
	CTexture m_tPause_Play;							//일시정지 텍스쳐
	CTexture t_Point;

	CPicture ReGame;								//재시작 

	CPicture Return_to_Title;						//타이틀로 돌아가기

	CPicture GameOver;								//게임오버 

	CTexture m_tReGame;								//재시작  텍스쳐
	CTexture m_tReturn_to_Title;				
	CTexture m_tGameOver;

	

	CEffect Effect[MonsterNum * 3];					//이펙트 객체
	CTexture m_tTower_1_Level_1_Effect;				//이펙트 텍스쳐
	CTexture m_tTower_1_Level_2_Effect;
	CTexture m_tTower_1_Level_3_Effect;

	CTexture m_tTower_2_Level_1_Effect;
	CTexture m_tTower_2_Level_2_Effect;
	CTexture m_tTower_2_Level_3_Effect;

	CTexture m_tTower_3_Level_1_Effect;
	CTexture m_tTower_3_Level_2_Effect;
	CTexture m_tTower_3_Level_3_Effect;

	CTexture m_tTower_4_Level_1_Effect;
	CTexture m_tTower_4_Level_2_Effect;
	CTexture m_tTower_4_Level_3_Effect;

	CTexture m_tTower_5_Level_1_Effect;
	CTexture m_tTower_5_Level_2_Effect;
	CTexture m_tTower_5_Level_3_Effect;

	CTexture m_tTower_6_Effect;

	CTexture t_PauseScreen;
	CTexture t_Option;
	CTexture t_Button;
	CPause PauseScreen;

	CTexture m_tWaveNumber;
	CWaveNumber m_WaveNumber;
public:
	

	int Monster_cnt;


	CTestStage(void){}
	~CTestStage(void){}

	void StageInit();
	void StageRun(float tick,int* total_score);
	void StageDraw();

	bool GameOverCheck;					//게임오버
	bool Pausechk;

	void CreateMonster(); //몬스터 생성
};