#pragma once
class CGamePlay
{
public:
	CGamePlay();
	~CGamePlay();
	
	void init();
	void update();
	void render();

	CUIObject m_backUI;
	
	D3DXVECTOR3 m_originPos;
	vector<CGamePlayCellButton*>m_array_cell_button;
	D3DXVECTOR3 m_currentClickPos;
	D3DXVECTOR3 m_lastClickPos;
	
	int posNum = 0;
	int lastNum=0;
	int currentNum = 0;
    int m_clickCount;
	bool isLinkCell();
	void isSwap();
	float  getDistance(D3DXVECTOR3 _pos1, D3DXVECTOR3 _pos2);

	vector<int>m_array_remove_button;
	float m_deltaTime = 0;
	bool m_isWaiting = true;
	void check(int _lastNum);
	void checkDown(int _lastNum);
	void checkUp(int _lastNum);
	void checkLeft(int _lastNum);
	void checkRight(int _lastNum);
	
	bool find_sameElem(int _num);
	
};

