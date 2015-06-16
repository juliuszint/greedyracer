#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "..\Entity.h"

using namespace Vektoria;

class CWater : CEntity
{
private:
	CGeoQuad quad;
	CMaterial material;
	CPlacement placement;
	CFileWavefront m_zgBay;
	CGeo* m_pzgBay;

	int width;
	int height;
public:
	void Configure(int width, int height);

	void Init();

	CPlacement* GetRootPlacement();
};

