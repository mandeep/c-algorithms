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
