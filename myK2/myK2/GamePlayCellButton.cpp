#include "stdafx.h"
#include "GamePlayCellButton.h"


CGamePlayCellButton::CGamePlayCellButton()
{
}


CGamePlayCellButton::~CGamePlayCellButton()
{
}

void CGamePlayCellButton::add_animation()
{
	m_animation = new CGameAnimation;
	m_animation->init(".\\particle.ini");
}
void CGamePlayCellButton::operator=(CGamePlayCellButton* _cellButton)
{
	this->m_center = _cellButton->m_center;
	this->m_color = _cellButton->m_color;
	this->m_height = _cellButton->m_height;
	this->m_isClick = _cellButton->m_isClick;
	this->m_isShow = _cellButton->m_isShow;
	this->m_msg = _cellButton->m_msg;
	strcpy(this->m_name, _cellButton->m_name);
	
	this->m_position = _cellButton->m_position;
	this->m_texture = _cellButton->m_texture;
	this->m_width = _cellButton->m_width;
}
void CGamePlayCellButton::MouseDown()
{
	m_isClick = true;
}

void CGamePlayCellButton::MouseOver()
{
	m_color = 0xffffffff;
}
void CGamePlayCellButton::MouseOut()
{
	m_color = 0xdddddddd;
}
bool CGamePlayCellButton::update()
{
	CUIObject::update();
	/*if (m_isShow == false)
	{
		m_animation->update(m_position);
	}*/
	if (m_isClick){ return true; }
	else{ return false; }
	
}
void  CGamePlayCellButton::show_animation()
{
	if (m_isShow == false)
	{
		m_animation->render(m_position);
	}
}