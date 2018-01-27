#include "stdafx.h"
#include "GameButton.h"


CGameButton::CGameButton()
{
}


CGameButton::~CGameButton()
{
}

void CGameButton::MouseDown()
{
	m_isClick = true;
}
void CGameButton::MouseOver()
{
	m_color = 0xffffffff;
}
void CGameButton::MouseOut()
{
	m_color = 0xdddddddd;
}

bool CGameButton::update()
{
	CUIObject::update();
	if (m_isClick)
	{
		return true;
	}
	else
	{
		return false;
	}
}
