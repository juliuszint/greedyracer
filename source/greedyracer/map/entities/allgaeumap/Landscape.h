#pragma once

#include "Vektoria\Root.h"
#include "VektoriaMath\Util.h"
#include "..\Entity.h"

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
public:
	CLandscape();
	~CLandscape();

	void Init();

	CPlacement* GetRootPlacement();
};

