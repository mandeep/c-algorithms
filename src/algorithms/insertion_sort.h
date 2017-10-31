#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int array[], int length) {
    for (int i = 1; i < length; ++i) {
        while (i > 0 && array[i] < array[i-1]) {
            swap(&array[i], &array[i-1]);
            i -= 1;
        }
    }
}
