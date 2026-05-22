#include "User.h"

static int IdGenerator = 1;

std::string User::GetPassword()
{
	return password;
}

void User::SetPassword(const std::string& password)
{
	this->password = password;
}

void User::SetName(const std::string& name)
{
	username = name;
}

void User::logout()
{

}

void User::changePassword(const std::string& oldPassword, const std::string& newPassword)
{
	if (oldPassword == GetPassword())SetPassword(newPassword);
}
