/**
* binary_search - continually halve an array to find the index of an element
*
* @numbers: the array to search through
* @count: the length of the array
* @number: the number to find in the array
*
* Returns: the index of the number if found, else -1
*/
int binary_search(int numbers[], unsigned int count, int number) {
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


/**
 * find_first_occurrence() - perform a binary search to find the first occurrence of the given number
 *
 * @numbers: the array containing sorted numbers in which to find the given number
 * @count: the number of elements in the array
 * @number: the number to find
 *
 * Returns: the index that contains the first occurrence of the given number
 *
 */
int find_first_occurrence(int numbers[], unsigned int count, int number) {
    int low = 0;
    int high = count - 1;
    int index = -1;

    while (low <= high) {
        int middle = (low + high) / 2;
        if (number > numbers[middle]) {
            low = middle + 1;
        } else if (number < numbers[middle]) {
            high = middle - 1;
        } else {
            index = middle;
            high = middle - 1;
        }
    }

    return index;
}


/**
* linear_search - traverse an array to find the index of an element
*
* @numbers: the array to search through
* @count: the length of the array
* @number: the index of the number to find in the array
*
* Returns: the index of the number if found, else -1
*/
int linear_search(int numbers[], int count, int number) {
    for (int i = 0; i < count; ++i) {
        if (numbers[i] == number) {
            return i;
        }
    }
    return -1;
}
