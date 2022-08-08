#include "Resources.h"

void CResources::Init(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(120, 10, 0);

	m_rect2 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos2 = D3DXVECTOR3(75, 10, 0);

	m_rect3 = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos3 = D3DXVECTOR3(30, 10, 0);


	p_recources = 20;
}

void CResources::Run(float m_StageTime)
{
	first = (int)p_recources % 10;
	second = ((int)(p_recources / 10) % 10);
	third = (int)p_recources / 100;

	m_rect.left = 60 * (first);
	m_rect.right = 60 * (first + 1);

	m_rect2.left = 60 * (second);
	m_rect2.right = 60 * (second + 1);

	m_rect3.left = 60 * (third);
	m_rect3.right = 60 * (third + 1);
}

void CResources::Draw()
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
	}
}