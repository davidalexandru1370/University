#pragma once
class Tests
{
public:
	static void run_all_tests();
private:
	static void test_vector_constructor();
	static void test_vector_push_back();
	static void test_trench();
	static void test_trench_getters_and_setters();
	static void test_trench_add_repository();
	static void test_delete_repository();
	static void test_update_repository();
	static void test_service_add();
	static void test_trench_validator();
};


