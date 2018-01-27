#include "stdafx.h"
#include "DirectManager.h"


CDirectManager::CDirectManager()
{
}


CDirectManager::~CDirectManager()
{
}

///获取信息
void CDirectManager::getMessage(HWND _hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	m_msg.hwnd = _hwnd;
	m_msg.message = message;
	m_msg.wParam = wParam;
	m_msg.lParam = lParam;
}
///利用显卡绘制
void CDirectManager::beginRender()
{
	m_device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(25, 25, 25), 1.0f, 0);
	SUCCEEDED(m_device->BeginScene());
}
///结束绘制
void CDirectManager::endRender()
{
	m_device->EndScene();
	m_device->Present(NULL,NULL,NULL,NULL);
}
///清理本次的信息
void CDirectManager::clearMsg()
{
	ZeroMemory(&m_msg, sizeof(m_msg));
}
///在某个窗口上创建他的显卡
HRESULT CDirectManager::createDevice(HWND _WND)
{
	if (NULL == (m_direct3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_DONOTWAIT;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	if (FAILED(m_direct3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _WND,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,&m_device)))
	{
		return E_FAIL;
	}
	D3DXCreateSprite(m_device,&m_sprite);
	m_hwnd = _WND;
	return S_OK;
}