#include "list_tests.h"

// Numbers to use for making lists
const int A = 0;
const int B = 1;
const int C = 2;

/*
 * Function: test_with_strings
 * ----------------------------
 * runs a test where the expected output is a char*
 *
 */
void test_with_strings(const char* test_name, const char* result, const char* expected) {
	printf("Test: %s... ", test_name);

	if (strcmp(result, expected) == 0) {
		printf("passed\n");
	} else {
		printf("FAILED. Expected %s (result %s)\n", expected, result);
	}
}

/*
 * Function: test_with_ints
 * ----------------------------
 * runs a test where the expected output is an integer
 *
 */
void test_with_ints(const char* test_name, const int result, const int expected) {
	printf("Test: %s... ", test_name);

	if (result == expected) {
		printf("passed\n");
	} else {
		printf("FAILED. Expected %d (result %d)\n", expected, result);
	}
}

/*
 * Function: test_is_null
 * ----------------------------
 * runs a test where the expected output is NULL
 *
 */
void test_is_null(const char* test_name, void* result) {
	printf("Test: %s... ", test_name);

	if (result == NULL) {
		printf("passed\n");
	} else {
		printf("FAILED. Expected NULL.");
	}
}

/*
 * Function: int_formatter
 * ----------------------------
 * returns a char* representation of the integer stored at a given address
 *
 *	data: points to an integer
 *
 */
char* int_formatter(void* data) {
	char* buffer = (char*) malloc(12 * sizeof(char));
	sprintf(buffer, "%d", *((int*) data));
	return buffer;
}
/**
// BASIC TESTS //
void test_size_empty_list() {
	LinkedList* list = create_list();
	int foo = (int) list_size(list);
	test_with_ints("Size of empty list = 0", foo, 0);
}

void test_size_null_list() {
	test_with_ints("list_size(NULL) = -1", list_size(NULL), -1);
}

void test_size_normal_list() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	add_end(list, &B, sizeof(int));
	add_end(list, &C, sizeof(int));
	test_with_ints("list_size works", list_size(list), 3);
}

// ADDITION TESTS //
void add_to_null_fails() {
	test_with_ints("Add to NULL list fails", add_end(NULL, &A, sizeof(int)), 0);
}

void add_negative_n_fails() {
	LinkedList* list = create_list();
	test_with_ints("Add with negative n fails", add_n(list, -1, &A, sizeof(int)), 0);
}

void add_too_large_n_fails() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	test_with_ints("Add with too large n fails", add_n(list, 2, &A, sizeof(int)), 0);
}

void add_to_beginning_of_empty_list() {
	LinkedList* list = create_list();
	add_beginning(list, &A, sizeof(int));
	test_with_strings("Add to beginning of empty list", get_string(list, int_formatter), "[0]");
}

void add_to_end_of_empty_list() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	test_with_strings("Add to end of empty list", get_string(list, int_formatter), "[0]");
}

void add_to_beginning_of_non_empty_list() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	test_with_strings("Add to beginning of non-empty list", get_string(list, int_formatter), "[1, 0]");
}

void add_to_end_of_non_empty_list() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	add_end(list, &B, sizeof(int));
	test_with_strings("Add to end of non-empty list", get_string(list, int_formatter), "[0, 1]");
}

void add_to_middle_of_list() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	add_end(list, &B, sizeof(int));
	add_n(list, 1, &C, sizeof(int));
	test_with_strings("Add to middle of non-empty list", get_string(list, int_formatter), "[0, 2, 1]");
}

// ACCESS TESTS //
void get_from_null_fails() {
	test_is_null("Get from NULL returns NULL", get_last(NULL));
}

void get_from_empty_fails() {
	LinkedList* list = create_list();
	test_is_null("Get from empty returns NULL", get_last(list));
}

void get_negative_n_fails() {
	LinkedList* list = create_list();
	test_is_null("Get with negative returns NULL", get_n(list, -1));
}

void get_too_large_n_fails() {
	LinkedList* list = create_list();
	add_end(list, &A, sizeof(int));
	test_is_null("Get with too large n returns NULL", get_n(list, 2));
}

void get_first_works() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	int i = *((int*) get_first(list));
	test_with_ints("Get first element works", i, A);
}

void get_last_works() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	int i = *((int*) get_last(list));
	test_with_ints("Get last element works", i, C);
}

void get_middle_works() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	int i = *((int*) get_n(list, 1));
	test_with_ints("Get middle element works", i, B);
}

// REMOVAL TESTS //
void remove_from_null_fails() {
	test_with_ints("Remove from NULL list fails", remove_last(NULL), 0);
}

void remove_from_empty_fails() {
	LinkedList* list = create_list();
	test_with_ints("Remove with negative n fails", remove_last(list), 0);
}

void remove_negative_n_fails() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	test_with_ints("Remove with negative n fails", remove_n(list, -1), 0);
}

void remove_too_large_n_fails() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	test_with_ints("Remove with too large n fails", remove_n(list, 3), 0);
}

void remove_first_of_non_empty_list() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	remove_first(list);
	test_with_strings("Remove first of non-empty list", get_string(list, int_formatter), "[1, 2]");
}

void remove_last_of_non_empty_list() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	remove_last(list);
	test_with_strings("Remove last of non-empty list", get_string(list, int_formatter), "[0, 1]");
}

void remove_from_middle_of_list() {
	LinkedList* list = create_list();
	add_beginning(list, &C, sizeof(int));
	add_beginning(list, &B, sizeof(int));
	add_beginning(list, &A, sizeof(int));
	remove_n(list, 1);
	test_with_strings("Remove from middle of non-empty list", get_string(list, int_formatter), "[0, 2]");
}

void remove_only_node_works() {
	LinkedList* list =  create_list();
	add_beginning(list, &C, sizeof(int));
	remove_first(list);
	test_with_strings("Remove only node works", get_string(list, int_formatter), "[]");
}

void basic_tests() {
    test_size_empty_list();
	test_size_null_list();
	test_size_normal_list();
}

void addition_tests() {
    add_to_null_fails();
	add_negative_n_fails();
	add_too_large_n_fails();
	add_to_beginning_of_empty_list();
	add_to_end_of_empty_list();
	add_to_beginning_of_non_empty_list();
	add_to_end_of_non_empty_list();
	add_to_middle_of_list();
}

void access_tests() {
    get_from_null_fails();
	get_from_empty_fails();
	get_negative_n_fails();
	get_too_large_n_fails();
	get_first_works();
	get_last_works();
	get_middle_works();
}

void deletion_tests() {
    remove_from_null_fails();
	remove_from_empty_fails();
	remove_negative_n_fails();
	remove_too_large_n_fails();
	remove_first_of_non_empty_list();
	remove_last_of_non_empty_list();
	remove_from_middle_of_list();
	remove_only_node_works();
}

void all_list_tests() {
    basic_tests();
    addition_tests();
    access_tests();
    deletion_tests();
}
*/
