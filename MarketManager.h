#pragma once
#include "User.h"

class MarketManager : public User 
{
	MarketManager();

public:

	static MarketManager& GetInstance();

	MarketManager(const MarketManager& m) = delete;
	MarketManager& operator=(const MarketManager& m) = delete;

	void openMarketCatalog();
	void Restock(Market& m, int productId, int quantity);
	void ChangePrice(Market& m, int productId, int quantity);

};