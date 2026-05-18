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
	Cow,
	Egg,
	Milk
};

std::string EntityToString(Entities);
Entities StringToEntity(const std::string&);
Entities& operator++(Entities& e);