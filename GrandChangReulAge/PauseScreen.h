#pragma once
#include "BaseObject.h"
#include "BaseStage.h"
class CPause : public CBaseObject
{
private:
	LPDIRECT3DTEXTURE9		Menu;
	LPDIRECT3DTEXTURE9		Option;
	LPDIRECT3DTEXTURE9		Point;

	LPDIRECT3DTEXTURE9		Return;
	LPDIRECT3DTEXTURE9		Continue;

	int PauseorSet;			//0�̸� �޴�, 1�̸� ����

	RECT					Point_Rect;
	RECT					Return_Rect;
	RECT					Continue_Rect;

	D3DXVECTOR3				Point_Pos;
	D3DXVECTOR3				Point_Pos2;
	D3DXVECTOR3				Return_Pos;
	D3DXVECTOR3				Continue_Pos;

	
	bool					BackSoundchk;
	bool					EffectSoundchk;

public:
	CPause(void){}
	~CPause(void){}
		
	bool ChangeChk;			//���������� �ٲٴ��Լ�
	bool getBackSoundchk(){ return BackSoundchk; };
	bool getEffectSoundchk(){ return EffectSoundchk; };

	void Init(CTexture t1, CTexture t2, CTexture t3, CTexture t4);

	void Run(bool* Pausechk, float MousePosx, float MousePosy);
	void Draw();
};;