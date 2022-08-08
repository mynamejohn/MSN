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
	MobData *m_Mobdata; //���� �����͸� �����ϴ� ����ü �迭
	int m_MobCounter; //�� ��° ���Ͱ� ���� ��������
	int m_MobdataLine; //txt������ �� ���� ��

public:
	CBaseStage(void);
	~CBaseStage(void);
	float m_StageTime;
	void StageInit();
	void StageRun(float tick);
	void StageDraw();

	void ChangeStage(int next);

	void LoadMonsters(const char* mobdata); //���� ������ �ҷ�����

	//Getter
	bool GetChangeStage() { return m_bChangeStage; }
	int GetNextStage() { return m_NextStage; }
	//Setter
};