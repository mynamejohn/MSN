#include "Picture.h"

//Pictures는 그냥 그림 띄우는데 쓰는 클래스
//움직이지 않고 아무 일도 일어나지 않는 그림은 다 이 클래스 사용.
//ex) 메인메뉴 배경, UI 장식 등

void CPicture::Run(float tick, bool GameOverCheck, float MousePosx, float MousePosy,bool* Pause)
{
	if (GameOverCheck == false)
	{

		if (1500 <= MousePosx && MousePosx < 1600 && 800 <= MousePosy && MousePosy < 900)
		{
			m_rect.left = 96.0;
			m_rect.right = 192.0;

			if (KeyInput(VK_LBUTTON))
			{
				if (*Pause == false)
				{
					m_rect.top = 92.0;
					m_rect.bottom = 184.0;
					*Pause = true;
				}
				else
				{
					m_rect.top = 0;
					m_rect.bottom = 92.0;
					*Pause = false;
				}
			}
		}
		else
		{
			m_rect.left = 0;
			m_rect.right = 96.0;
		}
		if (KeyInput(VK_ESCAPE))
		{
			if (*Pause == false)
			{
				*Pause = true;
			}
			else
			{
				*Pause = false;
			}
		}
	}
};

void CPicture::Init(CTexture m_ttunnel_horizon_1, CTexture m_ttunnel_horizon_2, CTexture m_ttunnel_vertical, CTexture m_tfactory)
{
	m_pSprite = CDevice::GetSprite();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, m_ttunnel_horizon_1.GetWidth(), m_ttunnel_horizon_1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(700, 0, 0);

	m_tunnel_vertical = m_ttunnel_vertical.GetTexture();
	m_tunnel_horizon_1 = m_ttunnel_horizon_1.GetTexture();
	m_tunnel_horizon_2 = m_ttunnel_horizon_2.GetTexture();
	m_factory = m_tfactory.GetTexture();

	m_tunnel_vertical_rect = { 0, 0, m_ttunnel_vertical.GetWidth(), m_ttunnel_vertical.GetHeight() };
	m_tunnel_horizon_rect_1 = { 0, 0, m_ttunnel_horizon_1.GetWidth(), m_ttunnel_horizon_1.GetHeight() };
	m_tunnel_horizon_rect_2 = { 0, 0, m_ttunnel_horizon_2.GetWidth(), m_ttunnel_horizon_2.GetHeight() };
	m_factory_rect = { 0, 0, m_tfactory.GetWidth(), m_tfactory.GetHeight() };

	m_tunnel_vertical_pos = D3DXVECTOR3(1228, 364, 0);
	m_tunnel_horizon_pos_1 = D3DXVECTOR3(95, 495, 0);
	m_tunnel_horizon_pos_2 = D3DXVECTOR3(1195, 532, 0);
	m_factory_pos = D3DXVECTOR3(640, 0, 0);
}

void CPicture::MTInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(550, 50, 0);
}
void CPicture::GSInit(CTexture t1, CTexture t2)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(670, 490, 0);
}

void CPicture::MAInit(CTexture t1, CTexture t2)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(670, 576, 0);
}

void CPicture::GEInit(CTexture t1, CTexture t2)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(670, 663, 0);
}

void CPicture::Open_MakerInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);

}

void CPicture::Pause_PlayInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 92, 96, 184 }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(1500, 800, 0);
}

void CPicture::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tunnel_vertical, &m_tunnel_vertical_rect, NULL, &m_tunnel_vertical_pos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tunnel_horizon_1, &m_tunnel_horizon_rect_1, NULL, &m_tunnel_horizon_pos_1, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_tunnel_horizon_2, &m_tunnel_horizon_rect_2, NULL, &m_tunnel_horizon_pos_2, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_factory, &m_factory_rect, NULL, &m_factory_pos, m_color);
		m_pSprite->End();
	}
}

void CPicture::Draw_ac()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();
}

void CPicture::Draw_inac()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(m_pTexture2, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();
}


void CPicture::Pause_PlayDraw()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();
}



void CPicture::RGInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(460, 615, 0);
}

void CPicture::RTInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(875, 615, 0);
}

void CPicture::GOInit(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);
}

void CPicture::Draw_GameOver()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();
}

void CPicture::ClearInit(CTexture t1, CTexture t2, CTexture t3, CTexture t4)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	m_pTexture2 = t2.GetTexture();
	m_pTexture3 = t3.GetTexture();
	m_pTexture4 = t4.GetTexture();

	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);

	t_Regame = m_pTexture;
	t_Return = m_pTexture3;

	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	m_vPos = D3DXVECTOR3(863, 423, 0);
	m_vPos2 = D3DXVECTOR3(1170, 423, 0);

}
void CPicture::Clear_Run(float MousePosx, float MousePosy, int* Change)
{
	if ((MousePosx > 870 && MousePosx < 1140) && (MousePosy>430 && MousePosy < 520))
	{
		t_Regame = m_pTexture2;
		if (KeyInput(VK_LBUTTON))
		{
			*Change = 1;
		}
	}
	else
		t_Regame = m_pTexture;

	if ((MousePosx > 1177 && MousePosx < 1450) && (MousePosy>430 && MousePosy < 520))
	{
		t_Return = m_pTexture4;
		if (KeyInput(VK_LBUTTON))
		{
			*Change = 2;
		}
	}
	else
		t_Return = m_pTexture3;

}
void CPicture::Clear_Draw()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(t_Regame, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(t_Return, &m_rect, NULL, &m_vPos2, m_color);
	m_pSprite->End();
}


void	CHelp::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(t_Button, &Button_Rect, NULL, &Button_Pos, m_color);
		m_pSprite->End();
	}
}
void	CHelp::Init(CTexture t1, CTexture t2, CTexture t3)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	t_Button_None = t2.GetTexture();
	t_Button_Hover = t3.GetTexture();
	t_Button = t_Button_None;

	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);


	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	Button_Rect = { 0, 0, t2.GetWidth(), t2.GetHeight() };

	m_vPos = D3DXVECTOR3{ 0, 0, 0 };
	Button_Pos = D3DXVECTOR3{ 1000, 630, 0 };

}
void	CHelp::Run(float MousePosx, float MousePosy,int* start)
{
	if (*start == 0)
	{
		m_bDraw = true;
	}
	if ((MousePosx > 1020 && MousePosx < 1227) && (MousePosy>650 && MousePosy < 710))
	{
		t_Button = t_Button_Hover;
		if (KeyInput(VK_LBUTTON))
		{
			m_bDraw = false;
			*start = 1;
		}
	}
	else
		t_Button = t_Button_None;

}



void	CWaveNumber::Draw()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
	m_pSprite->End();

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	m_pSprite->Draw(Wave_Second, &Wave_Second_Rect, NULL, &Wave_Second_Pos, m_color);
	m_pSprite->End();

}
void	CWaveNumber::Init(CTexture t1, CTexture t2)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();
	Wave_Second = t2.GetTexture();

	m_color = D3DCOLOR_ARGB( 255, 255, 255, 255) ;
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() };
	Wave_Second_Rect = { 0, 0, t2.GetWidth(), t2.GetHeight() };

	m_vPos = D3DXVECTOR3(245, 848, 0);
	Wave_Second_Pos = D3DXVECTOR3(225, 848, 0); 
	First_Wave = 0;
	Second_Wave = 0;
}
void	CWaveNumber::Run(int Wave)
{
	First_Wave = (Wave +1) % 10;
	Second_Wave = (Wave + 1) / 10;

	m_rect.left = First_Wave * 45;
	m_rect.right = (First_Wave + 1) * 45;

	Wave_Second_Rect.left = Second_Wave * 45;
	Wave_Second_Rect.right = (Second_Wave + 1) * 45;

}
