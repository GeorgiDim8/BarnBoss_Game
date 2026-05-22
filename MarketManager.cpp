#include "MarketManager.h"

MarketManager& MarketManager::GetInstance()
{
    static MarketManager instance;
    return instance;
}
