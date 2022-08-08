#pragma once
#include "BaseObject.h"
#include "Monster.h"
#include "Tile.h"
#include <math.h>

class CBullet :
	public CBaseObject
{
private:
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_1_Level_1_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_1_Level_2_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_1_Level_3_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_2_Level_1_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_2_Level_2_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_2_Level_3_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_3_Level_1_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_3_Level_2_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_3_Level_3_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_4_Level_1_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_4_Level_2_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_4_Level_3_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_5_Level_1_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_5_Level_2_Bullet;
	LPDIRECT3DTEXTURE9	m_pTexture_Tower_5_Level_3_Bullet;

	D3DXVECTOR3	m_vPos2;

	RECT				Penetration_tower;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_50;
	RECT				Attack_Range_50_rect;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_75;
	RECT				Attack_Range_75_rect;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_100;
	RECT				Attack_Range_100_rect;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_150;
	RECT				Attack_Range_150_rect;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_200;
	RECT				Attack_Range_200_rect;

	LPDIRECT3DTEXTURE9	m_pAttack_Range_250;
	RECT				Attack_Range_250_rect;

	D3DCOLOR			Attack_Range_color;


	float time = 2;

	int aninum = 0;
	int turnrecttop;
	int turnrectright;
	int turnrectleft;
	int turnrectbottom;

	float turntime;
	float turntick;

	bool ani_bool;

public:
	void	Init(CTexture Tower_1_Level_1_Bullet, CTexture Tower_1_Level_2_Bullet, CTexture Tower_1_Level_3_Bullet,
				 CTexture Tower_2_Level_1_Bullet, CTexture Tower_2_Level_2_Bullet, CTexture Tower_2_Level_3_Bullet,
				 CTexture Tower_3_Level_1_Bullet, CTexture Tower_3_Level_2_Bullet, CTexture Tower_3_Level_3_Bullet,
				 CTexture Tower_4_Level_1_Bullet, CTexture Tower_4_Level_2_Bullet, CTexture Tower_4_Level_3_Bullet,
				 CTexture Tower_5_Level_1_Bullet, CTexture Tower_5_Level_2_Bullet, CTexture Tower_5_Level_3_Bullet,
				 CTexture Attack_Range_50, CTexture Attack_Range_75, CTexture Attack_Range_100, CTexture Attack_Range_150,
				 CTexture Attack_Range_200, CTexture Attack_Range_250, CTile Tile, int i, int j);
	void	Run(CTile Tile, CMonster Monster, int i, int j, int z);
	void	Run_Level_Init(CTile Tile);
	void	Draw(CTile Tile);
	CBullet(){}
	~CBullet(){}
	
	float ani_time;
	int ani_num;

	// 공통 변수
	bool	Target[MonsterNum * 3];
	int		OnTarget[MonsterNum * 3];
	bool	BulletFire[MonsterNum * 3];
	bool	OnFire;
	int		Distance;
	int		TempDistance;
	int		Bullet_X;
	int		Bullet_Y;
	int		Bullet_Distance;
	float	Bullet_tick;
	float	first_time;
	int		X;
	int		Y;
	float resettime;

	// 기본타워 변수
	float	Attack_Damage;
	float	Bullet_Speed;
	float	Attack_Speed;
	float	Attack_Range;
	
	bool	m_bDraw2;
	bool	m_bDraw3;
	int		Bullet_X2;
	int		Bullet_Y2;
	int		Bullet_Distance2;

	// 스플래시타워 변수
	float	splash_Attack_Damage;
	float	splash_Bullet_Speed;
	float	splash_Attack_Speed;
	float	splash_Attack_Range; // 사정거리
	float	splash_Range; // 스플래시의 범위

	int		splash_X;
	int		splash_Y;
	int		splash_Bullet_Distance;
	int		Impacted_X_Pos;
	int		Impacted_Y_Pos;
	bool	splash_Impact_Switch[MonsterNum * 3];


	// 관통타워 변수
	float	Penetration_Attack_Damage;
	float	Penetration_Bullet_Speed;
	float	Penetration_Attack_Speed;
	float	Penetration_Attack_Range;
	float	Penetration_Distance; // 관통거리
	float	Penetration_Monster_Damage_Cooltime; // 일정한 간격(쿨타임)마다 데미지 입힘
	float	Penetration_Impact_Range; // 지나가면서 몬스터와의 충돌거리

	float	Bullet_cos;
	float	Bullet_sin;
	float	Target_X_Interval;
	float	Target_Y_Interval;
	int		Quadrant;
	float	Target_X_Pos;
	float	Target_Y_Pos;
	bool	Penetration_Attack;
	float	Penetration_Bullet_X;
	float	Penetration_Bullet_Y;
	float	Penetration_Bullet_Distance;
	float	Penetration_Temp_Bullet_Speed;
	float	Temp_X_Bullet_Speed;
	float	Temp_Y_Bullet_Speed;
	float	Penetration_Bullet_tick;
	float	Penetration_first_time;

	// 회전타워 변수
	float	turning_Attack_Damage;
	float	turning_Bullet_Speed;
	float	turning_Attack_Range;
	float	turning_Monster_Damage_Cooltime; // 일정한 간격(쿨타임)마다 데미지 입힘
	float	turning_Impact_Range; // 지나가면서 몬스터와의 충돌거리

	double	turning_N;
	int		turning_Distance;
	float	turning_Temp_Bullet_Speed;

	// 지속타워 변수
	float	persist_Attack_Damage;
	float	persist_Bullet_Speed;
	float	persist_Attack_Range;
	float	persist_Attack_Speed;

};