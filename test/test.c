#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void pass_test(void) {
	CU_PASS("Compilation success");
}

int main(int argc, char *argv[])
{
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("compile_test", 0, 0);

	CU_add_test(suite, "pass_test", pass_test);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return 0;
}