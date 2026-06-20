#pragma once
#include "Player.h"
#include "MarketManager.h"
#include "TaskManager.h"
#include "UserFactory.h"
#include<vector>

class UserManager 
{
	std::vector<std::unique_ptr<User>> users;
	User* currentUser = nullptr;


public:
	bool Register(const std::string& username,
		          const std::string& password,
		          const std::string& type);

	bool Login(const std::string& username,
		       const std::string& password);

	void Logout();

	bool HasType(UserTypes type);

	User* GetCurrentUser();

	const std::vector<std::unique_ptr<User>>& getUsers() const;
	void AddUser(std::unique_ptr<User>& user);




};