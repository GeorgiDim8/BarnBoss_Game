#include "Market.h"

Market::Market()
{
	items[Entities::Chicken] = MarketItem(10,25);
	items[Entities::Egg] = MarketItem(15, 30);
	items[Entities::Cow] = MarketItem(5, 50);
	items[Entities::Milk] = MarketItem(10, 60);
	items[Entities::Wheatseed] = MarketItem(20, 10);
	items[Entities::Wheat] = MarketItem(20, 15);
	items[Entities::Cornseed] = MarketItem(20, 15);
	items[Entities::Corn] = MarketItem(20, 20);


}

bool Market::BuyItem(Player& player, const Entities& e, int count)
{
	int tempCost = items[e].GetCost() * count;
	if (player.CheckBalance() < tempCost || items[e].GetQuantity() < count)
	{
		std::cout << "err1" << std::endl;
		return false;
	}

	items[e].SetQuantity(items[e].GetQuantity() - count);
	player.SetBalance(player.CheckBalance() - tempCost);
	player.GetBarn().AddItem(e, count);

	return true;
}

bool Market::SellItem(Player& player, const Entities& e, int count)
{
	if (!player.GetBarn().Check(e, count)) return false;

	player.GetBarn().RemoveItem(e, count);
	items[e].SetQuantity(items[e].GetQuantity() + count);
	player.SetBalance(player.GetBalance() + items[e].GetCost() * count);

	return true;
}

void Market::ChangePrice(const Entities& e, int newPrice)
{
	items[e].SetCost(newPrice);
}

void Market::Restock(const Entities& e, int count)
{
	items[e].SetQuantity(items[e].GetQuantity() + count);
}

void Market::Print() const
{
	std::cout<<"=== MARKET CATALOG ==="<<std::endl;
	int i = 1;
	for (const auto& [entity,m] : items)
	{
		std::cout << i << ": " 
			<< EntityToString(entity)
			<< " | Qty: " << m.GetQuantity() 
			<< " | Price: " << m.GetCost() 
			<< std::endl;
		
		i++;

	}

}

Entities Market::GetTypeId(int MarketId)
{
	int i = 1;
	for (const auto& [entity, m] : items)
	{
		if (i == MarketId) return entity;

		i++;

	}
	// TODO: insert return statement here
}
