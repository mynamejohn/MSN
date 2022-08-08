#pragma once

// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#define g_pDevice CDevice::GetInstance()->GetDevice()
#define g_pSprite CDevice::GetInstance()->GetSprite()
#define MonsterNum 15
// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

using namespace std;

#define VK_1			0x31
#define VK_2			0x32
#define VK_3			0x33
#define VK_4			0x34
#define VK_5			0x35
#define VK_6			0x36
#define VK_7			0x37
#define VK_8			0x38
#define VK_9			0x39
#define VK_0			0x40

#define VK_A			0x41
#define VK_B			0x42
#define VK_C			0x43
#define VK_D			0x44
#define VK_E			0x45
#define VK_F			0x46
#define VK_G			0x47
#define VK_H			0x48
#define VK_I			0x49
#define VK_J			0x4A
#define VK_K			0x4B
#define VK_L			0x4C
#define VK_M			0x4D
#define VK_N			0x4E
#define VK_O			0x4F
#define VK_P			0x50
#define VK_Q			0x51
#define VK_R			0x52
#define VK_S			0x53
#define VK_T			0x54
#define VK_U			0x55
#define VK_V			0x56
#define VK_W			0x57
#define VK_X			0x58
#define VK_Y			0x59
#define VK_Z			0x5A

#define VK_LBUTTON		0x01
#define VK_RBUTTON		0x02
#define VK_CANCEL		0x03
#define VK_MBUTTON		0x04

#define PI 3.141592

#define SAFE_RELEASE(p)			{ if (p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE(p)			{ if (p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p)	{ if (p) { delete[] (p);   (p)=NULL; } }

#define KeyInput(p)				((GetAsyncKeyState(p) & 0x8001) == 0x8001) //한번씩 입력됨 (메뉴 등에서 사용)
#define KeyDown(p)				((GetAsyncKeyState(p) & 0x8000) == 0x8000) //누르는 동안 계속 입력 (캐릭터 이동 등에서 사용)

#define Tilesum	192

#define Tilecol 32
#define Tilerow 16

enum StageName	//스테이지
{
	MainMenu, // = 0,
	TestStage,
	Clear,
	stop

	//나중에 추가
};

enum MonsterType	//몬스터의 상태
{
	firstwave, // = 0,
	secondwave,
	thirdwave,
	fourthwave,
	fifthwave
	//나중에 추가
};

enum TileStat		//타일의 상태
{
	Normal,		// = 0
	Selected,
	Road,
	WareHouse,  //초코 
	splash,   // 스플래시
	penetration,  //관통
	turning,  // 회전 
	persisttower,  //지속
	slowTower,   // 슬로우 
	WareHouseStand,
	splashStand,
	penetrationstand,
	turningstand,
	persisttowerstand,
	slowTowerstand,
	turningreturn,



};

enum Tower
{
	



};