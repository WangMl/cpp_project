#pragma once
class CCellTexturePool
{
public:
	CCellTexturePool();
	~CCellTexturePool();
	void init(char*_cellTextureFile);
	LPDIRECT3DTEXTURE9 getTextureByName(char*name);
	float getWidth(char*name);
	float getHeight(char*name);
	void clearPool();
	vector<CCellTexture*>m_array_cell;
	

	static CCellTexturePool*instance()
	{
		static CCellTexturePool temp;
		return &temp;
	}
};
