#include "Tests.h"
#include "Repository.h"
#include "Service.h"
#include "School.h"
#include <assert.h>
void Tests::test_all()
{
	test_remove_repository();
	test_remove_service();
}

void Tests::test_remove_service()
{
	Repository* repo = new Repository();
	Service* service = new Service(repo);
	service->generate_random();
	assert(service->get_all().size() == 5);
	char name[] = "Avram_Iancu";
	service->remove(name, 46.77, 23.60);
	assert(service->get_all().size() == 4);

}

void Tests::test_remove_repository()
{
	Repository* repo = new Repository();
	Service* service = new Service(repo);
	service->generate_random();
	assert(repo->get_all().size() == 5);
	char name[] = "Avram_Iancu";
	service->remove(name, 46.77, 23.60);
	assert(repo->get_all().size() == 4);
}
