#include "Scoreboard.h"

void Scoreboard::showScoreboard(const std::vector<std::unique_ptr<User>>& users) const
{
	std::cout << "=== SCOREBOARD ===" << std::endl;
	std::sort(users.begin(), user.end(), [](std::unique_ptr<Player> a, std::unique_ptr<Player> b) 
	{
			return a->GetScore() > b->GetScore();
	});
	int i = 1;
	for (const auto& u : users) 
	{
		std::cout << i << ". ";
	
		std::cout << u->GetName() << " | Score: ";
		std::cout << u->Get

			i++;
	}
}
