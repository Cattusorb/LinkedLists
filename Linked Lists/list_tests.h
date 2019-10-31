#ifndef LIST_TESTS_H_INCLUDED
#define LIST_TESTS_H_INCLUDED

#include "linked_list.h"

// UTILITIES //
void test_with_strings(const char*, const char*, const char*);
void test_with_ints(const char*, const int, const int);
void test_is_null(const char*, void*);
char* int_formatter(void*);

// BASIC TESTS //
void test_size_empty_list();
void test_size_null_list();
void test_size_normal_list();

// ADDITION TESTS //
void add_to_null_fails();
void add_negative_n_fails();
void add_too_large_n_fails();
void add_to_beginning_of_empty_list();
void add_to_end_of_empty_list();
void add_to_beginning_of_non_empty_list();
void add_to_end_of_non_empty_list();
void add_to_middle_of_list();

// ACCESS TESTS //
void get_from_null_fails();
void get_from_empty_fails();
void get_negative_n_fails();
void get_too_large_n_fails();
void get_first_works();
void get_last_works();
void get_middle_works();

// DELETION TESTS //
void remove_from_null_fails();
void remove_from_empty_fails();
void remove_negative_n_fails();
void remove_too_large_n_fails();
void remove_first_of_non_empty_list();
void remove_last_of_non_empty_list();
void remove_from_middle_of_list();
void remove_only_node_works();

// GROUPINGS OF TESTS//
void basic_tests();
void addition_tests();
void access_tests();
void deletion_tests();
void all_list_tests();


#endif // LIST_TESTS_H_INCLUDED
