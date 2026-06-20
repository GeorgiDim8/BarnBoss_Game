
#include <iostream>
#include "Game.h"

int main()
{
	Game FarmFrenzy;
	std::string input;

	std::cout << "========================================\n";
	std::cout << "            BARN BOSS\n";
	std::cout << "========================================\n";

	if (!FarmFrenzy.Load()) 
	{
		FarmFrenzy.getMarket().Initialize();
		FarmFrenzy.getTaskboard().Initialize();
	}
	std::cout << "Write \\help\\ for list of commands" << std::endl;

	while (true) 
	{
		std::cout << ">";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "exit") 
		{
			FarmFrenzy.Save();
			std::cout << "Game Saved Successfully. \n Goodbye!" << std::endl;
			break;
		}
		try {
			if (!FarmFrenzy.ProcessCommand(input))
				std::cout << "Unsuccessful command!" << std::endl;
		}
		catch (std::exception& e) 
		{
			std::cout << e.what() << std::endl;
		}

	}


	return 0;
}

