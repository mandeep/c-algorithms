#include "greatest.h"
#include "../src/algorithms/palindrome_number.c"
#include "../src/algorithms/valid_palindrome.c"


TEST test_is_palindrome(void) {
    ASSERT_EQ(is_palindrome_int((size_t) 487892), 0);
    ASSERT_EQ(is_palindrome_int((size_t) 43400434), 1);
    ASSERT_EQ(is_palindrome_int((size_t) 4375335734), 1);
    ASSERT_EQ(is_palindrome_string("123321"), 1);
    ASSERT_EQ(is_palindrome_string("42543200"),  0);
    ASSERT_EQ(is_palindrome_string("6787876"), 1);
    PASS();
}


SUITE(palindrome_algorithms) {
    RUN_TEST(test_is_palindrome);
}
