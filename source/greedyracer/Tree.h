#pragma once
#include "Vektoria\Root.h"
using namespace Vektoria;

class CTree
{
public:
	CTree();
	~CTree();

	CGeo* m_pzgLeafs;
	CGeo* m_pzgLog;
	CFileWavefront m_zgLeafs;
	CFileWavefront m_zgLog;
	CPlacement m_zpLeafs;
	CPlacement m_zpLog;
	CPlacement m_zpTree;
	CMaterial m_zmLeafs;
	CMaterial m_zmLog;
	
	void InitTree();
	void InitTreeBush();
	void InitTreeRound();
	void InitTreeRow();
	CPlacement* GetPlacementTree();
	
};

