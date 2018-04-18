/**
* swap - swap the values of the given parameters
*
* @a: the variable whose value will be changed to b's value
* @b: the variable whose value will be changed to a's value
*
* Returns: void
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


/**
* insertion_sort - traverse an array while bringing the smallest values to the front
*
* @array: the array to sort
* @length: the length of the array
*
* Returns: void
*/
void insertion_sort(int array[], int length) {
    for (int i = 1; i < length; ++i) {
        while (i > 0 && array[i] < array[i-1]) {
            swap(&array[i], &array[i-1]);
            i -= 1;
        }
    }
}
