#include "Farm.h"

void Farm::SetCroplandCapacity(int cap)
{
	croplandCapacity = cap;
}

int Farm::GetCroplandCapacity()
{
	return croplandCapacity;
}

void Farm::AddPlant(PlantEntity pl)
{
	plants.push_back(std::make_unique<PlantEntity>(pl));
}
