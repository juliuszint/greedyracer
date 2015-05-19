#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "entities\Entity.h"

using namespace Vektoria;

class Map : public Entity
{
public:
	// Note (julius): gibt die Startposition f�r den Spieler auf dieser Strecke zur�ck
	virtual CHVector GetStartPosition() = 0;
};

