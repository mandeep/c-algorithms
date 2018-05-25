#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define reverse_digits(x) _Generic((x), int: reverse_digits_int, char*: reverse_digits_string)(x)


/**
* reverse_digits_int - reverse the digits of the given int
*
* @n: the integer whose digits to reverse
*
* Returns: the reverse of the int
*
* The digits of the int are returned in reverse unless the int
* ends in a zero in which case the zero is truncated. If the
* given int is negative the reverse will also be negative.
*/
int reverse_digits_int(int n) {
    int reverse = 0;
    int sign = n < 0 ? -1 : 1;

    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return reverse * sign;
}


/**
* reverse_digits_string - reverse the digits of the given string
*
* @string: reverse the digits of the given string
*
* Returns: the reverse of the string
*
* The digits of the string are returned in reverse unless the string
* ends in a zero in which case the zero is truncated. If the
* given string is negative the reverse will also be negative.
*/
char *reverse_digits_string(char *string) {
    int n = strlen(string);
    char *reverse = malloc(sizeof(char) * n);

    for (int i = 0; i < n; i++) {
        reverse[i] = string[n - i - 1];
    }

    while (reverse[0] == '0') {
        memmove(reverse, reverse+1, strlen(reverse));
    }

    if (string[0] == '-') {
       for (int i = n - 1; i > 0; i--) {
           reverse[i] = reverse[i - 1];
       }
       reverse[0] = '-';
    }

    return reverse;
}
