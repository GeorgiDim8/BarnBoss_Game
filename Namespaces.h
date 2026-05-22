#pragma once
#include<string>
#include<iostream>

enum crops {
corn,
wheat
};

enum class Entities
{
	Air,
	Wheatseed,
	Wheat,
	Cornseed,
	Corn,
	Chicken,
	Egg,
	Cow,
	Milk
};

std::string EntityToString(Entities);
Entities StringToEntity(const std::string&);
Entities IdToEntity(int id);
Entities& operator++(Entities& e);