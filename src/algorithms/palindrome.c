#include <math.h>
#include <stdbool.h>
#include <string.h>


#define is_palindrome(x) _Generic((x), size_t: is_palindrome_int, char*: is_palindrome_string)(x)


/**
* is_palindrome_string - determine whether the given string is a palindrome
*
* @string: the string to check
*
* Returns: a boolean value of whether or not the string is a palindrome
*
*/
bool is_palindrome_string(char *string) {
    for (size_t i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            return false;
        }
    }
    return true;
}


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
    size_t exponent = pow(10, length - 1);

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
