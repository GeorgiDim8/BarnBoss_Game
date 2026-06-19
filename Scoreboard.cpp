#include "Scoreboard.h"

void Scoreboard::showScoreboard(const std::vector<std::unique_ptr<User>>& users) const
{
    std::cout << "=== SCOREBOARD ===" << std::endl;

    std::vector<Player*> players;

    for (const auto& u : users)
    {
        if (u->GetType() == UserTypes::Player)
        {
            players.push_back(static_cast<Player*>(u.get()));
        }
    }

    std::sort(players.begin(), players.end(),
        [](Player* a, Player* b)
        {
            return a->GetScore() > b->GetScore();
        });

    int i = 1;

    for (const auto& p : players)
    {
        std::cout << i << ". "
            << p->GetName()
            << " | Score: "
            << p->GetScore()
            << std::endl;
        i++;
    }
}
