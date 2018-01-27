#pragma once
class CCellPosPool
{
public:
	CCellPosPool();
	~CCellPosPool();
	void init(char*_cellTextureFile);
	struct tagPos
	{
		float posx;
		float posy;
	};
	vector<tagPos*>m_array_pos;

	static CCellPosPool*instance()
	{
		static CCellPosPool temp;
		return &temp;
	}
};

