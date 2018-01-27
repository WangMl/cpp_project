#include "stdafx.h"
#include "GameMenu.h"


CGameMenu::CGameMenu()
{
}


CGameMenu::~CGameMenu()
{
}

void CGameMenu::init()
{
	TiXmlDocument doc("gameMenu.xml");
	if (!doc.LoadFile())
	{
		MessageBox(NULL,"²Ëµ¥³Ø¼ÓÔØÊ§°Ü","warning",MB_OK);
	}
	TiXmlElement*root = doc.FirstChildElement("TEXTURE");
	TiXmlElement*ele = root->FirstChildElement("BACKtexture");
	m_UIback = new CUIObject;
	m_UIback->init("back", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), 0xffffffff);
	ele = root->FirstChildElement("BEGINtexture");
	float x = (float)atof(ele->Attribute("posx"));
	float y = (float)atof(ele->Attribute("posy"));
	float z = 0;
	m_startButton = new CGameButton;
	m_startButton->init("begin1", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(x, y, z), 0xffffffff);


	ele = root->FirstChildElement("EXITtexture");
	 x = (float)atof(ele->Attribute("posx"));
	 y = (float)atof(ele->Attribute("posy"));
	 z = 0;
	 m_stopButton = new CGameButton;
	 m_stopButton->init("exit1", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(x, y, z), 0xffffffff);


	ele = root->FirstChildElement("HELPtexture");
     x = (float)atof(ele->Attribute("posx"));
     y = (float)atof(ele->Attribute("posy"));
     z = 0;
	 m_helpButton = new CGameButton;
	 m_helpButton->init("help1", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(x, y, z), 0xffffffff);

	
}
int CGameMenu::update()
{
	if (m_startButton->update())
	{
		return 1;
	}
	if (m_stopButton->update())
	{
		return 2;
	}
	if(m_helpButton->update())
	{
		return 3;
	}
	return 0;
}
void CGameMenu::render()
{
	m_UIback->render();
	m_startButton->render();
	m_stopButton->render();
	m_helpButton->render();
}