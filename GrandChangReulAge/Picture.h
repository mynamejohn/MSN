#pragma once
#include "BaseObject.h"

class CPicture :
	public CBaseObject
{
private:

	LPDIRECT3DTEXTURE9 m_pTexture2;
	LPDIRECT3DTEXTURE9 m_pTexture3;
	LPDIRECT3DTEXTURE9 m_pTexture4;

	LPDIRECT3DTEXTURE9 t_Regame;
	LPDIRECT3DTEXTURE9 t_Return;


	LPDIRECT3DTEXTURE9 m_tunnel_vertical;
	LPDIRECT3DTEXTURE9 m_tunnel_horizon_1;
	LPDIRECT3DTEXTURE9 m_tunnel_horizon_2;
	LPDIRECT3DTEXTURE9 m_factory;

	RECT	m_tunnel_vertical_rect;
	RECT	m_tunnel_horizon_rect_1;
	RECT	m_tunnel_horizon_rect_2;
	RECT	m_factory_rect;

	D3DXVECTOR3		m_tunnel_vertical_pos;
	D3DXVECTOR3		m_tunnel_horizon_pos_1;
	D3DXVECTOR3		m_tunnel_horizon_pos_2;
	D3DXVECTOR3		m_factory_pos;
	D3DXVECTOR3		m_vPos2;

public:
	CPicture(void){}
	~CPicture(void){}

	void	MTInit(CTexture t1); // Main_Title
	void	GSInit(CTexture t1, CTexture t2);
	void	GEInit(CTexture t1, CTexture t2);
	void	MAInit(CTexture t1, CTexture t2);
	void	PauseInit(CTexture t1, CTexture t2);

	void	Open_MakerInit(CTexture t1);
	void	Pause_PlayInit(CTexture t1);
	void	Init(CTexture m_ttunnel_horizon_1, CTexture m_ttunnel_horizon_2, CTexture m_ttunnel_vertical, CTexture m_tfactory);
	void	Run(float tick, bool GameOverCheck, float MousePosx, float MousePosy, bool* Pause);
	void	Clear_Run(float MousePosx, float MousePosy,int* Change);

	void	Draw();
	void	Draw_ac();
	void	Draw_inac();
	void	Clear_Draw();

	void	Pause_PlayDraw();

	void	RGInit(CTexture t1); // ReGame
	void	RTInit(CTexture t1); // Return_to_Title
	void	GOInit(CTexture t1); // GameOver
	void	Draw_GameOver();

	void	ClearInit(CTexture t1, CTexture t2, CTexture t3, CTexture t4);

};

class CHelp : public CBaseObject
{
private:
	LPDIRECT3DTEXTURE9 t_Button_None;
	LPDIRECT3DTEXTURE9 t_Button_Hover;
	LPDIRECT3DTEXTURE9 t_Button;

	RECT Button_Rect;

	D3DXVECTOR3 Button_Pos;


public:
	void	Draw();
	void	Init(CTexture t1, CTexture t2, CTexture t3);
	void	Run(float MousePosx, float MousePosy,int *start);

};

class CWaveNumber : public CBaseObject
{
private:
	LPDIRECT3DTEXTURE9 Wave_Second;
	RECT Wave_Second_Rect;
	D3DXVECTOR3 Wave_Second_Pos;

	int First_Wave;
	int Second_Wave;

public:
	void	Draw();
	void	Init(CTexture t1, CTexture t2);
	void	Run(int Wave);

};

