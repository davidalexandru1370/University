#pragma once
#include <vector>
#include "Player.h"
class Repository
{
private:
	std::vector<Player*> data;
public:
	void add(Player* player);
	std::vector<Player*>get_all();
	bool check_if_exists(Player* p);
};

