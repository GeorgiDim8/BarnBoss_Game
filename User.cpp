#include "User.h"

static int IdGenerator = 1;

User::User(const std::string& u, const std::string& p)
{
	SetName(u);
	SetPassword(p);
}

std::string User::GetPassword()
{
	return password;
}

std::string User::GetName()
{
	return username;
}

int User::GetId()
{
	return id;
}

void User::SetPassword(const std::string& password)
{
	this->password = password;
}

void User::SetName(const std::string& name)
{
	username = name;
}

void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
	if (oldPassword != GetPassword())throw std::invalid_argument("Wrong password!");

	if(newPassword.size() < 3) throw std::invalid_argument("Password too short");
		
    SetPassword(newPassword);
}
