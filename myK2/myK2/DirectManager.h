#pragma once
class CDirectManager
{
public:
	CDirectManager();
	~CDirectManager();

	///��ȡ��Ϣ
	void getMessage(HWND _hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	///�����Կ�����
	void beginRender();
	///��������
	void endRender();
	///�����ε���Ϣ
	void clearMsg();
	///��ĳ�������ϴ��������Կ�
	HRESULT createDevice(HWND _WND);
	///����һ����Ϣ��¼����õ���Ϣ
	MSG m_msg;
	///����һ�������Ĵ���
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

