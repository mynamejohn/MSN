#include "BaseObject.h"

CBaseObject::CBaseObject()
{
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_bDraw = true;
	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
}
CBaseObject::~CBaseObject(void)
{

}

void CBaseObject::Animation(float *timer, int *aniNum, int width, int height, int rowNum, int lastNum, float delayTime)
{
	if (*timer > delayTime)
	{
		m_rect.left = width * (*aniNum);
		m_rect.right = width * (*aniNum + 1);
		
		(*aniNum)++;
		*timer = 0;
		*aniNum %= lastNum;
	}
}

void CBaseObject::FadeIn(unsigned int *alpha)
{
	if (*alpha < 255)
		(*alpha) += 15;

	if (*alpha >= 255)
		*alpha = 255;
						//일시적으로 지움
	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
}