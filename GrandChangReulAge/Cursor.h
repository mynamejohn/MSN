#pragma once
#include "BaseObject.h"


class Cursor :
	public CBaseObject
{
public:
	Cursor(void){}
	~Cursor(void){}

	void Init(CTexture t1);
	void Run(float tick);
	void Draw();
	
	float getMousePosx()	{ return m_vPos.x; };
	float getMousePosy()	{ return m_vPos.y; };

private:
	HWND hWnd; //Ŀ���� �ڵ�
	POINT	pt; // Ŀ���� ���콺 ��ǥ
	RECT	rt; // Ŀ���� ������ ��ǥ
};
