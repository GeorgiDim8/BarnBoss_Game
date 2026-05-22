#pragma once
#include "User.h"
#include "Farm.h"
#include "Market.h"

class Player : public User 
{
	Barn barn;
	Farm farm;
	int balance = 100;
	int score = 0;

public:

	Player(const std::string& name, const std::string& password);
	void SetBalance(int bal);
	int CheckBalance();
	int CheckScore();
	void CheckBarn();
	void CheckFarm();
	bool ExpandCropland();
	bool ExpandFarmland();
	bool SowPlant(Entities& seedId);
	bool AddAnimal(Entities animalId);
	void Harvest(Barn& barn);
	void OpenMarketCatalog(Market& market);
	bool BuyItem(Market& market, int productId, int quantity);
	bool SellItem(Market& market, int productId, int quantity);
	void ShowTaskBoard();
	bool CompleteTask(int taskId);

	Barn& GetBarn();
	void Cycle();

};