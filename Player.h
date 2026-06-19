#pragma once
#include "User.h"
#include "Farm.h"

class Taskboard;
class Market;

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
	bool SowPlant(const Entities& seedId);
	bool AddAnimal(const Entities& animalId);
	void Harvest(Barn& barn);
	void OpenMarketCatalog(Market& market);
	bool BuyItem(Market& market, int productId, int quantity);
	bool SellItem(Market& market, int productId, int quantity);
	void ShowTaskBoard(Taskboard& taskboard);
	bool CompleteTask(Taskboard& taskboard, int taskId);

	Barn& GetBarn();
	int GetBalance();
	int GetScore();
	void SetScore(int s);
	void Cycle();

	void profileInfo() override;
	UserTypes GetType() override;
};