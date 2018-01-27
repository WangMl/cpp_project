#pragma once
class CUIObject
{
public:
	CUIObject();
	~CUIObject();
	void init(char*_texture, D3DXVECTOR3 _center, D3DXVECTOR3 _pos, DWORD _color);
	void update();
	void render();


	LPD3DXSPRITE m_sprite = NULL;

	bool isCollid = false;
	virtual void MouseOver(){}
	virtual void MouseDown(){}
	virtual void MouseUp(){}
	virtual void MouseOut(){}

	char m_name[120];
	D3DXVECTOR3 m_center;
	D3DXVECTOR3 m_position;
	DWORD m_color=0xffffffff;
	float m_width = 0;
	float m_height = 0;
	MSG m_msg;
	LPDIRECT3DTEXTURE9 m_texture = nullptr;

	bool m_isShow = true; ///是否显示界面
};

