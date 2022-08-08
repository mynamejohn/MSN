#pragma once
#include "Device.h"
#include "Texture.h"
#include "Sound.h"


class CBaseObject
{
protected:
	LPDIRECT3DTEXTURE9	m_pTexture;
	LPD3DXSPRITE		m_pSprite;

	
	D3DCOLOR			m_color;
	unsigned int		m_alpha;

	bool				m_bDraw;
	float				m_tick;
	bool				die;
	float				m_radius;
	
	bool				* P_die = &die;
public:
	RECT				m_rect;
	RECT				pm_rect;
	CBaseObject(void);
	virtual ~CBaseObject(void);
	
	D3DXVECTOR3			m_vPos;
	void	Init(CTexture t1);
	void	Run(float tick);
	void	Draw();

	void	Animation(float *timer, int *aniNum, int width, int height, int rowNum, int lastNum, float delayTime);

	void	FadeIn(unsigned int *alpha);

	void        SetDie(bool *m_die) { P_die = m_die; }
	bool        GetDie()	{ return die; };
	//Getter
	
	bool		GetLive()	{ return m_bDraw; };
	D3DXVECTOR3	GetvPos()	{ return m_vPos; };
	float		GetRadius()	{ return m_radius; };

	//Setter
	void	SetRect(RECT rect)	{ m_rect = rect; }
	void	SetLive(bool live)	{ m_bDraw = live; };

};