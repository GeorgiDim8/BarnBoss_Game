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

		if (username.size() < 1 || password.size() < 4 || type.size() < 6)throw std::invalid_argument("Invalid register input!");
		
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

	if (command == "help") 
	{
		std::cout << "Available commands: \n register [username] [password] [ProfileType] \n"
			<< "login [username][password] \n logout \n exit \n help \n profileinfo \n"
			<< "\n Player specific commands: \n checkBarn \n checkBalance \n checkScore \n "
			<< "checkFarm \n expandFarmland \n expandCropland \n harvest \n openMarketCatalog \n"
			<< "sowPlant [PlantType] (1 = WheatSeed, 2 = CornSeed) \n addAnimal [animalType] (3 = Chicken, 4 = Cow) \n buyItem [itemId] [Quantity] \n"
			<< "sellItem [itemId] [Quantity] \n showTaskboard \n completeTask [taskId] \n"
			<< "showScoreboard \n \n MarketManager specific commands: \n openMarketCatalog \n"
			<< "restock [ItemId] [Quantity] \n changePrice [ItemId] [Price] \n \n "
			<< "TaskManager specific commands: \n showTasks \n addtask [Product] [Quantity] [RewardBalance] [Score] \n "
			<< "removeTask [TaskId] \n \n";
	}

	if (input.starts_with("profileInfo"))
	{
		if (!userManager.GetCurrentUser())throw std::invalid_argument("No user currently logged in!");
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
		if (plantT != 1 && plantT != 2)throw std::invalid_argument("Invalid plant type");
		return player.SowPlant(IntToEntity(plantT));
	}
	if (command == "addAnimal") 
	{
		int animalT;
		ss >> animalT;
		if (animalT != 3 && animalT != 4)throw std::invalid_argument("Invalid animal type");
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
		return player.BuyItem(m, id1, qnt);
	}

	if (command == "sellItem")
	{
		int id1, qnt;
		ss >> id1 >> qnt;
		return player.SellItem(m, id1, qnt);
	}

	if (command == "showTaskboard") 
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
	std::ofstream out("save.txt");

	if (!out.is_open())
	{
		std::cout << "Failed to open save file!\n";
		return;
	}

	out << "[USERS]\n";

	for (const auto& userPtr : userManager.getUsers())
	{
		User* u = userPtr.get();

		out << (int)u->GetType() << " "
			<< u->GetName() << " "
			<< u->GetPassword() << " ";

		if (u->GetType() == UserTypes::Player)
		{
			Player* p = static_cast<Player*>(u);
			out << p->GetScore() << " "
				<< p->GetBalance();
		}

		out << "\n";
	}

	out << "[MARKET]\n";

	for (const auto& [entity, item] : m.getItems())
	{
		out << (int)entity << " "
			<< item.GetQuantity() << " "
			<< item.GetCost() << "\n";
	}

	out << "[TASKS]\n";

	for (const auto& taskPtr : t.GetTasks())
	{
		out << (int)taskPtr->GetReqiredProduct() << " "
			<< taskPtr->GetRequiredQuantity() << " "
			<< taskPtr->GetRewardBalance() << " "
			<< taskPtr->GetRewardScore()
			<< "\n";
	}

	out << "[FARMS]\n";

	for (const auto& userPtr : userManager.getUsers())
	{
		if (userPtr->GetType() != UserTypes::Player)
			continue;

		Player* p = static_cast<Player*>(userPtr.get());

		out << p->GetName() << "\n";

		Farm& farm = p->GetFarm();
		
		out << farm.GetCroplandCapacity() << "\n";
		out << farm.GetFarmlandCapacity() << "\n";

		out << farm.GetPlantCount() << "\n";

		for (const auto& plant : farm.GetPlants())
		{
			out << EntityToString(plant->GetEntity()) << " "
				<< plant->GetCurrentCycles()
				<< "\n";
		}

		out << farm.GetAnimalCount() << "\n";

		for (const auto& animal : farm.GetAnimals())
		{
			out << EntityToString(animal->GetEntity()) << " "
				<< animal->GetCurrentCycles()
				<< "\n";
		}
	}

	out << "[BARNS]\n";

	for (const auto& userPtr : userManager.getUsers())
	{
		if (userPtr->GetType() != UserTypes::Player)
			continue;

		Player* p = static_cast<Player*>(userPtr.get());

		out << p->GetName() << "\n";

		const auto& barnItems = p->GetBarn().getProducts();

		out << barnItems.size() << "\n";

		for (const auto& [entity, qty] : barnItems)
		{
			out << EntityToString(entity) << " " << qty << "\n";
		}
	}

	out.close();

	
}

bool Game::Load()
{
	std::ifstream in("save.txt");

	if (!in.is_open())
	{
		std::cout << "No save file found. Creating new world...\n";
		return false;
	}

	std::string line;
	std::string section;

	while (std::getline(in, line))
	{
		if (line.empty()) continue;

		if (line[0] == '[')
		{
			section = line;
			continue;
		}

		std::stringstream ss(line);

		if (section == "[USERS]")
		{
			int type;
			std::string username, password;
			ss >> type >> username >> password;

			std::string typeStr;

			if (type == (int)UserTypes::Player)
				typeStr = "Player";
			else if (type == (int)UserTypes::MarketManager)
				typeStr = "MarketManager";
			else if (type == (int)UserTypes::TaskManager)
				typeStr = "TaskManager";

			auto user = UserFactory::createUser(username, password, typeStr);

			if (!user)
				continue;

			if (type == (int)UserTypes::Player)
			{
				int score, balance;
				ss >> score >> balance;

				Player* p = static_cast<Player*>(user.get());
				p->SetScore(score);
				p->SetBalance(balance);
			}

			userManager.AddUser(user);
		}

		else if (section == "[MARKET]")
		{
			int entity, qty, cost;
			ss >> entity >> qty >> cost;

			m.SetStock(static_cast<Entities>(entity), qty);
			m.ChangePrice(static_cast<Entities>(entity), cost);
		}


		else if (section == "[TASKS]")
		{
			int prod, qty, bal, score;
			ss  >> prod >> qty >> bal >> score;
			Task a(static_cast<Entities>(prod),
				qty,
				bal,
				score);

			t.AddTask(a);
		}
		else if (section == "[FARMS]")
		{
			//std::string username;
			//std::getline(in, line);
			//username = line;
			std::string username = line;

			Player* player = nullptr;

			for (auto& u : userManager.getUsers())
			{
				if (u->GetType() == UserTypes::Player &&
					u->GetName() == username)
				{
					player = static_cast<Player*>(u.get());
					break;
				}
			}

			if (!player)
				continue;

			std::getline(in, line);
			int cropCap = std::stoi(line);

			std::getline(in, line);
			int farmCap = std::stoi(line);

			player->GetFarm().SetCroplandCapacity(cropCap);
			player->GetFarm().SetFarmlandCapacity(farmCap);

			std::getline(in, line);
			int plantCount = std::stoi(line);
			
			

			for (int i = 0; i < plantCount; i++)
			{
				std::getline(in, line);
				std::stringstream ss(line);


				std::string type;
				int cycle;

				ss >> type >> cycle;

				PlantEntity plant(StringToEntity(type));

				plant.SetCurrentCycles(cycle);

				player->GetFarm().AddPlant(std::make_unique<PlantEntity>(plant));
			}

			std::getline(in, line);
			int animalCount = std::stoi(line);

			for (int i = 0; i < animalCount; i++)
			{
				std::getline(in, line);
				std::stringstream ss(line);


				std::string type;
				int cycle;

				ss >> type >> cycle;

				AnimalEntity animal(StringToEntity(type));

				animal.SetCurrentCycles(cycle);

				player->GetFarm().AddAnimal(std::make_unique<AnimalEntity>(animal));
			}
		}
		

		else if (section == "[BARNS]")
{

	std::string username = line;
    Player* player = nullptr;

    for (auto& u : userManager.getUsers())
    {
        if (u->GetType() == UserTypes::Player && u->GetName() == username)
        {
            player = static_cast<Player*>(u.get());
            break;
        }
    }

    if (!player)
        continue;

    std::string line;

    std::getline(in, line);
    int itemCount = std::stoi(line);

    for (int i = 0; i < itemCount; i++)
    {
        std::getline(in, line);
        std::stringstream ss(line);

        std::string entityStr;
        int qty;

        ss >> entityStr >> qty;


        Entities e = StringToEntity(entityStr);

        player->GetBarn().AddItem(e, qty);
    }
}
	}


	std::cout << "Game loaded successfully!\n";
	return true;
}

Market& Game::getMarket()
{
	return m;
}

Taskboard& Game::getTaskboard()
{
	return t;
}
