#include "Console.h"
#include <iostream>
void Console::run_console()
{
	int running = 1;
	while (running)
	{
		print_menu();
		int option;
		std::cin >> option;
		if (option == 1)
		{

		}
		else if (option == 2)
		{

		}
		else if (option == 3)
		{

		}
		else {

		}
	}
}

void Console::print_menu()
{
	std::cout << "Press 1 to add a new player";
	std::cout << "Press 2 to print all players";
	std::cout << "Press 3 to print all players in a team";
}

void Console::add_player()
{

}

void Console::print_all()
{

}

void Console::print_all_in_a_team_sorted()
{
}
