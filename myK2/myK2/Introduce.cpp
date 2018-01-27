#include "stdafx.h"
#include "Introduce.h"


CIntroduce::CIntroduce()
{
}


CIntroduce::~CIntroduce()
{
}

void CIntroduce::init(char*_nameBack)
{
	m_sprite = CDirectManager::instance()->getSprite();
	D3DXCreateTextureFromFile(CDirectManager::instance()->getDevice(), _nameBack, &m_textureBack);
}
bool CIntroduce::update()
{
	m_deltaTime += CDirectManager::instance()->m_deltaTime;
	if (m_deltaTime >= 0.1f)
	{
		m_alpha+= 5;
		m_deltaTime = 0;
	}
	if (m_alpha >= 255)
	{
		return true;
	}
	return false;

}
void CIntroduce::render()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_color = 0x00ffffff | (m_alpha<<24);
	m_sprite->Draw(m_textureBack, 0, 0, 0, m_color);
	m_sprite->End();
}
