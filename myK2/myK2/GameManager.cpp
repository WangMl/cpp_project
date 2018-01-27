#include "stdafx.h"
#include "GameManager.h"


CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	DELETE_POINT(pIntroduce);
	DELETE_POINT(pMenu);
}

void CGameManager::init()
{
	srand(GetTickCount());
	CGameTexturePool::instance()->init("gameMenu.xml");
	CCellTexturePool::instance()->init("cellTexture.xml");
	pIntroduce = new CIntroduce();
	pIntroduce->init("introduce.jpg");

	pMenu = new CGameMenu();
	pMenu->init();

	pPlay = new CGamePlay;
	pPlay->init();
}
void CGameManager::messagehandle(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CDirectManager::instance()->getMessage(hWnd, message, wParam, lParam);
}

void CGameManager::update()
{
	switch (CGameManager::m_gameState)
	{
	case GameState::INTRODUCE:
		if (pIntroduce->update())
		{
			m_gameState = GameState::MENU;
		}
		break;
	case GameState::MENU:
		switch (pMenu->update())
		{
		case 1:
			m_gameState = PLAY;
			break;
		case 2:
			m_gameState = HELP;
			break;
		case 3:
			m_gameState = EXIT;
			break;
		}
		break;
	case GameState::PLAY:
		pPlay->update();
		break;
	case GameState::HELP:
		break;
	case GameState::EXIT:
		exit(1001);
		break;
	}
	CDirectManager::instance()->clearMsg();
}

void CGameManager::render()
{
	CDirectManager::instance()->beginRender();
	switch (CGameManager::m_gameState)
	{
	case GameState::INTRODUCE:
		pIntroduce->render();
		break;
	case GameState::MENU:
		pMenu->render();
		break;
	case GameState::PLAY:
		pPlay->render();
		break;
	case GameState::HELP:
		break;
	case GameState::EXIT:
		break;
	}
	CDirectManager::instance()->endRender();
}