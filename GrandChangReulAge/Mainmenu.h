#pragma once

#include "BaseStage.h"
#include "Picture.h"
#include "Background.h"
#include "Cursor.h"


class CMainMenu :
	public CBaseStage
{
private:
	CPicture m_MT; // Main_Title
	CPicture m_GS;
	CPicture m_MA;
	CPicture m_GE;
	CPicture m_OP;
	CPicture GameEnd;

	CBackground m_BG;



	CTexture    m_GameEnd;
	CTexture    m_GameEnd2;
	CTexture m_tBG;
	CTexture m_tMT;
	CTexture m_start_ac;
	CTexture m_exit_ac;
	CTexture m_maker_ac;
	CTexture m_start_inac;
	CTexture m_exit_inac;
	CTexture m_maker_inac;
	CTexture m_tOP;

	CTexture m_tMouse;

	CSound Title_Sound;

	Cursor Mouse;

	bool OpenMaker;
	float Title_tick;
	float Title_first_time;

public:
	CMainMenu(void){}
	~CMainMenu(void){}

	void    TitleDraw();
	void	Init(CTexture t1);

	int TitleNum;
	void CTitlerun(float tick, int posX, int posY);
	void StageInit();
	void StageRun(float tick);
	void StageDraw();
};