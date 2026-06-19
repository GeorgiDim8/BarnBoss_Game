#pragma once
#include "User.h"
#include "Market.h"

class MarketManager : public User 
{

public:
	MarketManager(const std::string& name, const std::string& pw);
	

	void openMarketCatalog(Market& m);
	bool Restock(Market& m, int productId, int quantity);
	bool ChangePrice(Market& m, int productId, int quantity);

	UserTypes GetType() override;
	void profileInfo() override;
};