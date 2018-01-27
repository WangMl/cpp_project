#include "stdafx.h"
#include "CellTexturePool.h"


CCellTexturePool::CCellTexturePool()
{
}


CCellTexturePool::~CCellTexturePool()
{
}
void CCellTexturePool::init(char*_cellTextureFile)
{
	TiXmlDocument doc(_cellTextureFile);
	if (!doc.LoadFile())
	{
		MessageBox(NULL, "Í¼Æ¬×ÊÔ´³Ø¼ÓÔØÊ§°Ü", "warning", MB_OK);
	}
	TiXmlElement*root = doc.FirstChildElement("TEXTURE");
	TiXmlElement*ele = root->FirstChildElement("BLUEtexture");
	for (; ele != NULL; ele = ele->NextSiblingElement())
	{
		CCellTexture*temp = new CCellTexture;
		D3DXIMAGE_INFO info;
		D3DXCreateTextureFromFileEx(CDirectManager::instance()->getDevice(),
			ele->Attribute("path"), D3DX_FROM_FILE, D3DX_FROM_FILE, 0, D3DUSAGE_DYNAMIC,
			D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, D3DX_FILTER_LINEAR,
			0, 0x0, &info, 0, &temp->m_texture);
		strcpy_s(temp->m_name, ele->Attribute("name"));
		temp->m_textureHeight = (float)info.Height;
		temp->m_textureWidth = (float)info.Width;
		m_array_cell.push_back(temp);
	}
}

LPDIRECT3DTEXTURE9 CCellTexturePool::getTextureByName(char*_name)
{
	for (int i = 0; i < m_array_cell.size(); i++)
	{
		if (strcmp(m_array_cell[i]->m_name, _name) == 0)
		{
			return m_array_cell[i]->m_texture;
		}
	}
	return 0;
}

float CCellTexturePool::getWidth(char*_name)
{
	for (int i = 0; i < m_array_cell.size(); i++)
	{
		if (strcmp(m_array_cell[i]->m_name, _name) == 0)
		{
			return m_array_cell[i]->m_textureWidth;
		}
	}
	return 0;
}
float CCellTexturePool::getHeight(char*_name)
{
	for (int i = 0; i < m_array_cell.size(); i++)
	{
		if (strcmp(m_array_cell[i]->m_name, _name) == 0)
		{
			return m_array_cell[i]->m_textureHeight;
		}
	}
	return 0;
}
void CCellTexturePool::clearPool()
{
	for (int i = 0; i < m_array_cell.size(); i++)
	{
		RELEASE_COM(m_array_cell[i]->m_texture);
		DELETE_POINT(m_array_cell[i]);
	}
	m_array_cell.clear();
}


