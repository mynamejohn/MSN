#pragma once
#include "BaseObject.h"
#include "score.h"
#include "Tile.h"



class CMonster :
	public CBaseObject
{
private:
	
	int m_Pattern;
	int m_Type;
	int m_HP;
	bool resourcecheck;
	float m_MHP;
	float *pm_HP;
	float Entire_HP;
	int abc;
	int slowx;     //이 몬스터와 타일의 슬로우 충돌판정을 할떄만씀 
	int slowy;
	int persistx;
	int persisty;
	float BaseMoveSpeed;			//기본 이동속도
	float MoveSpeed;				//이동속도(디버프같은겉들을 합한 최종 이동속도)
	float slowSpeed;
	int resource;
	bool check;
	bool *P_check;



	float cooltime;
	float *P_cooltime;

	bool Persistcheck;
	bool *P_Persistcheck;

	float Persisttime;
	float *P_Persisttime;

	float	Persist_tick;
	float	*P_Persist_tick;

	float	Persist_first_time;
	float	*P_Persist_first_time;

	float	m_aniTimer;
	int		m_aniNum;
	float Coll_Radius;

	int	wave_num;

	int		m_pTexture_Direction;
	int		Monster_State;

	float	rect_left;
	float	rect_top;
	float	rect_right;
	float	rect_bottom;






	bool	Tower_1_Level_1_Effect;
	bool	*P_Tower_1_Level_1_Effect;
	bool	Tower_1_Level_2_Effect;
	bool	*P_Tower_1_Level_2_Effect;
	bool	Tower_1_Level_3_Effect;
	bool	*P_Tower_1_Level_3_Effect;

	bool	Tower_2_Level_1_Effect;
	bool	*P_Tower_2_Level_1_Effect;
	bool	Tower_2_Level_2_Effect;
	bool	*P_Tower_2_Level_2_Effect;
	bool	Tower_2_Level_3_Effect;
	bool	*P_Tower_2_Level_3_Effect;

	bool	Tower_3_Level_1_Effect;
	bool	*P_Tower_3_Level_1_Effect;
	bool	Tower_3_Level_2_Effect;
	bool	*P_Tower_3_Level_2_Effect;
	bool	Tower_3_Level_3_Effect;
	bool	*P_Tower_3_Level_3_Effect;

	bool	Tower_4_Level_1_Effect;
	bool	*P_Tower_4_Level_1_Effect;
	bool	Tower_4_Level_2_Effect;
	bool	*P_Tower_4_Level_2_Effect;
	bool	Tower_4_Level_3_Effect;
	bool	*P_Tower_4_Level_3_Effect;

	bool	Tower_5_Level_1_Effect;
	bool	*P_Tower_5_Level_1_Effect;
	bool	Tower_5_Level_2_Effect;
	bool	*P_Tower_5_Level_2_Effect;
	bool	Tower_5_Level_3_Effect;
	bool	*P_Tower_5_Level_3_Effect;

	bool	Tower_6_Effect;
	bool	*P_Tower_6_Effect;
	

	float	Sprite_tick;
	float	Sprite_first_time;

	LPDIRECT3DTEXTURE9	m_pTexture_nyang_cup;
	LPDIRECT3DTEXTURE9	m_pTexture_gitar;
	LPDIRECT3DTEXTURE9	m_pTexture_sangza;
	LPDIRECT3DTEXTURE9	m_pTexture_bongzi_1;
	LPDIRECT3DTEXTURE9	m_pTexture_bongzi_2;

	LPDIRECT3DTEXTURE9	m_pTexture_HP_Bar;
	D3DCOLOR			m_color_HP_Bar;
	RECT				m_rect_HP_Bar;
	D3DXVECTOR3			m_vPos_HP_Bar;

public:
	CMonster(void){}
	~CMonster(void){}
	bool resourceplus();
	void    damege() { m_HP -= 5; }
	void    m_die(){die = true;};
	void	Init(CTexture t1, CTexture t2, CTexture t3, CTexture t4, CTexture t5, CTexture HP);
	void	Run(float tick, int *Score, int* Monster_cnt);
	void	Draw();
	void	Start(int type, int pattern,int HP, int speed);
	void    slow(int Tilex, int Tiley, bool Cslowcheck,int level);
	void	HP_Bar();
	void	Tunnel();
	void	clear()	{ slowSpeed = 0; }
	

	bool	In_tunnel;
	bool	tunnel_end;

	float	Effect_tick;
	float	Effect_first_time;
	float	*P_Effect_first_time;

	D3DXVECTOR3 CollPos;			//충돌처리를 위한 좌표값
	
	void Setcheck(bool a) { *P_check = a; }


	float Getcooltime() { return cooltime; }
	void  Setcooltime(float b) { *P_cooltime = b; }

	bool Getcheck() { return check; }
	float GetPersisttime() { return Persisttime; }
	bool GetPersistcheck() { return Persistcheck; }
	float GetPersist_tick() { return Persist_tick; }
	float GetPersist_first_time() { return Persist_first_time; }

	void SetPersistcheck(bool check) { *P_Persistcheck = check; }
	void SetPersisttime(float time) { *P_Persisttime = time; }
	void SetPersist_tick(float tick) { *P_Persist_tick = tick; }
	void SetPersist_first_time(float tick) { *P_Persist_first_time = tick; }

	
	float slowtime;
	float GetPosx() { return m_vPos.x; }//성호추가
	float GetPosy() { return m_vPos.y; }

	float GetRadius(){ return Coll_Radius; }//여기까지

	float	GetHP()			{ return m_MHP; }
	void	SetHP(float HP)	{ *pm_HP = HP; }

	void Spriting();

	void SetEffect_first_time(float GetTickCount) { *P_Effect_first_time = GetTickCount; }

	bool GetTower_1_Level_1_Effect() { return Tower_1_Level_1_Effect; }
	void SetTower_1_Level_1_Effect(bool Hit) { *P_Tower_1_Level_1_Effect = Hit; }
	bool GetTower_1_Level_2_Effect() { return Tower_1_Level_2_Effect; }
	void SetTower_1_Level_2_Effect(bool Hit) { *P_Tower_1_Level_2_Effect = Hit; }
	bool GetTower_1_Level_3_Effect() { return Tower_1_Level_3_Effect; }
	void SetTower_1_Level_3_Effect(bool Hit) { *P_Tower_1_Level_3_Effect = Hit; }

	bool GetTower_2_Level_1_Effect() { return Tower_2_Level_1_Effect; }
	void SetTower_2_Level_1_Effect(bool Hit) { *P_Tower_2_Level_1_Effect = Hit; }
	bool GetTower_2_Level_2_Effect() { return Tower_2_Level_2_Effect; }
	void SetTower_2_Level_2_Effect(bool Hit) { *P_Tower_2_Level_2_Effect = Hit; }
	bool GetTower_2_Level_3_Effect() { return Tower_2_Level_3_Effect; }
	void SetTower_2_Level_3_Effect(bool Hit) { *P_Tower_2_Level_3_Effect = Hit; }

	bool GetTower_3_Level_1_Effect() { return Tower_3_Level_1_Effect; }
	void SetTower_3_Level_1_Effect(bool Hit) { *P_Tower_3_Level_1_Effect = Hit; }
	bool GetTower_3_Level_2_Effect() { return Tower_3_Level_2_Effect; }
	void SetTower_3_Level_2_Effect(bool Hit) { *P_Tower_3_Level_2_Effect = Hit; }
	bool GetTower_3_Level_3_Effect() { return Tower_3_Level_3_Effect; }
	void SetTower_3_Level_3_Effect(bool Hit) { *P_Tower_3_Level_3_Effect = Hit; }

	bool GetTower_4_Level_1_Effect() { return Tower_4_Level_1_Effect; }
	void SetTower_4_Level_1_Effect(bool Hit) { *P_Tower_4_Level_1_Effect = Hit; }
	bool GetTower_4_Level_2_Effect() { return Tower_4_Level_2_Effect; }
	void SetTower_4_Level_2_Effect(bool Hit) { *P_Tower_4_Level_2_Effect = Hit; }
	bool GetTower_4_Level_3_Effect() { return Tower_4_Level_3_Effect; }
	void SetTower_4_Level_3_Effect(bool Hit) { *P_Tower_4_Level_3_Effect = Hit; }

	bool GetTower_5_Level_1_Effect() { return Tower_5_Level_1_Effect; }
	void SetTower_5_Level_1_Effect(bool Hit) { *P_Tower_5_Level_1_Effect = Hit; }
	bool GetTower_5_Level_2_Effect() { return Tower_5_Level_2_Effect; }
	void SetTower_5_Level_2_Effect(bool Hit) { *P_Tower_5_Level_2_Effect = Hit; }
	bool GetTower_5_Level_3_Effect() { return Tower_5_Level_3_Effect; }
	void SetTower_5_Level_3_Effect(bool Hit) { *P_Tower_5_Level_3_Effect = Hit; }

	bool GetTower_6_Effect() { return Tower_6_Effect; }
	void SetTower_6_Effect(bool Hit) { *P_Tower_6_Effect = Hit; }


	
};



enum Direction
{
	Direction_front,
	Direction_behind,
	Direction_left,
	Direction_right
};

enum Monster_State
{
	nyang_cup,
	gitar,
	sangza,
	bongzi_1,
	bongzi_2
};