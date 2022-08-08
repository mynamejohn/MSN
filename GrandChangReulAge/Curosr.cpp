#include "Cursor.h"

void Cursor::Init(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.

};


void Cursor::Run(float tick)
{
	//FadeIn(&m_alpha);
	GetCursorPos(&pt); // 모니터의 마우스 좌표 얻음
	//hWnd = WindowFromPoint(pt); // 마우스 좌표 아래있는 윈도우의 핸들을 가져옴
	hWnd = GetActiveWindow(); // 현재 활성화된 윈도우의 핸들을 적용함 (윈도우창만 되나봄 c++창은 에러뜸)
	ScreenToClient(hWnd, &pt); // 전체 화면 기준인 커서의 좌표를 해당 클라이언트(윈도우) 기준으로 좌표를 변환해주는 함수
	GetWindowRect(hWnd, &rt);  // 핸들한 윈도우의 좌표 얻음

	m_vPos.x = pt.x;
	m_vPos.y = pt.y;

};


void Cursor::Draw()
{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
};