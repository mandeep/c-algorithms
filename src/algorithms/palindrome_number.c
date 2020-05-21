#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/**
* is_palindrome_int - determine whether the given integer is a palindrome
*
* @n: the positive integer to check
*
* Returns: a boolean value of whether or not the integer is a palindrome
*
*/
bool is_palindrome_int(size_t n) {
    size_t length = floor(log10(n)) + 1;
    :x
:xc
:x
:x

    for (size_t _ = 0; _ < length / 2; _++) {
        if (n / exponent != n % 10) {
            return false;
        }
        n %= exponent;
        n /= 10;
        exponent /= 100;
    }
    return true;
}
