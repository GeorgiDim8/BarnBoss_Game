#include "Player.h"
#include "Namespaces.h"
#include "Market.h"
#include "Taskboard.h"

Player::Player(const std::string& name, const std::string& password)
	: User(name, password)
{
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

	Cycle();

	return true;
}

bool Player::ExpandFarmland()
{
	if (CheckScore() < (10 * farm.GetFarmlandCapacity())) return false;
	else if (CheckBalance() < farm.GetFarmlandCapacity() * 50) return false;

	SetBalance(CheckBalance() - farm.GetFarmlandCapacity() * 50);
	farm.SetFarmlandCapacity(farm.GetFarmlandCapacity() + 1);

	Cycle();

	return true;
}

bool Player::SowPlant(const Entities& seedId)
{
	if (farm.GetCroplandCapacity() - farm.GetPlantCount() < 1)return false;

	if (!GetBarn().Check(seedId, 1)) return false;

	Cycle();
	
	GetBarn().RemoveItem(seedId, 1);

	farm.AddPlant(std::make_unique<PlantEntity>(seedId));
	
	return true;
}

bool Player::AddAnimal(const Entities& animalId)
{
	if (farm.GetFarmlandCapacity() - farm.GetAnimalCount() < 1)return false;

	Cycle();

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
	if (market.BuyItem(*this, market.GetTypeId(productId), quantity))
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

	if (market.SellItem(*this, market.GetTypeId(productId), quantity))
	{
		Cycle();
		return true;
	}
	return false;
}

void Player::ShowTaskBoard(Taskboard& taskboard)
{
	taskboard.Print();
}

bool Player::CompleteTask(Taskboard& taskboard, int taskId)
{
	if (taskboard.CompleteTask(*this, taskId))
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

int Player::GetBalance()
{
	return balance;
}

int Player::GetScore()
{
	return score;
}

void Player::SetScore(int s)
{
	score = s;
}

void Player::Cycle()
{
	farm.Cycle();
}

void Player::profileInfo()
{
	std::cout << "ID: " << this->GetId() << std::endl;
	std::cout << "Username: " << this->GetName() << std::endl;
	std::cout << "Type: " << UserTypeToString(this->GetType()) << std::endl;
	std::cout << "Balance: " << this->GetBalance() << std::endl;
	std::cout << "Score: " << this->GetId() << std::endl;

}

UserTypes Player::GetType()
{
	return UserTypes::Player;
}
