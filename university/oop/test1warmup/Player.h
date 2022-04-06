#pragma once
class Player
{
private:
	int number_of_goals;
	char* name;
	char* nationality;
	char* team;
public:
	Player();
	Player(int _goals, char* _name, char* _nationality,char* _team);
	Player(Player& player);
	~Player();
	int get_number_of_goals();
	void set_number_of_goals(int new_number);
	char* get_name();
	void set_name(char* new_name);
	char* get_nationality();
	void set_nationality(char* new_nationality);
	char* get_team();
	void set_team(char* new_team);
	bool operator==(Player* player);
	static bool cmp(const Player* p1, const Player* p2);
};




