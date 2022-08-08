#pragma once
#include "PauseScreen.h"
void CPause::Init(CTexture t1, CTexture t2, CTexture t3, CTexture t4)
{
	ChangeChk = false;

	m_pSprite = CDevice::GetSprite();
	
	Menu = t1.GetTexture();
	Option = t2.GetTexture();
	m_pTexture = Menu;

	Return = t4.GetTexture();
	Continue = t4.GetTexture();

	Point = t3.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	Point_Rect = { 0, 0, t3.GetWidth(), t3.GetWidth() };

	Return_Rect = { 0, 0, 291, 116 };
	Continue_Rect = { 0, 116, 291, 232 };

	m_vPos = D3DXVECTOR3(0, 0, 0);
	Point_Pos = D3DXVECTOR3(734, 383, 0);
	Point_Pos2 = D3DXVECTOR3(734, 453, 0);

	Return_Pos = D3DXVECTOR3(650, 335, 0);
	Continue_Pos = D3DXVECTOR3(650, 451, 0);

	BackSoundchk = true;
	EffectSoundchk = true;

	m_bDraw = false;
	PauseorSet = 0;
};



void CPause::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		if (PauseorSet == 0)
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(Return, &Return_Rect, NULL, &Return_Pos, m_color);
			m_pSprite->End();

			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(Continue, &Continue_Rect, NULL, &Continue_Pos, m_color);
			m_pSprite->End();
		}

		if (PauseorSet == 1)
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(Point, &Point_Rect, NULL, &Point_Pos, m_color);
			m_pSprite->End();

			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(Point, &Point_Rect, NULL, &Point_Pos2, m_color);
			m_pSprite->End();
		}
	}

};



void CPause::Run(bool* Pausechk, float MousePosx, float MousePosy)
{
	if (*Pausechk)
	{
		m_bDraw = true;

		switch (PauseorSet)
		{
		case 0:
			m_pTexture = Menu;
			if ((MousePosx > 450 && MousePosx < 515) && (MousePosy>425 && MousePosy < 490))
			{
				if (KeyInput(VK_LBUTTON))
				{
					PauseorSet = 1;
				}
			}
			
			if ((MousePosx>666 && MousePosx < 920) && (MousePosy>350 && MousePosy < 430))
			{
				Return_Rect = { 291, 0, 582, 116 };
				if (KeyInput(VK_LBUTTON))
				{
					ChangeChk = true;
				}
				
			}
			else
				Return_Rect = { 0, 0, 291, 116 };

			if ((MousePosx>666 && MousePosx < 920) && (MousePosy>460 && MousePosy < 540))
			{
				Continue_Rect = { 291, 116, 582, 232 };
				if (KeyInput(VK_LBUTTON))
				{
					*Pausechk = false;
				}
			}
			else
				Continue_Rect = { 0, 116, 291, 232 };
			break;
		case 1:
			m_pTexture = Option;
			if (BackSoundchk)
			{
				Point_Pos = D3DXVECTOR3(734, 383, 0);
				if ((MousePosx>850 && MousePosx < 955) && (MousePosy>400 && MousePosy < 434))
					if (KeyInput(VK_LBUTTON))
						BackSoundchk = false;
			}
			else
			{
				Point_Pos = D3DXVECTOR3(904, 383, 0);
				if ((MousePosx>690 && MousePosx < 785) && (MousePosy>400 && MousePosy < 434))
					if (KeyInput(VK_LBUTTON))
						BackSoundchk = true;
			}

			if (EffectSoundchk)
			{
				Point_Pos2 = D3DXVECTOR3(734, 453, 0);
				if ((MousePosx>850 && MousePosx < 955) && (MousePosy>470 && MousePosy < 504))
					if (KeyInput(VK_LBUTTON))
						EffectSoundchk = false;

			}
			else
			{
				Point_Pos2 = D3DXVECTOR3(904, 453, 0);
				if ((MousePosx>690 && MousePosx < 785) && (MousePosy>470 && MousePosy < 504))
					if (KeyInput(VK_LBUTTON))
						EffectSoundchk = true;

			}
			if ((MousePosx > 450 && MousePosx < 515) && (MousePosy>335 && MousePosy < 395))
			{
				if (KeyInput(VK_LBUTTON))
				{
					PauseorSet = 0;

				}
			}


			break;
		default:
			break;
		}
	}
	else
	{
		m_bDraw = false;
		PauseorSet = 0;
	}

}
