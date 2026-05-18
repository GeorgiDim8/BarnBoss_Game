#pragma once
#include "Namespaces.h"
#include "Entity.h"

class PlantEntity :: Entity
{
	bool Grown = false;

public:

	PlantEntity(Entities& e);
	PlantEntity(const PlantEntity& pl);
	int GetRequiredCycles() const;
	int GetCurrentCycles() const;
	Entities GetEntity() const;
	bool GetGrown() const;
	void SetRequiredCycles(int count);
	void SetCurrentCycles(int count);
	void SetEntity(Entities e);
	void SetGrown();

	bool Ready();
	void Cycle();
	Entities Reward() const;

	void Print() const;

};