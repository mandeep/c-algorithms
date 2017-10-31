#include <stdio.h>
#include <stdlib.h>


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
* bubble_sort - traverse an array and swap neighbors until the array is sorted
*
* @array: the array to sort
* @length: the length of the array
*
* Returns: void
*/
void bubble_sort(int array[], int length) {
    for (int _ = 0; _ < length; ++_) {
        for (int j = 0; j < length - 1; ++j) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
