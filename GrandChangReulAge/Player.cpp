#include "Player.h"


void CPlayer::Init(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;

	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() };	

};
void CPlayer::Run(float tick)
{


}

void CPlayer::Draw()
{

}