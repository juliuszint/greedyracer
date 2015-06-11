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
	this->Start->Init();
	this->root.AddPlacement(this->Start->GetRootPlacement());

	this->CP1 = new CCheckpoint();
	this->CP1->Init("meshes\\allgaeumap\\strecke\\03_CP_1.obj");
	this->root.AddPlacement(this->CP1->GetRootPlacement());

	this->CP2 = new CCheckpoint();
	this->CP2->Init("meshes\\allgaeumap\\strecke\\06_CP_2.obj");
	this->root.AddPlacement(this->CP2->GetRootPlacement());

	this->CP3 = new CCheckpoint();
	this->CP3->Init("meshes\\allgaeumap\\strecke\\08_CP_3.obj");
	this->root.AddPlacement(this->CP3->GetRootPlacement());

	this->CP4 = new CCheckpoint();
	this->CP4->Init("meshes\\allgaeumap\\strecke\\11_CP_4.obj");
	this->root.AddPlacement(this->CP4->GetRootPlacement());

	this->CP5 = new CCheckpoint();
	this->CP5->Init("meshes\\allgaeumap\\strecke\\13_CP_5.obj");
	this->root.AddPlacement(this->CP5->GetRootPlacement());

	this->Cut1_1 = new CAbkuerzung();
	this->Cut1_1->Init("meshes\\allgaeumap\\strecke\\04_Abkz_1_p1.obj");
	this->root.AddPlacement(this->Cut1_1->GetRootPlacement());

	this->Cut1_2 = new CAbkuerzung();
	this->Cut1_2->Init("meshes\\allgaeumap\\strecke\\05_Abkz_1_p2.obj");
	this->root.AddPlacement(this->Cut1_2->GetRootPlacement());

	this->Cut2_1 = new CAbkuerzung();
	this->Cut2_1->Init("meshes\\allgaeumap\\strecke\\09_Abkz_2_p1.obj");
	this->root.AddPlacement(this->Cut2_1->GetRootPlacement());

	this->Cut2_2 = new CAbkuerzung();
	this->Cut2_2->Init("meshes\\allgaeumap\\strecke\\10_Abkz_2_p2.obj");
	this->root.AddPlacement(this->Cut2_2->GetRootPlacement());

	this->Cut3 = new CAbkuerzung();
	this->Cut3->Init("meshes\\allgaeumap\\strecke\\12_Abkz_3.obj");
	this->root.AddPlacement(this->Cut3->GetRootPlacement());

	this->Sektor1 = new CSektor();
	this->Sektor1->Init("meshes\\allgaeumap\\strecke\\02_Sekt_1.obj");
	this->root.AddPlacement(this->Sektor1->GetRootPlacement());

	this->Sektor2 = new CSektor();
	this->Sektor2->Init("meshes\\allgaeumap\\strecke\\07_Sekt_2.obj");
	this->root.AddPlacement(this->Sektor2->GetRootPlacement());

	this->Sektor3 = new CSektor();
	this->Sektor3->Init("meshes\\allgaeumap\\strecke\\14_Sekt_3.obj");
	this->root.AddPlacement(this->Sektor3->GetRootPlacement());

	//Strecke verschieben
	root.Translate(CHVector(0, 0.1, 0));
}

CPlacement * CStrecke::GetRootPlacement()
{
	return &root;
}


CHVector CStrecke::GetStartPosition()
{
	return this->Start->GetRootPlacement()->GetTranslation();
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