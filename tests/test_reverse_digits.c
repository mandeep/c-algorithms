#include <string.h>
#include "greatest.h"

#include "../src/algorithms/reverse_digits.c"


TEST test_reverse_digits(void) {
    ASSERT_EQ_FMT(reverse_digits(487892), 298784, "%d");
    ASSERT_EQ_FMT(reverse_digits(98434000), 43489, "%d");
    ASSERT_EQ_FMT(reverse_digits(-12300), -321, "%d");
    ASSERT_EQ(strcmp(reverse_digits("123"), "321"), 0); 
    ASSERT_EQ(strcmp(reverse_digits("42543200"), "234524"), 0);
    ASSERT_EQ(strcmp(reverse_digits("-87876"), "-67878"), 0);
    PASS();
}


SUITE(reverse_algorithms) {
    RUN_TEST(test_reverse_digits);
}
