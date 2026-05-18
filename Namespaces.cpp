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

		case Entities::Wheatseed: { return "Wheat seed"; }
	
		default: { return "Unknown"; }
	}
}


Entities StringToEntity(const std::string& s) 
{
	if (s == "Chicken") return Entities::Chicken;

	else if (s == "Corn") return Entities::Corn;

	else if (s == "Corn seed") return Entities::Cornseed;

	else if (s == "Cow") return Entities::Cow;

	else if (s == "Egg") return Entities::Egg;

	else if (s == "Milk") return Entities::Milk;

	else if (s == "Wheat") return Entities::Wheat;

	else if (s == "Wheat seed") return Entities::Wheatseed;

	else throw std::invalid_argument("Invalid product!");
}

Entities& operator++(Entities& e)
{
	e = static_cast<Entities>(static_cast<int>(e) + 1);

	return e;
}
