#include "BaseObject.h"

class CResources : public CBaseObject
{
private:
	float p_recources;

	RECT			m_rect2;
	D3DXVECTOR3		m_vPos2;
	
	RECT			m_rect3;
	D3DXVECTOR3		m_vPos3;

	int first;		//ù��° �ڸ���
	int second;		//�ι�° �ڸ���
	int third;		//����° �ڸ���
public:
	CResources(void){}
	~CResources(void){}

	void Init(CTexture t1);
	void Run(float m_StageTime);
	void Draw();

	float* getRecources()	{ return &p_recources; }
	void setRecources(float RE) { p_recources = RE; }

};