#pragma once

#include "Mainmenu.h"
#include "TestStage.h"
#include "Cursor.h"
#include "Clear.h"




#pragma comment(linker, "/entry:wWinMainCRTStartup")
#pragma comment(linker, "/subsystem:console")


class CLooper
{
private:
//	Cursor mouse;
//	CTexture m_tMouse;

	CMainMenu m_MainMenu;
	CTestStage m_TestStage;
	CClear m_Clear;

	int total_score;
	int m_Stage;

public:
	CLooper(void){}
	~CLooper(void){}


	void Init();
	void Inplay(float tick);
	void Render();

	//Setter
	void SetStage(int stage);

	//Getter
	int GetStage(){ return m_Stage; };
};