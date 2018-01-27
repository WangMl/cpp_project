#pragma once
class CGamePlayCellButton
	:public CUIObject
{
public:
	CGamePlayCellButton();
	~CGamePlayCellButton();

	void add_animation();
	CGameAnimation* m_animation;
	virtual void MouseDown();
	virtual void MouseOver();
	virtual void MouseOut();

	        bool  update();
			void show_animation();
	bool m_isClick = false;

	void operator=(CGamePlayCellButton* _cellButton);
};

