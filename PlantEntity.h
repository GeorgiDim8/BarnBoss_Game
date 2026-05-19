#pragma once
#include "Namespaces.h"
#include "Entity.h"

class PlantEntity : Entity
{
	bool Grown = false;
	

public:
	/*
	PlantEntity(Entities& e);
	PlantEntity(const PlantEntity& pl);
	int GetRequiredCycles() const;
	int GetCurrentCycles() const;
	Entities GetEntity() const;
	
	void SetRequiredCycles(int count);
	void SetCurrentCycles(int count);
	void SetEntity(Entities e);
	void SetGrown();
	bool Ready();
	*/
	bool GetGrown() const;
	void SetGrown();
	void Cycle() override;
	bool Harvest(Barn& barn) override;

	void Print() const override;

};