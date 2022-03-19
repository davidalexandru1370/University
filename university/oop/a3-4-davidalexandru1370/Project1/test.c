#include "Vector.h"
#include "Country.h"
#include "Repository.h"
#include "Service.h"
#include <assert.h>
#include <string.h>


void test_country() {
	Country* my_country = create_country(2, "romania", "europa");
	assert(strcmp(my_country->name, "romania") == 0);
	assert(strcmp(my_country->continent, "europa") == 0);
	assert(my_country->population == 2);
	destroy_country(my_country);
}

void test_vector() {
	vector* my_vector = create_vector(1, &destroy_country);
	assert(get_size(my_vector) == 1);
	Country* my_country = create_country(2, "romania", "europa");
	Country* my_country2 = create_country(3, "david", "boss");
	add_element_in_vector(my_vector, my_country);
	assert(get_length(my_vector) == 1);
	add_element_in_vector(my_vector, my_country2);
	assert(get_length(my_vector) == 2);
	destroy_vector(my_vector);
}

void test_repository() {
	Repository* repository = create_repository(1, &destroy_country);
	assert(get_length(repository->data) == 0);
	Country* my_country = create_country(2, "romania", "europa");
	Country* my_country2 = create_country(3, "david", "boss");
	Country* my_country3 = create_country(3, "franta", "boss");
	Country* my_country4 = create_country(4, "anglia", "boss");
	Country* my_country5 = create_country(5, "germania", "boss");
	add_element_in_repository(repository, my_country);
	assert(get_length(repository->data) == 1);
	add_element_in_repository(repository, my_country2);
	assert(get_length(repository->data) == 2);
	add_element_in_repository(repository, my_country3);
	assert(get_size(repository->data) == 4);
	add_element_in_repository(repository, my_country4);
	add_element_in_repository(repository, my_country5);
	assert(get_size(repository->data) == 8);
	destroy_repository(repository);
}

void test_service() {
	Repository* repository = create_repository(1, &destroy_country);
	Service* service = create_service(repository);
	assert(get_length(repository->data) == 0);
	add_element_in_service(service, 5000000, "romania", "europa");
	add_element_in_service(service, 2000000, "germania", "europa");
	add_element_in_service(service, 2000000, "franta", "europa");
	assert(get_service_length(service) == 3);
	remove_element_in_service(service, "germania");
	assert(get_service_length(service) == 2);
	remove_element_in_service(service, "franta");
	assert(get_service_length(service) == 1);
	
	add_element_in_service(service, 4000000, "germania", "noteuropa");
	assert(get_service_length(service) == 2);
	add_element_in_service(service, 3000000, "franta", "europa");
	add_element_in_service(service, 2000000, "spania", "noteuropa");
	assert(get_service_length(service) == 4);
	vector* continent = get_countries_on_a_continent(service, "europa");
	assert(get_length(continent) == 2);
	sort_vector_ascending_by_population(continent);
	assert(get_country_population(get_element_at_position_in_vector(continent, 0)) == 3000000);
	assert(get_country_population(get_element_at_position_in_vector(continent, 1)) == 5000000);
	destroy_vector(continent);
	destroy_service(service);
}

void run_all_tests() {
	test_country();
	test_vector();
	test_repository();
	test_service();
}