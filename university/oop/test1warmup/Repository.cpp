#include "Repository.h"
#include <exception>

void Repository::add(Player* player)
{
	if (check_if_exists(player)==true)
	{
		throw std::exception("Player already exists!");
	}
	data.push_back(player);
}

std::vector<Player*> Repository::get_all()
{
    return data;
}

bool Repository::check_if_exists(Player* p)
{
	for (std::vector<Player*>::iterator it = data.begin(); it < data.end(); it++)
	{
		if (*it == p)
		{
			return true;
		}
	}
	return false;
}
