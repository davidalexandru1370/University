#include <iostream>
#include "Tests.h"
#include "Console.h"
#include "TrenchRepository.h"
#include "TrenchService.h"
#include "UserRepository.h"
int main()
{
	Tests().run_all_tests();
	TrenchRepository* repository = new TrenchRepository();
	UserRepository* user_repository = new UserRepository();
	TrenchService* service = new TrenchService(repository,user_repository);
	Console* console = new Console(service);
	console->run_console();
}

