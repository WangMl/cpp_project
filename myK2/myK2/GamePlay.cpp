#include "stdafx.h"
#include "GamePlay.h"


CGamePlay::CGamePlay()
{
	ZeroMemory(&m_currentClickPos, sizeof(m_currentClickPos));
	ZeroMemory(&m_lastClickPos, sizeof(m_lastClickPos));
	ZeroMemory(&m_originPos, sizeof(m_originPos));
	m_clickCount = 0;
}


CGamePlay::~CGamePlay()
{
}

void CGamePlay::init()
{
	m_backUI.init("playBack", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0),0xffffffff);
	int numTemp = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			CGamePlayCellButton* temp = new CGamePlayCellButton;
			numTemp = (rand() % 5) + 5;
			temp->init(CGameTexturePool::instance()->m_array_texture[numTemp]->m_name, D3DXVECTOR3(0,0,0),
				D3DXVECTOR3(j * 72, i * 65, 0),0xdddddddd);
			//temp->add_animation();
			m_array_cell_button.push_back(temp);
		}
	}
}

bool CGamePlay::find_sameElem(int _num)
{
	for (int i = 0; i < m_array_remove_button.size(); i++)
	{
		if (m_array_remove_button[i] == _num)
		{
			return true;
		}
	}
	return false;
}
void CGamePlay::update()
{
	
	for (int i = 0; i < m_array_cell_button.size(); i++)
	{
		if (m_array_cell_button[i]->update() && m_array_cell_button[i]->m_isShow)
		{
			m_clickCount++;
			posNum = i;
			break;
		}
	}
	switch (m_clickCount)
	{
	case 1:
	{
			  m_lastClickPos = m_array_cell_button[posNum]->m_position;
			  lastNum = posNum;
			  m_array_cell_button[lastNum]->m_isClick = false;
			  check(lastNum);
			  int count = 0;
			  int tempSize = 0; 
			  while (count <= 5)
			  {
				 tempSize = m_array_remove_button.size();
				 for (int i = 0; i < tempSize; i++)
				 {
					 check(m_array_remove_button[i]);
				  }
				  count++;
			  }
			  if (m_array_remove_button.size() > 0)
			  {
				  for (int i = 0; i < m_array_remove_button.size(); i++)
				  {
					  m_array_cell_button[m_array_remove_button[i]]->m_isShow = false;
					  m_array_cell_button[m_array_remove_button[i]]->add_animation();
					  m_array_cell_button[m_array_remove_button[i]]->m_animation->update(m_array_cell_button[m_array_remove_button[i]]->m_position);
				  }
				 m_array_remove_button.clear();
				  m_clickCount = 0;
				  ZeroMemory(&m_currentClickPos, sizeof(m_currentClickPos));
				  ZeroMemory(&m_lastClickPos, sizeof(m_lastClickPos));
			  }
			  break;
	}
	case 2:
	{
			  m_currentClickPos = m_array_cell_button[posNum]->m_position;
			  currentNum = posNum;
			  m_array_cell_button[currentNum]->m_isClick = false;
			  if (isLinkCell())
			  {
				  isSwap();
			  }
			  m_clickCount=0;
			  ZeroMemory(&m_currentClickPos, sizeof(m_currentClickPos));
			  ZeroMemory(&m_lastClickPos, sizeof(m_lastClickPos));
			  break;
	}
	default:
		break;
	}
	//m_array_remove_button.clear();
}
void CGamePlay::check(int _lastNum)
{
	checkLeft(_lastNum);
	checkRight(_lastNum);
	checkDown(_lastNum);
	checkUp(_lastNum);
	if (m_array_remove_button.size() > 0)
	{
		if (!find_sameElem(_lastNum))
		{
			m_array_remove_button.push_back(_lastNum);
		}
	}
}
void  CGamePlay::checkDown(int _lastNum)
{///下
	for (int i = 1; (_lastNum + 12 * i) < 84; i++)
	{
		if (strcmp(m_array_cell_button[_lastNum]->m_name, m_array_cell_button[_lastNum + 12 * i]->m_name)==0
			&& m_array_cell_button[_lastNum + 12 * i]->m_isShow==true)
		{
			if (!find_sameElem(_lastNum + 12 * i))
			{
				m_array_remove_button.push_back(_lastNum + 12 * i);
			}
			
		}
		else
		{
			break;
		}
	}
}
void  CGamePlay::checkUp(int _lastNum)
{
	///向上找
	for (int k = 1; (_lastNum - 12 * k) >= 0; k++)
	{
		if (0 == strcmp(m_array_cell_button[_lastNum]->m_name, m_array_cell_button[_lastNum - 12 * k]->m_name)
			&& m_array_cell_button[_lastNum - 12 * k]->m_isShow == true)
		{
			if (!find_sameElem(_lastNum - 12 * k))
			{
				m_array_remove_button.push_back(_lastNum - 12 * k);
			}
		}
		else
		{
			break;
		}
	}
}
void  CGamePlay::checkLeft(int _lastNum)
{///向左找
	for (int h = 1; h <= _lastNum % 12; h++)
	{
		if (0 == strcmp(m_array_cell_button[_lastNum]->m_name, m_array_cell_button[_lastNum - h]->m_name)
			&& m_array_cell_button[_lastNum - h]->m_isShow == true)
		{
			if (!find_sameElem(_lastNum - h))
			{
				m_array_remove_button.push_back(_lastNum - h);
			}
			
		}
		else
		{
			break;
		}
	}
}
void  CGamePlay::checkRight(int _lastNum)
{
	///向右找
	for (int j = 1; j < 12 - (_lastNum % 12); j++)
	{
		if (0 == strcmp(m_array_cell_button[_lastNum]->m_name, m_array_cell_button[_lastNum + j]->m_name)
			&& m_array_cell_button[_lastNum + j]->m_isShow == true)
		{
			if (!find_sameElem(_lastNum + j))
			m_array_remove_button.push_back(_lastNum + j);
		}
		else
		{
			break;
		}
	}
}
void CGamePlay::isSwap()
{
	CGamePlayCellButton* newButton = new CGamePlayCellButton;
	newButton = m_array_cell_button[lastNum];
	m_array_cell_button[lastNum] = m_array_cell_button[currentNum];
	m_array_cell_button[currentNum] = newButton;
	m_array_cell_button[lastNum]->m_position = m_lastClickPos;
	m_array_cell_button[currentNum]->m_position = m_currentClickPos;
	
}
float CGamePlay::getDistance(D3DXVECTOR3 _pos1, D3DXVECTOR3 _pos2)
{
	float dis = sqrt(pow(_pos1.x - _pos2.x, 2.0f) + pow(_pos1.y - _pos2.y, 2.0f));
	return dis;
}
bool CGamePlay::isLinkCell()
{
		if (getDistance(m_currentClickPos, m_lastClickPos) == 72.0f ||
			getDistance(m_currentClickPos, m_lastClickPos) == 65.0f)
		{
			return true;
		}
		return false;
}
void CGamePlay::render()
{
	m_backUI.render();
	for (int i = 0; i < m_array_cell_button.size(); i++)
	{
		m_array_cell_button[i]->render();
		m_array_cell_button[i]->show_animation();
	}
}
