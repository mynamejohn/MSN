#include "texture.h"
#include "device.h"

void CTexture::Init(LPCTSTR	lpszFileName)
{
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(lpszFileName, &info);

	m_Width = info.Width;
	m_Height = info.Height;

	D3DXCreateTextureFromFileEx(CDevice::GetDevice(), lpszFileName, m_Width, m_Height,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &m_pTexture);
}

void CTexture::CleanUp()
{
	SAFE_RELEASE(m_pTexture);
}