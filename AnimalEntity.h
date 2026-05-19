#pragma once
#include "Namespaces.h"
#include "Entity.h"

class AnimalEntity : Entity 
{

	int rewardCount = 0;

public:

	int GetRewardCount() const;
	void SetRewardCount(int n);

	void Cycle() override;
	bool Harvest(Barn& barn) override;

	void Print() const override;



};