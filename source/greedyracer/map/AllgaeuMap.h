#pragma once


#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "Map.h"
#include "entities\common\Ground.h"
#include "entities\common\Water.h"

using namespace Vektoria;

class CAllgaeuMap : public CMap
{
private:
	CPlacement placement;
	CGround * ground;
	CWater * water;
public:
	~CAllgaeuMap();

	void Init();

	CPlacement* GetRootPlacement();

	CHVector GetStartPosition();
};

