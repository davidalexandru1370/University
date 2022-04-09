#include "Console.h"
#include <iostream>
#include <string>
#include "School.h"
using namespace std;
void Console::run_console()
{
	int running = 1;
	service->generate_random();
	while (running)
	{
		int command;
		show_menu();
		fseek(stdin, 0, SEEK_END);
		cin >> command;

		if (command == 1)
		{
			ui_remove();
		}
		else if (command == 2) {
			list_all_sorted();
		}
		else if (command == 3) {
			task_3();
		}
		else {
			cout << "Invalid command\n";
		}
	}
}

Console::Console(Service* _service)
{
	service = _service;
}

void Console::show_menu()
{
	cout << "Press 1 to remove\n";
	cout << "press 2 to show all sorted\n";
	cout << "press 3 to solve task 3\n";
}

void Console::ui_remove()
{
	char name[100];
	fseek(stdin, 0, SEEK_END);
	cin >> name;
	fseek(stdin, 0, SEEK_END);
	float latitude;
	float longitude;
	fseek(stdin, 0, SEEK_END);
	cin >> longitude;
	fseek(stdin, 0, SEEK_END);
	cin >> latitude;
	try
	{
		service->remove(name, longitude, latitude);
		cout << "Removed!\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << "\n";
	}
}

void Console::list_all_sorted()
{
	vector<School>v = service->get_all();
	v = service->sort_by_name(v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << "name = " << v[i].get_name() << " longitude " << v[i].get_longitude() << " latitude " << v[i].get_latitude() << " date " << v[i].get_date_of_visit() << " visited " << v[i].get_visited();
		cout << "\n";
	}
}

void Console::task_3()
{
	fseek(stdin, 0, SEEK_END);
	char date[100];
	cin >> date;
	service->task_3(date);
}
