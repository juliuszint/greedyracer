#include "Tree.h"

void CTree::Init(){
	m_zgTip.InitTubeOriel(2.0f, 2.0f, 0.2f, &m_zmLeafs);
	m_zgMiddle.InitTubeOriel(2.5f, 2.0f, 0.2f, &m_zmLeafs);
	m_zgBottom.InitTubeOriel(3.0f, 2.5f, 0.2f, &m_zmLeafs);
	m_zgLog.InitTubeSine(1.0f, 0.8f, 3.0f, 0.2f, &m_zmLog);

	m_zpTip.AddGeo(&m_zgTip);
	m_zpMiddle.AddGeo(&m_zgMiddle);
	m_zpBottom.AddGeo(&m_zgBottom);
	m_zpLog.AddGeo(&m_zgLog);

	m_zpTip.RotateX(PI);
	m_zpTip.TranslateYDelta(5.5f);
	m_zpMiddle.RotateX(PI);
	m_zpMiddle.TranslateYDelta(4.2f);
	m_zpBottom.RotateX(PI);
	m_zpBottom.TranslateYDelta(3.8f);
	m_zpLog.TranslateY(0.0f);

	m_zpTree.AddPlacement(&m_zpTip);
	m_zpTree.AddPlacement(&m_zpMiddle);
	m_zpTree.AddPlacement(&m_zpBottom);
	m_zpTree.AddPlacement(&m_zpLog);
}

CPlacement* CTree::GetRootPlacement(){
	return &m_zpTree;
}