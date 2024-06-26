#include "greatest.h"

#include "../src/algorithms/check_parity.c"
#include "../src/algorithms/convert_to_binary.c"
#include "../src/algorithms/number_of_one_bits.c"
#include "../src/algorithms/reverse_bits.c"
#include "../src/algorithms/swap_bits.c"


TEST test_bit_algorithms(void) {
    ASSERT_EQ(count_ones(8), 1);
    ASSERT_EQ(count_ones(63), 6);
    ASSERT_EQ(check_parity(10), 0);
    ASSERT_EQ(check_parity(11), 1);
    ASSERT_EQ(swap_bits(10, 2, 3), 6);
    ASSERT_EQ(swap_bits(6, 0, 1), 5);
    ASSERT_EQ(reverse_bits(10), 5);
    ASSERT_EQ(reverse_bits(11), 13);

    int array[32] = {0};
    int_to_binary(256, array);
    for (int i = 31; i >= 0; i--) {
        if (i == 23) {
            ASSERT_EQ(array[i], 1);
        } else {
            ASSERT_EQ(array[i], 0);
        }
    }
    PASS();
}


SUITE(bit_algorithms) {
    RUN_TEST(test_bit_algorithms);
}
