#include "stdafx.h"
#include "GameAnimation.h"


CGameAnimation::CGameAnimation()
{
	ZeroMemory(m_mydir, sizeof(m_mydir));
	ZeroMemory(m_posbegin, sizeof(m_posbegin));
	ZeroMemory(m_posend, sizeof(m_posend));
}

CGameAnimation::~CGameAnimation()
{
}

void CGameAnimation::init(char*INIname)
{
	char temp[100] = {};
	GetPrivateProfileString("particle", "m_poolSize", "error", temp, 100, INIname);
	m_poolSize = atoi(temp);
	GetPrivateProfileString("particle", "m_minlife", "error", temp, 100, INIname);
	m_minlife = atoi(temp);
	GetPrivateProfileString("particle", "m_maxlife", "error", temp, 100, INIname);
	m_maxlife = atoi(temp);
	GetPrivateProfileString("particle", "m_minsize", "error", temp, 100, INIname);
	m_minsize = atoi(temp);
	GetPrivateProfileString("particle", "m_maxsize", "error", temp, 100, INIname);
	m_maxsize = atoi(temp);
	GetPrivateProfileString("particle", "m_minspeed", "error", temp, 100, INIname);
	m_minspeed = atoi(temp);
	GetPrivateProfileString("particle", "m_maxspeed", "error", temp, 100, INIname);
	m_maxspeed = atoi(temp);
	GetPrivateProfileString("particle", "m_minangle", "error", temp, 100, INIname);
	m_minangle = atoi(temp);
	GetPrivateProfileString("particle", "m_maxangle", "error", temp, 100, INIname);
	m_maxangle = atoi(temp);
	GetPrivateProfileString("particle", "m_gravity", "error", temp, 100, INIname);
	m_gravity = atof(temp);
	GetPrivateProfileString("particle", "dirX", "error", temp, 100, INIname);
	m_mydir.x = atoi(temp);
	GetPrivateProfileString("particle", "dirY", "error", temp, 100, INIname);
	m_mydir.y = atoi(temp);
	m_mydir.z = 0;


	m_posbegin = D3DXVECTOR3(0, 0, 0);
	m_posend.x = m_posbegin.x + 60;
	m_posend.y = m_posbegin.y + 40;
	m_posend.z = 0;

	D3DXVec3Normalize(&m_mydir, &m_mydir);


	D3DXCreateSprite(CDirectManager::instance()->getDevice(), &m_sprite);
	D3DXCreateTextureFromFile(CDirectManager::instance()->getDevice(),"starSmall.png", &m_texture);
	for (int i = 0; i < m_poolSize; i++)
	{
		tagParticle par;
		par.lifeTime = rangeFloat(m_minlife, m_maxlife);
		par.currentTime = -rangeFloat(0, 10)*0.01f;
		par.parSize = rangeFloat(m_minsize, m_maxsize);
		par.speed = rangeFloat(m_minspeed, m_maxspeed);
		par.gravity = m_gravity;
		par.pos.x = rangeFloat(m_posbegin.x, m_posend.x);
		par.pos.y = rangeFloat(m_posbegin.y, m_posend.y);
		par.pos.z = 0;
		par.dir = m_mydir;
		par.angle = rangeFloat(m_minangle, m_maxangle);
		m_array_particle.push_back(par);
	}
}
float CGameAnimation::rangeFloat(float minNum, float maxNum)
{
	if (maxNum - minNum == 0)
	{
		return minNum;
	}
	return (rand() % (int)(maxNum - minNum)) + minNum;
}
void CGameAnimation::update(D3DXVECTOR3 _pos)
{
	for (int i = 0; i < m_array_particle.size(); i++)
	{
		m_array_particle[i].currentTime += CDirectManager::instance()->m_deltaTime;
		if (m_array_particle[i].currentTime >= 0)
		{
			m_array_particle[i].pos.x = rangeFloat(_pos.x,_pos.x+20);
			m_array_particle[i].pos.y = rangeFloat(_pos.y, _pos.y+25); 
			m_array_particle[i].pos.x += m_array_particle[i].speed*m_array_particle[i].dir.x*CDirectManager::instance()->m_deltaTime;
			m_array_particle[i].gravity += 0.01f;
			m_array_particle[i].pos.y += m_array_particle[i].speed*m_array_particle[i].dir.y*CDirectManager::instance()->m_deltaTime
				+ m_array_particle[i].gravity;
		}
	}
}
void CGameAnimation::render(D3DXVECTOR3 _pos)
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND); 
	for (int i = 0; i < m_array_particle.size(); i++)
	{
		if (m_array_particle[i].currentTime >= 0 && m_array_particle[i].currentTime <= m_array_particle[i].lifeTime)
		{
			D3DXMATRIXA16 mat, mat1, mat2, mat3;
			D3DXMatrixScaling(&mat1, m_array_particle[i].parSize, m_array_particle[i].parSize, m_array_particle[i].parSize);
			D3DXMatrixRotationZ(&mat2, (D3DX_PI / 180)*m_array_particle[i].angle);
			D3DXMatrixTranslation(&mat3, m_array_particle[i].pos.x, m_array_particle[i].pos.y, m_array_particle[i].pos.z);
			mat = mat1*mat2*mat3;
			m_sprite->SetTransform(&mat);
			m_sprite->Draw(m_texture, 0, 0,&_pos, 0xffffffff);
		}
	}
	m_sprite->End();
}