#include "Cursor.h"

void Cursor::Init(CTexture t1)
{
	m_pSprite = CDevice::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, t1.GetWidth(), t1.GetHeight() }; //�ؽ����� ũ�⸦ �ڵ����� �޾ƿ�. ���� ��ġ �Է��� �ʿ� ����.

};


void Cursor::Run(float tick)
{
	//FadeIn(&m_alpha);
	GetCursorPos(&pt); // ������� ���콺 ��ǥ ����
	//hWnd = WindowFromPoint(pt); // ���콺 ��ǥ �Ʒ��ִ� �������� �ڵ��� ������
	hWnd = GetActiveWindow(); // ���� Ȱ��ȭ�� �������� �ڵ��� ������ (������â�� �ǳ��� c++â�� ������)
	ScreenToClient(hWnd, &pt); // ��ü ȭ�� ������ Ŀ���� ��ǥ�� �ش� Ŭ���̾�Ʈ(������) �������� ��ǥ�� ��ȯ���ִ� �Լ�
	GetWindowRect(hWnd, &rt);  // �ڵ��� �������� ��ǥ ����

	m_vPos.x = pt.x;
	m_vPos.y = pt.y;

};


void Cursor::Draw()
{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
};