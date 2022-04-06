#include "Service.h"
#include <algorithm>
#include <iostream>
Service::Service(Repository* _repository)
{
	repository = _repository;
}
void Service::add(char* name, char* nationality, char* team, int number_of_goals)
{

	Player* player = new Player(number_of_goals, name, nationality, team);
	repository->add(player);
}

std::vector<Player*> Service::get_all()
{
	return repository->get_all();
}

std::vector<Player*> Service::get_players_in_a_team(char* team)
{
	std::vector<Player*>players_in_a_team;
	std::vector<Player*>players = get_all();
	for (std::vector<Player*>::iterator it = players.begin(); it < players.end(); it++)
	{
		if (strcmp((*it)->get_team(), team) == 0)
		{
			players_in_a_team.push_back(*it);
		}
	}
	return players_in_a_team;
}

std::vector<Player*> Service::sort_a_team_by_number_of_goals(std::vector<Player*>team)
{
	std::sort(team.begin(), team.end(), Player().cmp);
	return team;
}

void Service::generate_random_players(int count)
{
	for (size_t index = 1; index <= count; index++)
	{
		char team[10];
		char nation[10] = "RO";
		char name[10];
		sprintf(team, "%s%d", "team", index % 2);
		sprintf(name, "%s%d", "name", index);
		add(name, nation, team, rand() % 10);
	}
}
