#pragma once
#include "BaseObject.h"
class CTowerSelection :
	public CBaseObject
{
private:
	LPDIRECT3DTEXTURE9	m_tower_1_active;
	LPDIRECT3DTEXTURE9	m_tower_1_inactive;
	LPDIRECT3DTEXTURE9	m_tower_2_active;
	LPDIRECT3DTEXTURE9	m_tower_2_inactive;
	LPDIRECT3DTEXTURE9	m_tower_3_active;
	LPDIRECT3DTEXTURE9	m_tower_3_inactive;
	LPDIRECT3DTEXTURE9	m_tower_4_active;
	LPDIRECT3DTEXTURE9	m_tower_4_inactive;
	LPDIRECT3DTEXTURE9	m_tower_5_active;
	LPDIRECT3DTEXTURE9	m_tower_5_inactive;
	LPDIRECT3DTEXTURE9	m_tower_6_active;
	LPDIRECT3DTEXTURE9	m_tower_6_inactive;

	LPDIRECT3DTEXTURE9	m_tower_1_mouse;
	LPDIRECT3DTEXTURE9	m_tower_2_mouse;
	LPDIRECT3DTEXTURE9	m_tower_3_mouse;
	LPDIRECT3DTEXTURE9	m_tower_4_mouse;
	LPDIRECT3DTEXTURE9	m_tower_5_mouse;
	LPDIRECT3DTEXTURE9	m_tower_6_mouse;

	LPDIRECT3DTEXTURE9	m_tower_1_info;
	LPDIRECT3DTEXTURE9	m_tower_2_info;
	LPDIRECT3DTEXTURE9	m_tower_3_info;
	LPDIRECT3DTEXTURE9	m_tower_4_info;
	LPDIRECT3DTEXTURE9	m_tower_5_info;
	LPDIRECT3DTEXTURE9	m_tower_6_info;


	RECT				m_rect2;

	D3DXVECTOR3			m_vPos_tower_1;
	D3DXVECTOR3			m_vPos_tower_2;
	D3DXVECTOR3			m_vPos_tower_3;
	D3DXVECTOR3			m_vPos_tower_4;
	D3DXVECTOR3			m_vPos_tower_5;
	D3DXVECTOR3			m_vPos_tower_6;


	D3DXVECTOR3			m_vPos_tower_info;

	D3DCOLOR			m_color2;

	int m_alpha2;


public:
	CTowerSelection(void){}
	~CTowerSelection(void){}
	int SelectedTower;
	int TowerInfo;

	void	Init(CTexture tower_1_active,
		CTexture tower_1_inactive,
		CTexture tower_2_active,
		CTexture tower_2_inactive,
		CTexture tower_3_active,
		CTexture tower_3_inactive,
		CTexture tower_4_active,
		CTexture tower_4_inactive,
		CTexture tower_5_active,
		CTexture tower_5_inactive,
		CTexture tower_6_active,
		CTexture tower_6_inactive,

		CTexture tower_1_mouse,
		CTexture tower_2_mouse,
		CTexture tower_3_mouse,
		CTexture tower_4_mouse,
		CTexture tower_5_mouse,
		CTexture tower_6_mouse,

		CTexture tower_1_info,
		CTexture tower_2_info,
		CTexture tower_3_info,
		CTexture tower_4_info,
		CTexture tower_5_info,
		CTexture tower_6_info);

	void	Run(float tick, float posX, float posY);
	void	Draw();
};
