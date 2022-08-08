#include "BaseStage.h"

CBaseStage::CBaseStage()
{

}

CBaseStage::~CBaseStage(void)
{
	SAFE_DELETE_ARRAY(m_Mobdata);
}

void CBaseStage::ChangeStage(int next)
{
	m_bChangeStage = true;
	m_NextStage = next;
}

void CBaseStage::LoadMonsters(const char* mobdata)
{
	ifstream Data;
	m_MobdataLine = 1;

	//line 수 구하기
	Data.open(mobdata, ios::in);
	char c;
	while (Data.get(c))
	{
		if (c == '\n') ++m_MobdataLine;
	}
	Data.close();

	m_Mobdata = new MobData[m_MobdataLine];

	//데이터 불러오기
	Data.open(mobdata, ios::in);
	for (int i = 0; i < m_MobdataLine; i++)
	{
		Data >> m_Mobdata[i].time >> m_Mobdata[i].type >> m_Mobdata[i].pattern;
	}
	Data.close();
}