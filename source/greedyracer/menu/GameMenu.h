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
	
	COverlay startButtonOverlay;
	COverlay creditsButtonOverlay;
	COverlay stopButtonOverlay;

	CImage backgroundImage;
	
	CDeviceCursor * cursor;

	CImage startButtonImage;
	CImage creditsButtonImage;
	CImage stopButtonImage;
public:
	void Init(CDeviceCursor * cursor);
	bool GetIsVisible();
	void SetIsVisible(bool value);
	EGameMenuButton Tick();
	COverlay* GetRootOverlay();
};

