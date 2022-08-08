#include "device.h"

CDevice::~CDevice()
{
	SAFE_RELEASE(m_pd3dDevice);
	SAFE_RELEASE(m_pD3D);
}

CDevice* CDevice::GetInstance()
{
	static CDevice Instance;
	return &Instance;
}


HRESULT CDevice::Init(HWND hWnd, UINT Width, UINT Height)
{
	// Init�� ���ڸ� Ŭ���� ���� ���ڷ� �����Ѵ�.
	m_hWnd = hWnd;
	m_Width = Width;
	m_Height = Height;

	// ����̽��� �����ϱ����� D3D��ü ����
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// ����̽��� ������ ����ü
	D3DPRESENT_PARAMETERS d3dpp = { m_Width, m_Height, D3DFMT_A8R8G8B8, 1,
		D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_DISCARD,
		m_hWnd, true, TRUE, D3DFMT_D24S8, 0,
		D3DPRESENT_RATE_DEFAULT, D3DPRESENT_INTERVAL_DEFAULT };

	/// ����̽� ����
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	D3DXCreateSprite(m_pd3dDevice, &m_pSprite);

	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);

	return S_OK;
}