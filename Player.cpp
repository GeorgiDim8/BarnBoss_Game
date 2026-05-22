#include "Player.h"

Player::Player(const std::string& name, const std::string& password)
{
	SetName(name);
	SetPassword(password);
}

void Player::SetBalance(int bal)
{
	balance = bal;
}

int Player::CheckBalance()
{
	return balance;
}

int Player::CheckScore()
{
	return score;
}

void Player::CheckBarn()
{
	barn.print();
}

void Player::CheckFarm()
{
	farm.Print();
}

bool Player::ExpandCropland()
{
	if (CheckScore() < (10 * farm.GetCroplandCapacity())) return false;
	else if (CheckBalance() < farm.GetCroplandCapacity() * 50) return false;
	
	SetBalance(CheckBalance() - farm.GetCroplandCapacity() * 50);
	farm.SetCroplandCapacity(farm.GetCroplandCapacity() + 1);

	return true;
}

bool Player::ExpandFarmland()
{
	if (CheckScore() < (10 * farm.GetFarmlandCapacity())) return false;
	else if (CheckBalance() < farm.GetFarmlandCapacity() * 50) return false;

	SetBalance(CheckBalance() - farm.GetFarmlandCapacity() * 50);
	farm.SetFarmlandCapacity(farm.GetFarmlandCapacity() + 1);

	return true;
}

bool Player::SowPlant(Entities& seedId)
{
	if (farm.GetCroplandCapacity() - farm.GetPlantCount() < 1)return false;


	farm.AddPlant(std::make_unique<PlantEntity>(seedId));
	
	return true;
}

bool Player::AddAnimal(Entities animalId)
{
	if (farm.GetFarmlandCapacity() - farm.GetAnimalCount() < 1)return false;

	farm.AddAnimal(std::make_unique<AnimalEntity>(animalId));

	return true;
}

void Player::Harvest(Barn& barn)
{
	farm.Harvest(barn);
}

void Player::OpenMarketCatalog(Market& market)
{
	market.Print();
}

bool Player::BuyItem(Market& market, int productId, int quantity)
{
	if (market.BuyItem(*this, IdToEntity(productId), quantity)) 
	{
		Cycle();
		return true;
	}
	return false;
}

bool Player::SellItem(Market& market, int productId, int quantity)
{
	if (productId < 1 || productId > 8) {
		std::cout << "Wrong id" << std::endl;
		return false;
	}

	if (market.SellItem(*this, IdToEntity(productId), quantity))
	{
		Cycle();
		return true;
	}
	return false;
}

Barn& Player::GetBarn()
{
	return barn;
}

void Player::Cycle()
{
	farm.Cycle();
}
