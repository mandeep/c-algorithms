#include "greatest.h"

#include "../src/algorithms/bits.c"


TEST test_bit_algorithms(void) {
    ASSERT_EQ(count_ones(8), 1);
    ASSERT_EQ(count_ones(63), 6);
    ASSERT_EQ(check_parity(10), 0);
    ASSERT_EQ(check_parity(11), 1);
    ASSERT_EQ(swap_bits(10, 2, 3), 6);
    ASSERT_EQ(swap_bits(6, 0, 1), 5);
    ASSERT_EQ(reverse_bits(10), 5);
    ASSERT_EQ(reverse_bits(11), 13);
    PASS();
}


SUITE(bit_algorithms) {
    RUN_TEST(test_bit_algorithms);
}
