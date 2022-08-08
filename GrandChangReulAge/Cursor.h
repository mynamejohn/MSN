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
	HWND hWnd; //커서용 핸들
	POINT	pt; // 커서용 마우스 좌표
	RECT	rt; // 커서용 윈도우 좌표
};
