#include "stdafx.h"
#include "UIObject.h"


CUIObject::CUIObject()
{
	D3DXVECTOR3 m_center = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 m_position = D3DXVECTOR3(0, 0, 0);
}


CUIObject::~CUIObject()
{
}
void CUIObject::init(char*_texture, D3DXVECTOR3 _center, D3DXVECTOR3 _pos, DWORD _color)
{
	strcpy(m_name, _texture);
	m_sprite = CDirectManager::instance()->getSprite();
	m_width = (float)CGameTexturePool::instance()->getWidth(m_name);
	m_height = (float)CGameTexturePool::instance()->getHeight(m_name);
	m_position = _pos;
	m_center = _center;
	m_color = _color;
	m_texture = CGameTexturePool::instance()->getTextureByName(m_name);
}
void CUIObject::update()
{
	m_msg = CDirectManager::instance()->m_msg;
	//ÅÐ¶ÏÊÇ·ñ·¢ÉúÅö×²
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(GetActiveWindow(), &point);
	if (point.x > m_position.x - m_center.x&&point.y > m_position.y - m_center.y
		&&point.x < m_position.x + m_width - m_center.x&&point.y < m_position.y + m_height - m_center.y)
	/*if (point.x > m_position.x &&point.y > m_position.y
		&&point.x < m_position.x + m_width&&point.y < m_position.y + m_height)*/
	{
		isCollid = true;
		MouseOver();
	}
	else
	{
		isCollid = false;
		MouseOut();
	}
	switch (m_msg.message)
	{
	case WM_LBUTTONDOWN:
		if (isCollid)
		{
			MouseDown();
		}
		break;
	case WM_LBUTTONUP:
		MouseUp();
		break;
	}

}
void CUIObject::render()
{
	if (m_isShow)
	{
		m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
		m_sprite->Draw(m_texture, 0, &m_center, &m_position, m_color);
		m_sprite->End();
	}
}