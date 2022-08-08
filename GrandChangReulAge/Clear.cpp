#include"Clear.h"

void CClear::StageInit(int* Score)
{
	m_bChangeStage = false;
	stage = 0;

	t_Background.Init(L"Image/Clear.png");
	Background.Init(t_Background);

	t_Cursor.Init(L"Image/mouse.png");
	Cursor.Init(t_Cursor);

	Regame.Init(L"Image/ReGame.png");
	Regame_Click.Init(L"Image/ReGame_Click.png");
	Return.Init(L"Image/Return.png");
	Return_Click.Init(L"Image/Return_Click.png");

	t_Number.Init(L"Image/Clear_Score.png");
	Total_Score.Clear_Init(t_Number,*Score);

	Clear_Button.ClearInit(Regame, Regame_Click, Return, Return_Click);
};


void CClear::StageRun(float tick)
{
	Cursor.Run(tick);
	Clear_Button.Clear_Run(Cursor.getMousePosx(), Cursor.getMousePosy(),&stage);

	if (stage == 1)
	{
		stage = 0;
		ChangeStage(TestStage);
	}
	if (stage == 2)
	{
		stage = 0;
		ChangeStage(MainMenu);
	}
}


void CClear::StageDraw()
{
	Background.Draw();
	Clear_Button.Clear_Draw();
	Cursor.Draw();
	Total_Score.Draw();
	
}