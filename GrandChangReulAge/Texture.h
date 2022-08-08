#pragma once
#include "define.h"
#include "Device.h"


class CTexture
{
private:
	LPDIRECT3DTEXTURE9	m_pTexture;

	unsigned int	m_Width;
	unsigned int	m_Height;

public:
	CTexture(void){}
	~CTexture(void){}

	void	Init(LPCTSTR	lpszFileName);
	void	CleanUp();

	LPDIRECT3DTEXTURE9	GetTexture(void) { return m_pTexture; }

	unsigned int	GetWidth()	{ return m_Width; };
	unsigned int	GetHeight()	{ return m_Height; };
};