#pragma once
class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void init();
	void update();
	void render();


	enum  GameState
	{
		INTRODUCE,MENU,PLAY,HELP,EXIT
	};
	GameState m_gameState = INTRODUCE;

	void messagehandle(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	CIntroduce * pIntroduce = NULL;
	CGameMenu * pMenu = NULL;
	CGamePlay* pPlay = NULL;

private:
protected:

};

