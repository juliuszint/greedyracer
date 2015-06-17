//#include "GameMenu.h"
#include "GameMenu.h"


void CGameMenu::Init(CDeviceCursor * cursor)
{
	this->cursor = cursor;
	this->isVisible = true;

	this->backgroundImage.Init("resources\\menu\\MenuScreen.jpg");
	this->startButtonImage.Init("resources\\menu\\StartButton.jpg");
	this->creditsButtonImage.Init("resources\\menu\\CreditsButton.jpg");
	this->stopButtonImage.Init("resources\\menu\\EndButton.jpg");

	this->rootOverlay.InitFull(&this->backgroundImage);
	this->rootOverlay.SetLayer(0.8f);
	// Note (julius): f�r die berechnung der gr��en im menu wird der einfach heit 
	// halber angenommen das das spiel immer im seitenverh�ltins von 16:9 l�uft
	// die grafiken werden in einer aufl�sung von 180 pixeln gerade geliefert
	// damit sie nicht skaliert werden bei einer aufl�sung von 1280 muss eine relative
	// groesse von 0.14

	//float ratio = 16.0 / 9.0;
	//float buttonWidth = 0.14; // breite 
	//float buttonHeight = buttonWidth * ratio;
	//float buttonLeft = 0.5 - (buttonWidth / 2);

	float buttonWidth = 0.15f;
	float buttonHeight = 0.075f;
	float buttonLeft = 0.475f - (buttonWidth / 2);

	this->startButtonRect.Init(buttonLeft, 0.4, buttonWidth, buttonHeight);
	this->creditsButtonRect.Init(buttonLeft, 0.5, buttonWidth, buttonHeight);
	this->stopButtonRect.Init(buttonLeft, 0.6, buttonWidth, buttonHeight);

	this->startButtonOverlay.Init(&this->startButtonImage, this->startButtonRect);
	this->creditsButtonOverlay.Init(&this->creditsButtonImage, this->creditsButtonRect);
	this->stopButtonOverlay.Init(&this->stopButtonImage, this->stopButtonRect);

	this->rootOverlay.AddOverlay(&this->startButtonOverlay);
	this->rootOverlay.AddOverlay(&this->creditsButtonOverlay);
	this->rootOverlay.AddOverlay(&this->stopButtonOverlay);
}

COverlay* CGameMenu::GetRootOverlay()
{
	return &this->rootOverlay;
}

bool CGameMenu::GetIsVisible()
{
	return this->isVisible;
}
void CGameMenu::SetIsVisible(bool value)
{
	this->isVisible = value;
	if (value) this->rootOverlay.SwitchOn();
	else	   this->rootOverlay.SwitchOff();
}

EGameMenuButton CGameMenu::Tick()
{
	COverlay* currentOverlay = this->cursor->PickOverlay();
	bool leftMousePressed = this->cursor->ButtonPressedLeft();

	if (currentOverlay == &this->startButtonOverlay)
	{
		if (leftMousePressed)
		{
			CFloatRect rect;
			rect.Init(this->startButtonRect.m_fxPos + 0.01,
				this->startButtonRect.m_fyPos + 0.01,
				this->startButtonRect.m_fxSize - 0.02,
				this->startButtonRect.m_fySize - 0.02);

			this->startButtonOverlay.SetRect(rect);

			return EGameMenuButtonStart;
		}
	}
	if (currentOverlay == &this->creditsButtonOverlay)
	{
		if (leftMousePressed)
		{
			return EGameMenuButtonHighscore;
		}
	}
	if (currentOverlay == &this->stopButtonOverlay && leftMousePressed)
	{
		return EGameMenuButtonQuit;
	}
	return EGameMenuButtonNone;
}