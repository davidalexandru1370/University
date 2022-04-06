#include "Player.h"
#include <string>
Player::Player()
{
	this->name = new char[1];
	this->nationality = new char[1];
	this->team = new char[1];
	number_of_goals = 0;
}

Player::Player(int _goals, char* _name, char* _nationality,char* _team)
{
	this->number_of_goals = _goals;
	this->name = new char[strlen(_name)];
	this->nationality = new char[strlen(_nationality)];
	this->team = new char[strlen(_team)];
	strcpy(name, _name);
	strcpy(nationality, _nationality);
	strcpy(team, _team);
}

Player::Player(Player& player)
{
	number_of_goals = player.number_of_goals;
	this->name = new char[strlen(player.name)];
	this->nationality = new char[strlen(player.nationality)];
	this->team = new char[strlen(player.team)];
	strcpy(name, player.name);
	strcpy(nationality, player.nationality);
	strcpy(team, player.team);
}

Player::~Player()
{
	delete[] name;
	delete[] nationality;
}

int Player::get_number_of_goals()
{
	return number_of_goals;
}

void Player::set_number_of_goals(int new_number)
{
	number_of_goals = new_number;
}

char* Player::get_name()
{
	return name;
}

void Player::set_name(char* new_name)
{
	name = new char[strlen(new_name)];
	strcpy(name, new_name);
}

char* Player::get_nationality()
{
	//nationality = new char[strlen(new_nationality)];
	return nationality;
}

void Player::set_nationality(char* new_nationality)
{
	nationality = new char[strlen(new_nationality)];
	strcpy(nationality, new_nationality);
}

char* Player::get_team()
{
	return team;
}

void Player::set_team(char* new_team)
{
	team = new char[strlen(new_team)];
	strcpy(team, new_team);
}

bool Player::operator==(Player* player)
{
	if (strcmp(this->name, player->name) == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::cmp(const Player* p1, const Player* p2)
{
	if (p1->number_of_goals < p2->number_of_goals)
	{
		return false;
	}
	return true;
}
