#include "Barn.h"

void Barn::AddItem(Entities e, int count)
{
	products[e] += count;


}

bool Barn::RemoveItem(Entities e, int count)
{
	if (!Check(e, count))return false;

	products[e] -= count;

	if (products[e] == 0) products.erase(products.find(e));
	return true;
}

bool Barn::Check(Entities e, int count) const
{
	auto loc = products.find(e);

	return loc != products.end() && loc->second >= count;
}

void Barn::print()
{

	std::cout << "==== BARN ==== "<<std::endl;

	for (const auto& [type, count] : products) 
	{
		std::cout << EntityToString(type) << " : " << count << std::endl;
	}
}
