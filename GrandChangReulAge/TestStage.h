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

	CTile m_Tile[Tilerow][Tilecol];		//Ÿ�� ��ü



	CTexture m_tTower_1;		//Ÿ�� �ؽ���
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
	



	CTexture m_tHouseHover;			//���콺�� �÷����� ��Ÿ���� �簢��

	int abcd;

	CHelp	Help_screen;
	CTexture t_Help_screen;
	CTexture t_StartButton;
	CTexture t_StartButton_Hover;


	CTexture m_tnyang_cup;			//�� �ؽ���
	CTexture m_tgitar;
	CTexture m_tsangza;
	CTexture m_tbongzi_1;
	CTexture m_tbongzi_2;

	CTexture m_tHP_Bar;				//HP�� �ؽ���

	CSound sound;					//����


	int a = 0;
	int j = 0;

	int resource;					//�ڿ�

	CMonster m_Monster[MonsterNum];			//�� ��ü
	CMonster m_FMonster[MonsterNum];
	CMonster m_SMonster[MonsterNum];
	CMonster m_TMonster[MonsterNum];

	Cursor Mouse;							//���콺 ��ü
	CTexture m_tMouse;						//���콺 �ؽ���

	CTowerSelection    m_TowerSelection;		//Ÿ�� ���� ��ü

	CTexture	m_tower_1_active;				//Ÿ�� ���� �ؽ���
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

	CTexture	m_tower_1_mouse;				//Ÿ�� ���� ���콺 �÷����� �ؽ���
	CTexture	m_tower_2_mouse;
	CTexture	m_tower_3_mouse;
	CTexture	m_tower_4_mouse;
	CTexture	m_tower_5_mouse;
	CTexture	m_tower_6_mouse;

	CTexture	m_tower_1_info;					//Ÿ�� ���� �ؽ���
	CTexture	m_tower_2_info;
	CTexture	m_tower_3_info;
	CTexture	m_tower_4_info;
	CTexture	m_tower_5_info;
	CTexture	m_tower_6_info;
	



	CBullet m_WBullet[Tilerow][Tilecol];			//�Ѿ� ��ü

	CTexture m_tTower_1_Level_1_Bullet;				//�Ѿ� �ؽ���
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

	CTexture m_tAttack_Range_50;					//���ݹ��� �ؽ���
	CTexture m_tAttack_Range_75;
	CTexture m_tAttack_Range_100;
	CTexture m_tAttack_Range_150;
	CTexture m_tAttack_Range_200;
	CTexture m_tAttack_Range_250;

	Cscore Score;									//���� ��ü
	CTexture tScore;								//���� �ؽ���
		
	CResources Resources;							//�ڿ� ��ü
	CTexture tResources;							//�ڿ� �ؽ���

	CTexture m_tfactory;							//���� �ؽ���
	CPicture Factory;								//���� ��ü

	CTexture m_ttunnel_vertical;					//�ͳ� �ؽ���
	CTexture m_ttunnel_horizon_1;
	CTexture m_ttunnel_horizon_2;

	CPicture Pause_Play;							//�Ͻ����� ��ü
	CTexture m_tPause_Play;							//�Ͻ����� �ؽ���
	CTexture t_Point;

	CPicture ReGame;								//����� 

	CPicture Return_to_Title;						//Ÿ��Ʋ�� ���ư���

	CPicture GameOver;								//���ӿ��� 

	CTexture m_tReGame;								//�����  �ؽ���
	CTexture m_tReturn_to_Title;				
	CTexture m_tGameOver;

	

	CEffect Effect[MonsterNum * 3];					//����Ʈ ��ü
	CTexture m_tTower_1_Level_1_Effect;				//����Ʈ �ؽ���
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

	bool GameOverCheck;					//���ӿ���
	bool Pausechk;

	void CreateMonster(); //���� ����
};