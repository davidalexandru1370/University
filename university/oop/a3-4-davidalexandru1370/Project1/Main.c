#include <stdio.h>
#include "test.h"
#include <crtdbg.h>
#include "Country.h"
#include "Console.h"
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC

int main(int argc, char** argv) {
	run_all_tests();
	Repository* repository = create_repository(1, &destroy_country);
	Service* service = create_service(repository);
	Console* console=create_console(service);
	run_console(console);
	destroy_console(console);
	_CrtDumpMemoryLeaks();
	return 0;
}