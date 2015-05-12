#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"

using namespace Vektoria;

class Ground
{
	CPlacement overallPlacement;
	CPlacement* groundPlacements;
	CGeoQuad* quadGeos;
	CMaterial material;
public:
	Ground();
	~Ground();

	void Init(float quadWidth, float quadHeight, int width, int height);

	CPlacement* GetPlacement();
};

