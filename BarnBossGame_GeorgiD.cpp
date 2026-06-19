
#include <iostream>
#include "Game.h"

int main()
{
	Game FarmFrenzy;
	std::string input;

	std::cout << "========================================\n";
	std::cout << "            BARN BOSS\n";
	std::cout << "========================================\n";



	while (true) 
	{
		std::cout << ">";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "exit") 
		{
			std::cout << "Game Saved Successfully. \n Goodbye!" << std::endl;
			break;
		}
		if (!FarmFrenzy.ProcessCommand(input))
			std::cout << "Unsuccessful command!" << std::endl;

	}


	return 0;
}

