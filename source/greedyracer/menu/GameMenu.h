#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

using namespace Vektoria;

enum EGameMenuButton
{
	EGameMenuButtonNone,
	EGameMenuButtonStart,
	EGameMenuButtonHighscore,
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

	CImage backgroundImage;
	
	CDeviceCursor * cursor;

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
	EGameMenuButton Tick();
	COverlay* GetRootOverlay();
	CAudio* GetAudio();
};

