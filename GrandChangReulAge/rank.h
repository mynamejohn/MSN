#pragma once
#include "Score.h"
#include <iostream>
#include <fstream>
#include "BaseObject.h"
using namespace std;

#define MAX_SIZE 1000



class Crank :
	public CBaseObject
{
private:

	int first, second, third, fourth, fifth, sixth;
	RECT			m_rect2;
	D3DXVECTOR3		m_vPos2;

	RECT			m_rect3;
	D3DXVECTOR3		m_vPos3;

	RECT			m_rect4;
	D3DXVECTOR3		m_vPos4;

	RECT			m_rect5;
	D3DXVECTOR3		m_vPos5;

	RECT			m_rect6;
	D3DXVECTOR3		m_vPos6;
	int firstrankscore;
	int secondrankscore;
	int thirdrankscore;

	char inputString[MAX_SIZE];

	int lineNum;
	int messageNum;
	bool check;
public:


	void compare();



	void Init(CTexture t1);
	void Run(float m_StageTime);
	void Draw();
	Crank();
	~Crank();

	void input(ifstream &infile, ofstream &outfile);

	void OutputSave(int a);
	void OutputLoad();


};

