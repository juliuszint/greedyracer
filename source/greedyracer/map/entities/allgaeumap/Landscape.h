#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "..\Entity.h"
#include "Brewery.h"
#include "..\common\BigHouse.h"
#include "..\common\LittleHouse.h"

using namespace Vektoria;

class CLandscape : public CEntity

{
private:
	CPlacement m_zpOverallPlacement;
	CPlacement m_zpLandscape;
	CPlacement m_zpTreeFir;
	CPlacement m_zpTreeRound;
	CPlacement m_zpTreeBobblig;
	CPlacement m_zpTreeLog;

	CGeo* m_pzgLandscape;
	CGeo* m_pzgTreeFir;
	CGeo* m_pzgTreeRound;
	CGeo* m_pzgTreeBobblig;
	CGeo* m_pzgTreeLog;

	CFileWavefront m_zgLandscape;
	CFileWavefront m_zgTreeFir;
	CFileWavefront m_zgTreeRound;
	CFileWavefront m_zgTreeBobblig;
	CFileWavefront m_zgTreeLog;

	CMaterial m_zmLandscape;
	CMaterial m_zmTreeFir;
	CMaterial m_zmTreeRound;
	CMaterial m_zmTreeBobblig;
	CMaterial m_zmTreeLog;

	CBrewery m_zgBrewery;
	CBigHouse m_zgBigHouse;
	CBigHouse m_zgBigHouse2;
	CBigHouse m_zgBigHouse3;
	CBigHouse m_zgBigHouse4;
	CLittleHouse m_zgLittleHouse;
	CLittleHouse m_zgLittleHouse2;
	CLittleHouse m_zgLittleHouse3;
	
public:
	CLandscape();
	~CLandscape();

	

	void Init();

	CPlacement* GetRootPlacement();
};

