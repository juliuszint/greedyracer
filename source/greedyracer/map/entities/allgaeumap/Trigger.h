#pragma once
#include "C:\Users\Peter\Documents\GitHub\greedyracer\source\greedyracer\map\entities\Entity.h"
class CTrigger :
	public CEntity
{
private:
	CGeo* m_pzgTrigger;
	CFileWavefront m_zgTrigger;
	CPlacement m_zpTrigger;
	CMaterial m_zmTrigger;

public:
	CTrigger();
	~CTrigger();

	void InitTree();
	void InitRocks();
	void InitBeerbarrel();
	CPlacement * GetRootPlacement();
	CGeo * GetGeo();

};

