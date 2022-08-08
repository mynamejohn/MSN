#pragma once
#include "BaseObject.h"
#include "Monster.h"

class CEffect :
	public CBaseObject
{
private:
	float		rect_top_Tower_1;
	float		rect_bottom_Tower_1;
	float		rect_left_Tower_1;
	float		rect_right_Tower_1;
	RECT		RECT_TOWER1;

	float		rect_top_Tower_2;
	float		rect_bottom_Tower_2;
	float		rect_left_Tower_2;
	float		rect_right_Tower_2;
	RECT		RECT_TOWER2;

	float		rect_top_Tower_3;
	float		rect_bottom_Tower_3;
	float		rect_left_Tower_3;
	float		rect_right_Tower_3;
	RECT		RECT_TOWER3;

	float		rect_top_Tower_4;
	float		rect_bottom_Tower_4;
	float		rect_left_Tower_4;
	float		rect_right_Tower_4;
	RECT		RECT_TOWER4;

	float		rect_top_Tower_5;
	float		rect_bottom_Tower_5;
	float		rect_left_Tower_5;
	float		rect_right_Tower_5;
	RECT		RECT_TOWER5;

	float		rect_top_Tower_6;
	float		rect_bottom_Tower_6;
	float		rect_left_Tower_6;
	float		rect_right_Tower_6;
	RECT		RECT_TOWER6;

	float	Effect_delay_tick;
	float	Effect_delay_first_time;

	float	Effect_delay_Tower_1; // 이펙트 스프라이트 딜레이 변수
	float	Effect_delay_Tower_2;
	float	Effect_delay_Tower_3;
	float	Effect_delay_Tower_4;
	float	Effect_delay_Tower_5;
	float	Effect_delay_Tower_6;


	float	Effect_Time_Tower_1; // 이펙트 적용되는 시간 변수
	float	Effect_Time_Tower_2;
	float	Effect_Time_Tower_3;
	float	Effect_Time_Tower_4;
	float	Effect_Time_Tower_5;
	float	Effect_Time_Tower_6;


	LPDIRECT3DTEXTURE9		m_pTexture2;
	LPDIRECT3DTEXTURE9		m_pTexture3;
	LPDIRECT3DTEXTURE9		m_pTexture4;
	LPDIRECT3DTEXTURE9		m_pTexture5;
	LPDIRECT3DTEXTURE9		m_pTexture6;
	LPDIRECT3DTEXTURE9		m_pTexture7;
	LPDIRECT3DTEXTURE9		m_pTexture8;
	LPDIRECT3DTEXTURE9		m_pTexture9;
	LPDIRECT3DTEXTURE9		m_pTexture10;
	LPDIRECT3DTEXTURE9		m_pTexture11;
	LPDIRECT3DTEXTURE9		m_pTexture12;
	LPDIRECT3DTEXTURE9		m_pTexture13;
	LPDIRECT3DTEXTURE9		m_pTexture14;
	LPDIRECT3DTEXTURE9		m_pTexture15;
	LPDIRECT3DTEXTURE9		m_pTexture16;


	D3DXVECTOR3		m_vPos_Tower_1;
	D3DXVECTOR3		m_vPos_Tower_2;
	D3DXVECTOR3		m_vPos_Tower_3;
	D3DXVECTOR3		m_vPos_Tower_4;
	D3DXVECTOR3		m_vPos_Tower_5;
	D3DXVECTOR3		m_vPos_Tower_6;


public:
	CEffect(void){}
	~CEffect(void){}

	void	Init(CTexture t1, CTexture t2, CTexture t3,
				 CTexture t4, CTexture t5, CTexture t6,
				 CTexture t7, CTexture t8, CTexture t9,
				 CTexture t10, CTexture t11, CTexture t12,
				 CTexture t13, CTexture t14, CTexture t15,
				 CTexture t16);

	void	Run(CMonster* Monster);
	void	Draw(CMonster Monster);

};