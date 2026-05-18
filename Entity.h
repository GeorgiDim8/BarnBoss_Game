#pragma once
#include "Namespaces.h"

class Entity 
{

	Entities object;

	int required_cycles = 0;
	int current_cycles = 0;

public:

	Entity(Entities& e);
	Entity(const Entity& e);
	int GetRequiredCycles() const;
	int GetCurrentCycles() const;
	Entities GetEntity() const;
	void SetRequiredCycles(int count);
	void SetCurrentCycles(int count);
	void SetEntity(Entities e);

	bool Ready();
	virtual void Cycle() = 0;
	virtual Entities Reward() const = 0;

	virtual void Print() const = 0;

	virtual ~Entity() = default;

};