#pragma once
#include "Usermanager.h"
#include<vector>
#include<algorithm>


class Scoreboard 
{

public:

	void showScoreboard(const std::vector<std::unique_ptr<User>>& users) const;

};