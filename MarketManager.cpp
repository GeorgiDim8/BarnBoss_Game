#include "MarketManager.h"



MarketManager::MarketManager(const std::string& name, const std::string& pw)
    : User(name, pw)
{
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

UserTypes MarketManager::GetType()
{
    return UserTypes::MarketManager;
}

void MarketManager::profileInfo()
{
    std::cout << "Market Manager logged in." << std::endl;
}
