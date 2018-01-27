#pragma once
class CGameAnimation
{
public:
	CGameAnimation();
	~CGameAnimation();

	void init(char*INIname);
	void update(D3DXVECTOR3 _pos);
	void render(D3DXVECTOR3 _pos);
	float rangeFloat(float minNum, float maxNum);

	LPD3DXSPRITE m_sprite = NULL;
	LPDIRECT3DTEXTURE9 m_texture = NULL;

	///∑¢…‰∆˜µƒ Ù–‘
	int m_poolSize = 0;
	float m_minlife = 0; float m_maxlife = 0;
	float m_minsize = 0; float m_maxsize = 0;
	float m_minspeed = 0; float m_maxspeed = 0;
	float m_gravity = 0;
	float m_minangle = 0; float m_maxangle = 0;
	D3DXVECTOR3 m_mydir;
	D3DXVECTOR3 m_posbegin;
	D3DXVECTOR3 m_posend;


	struct tagParticle
	{
		float lifeTime = 0;
		float currentTime = 0;
		float parSize = 0.5;
		float speed = 50;
		float gravity = 0.2f;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 dir;
		float angle = 0;
	};
	vector<tagParticle>m_array_particle;
	float m_waitingDeltaTime;

	
};