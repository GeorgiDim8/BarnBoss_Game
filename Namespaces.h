#pragma once
#include<string>
#include<iostream>

enum crops {
corn,
wheat
};

enum class Entities
{
	Air = 0,
	Wheatseed,
	Wheat,
	Cornseed,
	Corn,
	Chicken,
	Egg,
	Cow,
	Milk
};

enum class UserTypes 
{
	Player,
	MarketManager,
	TaskManager
};

std::string EntityToString(Entities);
Entities StringToEntity(const std::string&);
Entities IdToEntity(int id);
Entities IntToEntity(int id);
Entities& operator++(Entities& e);

UserTypes StringToUserType(const std::string&);
std::string UserTypeToString(const UserTypes& t);