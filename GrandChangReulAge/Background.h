#pragma once
#include "BaseObject.h"


class CBackground :
	public CBaseObject
{
	LPDIRECT3DTEXTURE9 m_pTitle_Menu;

public:
	CBackground(void){}
	~CBackground(void){}

	int choice;

	void	Init(CTexture m_tBackground);
	void	Run(float tick);
	void	Draw();
};
