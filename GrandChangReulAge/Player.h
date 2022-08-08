#pragma once
#include "BaseObject.h"

class CPlayer : public CBaseObject
{
private:
	int score;

public:
	CPlayer(void){}
	~CPlayer(void){}

	void Init(CTexture t1);
	void Run(float tick);
	void Draw();


};