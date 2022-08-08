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

	int first;		//ù��° �ڸ���
	int second;		//�ι�° �ڸ���
	int third;		//����° �ڸ���
	int fourth;		//�׹�° �ڸ���
	int fifth;		//�ټ���° �ڸ���
	int sixth;		//������° �ڸ���


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