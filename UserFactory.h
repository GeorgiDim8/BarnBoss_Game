#pragma once
#include<memory>
#include<string>
#include "User.h"

class UserFactory 
{

public:
	static std::unique_ptr<User> createUser(const std::string& name, const std::string& password,
		const std::string& type);

};