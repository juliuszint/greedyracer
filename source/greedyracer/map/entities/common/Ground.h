#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "..\Entity.h"

using namespace Vektoria;

class CGround : public CEntity
{
private:
	CPlacement overallPlacement;
	CPlacement* groundPlacements;
	CGeoQuad* quadGeos;
	CMaterial material;
	float quadWidth;
	float quadHeight;
	int width;
	int height;
public:
	// Note (julius): Destructor
	~CGround();
	
	// Note (julius): wird vor init aufgerufen um einzustellen wie breit die quads 
	// sind und wie viel auf wie viele felder hinzugefügt werden
	void Configure(float quadWidth, float quadHeight, int width, int height);

	void Init();

	CPlacement* GetRootPlacement();
};

