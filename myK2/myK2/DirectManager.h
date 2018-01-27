#pragma once
class CDirectManager
{
public:
	CDirectManager();
	~CDirectManager();

	///获取信息
	void getMessage(HWND _hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	///利用显卡绘制
	void beginRender();
	///结束绘制
	void endRender();
	///清理本次的信息
	void clearMsg();
	///在某个窗口上创建他的显卡
	HRESULT createDevice(HWND _WND);
	///创建一个消息记录所获得得消息
	MSG m_msg;
	///创建一个操作的窗口
	HWND m_hwnd;

	LPD3DXSPRITE m_sprite = NULL;
	LPD3DXSPRITE getSprite()
	{
		return m_sprite;
	}

	LPDIRECT3D9 m_direct3d = NULL;
	

	LPDIRECT3DDEVICE9 m_device = NULL;
	LPDIRECT3DDEVICE9 getDevice()
	{
		return m_device;
	}

	float m_deltaTime = 0;
	static CDirectManager* instance()
	{
		static CDirectManager directManager;
		return  &directManager;
	}
};

