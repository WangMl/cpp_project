#pragma once
class CGameTexture
{
public:
	CGameTexture();
	~CGameTexture();

	LPDIRECT3DTEXTURE9 m_texture = NULL;
	char m_name[120];
	float m_textureWidth = 0;
	float m_textureHeight = 0;
};

