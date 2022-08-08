#include "rank.h"


Crank::Crank()
{
}


Crank::~Crank()
{
}


void Crank::Init(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(1535, 2, 0);

	m_rect2 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos2 = D3DXVECTOR3(1494, 2, 0);

	m_rect3 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos3 = D3DXVECTOR3(1453, 2, 0);

	m_rect4 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos4 = D3DXVECTOR3(1412, 2, 0);

	m_rect5 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos5 = D3DXVECTOR3(1371, 2, 0);

	m_rect6 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos6 = D3DXVECTOR3(1330, 2, 0);

	check = false;

	
	

}


void Crank::Run(float m_StageTime)
{
	m_rect.left = 50 * (first);
	m_rect.right = 50 * (first + 1);

	m_rect2.left = 50 * (second);
	m_rect2.right = 50 * (second + 1);

	m_rect3.left = 50 * (third);
	m_rect3.right = 50 * (third + 1);

	m_rect4.left = 50 * (fourth);
	m_rect4.right = 50 * (fourth + 1);

	m_rect5.left = 50 * (fifth);
	m_rect5.right = 50 * (fifth + 1);

	m_rect6.left = 50 * (sixth);
	m_rect6.right = 50 * (sixth + 1);
}

void Crank::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect2, NULL, &m_vPos2, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect3, NULL, &m_vPos3, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect4, NULL, &m_vPos4, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect5, NULL, &m_vPos5, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect6, NULL, &m_vPos6, m_color);
		m_pSprite->End();
	}
}

void Crank::compare()
{
	int temp;
	if (thirdrankscore > secondrankscore)
	{
		temp = secondrankscore;


	}



}

void Crank::OutputLoad()
{
	ifstream inFile;
	inFile.open("score.txt");



}


void Crank::OutputSave(int a)
{
	ofstream fout,score;
	if (check == false)
	{
		fout.open("rank.txt",ios::app);
		score.open("Score.txt", ios::app);
		check = true;
	}
	first = a % 10;
	second = ((a / 10) % 10);
	third = ((a / 100) % 10);
	fourth = ((a / 1000) % 10);
	fifth = ((a / 10000) % 10);
	sixth = a / 100000;

	thirdrankscore = a;

	fout << sixth << fifth << fourth << third << second << first << endl;
	score << firstrankscore << endl;

}

