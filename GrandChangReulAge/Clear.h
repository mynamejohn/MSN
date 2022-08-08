#pragma once

#include "BaseStage.h"
#include "Picture.h"
#include "Background.h"
#include "Cursor.h"
#include "score.h"

class CClear : public CBaseStage
{
private:

	Cscore				Total_Score;
	CTexture			t_Number;

	CTexture			t_Background;
	CBackground			Background;

	CTexture			t_Cursor;
	Cursor				Cursor;

	CTexture			Regame;
	CTexture			Regame_Click;
	CTexture			Return;
	CTexture			Return_Click;
	CPicture			Clear_Button;
public:
	CClear(){};
	~CClear(){};

	int stage;

	void StageInit(int* Score);
	void StageRun(float tick);
	void StageDraw();
};