#include "Background.h"

void CBackground::Run(float tick)
{
}

void CBackground::Init(CTexture m_tBackground)
{

	m_pSprite = CDevice::GetSprite();
	m_pTexture = m_tBackground.GetTexture();
	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, m_tBackground.GetWidth(), m_tBackground.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);
}

void CBackground::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
	}
}