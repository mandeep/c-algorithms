#include <stdlib.h>


/**
* binary_search - continually halve an array to find the index of an element
*
* @numbers: the array to search through
* @count: the length of the array
* @number: the index of the number to find in the array
*
* Returns: the index of the number if found, else -1
*/
int binary_search(int numbers[], size_t count, int number) {
    int low = 0;
    int high = count - 1;

    while (low <= high) { 
        int middle = (low + high) / 2;
        if (number > numbers[middle]) {
            low = middle + 1;
        } else if (number < numbers[middle]) {
            high = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}
