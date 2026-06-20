#pragma once
#include "UserFactory.h"
#include "UserManager.h"
#include "Taskboard.h"
#include "Scoreboard.h"
#include<sstream>
#include<fstream>

class Game 
{
	UserManager userManager;
	Market m;
	Taskboard t;
	Scoreboard s;

public:

	bool ProcessCommand(const std::string& input);
	bool ProcessPlayerCommand(Player& player,
		const std::string& command,
		std::stringstream& ss);
	bool ProcessMarketCommand(MarketManager& manager,
		const std::string& command,
		std::stringstream& ss);
	bool ProcessTaskCommand(TaskManager& manager,
		const std::string& command,
		std::stringstream& ss);
	void Save();
	bool Load();
	Market& getMarket();
	Taskboard& getTaskboard();
};