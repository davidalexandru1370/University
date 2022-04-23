#include <iostream>
#include "Tests.h"
#include "Console.h"
#include "TrenchRepository.h"
#include "TrenchService.h"
#include "UserRepository.h"
#include "TrenchFileRepository.h"
#include "UserFileRepository.h"
int main()
{
	Tests().run_all_tests();
	//TrenchRepository* repository = new TrenchRepository();
	//UserRepository* user_repository = new UserRepository();
	Repository* user_repository = new UserFileRepository("user_output");
	Repository* repository = new TrenchFileRepository("input.txt");
	TrenchService* service = new TrenchService(repository,user_repository);
	Console* console = new Console(service);
	console->run_console();
}

