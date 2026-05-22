#pragma once
#include "MarketItem.h"
#include "Player.h"
#include<unordered_map>

class Market 
{
	std::unordered_map<Entities, MarketItem> items;

public:
	Market();
	bool BuyItem(Player& player, const Entities& e, int count);
	bool SellItem(Player& player, const Entities& e, int count);
	void ChangePrice(const Entities& e, int newPrice);
	void Restock(const Entities& e, int count);
	void Print() const;

};