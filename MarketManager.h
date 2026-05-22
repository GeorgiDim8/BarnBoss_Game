#pragma once
#include "User.h"
#include "Market.h"

class MarketManager : public User 
{
	MarketManager();

public:

	static MarketManager& GetInstance();

	MarketManager(const MarketManager& m) = delete;
	MarketManager& operator=(const MarketManager& m) = delete;

	void openMarketCatalog(Market& m);
	bool Restock(Market& m, int productId, int quantity);
	bool ChangePrice(Market& m, int productId, int quantity);

};