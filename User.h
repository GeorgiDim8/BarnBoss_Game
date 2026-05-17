#pragma once
#include<string>

class User 
{
	static int IdGenerator;
	int id;
	std::string username;
	std::string password;

	void logout();
	void changePassword(const std::string& oldPassword, const std::string& newPassword);
	void profileInfo();
	virtual void Register(const std::string& username, const std::string& password, const std::string& type);


};