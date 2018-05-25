#include "greatest.h"

#include "../src/algorithms/reverse_digits.c"


TEST test_reverse_digits(void) {
    ASSERT_EQ_FMT(reverse_digits(487892), 298784, "%d");
    ASSERT_EQ_FMT(reverse_digits(98434000), 43489, "%d");
    ASSERT_EQ_FMT(reverse_digits(-12300), -321, "%d"); 
    PASS();
}


SUITE(reverse_algorithms) {
    RUN_TEST(test_reverse_digits);
}
