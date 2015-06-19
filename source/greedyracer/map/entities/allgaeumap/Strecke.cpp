#include "Strecke.h"

CStrecke::~CStrecke()
{
	free(this->Start);
	free(this->CP1);
	free(this->CP2);
	free(this->CP3);
	free(this->CP4);
	free(this->CP5);
	free(this->Cut1_1);
	free(this->Cut1_2);
	free(this->Cut2_1);
	free(this->Cut2_2);
	free(this->Cut3);
	free(this->Sektor1);
	free(this->Sektor2);
	free(this->Sektor3);
}

void CStrecke::Init()
{
	this->Start = new CStart();
	this->Start->Translate(CHVector(25.11, 0, 26.101));
	this->Start->Init();
	this->root.AddPlacement(this->Start->GetRootPlacement());

	this->CP1 = new CCheckpoint();
	this->CP1->Translate(CHVector(2.47, 0, 36.46));
	this->CP1->Init("meshes\\allgaeumap\\strecke\\03_CP_1.obj");
	this->root.AddPlacement(this->CP1->GetRootPlacement());

	this->CP2 = new CCheckpoint();
	this->CP2->Translate(CHVector(-22.231, 0, -4.751));
	this->CP2->Init("meshes\\allgaeumap\\strecke\\06_CP_2.obj");
	this->root.AddPlacement(this->CP2->GetRootPlacement());

	this->CP3 = new CCheckpoint();
	this->CP3->Translate(CHVector(-17.915, 0, -27.665));
	this->CP3->Init("meshes\\allgaeumap\\strecke\\08_CP_3.obj");
	this->root.AddPlacement(this->CP3->GetRootPlacement());

	this->CP4 = new CCheckpoint();
	this->CP4->Translate(CHVector(25.844, 0, -10.3));
	this->CP4->Init("meshes\\allgaeumap\\strecke\\11_CP_4.obj");
	this->root.AddPlacement(this->CP4->GetRootPlacement());

	this->CP5 = new CCheckpoint();
	this->CP5->Translate(CHVector(22.27, 0, 6.97));
	this->CP5->Init("meshes\\allgaeumap\\strecke\\13_CP_5.obj");
	this->root.AddPlacement(this->CP5->GetRootPlacement());

	this->Cut1_1 = new CAbkuerzung();
	this->Cut1_1->ConfigureInit(true, true, false);
	this->Cut1_1->Init("meshes\\allgaeumap\\strecke\\04_Abkz_1_p1.obj");
	this->Cut1_1->Translate(CHVector(1.25, 0, 34.78));
	this->Cut1_1->RotateTriggerY(0.0f, TRIGGERSTART);
	this->Cut1_1->TranslateTrigger(CHVector(-14.3, -0.2, -9.5), TRIGGERSTART);

	this->Cut1_1->RotateTriggerY(0.2f, TRIGGERMID);
	this->Cut1_1->TranslateTrigger(CHVector(-19.5, -0.2, -19.5), TRIGGERMID);
	this->root.AddPlacement(this->Cut1_1->GetRootPlacement());

	this->Cut1_2 = new CAbkuerzung();
	this->Cut1_2->ConfigureInit(false, false, true);
	this->Cut1_2->Init("meshes\\allgaeumap\\strecke\\05_Abkz_1_p2.obj");
	this->Cut1_2->Translate(CHVector(-41.66, 0, 15.438));
	this->Cut1_2->RotateTriggerY(1.2f, TRIGGEREND);
	this->Cut1_2->TranslateTrigger(CHVector(24, -0.2, -13), TRIGGEREND);
	this->root.AddPlacement(this->Cut1_2->GetRootPlacement());

	this->Cut2_1 = new CAbkuerzung();
	this->Cut2_1->ConfigureInit(true, true, false);
	this->Cut2_1->Init("meshes\\allgaeumap\\strecke\\09_Abkz_2_p1.obj");
	this->Cut2_1->Translate(CHVector(-16.507, 0, -27.478));
	this->Cut2_1->RotateTriggerY(1.8f, TRIGGERSTART);
	this->Cut2_1->TranslateTrigger(CHVector(3, -0.2, -0.8), TRIGGERSTART);

	this->Cut2_1->RotateTriggerY(1.6f, TRIGGERMID);
	this->Cut2_1->TranslateTrigger(CHVector(25, -0.2, -6.5f), TRIGGERMID);
	this->root.AddPlacement(this->Cut2_1->GetRootPlacement());

	this->Cut2_2 = new CAbkuerzung();
	this->Cut2_2->ConfigureInit(false, false, true);
	this->Cut2_2->Init("meshes\\allgaeumap\\strecke\\10_Abkz_2_p2.obj");
	this->Cut2_2->Translate(CHVector(14.47, 0, -26.164));
	this->Cut2_2->RotateTriggerY(0.3f, TRIGGEREND);
	this->Cut2_2->TranslateTrigger(CHVector(16, -0.2, 2.2), TRIGGEREND);
	this->root.AddPlacement(this->Cut2_2->GetRootPlacement());

	this->Cut3 = new CAbkuerzung();
	this->Cut3->ConfigureInit(true, true, true);
	this->Cut3->Init("meshes\\allgaeumap\\strecke\\12_Abkz_3.obj");
	this->Cut3->Translate(CHVector(24.25, 0, -10.58));
	this->Cut3->RotateTriggerY(-0.5f, TRIGGERSTART);
	this->Cut3->TranslateTrigger(CHVector(-7, -0.2, 1.2), TRIGGERSTART);

	this->Cut3->RotateTriggerY(0.0f * PI, TRIGGERMID);
	this->Cut3->TranslateTrigger(CHVector(-12, -0.2, 9.2), TRIGGERMID);

	this->Cut3->RotateTriggerY(0.3f, TRIGGEREND);
	this->Cut3->TranslateTrigger(CHVector(-6.1,-0.2,15.8), TRIGGEREND);

	this->root.AddPlacement(this->Cut3->GetRootPlacement());

	this->Sektor1 = new CSektor();
	this->Sektor1->Translate(CHVector(24.715, 0, 28.284));
	this->Sektor1->Init("meshes\\allgaeumap\\strecke\\02_Sekt_1.obj");
	this->root.AddPlacement(this->Sektor1->GetRootPlacement());

	this->Sektor2 = new CSektor();
	this->Sektor2->Translate(CHVector(-23.268, 0, -6.07));
	this->Sektor2->Init("meshes\\allgaeumap\\strecke\\07_Sekt_2.obj");
	this->root.AddPlacement(this->Sektor2->GetRootPlacement());

	this->Sektor3 = new CSektor();
	this->Sektor3->Translate(CHVector(23.677, 0, 7.535));
	this->Sektor3->Init("meshes\\allgaeumap\\strecke\\14_Sekt_3.obj");
	this->root.AddPlacement(this->Sektor3->GetRootPlacement());

	//Strecke verschieben
	root.Translate(CHVector(0, 0.1, 0));

	this->aCheckpoints[0] = CP1;
	this->aCheckpoints[1] = CP2;
	this->aCheckpoints[2] = CP3;
	this->aCheckpoints[3] = CP4;
	this->aCheckpoints[4] = CP5;

	this->aAbkuerzungen[0] = Cut1_1;
	this->aAbkuerzungen[1] = Cut1_2;
	this->aAbkuerzungen[2] = Cut2_1;
	this->aAbkuerzungen[3] = Cut2_2;
	this->aAbkuerzungen[4] = Cut3;

	this->aSektoren[0] = Sektor1;
	this->aSektoren[1] = Sektor2;
	this->aSektoren[2] = Sektor3;

}

CPlacement * CStrecke::GetRootPlacement()
{
	return &root;
}


int CStrecke::IsOnShortcutTrigger(CHVector position)
{
	CRay raytoRoad(position + CHVector(0.0f, 1.0f, 0.0f), CHVector(0.0f, -1.0f, 0.0f, 0.0f), QUASI_ZERO, F_MAX);
	for (int i = 0; i < 5; i++)
	{
		CGeoQuad* midTrigger = this->aAbkuerzungen[i]->GetMidTrigger();
		if (midTrigger != NULL)
		{
			if (midTrigger->IsIntersecting(raytoRoad))
			{
				return i + 1;
			}
		}
	}
	return -1;
}

CHVector CStrecke::GetStartPosition()
{
	return (this->Start->GetRootPlacement()->GetTranslation() + CHVector(0.0f, 0.255f, 0.0f, 0.0f));
}

int CStrecke::IsOnCheckpoint(CHVector position)
{
	return 0;
}

CHVector CStrecke::IsOnTrack(CHVector position)
{
	return CHVector(0, 0, 0);
}

bool CStrecke::IsOnFinish(CHVector position)
{
	return false;
}

CStart* CStrecke::getStartGeo()
{
	return this->Start;
}

CCheckpoint* CStrecke::getCheckpointGeo(int iarraypos)
{
	return this->aCheckpoints[iarraypos];
}

CSektor* CStrecke::getSektorGeo(int iarraypos)
{
	return this->aSektoren[iarraypos];
}

CAbkuerzung* CStrecke::getAbkuerzungGeo(int iarraypos)
{
	return this->aAbkuerzungen[iarraypos];
}


/*
CGeo * CStrecke::getStartGeo(){
	return this->Start->GetGeo();
}
CGeo * CStrecke::getCheckpointGeo(int pos){
	//return this->Checkpoints[pos]->GetGeo()
}
CGeo * CStrecke::getSektorGeo(int pos){
	//return this->Sektoren[pos]->GetGeo()
}
CGeo * CStrecke::getAbkuerzungGeo(int pos){
	//return this->Abkuerzungen[pos]->GetGeo()
}
*/