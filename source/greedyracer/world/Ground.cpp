#include "Ground.h"


Ground::Ground()
{
}


Ground::~Ground()
{
	free(this->groundPlacements);
	free(this->quadGeos);
}

void Ground::Init(float quadWidth, float quadHeight, int width, int height)
{
	int memSize = width * height;
	this->quadGeos = NULL;
	this->groundPlacements = NULL;
	this->groundPlacements = new CPlacement[memSize];
	this->quadGeos = new CGeoQuad[memSize];

	//this->groundPlacements = (CPlacement*)malloc(sizeof(CPlacement) * memSize); 
	//memset(this->groundPlacements, 0x00, sizeof(CPlacement) * memSize);
	//this->quadGeos = (CGeoQuad*)malloc(sizeof(CGeoQuad) * memSize); 
	//memset(this->quadGeos, 0x00, sizeof(CPlacement) * memSize);

	this->material.MakeTextureDiffuse("textures\\natur\\Gras_512.png");
	this->material.MakeTextureSpecular("textures\\black_image.jpg");

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int currentOffset = x + (y * width);
			this->quadGeos[currentOffset].Init(quadWidth, quadHeight, &this->material);
			this->quadGeos[currentOffset].MapPlanarZ();
			this->groundPlacements[currentOffset].AddGeo(&this->quadGeos[x]);
			this->groundPlacements[currentOffset].RotateXDelta(-HALFPI);
			this->groundPlacements[currentOffset].TranslateDelta(CHVector(20 * x, 0, 20 * y));
			this->overallPlacement.AddPlacement(&this->groundPlacements[currentOffset]);
		}
	}
}

CPlacement* Ground::GetPlacement()
{
	return  &this->overallPlacement;
}
