#include <stdbool.h>
#include <string.h>

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
