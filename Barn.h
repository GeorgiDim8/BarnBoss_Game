#pragma once
#include<map>
#include "Namespaces.h"

class Barn 
{
	std::map<Entities, int> products;
	
public:

	void AddItem(Entities e, int count);
	bool RemoveItem(Entities e, int count);
	bool Check(Entities e, int count) const;

	void print();

};