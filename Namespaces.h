#pragma once
#include<string>
#include<iostream>

enum crops {
corn,
wheat
};

enum class Entities
{
	Wheatseed,
	Cornseed,
	Chicken,
	Cow,
	Wheat,
	Corn,
	Egg,
	Milk
};

std::string EntityToString(Entities);
Entities StringToEntity(const std::string&);