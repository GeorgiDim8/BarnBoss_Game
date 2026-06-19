#pragma once
#include<string>
#include<stdexcept>
#include "Namespaces.h"

class User 
{
	static int IdGenerator;
	int id;
	std::string username;
	std::string password;

public:

	User(const std::string& u, const std::string& p);

	std::string GetPassword();
	std::string GetName();
	int GetId();
	void SetPassword(const std::string& password);
	void SetName(const std::string& name);

	
	void changePassword(const std::string& oldPassword, const std::string& newPassword);
	virtual void profileInfo() = 0;
	virtual UserTypes GetType() = 0;

	virtual ~User() = default;
};