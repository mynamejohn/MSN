#include "Tile.h"


void CTile::Run(float tick, float posX, float posY)
{
	FadeIn(&m_alpha);

	if ((posX - m_vPos.x < 75 && posX - m_vPos.x > 0) && (posY - m_vPos.y < 75 && posY - m_vPos.y>0))
	{
		normal = true;
		if (KeyInput(VK_LBUTTON))
		{
			status = TowerLv1;
		}
		if (KeyInput(VK_RBUTTON))
		{
			status = Normal;
		}
	}
	else
	{
		normal = false;		//기본상태
	}
}

void CTile::Init(CTexture t1, CTexture t2, int i)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	
	status = 0;	//0은 평지

	//타일깔기s
	if(i<16)
		m_vPos = D3DXVECTOR3((float)i * 75, 0, 0);		//정리 필요
	else if (i < 32)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75, 0);
		
	}
	else if (i < 48)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 2, 0);
		
	}
	else if (i < 64)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 3, 0);
	}
	else if (i < 80)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 4, 0);
	}
	else if (i < 96)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 5, 0);
	}
	else if (i < 16*7)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 6, 0);
	}
	else if (i < 16 * 8)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 7, 0);
	}
	else if (i < 16 * 9)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 8, 0);
	}
	else if (i < 16 * 10)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 9, 0);
	}
	else if (i < 16 * 11)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 10, 0);
	}

	else if (i < 16 * 12)
	{
		i %= 16;
		m_vPos = D3DXVECTOR3((float)i * 75, 75 * 11, 0);
	}
	normal = false;		//마우스를 올렸을때 타일의 테두리를 나타내 줌ㅁ
}

void CTile::Draw()
{
	if (m_bDraw)
	{
		switch (status)
		{
		case Normal:

			break;
		case TowerLv1:
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(m_pTexture2, &m_rect, NULL, &m_vPos, m_color);
			m_pSprite->End();
			break;
		}

	}
	if (normal)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
	}
}