#pragma once
#include "Repository.h"
class Service
{
private:
	Repository* repository;

public:
	Service(Repository* _repository);
	void add(char* name, char* nationality, char* team, int number_of_goals);
	std::vector<Player*> get_all();
	std::vector<Player*> get_players_in_a_team(char* team);
	std::vector<Player*> sort_a_team_by_number_of_goals(std::vector<Player*>team);
	void generate_random_players(int count);
};

