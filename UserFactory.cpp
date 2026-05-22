#include "UserFactory.h"
#include "Player.h"
#include "MarketManager.h"
#include "TaskManager.h"

std::unique_ptr<User> UserFactory::createUser(const std::string& name, const std::string& password, const std::string& type)
{
    if (type == "Player") 
        return std::make_unique<Player>(name, password);

    if (type == "MarketManager")
        return std::make_unique<MarketManager>(name, password);

    if (type == "TaskManager")
        return std::make_unique<TaskManager>(name, password);

    return nullptr;
}
