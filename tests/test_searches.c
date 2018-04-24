#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greatest.h"

#include "../src/algorithms/binary_search.c"
#include "../src/algorithms/linear_search.c"


int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 24, 26, 28, 30};
int length = sizeof(array) / sizeof(int);

TEST test_binary_search(void) {
    int index = binary_search(array, length, 12);
    ASSERT_EQ(index, 5);
    PASS();
}

TEST test_linear_search(void) {
    int index = linear_search(array, length, 30);
    ASSERT_EQ(index, 13);
    PASS();
}

SUITE(searching_algorithms) {
    RUN_TEST(test_binary_search);
    RUN_TEST(test_linear_search);
}
