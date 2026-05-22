#pragma once

class MarketItem 
{
private:

	int quantity = 0;
	int cost = 0;

public:

	MarketItem(int q, int c);
	int GetQuantity() const;
	int GetCost() const;
	void SetQuantity(int q);
	void SetCost(int c);

};