#include "Sound.h"

void CSound::Init()
{
	BGM = irrklang::createIrrKlangDevice();

	//����̽� ����
	Upgrade = irrklang::createIrrKlangDevice();	
	if (Upgrade == NULL)
			return;
	Upgrade->setSoundVolume(0.5);

	Downgrade = irrklang::createIrrKlangDevice();	
	if (Downgrade == NULL)
		return;
	Downgrade->setSoundVolume(0.5);

	Title_BGM = irrklang::createIrrKlangDevice();

	Button = irrklang::createIrrKlangDevice();

	GameOver_BGM = irrklang::createIrrKlangDevice();
};
