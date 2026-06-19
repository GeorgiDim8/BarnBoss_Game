#include "Game.h"



bool Game::ProcessCommand(const std::string& input)
{
	std::stringstream ss(input);

	std::string command;
	ss >> command;

	if (command == "register")
	{
		std::string username;
		std::string password;
		std::string type;

		ss >> username >> password >> type;

		
		if (userManager.Register(username, password, type))
		{
			std::cout << "User registered successfully!" << std::endl;
		}

		else
		{
			std::cout << "Registration failed!" << std::endl;
		}


		return true;
	}

	if (command == "login")
	{
		std::string username;
		std::string password;

		ss >> username >> password;

		if (userManager.Login(username, password)) 
		{
			std::cout << "Welcome, " << username<< "!" << std::endl;
			return true;
		}
		std::cout << "Invalid username or password!" << std::endl;
		return false;
	}
	if (command == "logout")
	{
		if (!userManager.GetCurrentUser())
		{
			std::cout << "No user is logged in!" << std::endl;
			return false;
		}
		userManager.Logout();

		return true;
	}

	if (command == "exit")
	{
		Save();
		return true;
	}

	if (input.starts_with("profileInfo"))
	{
		userManager.GetCurrentUser()->profileInfo();
		return true;
	}


	User* current = userManager.GetCurrentUser();
	if (!current) {
		//std::cout << "Invalid command! Try again." << std::endl;
		return false;
	}

	if (current->GetType() == UserTypes::Player) 
	{
		Player* player = static_cast<Player*>(current);
		return ProcessPlayerCommand(*player, command, ss);
	}

	if (current->GetType() == UserTypes::MarketManager) 
	{
		MarketManager* marketmanager = static_cast<MarketManager*>(current);
		return ProcessMarketCommand(*marketmanager, command, ss);
	}

	if (current->GetType() == UserTypes::TaskManager)
	{
		TaskManager* taskmanager = static_cast<TaskManager*>(current);
		return ProcessTaskCommand(*taskmanager, command, ss);
	}

	/*

	if (input.starts_with("checkBarn"))
	{
		current->
	}
	if (input.starts_with("openMarketCatalog"))
	{

		return true;
	}
	if (input.starts_with("buyItem"))
	{

		return true;
	}
	if (input.starts_with("sowPlant"))
	{

		return true;
	}
	if (input.starts_with("addAnimal"))
	{

		return true;
	}
	if (input.starts_with("harvest"))
	{

		return true;
	}
	if (input.starts_with("showTaskBoard"))
	{

		return true;
	}
	if (input.starts_with("checkBalance"))
	{

		return true;
	}
	*/
	std::cout << "No matching command" << std::endl;
		return true;
}

bool Game::ProcessPlayerCommand(Player& player,
	const std::string& command,
	std::stringstream& ss)
{

	if (command == "checkBarn") 
	{
		player.CheckBarn();
		return true;
	}

	if (command == "checkBalance")
	{
		std::cout<<"Current balance: "<<player.CheckBalance() << std::endl;
		return true;
	}

	if (command == "checkScore") 
	{
		std::cout << "Current score: " << player.CheckScore() << std::endl;
		return true;	
	}

	if (command == "checkFarm") 
	{
		player.CheckFarm();
		return true;
	}

	if (command == "expandCropland") 
	{
		return player.ExpandCropland();
	}

	if (command == "expandFarmland") 
	{
		return player.ExpandFarmland();
	}

	if (command == "sowPlant") 
	{
		int plantT;
		ss >> plantT;

		return player.SowPlant(IntToEntity(plantT));
	}
	if (command == "addAnimal") 
	{
		int animalT;
		ss >> animalT;

		return player.AddAnimal(IntToEntity(animalT));
	}

	if (command == "harvest") 
	{
		player.Harvest(player.GetBarn());

		return true;
	}

	if (command == "openMarketCatalog") 
	{
		player.OpenMarketCatalog(m);
		return true;
	}

	if (command == "buyItem") 
	{
		int id1, qnt;
		ss >> id1 >> qnt;
		std::cout << "Ok1" << std::endl;
		return player.BuyItem(m, id1, qnt);
	}

	if (command == "sellItem")
	{
		int id1, qnt;
		ss >> id1 >> qnt;
		return player.SellItem(m, id1, qnt);
	}

	if (command == "showTaskBoard") 
	{
		player.ShowTaskBoard(t);
		return true;
	}

	if (command == "completeTask") 
	{
		int id1;
		ss >> id1;
		return player.CompleteTask(t, id1);
	}

	if (command == "showScoreboard") 
	{
		s.showScoreboard(userManager.getUsers());
		return true;
	}
	std::cout << "No matching command" << std::endl;
	return true;
	
}

bool Game::ProcessMarketCommand(MarketManager& manager, const std::string& command, std::stringstream& ss)
{

	
	if (command == "openMarketCatalog") 
	{
		manager.openMarketCatalog(m);
		return true;
	}
	if (command == "restock") 
	{
		int id1, qnt;
		ss >> id1 >> qnt;

		return manager.Restock(m, id1, qnt);
	}

	if (command == "changePrice") 
	{
		int id1, prc;
		ss >> id1 >> prc;

		return manager.ChangePrice(m, id1, prc);
	}
	std::cout << "No matching command" << std::endl;
	return true;
}

bool Game::ProcessTaskCommand(TaskManager& manager, const std::string& command, std::stringstream& ss)
{

	if (command == "showTasks") 
	{
		manager.showTasks(t);
		return true;
	}
	

	if (command == "addTask") 
	{
		std::string pr;
		int quantity, rbalance, rscore;
		ss >> pr >> quantity >> rbalance >> rscore;

		return manager.AddTask(t, pr, quantity, rbalance, rscore);
	}
	if (command == "removeTask") 
	{
		int taskId;
		ss >> taskId;

		return manager.RemoveTask(t, taskId);
	}

	std::cout << "No matching command" << std::endl;
	return true;
}


void Game::Save()
{

}
