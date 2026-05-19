#pragma once
#include "Namespaces.h"
#include "PlantEntity.h"
#include "AnimalEntity.h"
#include<vector>
#include<string>
#include<memory>

class Farm 
{
	std::vector<std::unique_ptr<PlantEntity>> plants;
	std::vector<std::unique_ptr<AnimalEntity>> animals;

	int croplandCapacity = 3;
	int farmlandCapacity = 3;

public:

	void SetCroplandCapacity(int cap);
	int GetCroplandCapacity() const;
	void SetFarmlandCapacity(int cap);
	int GetFarmlandCapacity() const;
	int GetPlantCount() const;
	int GetAnimalCount();

	bool AddPlant(std::unique_ptr<PlantEntity> pl);
	bool AddAnimal(std::unique_ptr<AnimalEntity> an);

	void Cycle();
	void Harvest(Barn& barn);


};
