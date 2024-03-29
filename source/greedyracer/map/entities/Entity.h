#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include <string>


using namespace Vektoria;

class CEntity
{
public:
	// Note (julius): Initialisiert und l�dt das Entity und seine darstellung in den Speicher
	virtual void Init() = 0;
	
	// Note (julius): gibt das RootPlacement der Map zur�ck an dem jegliche teile der map 
	// h�ngen 
	virtual CPlacement* GetRootPlacement() = 0;
};
