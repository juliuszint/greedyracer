#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include <string>


using namespace Vektoria;

class CEntity
{
public:
	// Note (julius): Initialisiert und lädt das Entity und seine darstellung in den Speicher
	virtual void Init() = 0;
	
	// Note (julius): gibt das RootPlacement der Map zurück an dem jegliche teile der map 
	// hängen 
	virtual CPlacement* GetRootPlacement() = 0;
};
