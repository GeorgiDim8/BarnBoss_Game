#include "Namespaces.h"
#include <stdexcept>

std::string EntityToString(Entities e) 
{ 
	switch (e) 
	{
		case Entities::Chicken: { return "Chicken"; }

		case Entities::Corn: { return "Corn"; }
						   
		case Entities::Cornseed: { return "Cornseed"; }

		case Entities::Cow: { return "Cow"; }

		case Entities::Egg: { return "Egg"; }

		case Entities::Milk: { return "Milk"; }

		case Entities::Wheat: { return "Wheat"; }

		case Entities::Wheatseed: { return "Wheatseed"; }
	
		default: { return "Unknown"; }
	}
}


Entities StringToEntity(const std::string& s) 
{
	if (s == "Chicken") return Entities::Chicken;

	else if (s == "Corn") return Entities::Corn;

	else if (s == "CornSeed") return Entities::Cornseed;

	else if (s == "Cow") return Entities::Cow;

	else if (s == "Egg") return Entities::Egg;

	else if (s == "Milk") return Entities::Milk;

	else if (s == "Wheat") return Entities::Wheat;

	else if (s == "WheatSeed") return Entities::Wheatseed;

	else throw std::invalid_argument("Invalid product!");
}

Entities IdToEntity(int id)
{
	Entities e = static_cast<Entities>(id);
	return e;
}

Entities IntToEntity(int id)
{
	if (id == 1) return Entities::Wheatseed;
	if (id == 2) return Entities::Cornseed;
	if (id == 3) return Entities::Chicken;
	if (id == 4) return Entities::Cow;
	return Entities();
}

Entities& operator++(Entities& e)
{
	e = static_cast<Entities>(static_cast<int>(e) + 1);

	return e;
}

bool IdCheck(int productId) 
{
	if (productId < 1 || productId > 8) {
		std::cout << "Wrong id" << std::endl;
		return false;
	}
	return true;
}

UserTypes StringToUserType(const std::string& t) 
{
	if (t == "MarketManager") return UserTypes::MarketManager;
	if (t == "TaskManager") return UserTypes::TaskManager;
	if (t == "Player") return UserTypes::Player;

	throw std::invalid_argument("No such type");
}

std::string UserTypeToString(const UserTypes& t)
{
	switch (t) 
	{
	case UserTypes::Player:
		{
			return "Player";
			break;
		}
	case UserTypes::MarketManager: 
	{
		return "MarketManager";
		break;
	}
	case UserTypes::TaskManager: 
	{
		return "TaskManager";
		break;
	}

	}
	return "";
}
