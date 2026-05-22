#include "MarketManager.h"

MarketManager& MarketManager::GetInstance()
{
    static MarketManager instance;
    return instance;
}

void MarketManager::openMarketCatalog(Market& m)
{
    m.Print();
}

bool MarketManager::Restock(Market& m, int productId, int quantity)
{
    if (productId < 1 || productId > 8) {
        std::cout << "Wrong id" << std::endl;
        return false;
    }

    m.Restock(IdToEntity(productId), quantity);
    return true;
}

bool MarketManager::ChangePrice(Market& m, int productId, int quantity)
{
    if (productId < 1 || productId > 8) {
        std::cout << "Wrong id" << std::endl;
        return false;
    }

    m.ChangePrice(IdToEntity(productId), quantity);
    return true;
}
