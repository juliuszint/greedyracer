#pragma once
#include "Vektoria\Root.h"
#include "..\Entity.h"

using namespace Vektoria;

class CTrack : public Entity
{
private:
	CGeo* m_pzgAsphalt;
	CGeo* m_pzgAsphaltMarks;

	CFileWavefront m_zgAsphalt;
	CFileWavefront m_zgAsphaltMarks;

	CPlacement m_zpAsphalt;
	CPlacement m_zpAsphaltMarks;
	CPlacement m_zpTrack;

	CMaterial m_zmAsphalt;
	CMaterial m_zmAsphaltMarks;
public:
	void Init();

	CPlacement* GetRootPlacement();
};

