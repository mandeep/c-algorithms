#ifndef SWAP_FUNC_
#define SWAP_FUNC_


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


#endif


/**
* insertion_sort - traverse an array and swap minimum elements until the array is sorted
*
* @array: the array to sort
* @length: the length of the array
*
* Returns: void
*/
void selection_sort(int array[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        int minimum = i;
        for (int j = i+1; j < length; ++j) {
            if (array[j] < array[minimum]) {
                minimum = j;
            }
        }
        swap(&array[minimum], &array[i]);
    }
}
