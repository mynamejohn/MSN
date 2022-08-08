#include <irrKlang.h>
#pragma comment(lib,"irrKlang.lib")
using namespace irrklang;

class CSound
{
private:
	ISoundEngine* BGM;				//사운드 엔진 생성 (소리를 내기위한 객체)

	ISoundEngine* Upgrade;

	ISoundEngine* Downgrade;

	ISoundEngine* Title_BGM;

	ISoundEngine* Button;

	ISoundEngine* GameOver_BGM;
public:
	CSound(){};
	~CSound(){};


	void Init();
	
	void PlayBGM()
	{
		if (BGM == NULL)
			return;

		BGM->play2D("sound/BGM.mp3", true);		//파일이름, 루프
	}
	void PlayUpgrade()
	{
		if (Upgrade == NULL)
			return;

		Upgrade->play2D("sound/Upgrade.mp3");
	}
	void PlayDowngrade()
	{
		if (Downgrade == NULL)
			return;
		Downgrade->play2D("sound/Downgrade.mp3");
	}
	void PlayTitle_BGM()
	{
		if (Title_BGM == NULL)
			return;

		Title_BGM->play2D("sound/Title_BGM.mp3",true);
	}
	void PlayButton()
	{

		if (Button == NULL)
			return;

		Button->play2D("sound/Button.mp3");
	}
	void PlayGameOver_BGM()
	{
		if (GameOver_BGM == NULL)
			return;

		GameOver_BGM->play2D("sound/GameOver_BGM.mp3", true);
	}


	void StageStop()
	{

		if (BGM == NULL)
			return;

		BGM->stopAllSounds();
	}
	void TitleStop()
	{
		if (Title_BGM == NULL)
			return;
		Title_BGM->stopAllSounds();
	}
	void GameOverStop()
	{
		if (GameOver_BGM == NULL)
			return;
		GameOver_BGM->stopAllSounds();
	}

	void SetBGMMute()
	{
		if (BGM == NULL)
			return;
		BGM->setSoundVolume(0);
	}
	void SetBGMPlay()
	{
		if (BGM == NULL)
			return;
		BGM->setSoundVolume(0.5);
	}
	void SetEffectMute()
	{
		if (Button == NULL || Upgrade == NULL || Downgrade == NULL)
			return;

		Button->setSoundVolume(0);
		Upgrade->setSoundVolume(0);
		Downgrade->setSoundVolume(0);
	}
	void SetEffectPlay()
	{
		if (Upgrade == NULL || Button == NULL || Downgrade == NULL)
			return;
		Upgrade->setSoundVolume(0.5);
		Button->setSoundVolume(0.5);
		Downgrade->setSoundVolume(0.5);
	}
};