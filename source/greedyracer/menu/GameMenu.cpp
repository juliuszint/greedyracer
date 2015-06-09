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
	// Note (julius): für die berechnung der größen im menu wird der einfach heit 
	// halber angenommen das das spiel immer im seitenverhältins von 16:9 läuft
	// die grafiken werden in einer auflösung von 180 pixeln gerade geliefert
	// damit sie nicht skaliert werden bei einer auflösung von 1280 muss eine relative
	// groesse von 0.14

	//float ratio = 16.0 / 9.0;
	//float buttonWidth = 0.14; // breite 
	//float buttonHeight = buttonWidth * ratio;
	//float buttonLeft = 0.5 - (buttonWidth / 2);

	float buttonWidth = 0.15f;
	float buttonHeight = 0.075f;
	float buttonLeft = 0.475f - (buttonWidth / 2);

	this->startButtonOverlay.Init(&this->startButtonImage, CFloatRect(buttonLeft, 0.4, buttonWidth, buttonHeight));
	//this->startButtonOverlay.SetLayer(0.5f);
	this->creditsButtonOverlay.Init(&this->creditsButtonImage, CFloatRect(buttonLeft, 0.5, buttonWidth, buttonHeight));
	//this->creditsButtonOverlay.SetLayer(0.5f);
	this->stopButtonOverlay.Init(&this->stopButtonImage, CFloatRect(buttonLeft, 0.6, buttonWidth, buttonHeight));
	//this->stopButtonOverlay.SetLayer(0.5f);

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

	if (currentOverlay == &this->startButtonOverlay && leftMousePressed)
	{
		return EGameMenuButtonStart;
	}
	if (currentOverlay == &this->creditsButtonOverlay && leftMousePressed)
	{
		return EGameMenuButtonHighscore;
	}
	if (currentOverlay == &this->stopButtonOverlay && leftMousePressed) 
	{
		return EGameMenuButtonQuit;
	}
	return EGameMenuButtonNone;
}