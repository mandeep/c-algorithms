
#include "greatest.h"

#include "../src/algorithms/euclidean_algorithm.c"


TEST test_recursive_gcd(void) {
    ASSERT_EQ_FMT(recursive_gcd(2, 3), 1, "%d");
    ASSERT_EQ_FMT(recursive_gcd(5, 15), 5, "%d");
    ASSERT_EQ_FMT(recursive_gcd(300, 900), 300, "%d");
    PASS();
}

TEST test_iterative_gcd(void) {
    ASSERT_EQ_FMT(iterative_gcd(2, 3), 1, "%d");
    ASSERT_EQ_FMT(iterative_gcd(5, 15), 5, "%d");
    ASSERT_EQ_FMT(iterative_gcd(300, 900), 300, "%d");
    PASS();
}


SUITE(euclidean_algorithms) {
    RUN_TEST(test_recursive_gcd);
    RUN_TEST(test_iterative_gcd);
}
