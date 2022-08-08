#pragma once
#include "BaseObject.h"

class Cscore : public CBaseObject
{
private:
	int Score;

	RECT			m_rect2;
	D3DXVECTOR3		m_vPos2;

	RECT			m_rect3;
	D3DXVECTOR3		m_vPos3;

	RECT			m_rect4;
	D3DXVECTOR3		m_vPos4;

	RECT			m_rect5;
	D3DXVECTOR3		m_vPos5;

	RECT			m_rect6;
	D3DXVECTOR3		m_vPos6;

	int first;		//첫번째 자릿수
	int second;		//두번째 자릿수
	int third;		//세번째 자릿수
	int fourth;		//네번째 자릿수
	int fifth;		//다섯번째 자릿수
	int sixth;		//여섯번째 자릿수


public:
	Cscore(void){}
	~Cscore(void){}

	void Init(CTexture t1);
	void Run(float m_StageTime);
	void Draw();
	void GameOverDraw();
	void Clear_Init(CTexture t1,int total_score);

	int* GetScore()	{ return &Score; }
	int Get_totale_Score() { return Score;}
	void SetScore(int score) { Score = score; }
};