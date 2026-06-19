#include "UserManager.h"

bool UserManager::Register(const std::string& username, const std::string& password, const std::string& type)
{
    if (password.size() < 3) return false;

    if (type == "MarketManager" || type == "TaskManager")
        if (HasType(StringToUserType(type)))return false;

    for (const auto& user : users) 
    {
        if (user->GetName() == username) return false;
    }


    users.push_back(UserFactory::createUser(username, password, type));

    return true;
}

bool UserManager::Login(const std::string& username, const std::string& password)
{
    if (currentUser != nullptr) throw std::invalid_argument("A user is already logged in!");

    for (const auto& user : users)
    {
        if (user->GetName() == username)
        {
            if (user->GetPassword() == password)
            { 
                currentUser = user.get();
                return true;
            }
        }
    }

    return false;
}

void UserManager::Logout()
{
    currentUser = nullptr;
    std::cout << "Successfully logged out!" << std::endl;
}

bool UserManager::HasType(UserTypes type)
{
  
    for (const auto& user : users) 
    {
        if (user->GetType() == type) return true;
    }

    return false;
}

User* UserManager::GetCurrentUser()
{
    return currentUser;
}

const std::vector<std::unique_ptr<User>>& UserManager::getUsers() const
{
    return users;
}
