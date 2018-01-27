#pragma once
class CIntroduce
{
public:
	CIntroduce();
	~CIntroduce();
	void init(char*_nameBack);
	bool update();
	void render();

	void showText();

	LPD3DXSPRITE m_sprite = NULL;
	LPDIRECT3DTEXTURE9 m_textureBack = NULL;
	
	DWORD m_color = 0xffffffff;

	float m_deltaTime = 0;
	int m_alpha = 0;
};

