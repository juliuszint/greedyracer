#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "entities\Entity.h"

using namespace Vektoria;

class CMap : public CEntity
{
public:
	// Note (julius): gibt die Startposition f�r den Spieler auf dieser Strecke zur�ck
	virtual CHVector GetStartPosition() = 0;

	virtual int IsOnCheckpoint(CHVector) = 0;

	virtual CHVector IsOnTrack(CHVector) = 0;

	virtual bool IsOnFinish(CHVector) = 0;

	virtual int IsOnShortcutTrigger(CHVector) = 0;
};

