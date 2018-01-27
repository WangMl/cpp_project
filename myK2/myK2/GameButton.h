#pragma once
class CGameButton
	:public CUIObject
{
public:
	CGameButton();
	~CGameButton();
	

	virtual void MouseDown();
	virtual void MouseOver();
	virtual void MouseOut();

	        bool update();
	bool m_isClick = false;
};

