#pragma once
class CGameTexturePool
{
public:
	CGameTexturePool();
	~CGameTexturePool();
	vector<CGameTexture*>m_array_texture;
	void init(char*_poolFileName);
	LPDIRECT3DTEXTURE9 getTextureByName(char*name);
	float getWidth(char*name);
	float getHeight(char*name);
	void clearPool();
	static CGameTexturePool*instance()
	{
		static CGameTexturePool texturePool;
		return &texturePool;
	}
};

