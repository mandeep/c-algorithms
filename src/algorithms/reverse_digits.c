#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define reverse_digits(x) _Generic((x), int: reverse_digits_int, char*: reverse_digits_string)(x)


int reverse_digits_int(int n) {
    int reverse = 0;
    int sign = n < 0 ? -1 : 1;

    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return reverse * sign;
}


char *reverse_digits_string(char *string) {
    int negative = string[0] == '-' ? true : false;
    int n = strlen(string);
    char *reverse = malloc(sizeof(char) * n);

    for (int i = 0; i < n; i++) {
        reverse[i] = string[n - i - 1];
    }

    while (reverse[0] == '0') {
        memmove(reverse, reverse+1, strlen(reverse));
    }

    if (negative) {
       for (int i = n - 1; i > 0; i--) {
           reverse[i] = reverse[i - 1];
       }
       reverse[0] = '-';
    }

    return reverse;
}
