#pragma once
#include "MarketManager.h"
#include "TaskManager.h"
#include "User.h"
class Command 
{
	Player& p;

public:
	virtual void execute() = 0;
	virtual void info() = 0;

	~Command() = default;

};