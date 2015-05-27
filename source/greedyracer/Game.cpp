#include "StdAfx.h"
#include "Game.h"
#include "RouteGenerator.h"

// Todo (julius): neue engine herunterladen (bug mit leerem Szenegraphen gefixed)
// blender lieber als .obj exportieren und dann importieren 


CGame::CGame(void)
{
	// Hier eventuelle Vorinitialisierungen Deiner Vektoria-Objekte einfügen:
}

CGame::~CGame(void)
{
	// Hier eventuelle Nachinitialisierungen Deiner Vektoria-Objekte einfügen:
}

void CGame::Init(HWND hwnd, CSplash * psplash)
{
	m_hwnd = hwnd;
	m_bReSized = false;
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	this->m_zroot.Init(psplash);
	this->camera.Init();
	
	this->m_zframe.Init(hwnd, eApiRender_DirectX11_Shadermodel50);
	this->m_zviewport.InitFull(&camera);
	this->m_zviewport.SetBackfaceCullingOff();

	//this->m_zviewport.SetWireframeOn();
	this->m_zframe.AddDeviceKeyboard(&this->keyboard);

	m_zlight.Init(CHVector(0, 1, 0), CColor(1, 1, 1));

	// Note(julius): mit der neusten blender version (2.47) funktioniert der import nicht!
	// mit der version (2.59) scheint alles zu klappen

	//this->worldGeo = this->importer.LoadGeo("..\\..\\models\\map.obj");
	//this->worldPlacement.AddGeo(this->worldGeo);
	//this->worldGeo->ReduceRedundancy();
	//this->worldPlacement.Translate(CHVector(0, 0, 0));
	//this->worldMaterial.MakeTextureDiffuse("textures\\mapTexture.jpg");
	//this->worldMaterial.MakeTextureSpecular("textures\\mapReflection.jpg");
	//this->worldMaterial.SetTextureGlowBlack();
	//this->worldGeo->SetMaterial(&this->worldMaterial);
	//this->worldGeo->MapPlanarY();
	//this->worldPlacement.Scale(12);
	//this->m_zscene.AddPlacement(&worldPlacement);
	//this->worldPlacement.RotateYDelta(HALFPI);

	this->carMaterial.MakeTextureDiffuse("textures\\green_image.jpg");
	this->carGeo.Init(1.05f, &this->carMaterial, 50, 50);
	this->carPlacement.AddGeo(&this->carGeo);
	this->carPlacement.Translate(CHVector(100.f, 1.1f, 400.f));
	this->m_zscene.AddPlacement(&this->carPlacement);

	this->routeMaterial.MakeTextureDiffuse("textures\\streettexture.jpg");
	this->routeMaterial.MakeTextureSpecular("textures\\black_image.jpg");
	this->routeMaterial.MakeTextureBump("textures\\streettexture_NRM.png");

	this->groundMaterial.MakeTextureDiffuse("textures\\grass.jpg");
	this->groundMaterial.MakeTextureSpecular("textures\\black_image.jpg");

	CRouteGenerator generator;
	CPlacement route = generator.Generate();

	Cont1.addCharacter(&carPlacement);
	Cont1.addKeyboard(&keyboard);
	Cont1.setKeybinding(DIK_U, DIK_J, DIK_H, DIK_K);


	for (int i = 0; i < RELEM; i++)
	{
		this->routeGeos[i].Init(28, 19, &this->routeMaterial);
		this->routeGeos[i].MapPlanarZ();
		this->routePlacements[i].AddGeo(&this->routeGeos[i]);
		this->routePlacements[i].RotateXDelta(-HALFPI);
		this->routePlacements[i].TranslateDelta(CHVector(100, 0.1, 100 + 38 * i,
			
			1));
		this->m_zscene.AddPlacement(&this->routePlacements[i]);
		//this->routePlacement.AddPlacement(&this->routePlacements[i]);
	}

	for (int x = 0; x < GELEM; x++)
	{
		for (int y = 0; y < GELEM; y++)
		{
			this->groundGeos[x][y].Init(10, 10, &this->groundMaterial);
			this->groundGeos[x][y].MapPlanarZ();
			this->groundPlacements[x][y].AddGeo(&this->groundGeos[x][y]);
			this->groundPlacements[x][y].RotateXDelta(-HALFPI);
			this->groundPlacements[x][y].TranslateDelta(CHVector(20 * x, 0, 20* y));
			this->m_zscene.AddPlacement(&this->groundPlacements[x][y]);
		}
	}

	//this->m_zscene.AddPlacement(&this->routePlacement);
	
	keyboard.SetWASDTranslationSensitivity(10);

	this->m_zroot.AddFrameHere(&m_zframe);
	this->m_zframe.AddViewport(&m_zviewport);
	this->m_zroot.AddScene(&m_zscene);


	this->cameraPlacement.AddCamera(&camera);
	this->cameraPlacement.Translate(CHVector(200, 200, 400));
	this->cameraPointPlacement.Translate(CHVector(200, 199, 400));

	//this->cameraPlacement.SetPointing(&this->cameraPointPlacement);
	this->m_zscene.AddPlacement(&this->cameraPlacement);

	this->m_zscene.AddParallelLight(&m_zlight);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Hier die Echtzeit-Veränderungen einfügen
	float res = fTimeDelta * 15;

	this->keyboard.PlaceWASD(this->cameraPlacement, res, true);
	
	this->Cont1.Move(10 * fTimeDelta);

	this->m_zroot.Tick(fTimeDelta);
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:

}

