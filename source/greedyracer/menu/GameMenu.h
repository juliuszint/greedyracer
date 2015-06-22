#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

using namespace Vektoria;

enum EGameMenuButton
{
	EGameMenuButtonNone,
	EGameMenuButtonStart,
	EGameMenuButtonCredits,
	EGameMenuButtonQuit
};

class CGameMenu
{
private:
	bool isVisible;
	COverlay rootOverlay;
	CAudio menuSound;
	
	COverlay startButtonOverlay;
	COverlay creditsButtonOverlay;
	COverlay stopButtonOverlay;
	COverlay creditsOverlay;

	CImage backgroundImage;
	
	CDeviceCursor * cursor;

	CImage creditsImage;

	CFloatRect startButtonRect;
	CImage startButtonImage;
	CFloatRect creditsButtonRect;
	CImage creditsButtonImage;
	CFloatRect stopButtonRect;
	CImage stopButtonImage;
public:
	void Init(CDeviceCursor * cursor);
	bool GetIsVisible();
	void SetIsVisible(bool value);

	bool CreditsOn();
	void CreditsSwitch(bool);

	EGameMenuButton Tick();
	COverlay* GetRootOverlay();
	CAudio* GetAudio();
};

