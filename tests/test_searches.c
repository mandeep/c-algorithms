#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greatest.h"

#include "../src/algorithms/searching.c"


int search_array[] = {2, 4, 6, 8, 10, 12, 12, 12, 14, 16, 18, 20, 24, 26, 28, 30};
int array_length = sizeof(search_array) / sizeof(int);


TEST test_binary_search(void) {
    int index = binary_search(search_array, array_length, 8);
    ASSERT_EQ_FMT(index, 3, "%d");

    index = binary_search(search_array, array_length, 26);
    ASSERT_EQ_FMT(index, 13, "%d");
    PASS();
}


TEST test_find_first_occurrence(void) {
    int index = find_first_occurrence(search_array, array_length, 12);
    ASSERT_EQ_FMT(index, 5, "%d");
    PASS();
}


TEST test_linear_search(void) {
    int index = linear_search(search_array, array_length, 30);
    ASSERT_EQ_FMT(index, 15, "%d");
    PASS();
}


SUITE(searching_algorithms) {
    RUN_TEST(test_binary_search);
    RUN_TEST(test_find_first_occurrence);
    RUN_TEST(test_linear_search);
}
