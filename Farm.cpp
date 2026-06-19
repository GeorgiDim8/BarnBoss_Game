#include "Farm.h"

void Farm::SetCroplandCapacity(int cap)
{
	croplandCapacity = cap;
}

int Farm::GetCroplandCapacity() const
{
	return croplandCapacity;
}

void Farm::SetFarmlandCapacity(int cap)
{
	farmlandCapacity = cap;
}

int Farm::GetFarmlandCapacity() const
{
	return farmlandCapacity;
}

int Farm::GetPlantCount() const
{
	return plants.size();
}

int Farm::GetAnimalCount()
{
	return animals.size();
}

bool Farm::AddPlant(std::unique_ptr<PlantEntity> pl)
{
	if (GetCroplandCapacity() > GetPlantCount())
	{
		plants.push_back(std::move(pl));
		return true;
	}
	else 
	{
		std::cout << "Cropland is full" << std::endl;
		return false;
	}
}

bool Farm::AddAnimal(std::unique_ptr<AnimalEntity> an)
{
	if (GetFarmlandCapacity() > GetAnimalCount())
	{
		animals.push_back(std::move(an));
		return true;
	}
	else
	{
		std::cout << "Farmland is full" << std::endl;
		return false;
	}
	
}

void Farm::Cycle()
{
	for (auto& p : plants) 
	{
		p->Cycle();
	}

	for (auto& a : animals) 
	{
		a->Cycle();
	}
}

void Farm::Harvest(Barn& barn)
{
	for (auto i = plants.begin(); i != plants.end();) 
	{
		if ((*i)->Harvest(barn))
		{
			i = plants.erase(i);

		}

		else ++i;
	}

	for (auto& a : animals)
	{
		a->Harvest(barn);
	}
}

void Farm::Print()
{
	std::cout << "There are currently " << GetCroplandCapacity() - GetPlantCount() << " empty plant spaces out of " <<
		GetCroplandCapacity() << std::endl;

	std::cout << "There are currently " << GetFarmlandCapacity() - GetAnimalCount() << " empty animal spaces out of " <<
		GetFarmlandCapacity() << std::endl;
}
