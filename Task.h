#pragma once
#include "Namespaces.h"

class Task
{
	static int IdGenerator;
	int id = 0;
	Entities RequiredProduct;
	int RequiredQuantity;
	int RewardBalance;
	int RewardScore;

public:
	Task(const Entities& prod, int quant, int bal, int score);
	

	int GetId() const;
	Entities GetReqiredProduct() const;
	int GetRequiredQuantity() const;
	int GetRewardBalance() const;
	int GetRewardScore() const;

	void SetId(int id);
	void SetRequiredProduct(const Entities& e);
	void SetRequiredQuantity(const int q);
	void SetRewardBalance(const int b);
	void SetRewardScore(const int s);

	void Print() const;



};

int Task::IdGenerator = 1;