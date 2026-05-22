#include "MarketItem.h"

MarketItem::MarketItem(int q, int c)
{
    SetQuantity(q);
    SetCost(c);
}

int MarketItem::GetQuantity() const
{
    return quantity;
}

int MarketItem::GetCost() const
{
    return cost;
}

void MarketItem::SetQuantity(int q)
{
    quantity = q;
}

void MarketItem::SetCost(int c)
{
    cost = c;
}
