#pragma once
class CGameMenu
{
public:
	CGameMenu();
	~CGameMenu();

	void init();
	int update();
	void render();

	CUIObject* m_UIback = NULL;
	CGameButton* m_startButton = NULL;
	CGameButton* m_stopButton = NULL;
	CGameButton* m_helpButton = NULL;
};

