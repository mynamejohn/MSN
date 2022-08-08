#pragma once

#include "Device.h"
#include "Texture.h"
#include <fstream>

struct MobData
{
	float time;
	int type;
	int pattern;
};

class CBaseStage
{
protected:
	float m_SFtageTime;
	

	bool m_bChangeStage;
	int m_NextStage;
	bool tickcnt;
	MobData *m_Mobdata; //몬스터 데이터를 저장하는 구조체 배열
	int m_MobCounter; //몇 번째 몬스터가 나올 차례인지
	int m_MobdataLine; //txt파일의 총 라인 수

public:
	CBaseStage(void);
	~CBaseStage(void);
	float m_StageTime;
	void StageInit();
	void StageRun(float tick);
	void StageDraw();

	void ChangeStage(int next);

	void LoadMonsters(const char* mobdata); //몬스터 데이터 불러오기

	//Getter
	bool GetChangeStage() { return m_bChangeStage; }
	int GetNextStage() { return m_NextStage; }
	//Setter
};