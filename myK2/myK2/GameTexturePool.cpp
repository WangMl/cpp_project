#include "stdafx.h"
#include "GameTexturePool.h"


CGameTexturePool::CGameTexturePool()
{
}
CGameTexturePool::~CGameTexturePool()
{
}
void CGameTexturePool::init(char*_poolFileName)
{
	TiXmlDocument doc(_poolFileName);
	if (!doc.LoadFile())
	{
		MessageBox(NULL, "Í¼Æ¬×ÊÔ´³Ø¼ÓÔØÊ§°Ü", "warning", MB_OK);
	}
	TiXmlElement*root = doc.FirstChildElement("TEXTURE");
	TiXmlElement*ele = root->FirstChildElement("BACKtexture");
	for (; ele != NULL; ele = ele->NextSiblingElement())
	{
		CGameTexture*temp = new CGameTexture;
		D3DXIMAGE_INFO info;
		D3DXCreateTextureFromFileEx(CDirectManager::instance()->getDevice(),
			ele->Attribute("path"), D3DX_FROM_FILE, D3DX_FROM_FILE, 0, D3DUSAGE_DYNAMIC,
			D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, D3DX_FILTER_LINEAR,
			0, 0x0, &info, 0, &temp->m_texture);
		strcpy_s(temp->m_name, ele->Attribute("name"));
		temp->m_textureHeight = (float)info.Height;
		temp->m_textureWidth = (float)info.Width;
		m_array_texture.push_back(temp);
	}
}
LPDIRECT3DTEXTURE9 CGameTexturePool::getTextureByName(char*name)
{
	for (int i = 0; i < m_array_texture.size(); i++)
	{
		if (0 == strcmp(name, m_array_texture[i]->m_name))
		{
			return m_array_texture[i]->m_texture;
		}
	}
	return 0;
}
float CGameTexturePool::getWidth(char*name)
{
	for (int i = 0; i < m_array_texture.size(); i++)
	{
		if (0 == strcmp(name, m_array_texture[i]->m_name))
		{
			return m_array_texture[i]->m_textureWidth;
		}
	}
	return 0;
}
float CGameTexturePool::getHeight(char*name)
{
	for (int i = 0; i < m_array_texture.size(); i++)
	{
		if (0 == strcmp(name, m_array_texture[i]->m_name))
		{
			return m_array_texture[i]->m_textureHeight;
		}
	}
	return 0;
}
void CGameTexturePool::clearPool()
{
	for (int i = 0; i < m_array_texture.size(); i++)
	{
		RELEASE_COM(m_array_texture[i]->m_texture);
		DELETE_POINT(m_array_texture[i]);
	}
	m_array_texture.clear();
}