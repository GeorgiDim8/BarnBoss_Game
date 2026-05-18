#pragma once
#include "Namespaces.h"
#include "PlantEntity.h"
#include<vector>
#include<string>
#include<memory>

class Farm 
{
	std::vector<std::unique_ptr<PlantEntity>> plants;
	int croplandCapacity = 3;

public:

	void SetCroplandCapacity(int cap);
	int GetCroplandCapacity();
	void AddPlant(PlantEntity pl);


};
