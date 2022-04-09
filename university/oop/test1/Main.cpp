#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "Console.h"
#include "Tests.h"
int main() {
	Tests().test_all();
	Repository* repo = new Repository();
	Service* service = new Service(repo);
	Console* console = new Console(service);
	console->run_console();

	return 0;
}