#include "greatest.h"

#include "../src/algorithms/remove_duplicates.c"


TEST test_remove_duplicates(void) {
    int array[] = {1, 2, 2, 3, 3, 3, 4};
    int length = 7;
    length = remove_duplicates(array, length);
    ASSERT_EQ_FMT(length, 4, "%d");

    int array1[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6};
    length = 21;
    length = remove_duplicates(array1, length);
    ASSERT_EQ_FMT(length, 6, "%d");
    PASS();
}


SUITE(removal_algorithms) {
    RUN_TEST(test_remove_duplicates);
}
