#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Map.h"
#include "entities\common\Ground.h"
#include "entities\common\Water.h"

using namespace Vektoria;

class AllgaeuMap : public Map
{
private:
	CPlacement placement;
	Ground * ground;
	Water * water;
public:
	~AllgaeuMap();

	void Init();

	CPlacement* GetRootPlacement();

	CHVector GetStartPosition();
};

