#include "Tests.h"
#include <assert.h>
void Tests::test_service_add()
{
	Repository* repo = new Repository();
	Service* service = new Service(repo);
	char name[] = "david";
	char nation[] = "RO";
	char team[] = "u cluj";
	service->add(name, nation, team, 5);
	assert(service->get_all().size() == 1);
}

void Tests::test_repository_add()
{
	Repository* repo = new Repository();
	char name[] = "david";
	char nation[] = "RO";
	char team[] = "u cluj";
	Player* p1 = new Player(5, name,nation,team);
	repo->add(p1);
	assert(repo->get_all().size() == 1);
}

void Tests::run_all_tests()
{
}
