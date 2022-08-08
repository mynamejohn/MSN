#pragma once
#include "BaseObject.h"
#include <math.h>
#include "Monster.h"


class CTile :
	public CBaseObject
{
private:
	int status;
	LPDIRECT3DTEXTURE9	m_pTower;
	LPDIRECT3DTEXTURE9	m_pTower_1;
	LPDIRECT3DTEXTURE9	m_pTower_2;
	LPDIRECT3DTEXTURE9	m_pTower_3;
	LPDIRECT3DTEXTURE9	m_pTower_4;
	LPDIRECT3DTEXTURE9	m_pTower_5;
	LPDIRECT3DTEXTURE9	m_pTower_6;

	LPDIRECT3DTEXTURE9	m_pTower_1_Stand;
	LPDIRECT3DTEXTURE9	m_pTower_2_Stand;
	LPDIRECT3DTEXTURE9	m_pTower_3_Stand;
	LPDIRECT3DTEXTURE9	m_pTower_4_Stand;
	LPDIRECT3DTEXTURE9	m_pTower_5_Stand;
	LPDIRECT3DTEXTURE9	m_pTower_6_Stand;









	RECT	MouseHover_rect;
		//타일의 상태 (평지, 길, 타워)
	
	bool AttackSt;

	float rect_left;
	float rect_top;
	float rect_right;
	float rect_bottom;

	float Tower_tick;
	float Tower_first_time;

	float Tile_tick;
	float Tile_first_time;

	float distance; //충돌처리를 위한 적과 건물의 거리

	float AttackDelay;		//공격 딜레이
	int ani;
	int *P_ani;

	float *p_m_rect_left;
	float *p_m_rect_right;
public:


	void Setani(int anime) 
	{
		*P_ani = anime; 
	}
	void TheEnd()
	{
		
	}
	int	Getani() { return ani; };

	
	CTile(void){}
	~CTile(void){}
	int level;
	bool detect;
	D3DXVECTOR3 CollPos;			//충돌처리를 위한 좌표값
	float x;
	float y;
	float d;
	int abc;
	int check;
	bool MouseHover;

	void	Init(CTexture Hover, CTexture Tower_1, CTexture Tower_2, CTexture Tower_3,
		CTexture Tower_4, CTexture Tower_5, CTexture Tower_6, CTexture Tower_1_Stand, CTexture Tower_2_Stand, CTexture Tower_3_Stand,
		CTexture Tower_4_Stand, CTexture Tower_5_Stand ,int i, int j);
	void	Run(float tick, float posX, float posY, float* resourcesnum, int SelectedTower, CSound* sound);
	void	Draw();


	int checkx;
	int checky;
	int		GetStatus()	{ return status; }

	
	int 	Getcheckx() { return checkx; }
	int 	Getchecky() { return checky; }
	float 	Getdistance() { return distance; };
	void	SetStage1(int i, int j);

	bool*	GetAttackSt() { return &AttackSt; };
	void	SetAttackSt(bool st){ AttackSt = st; };

	void	Collision(int* m_Hp, D3DXVECTOR3 MonsterPos,float tick);	//충돌처리를위한함수
	void	DeCollision(float tick);

	bool	Check(D3DXVECTOR3 MonsterPos, float tick);

	void	Spriting();
};
