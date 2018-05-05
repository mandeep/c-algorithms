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
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


#endif
 

#ifndef PARTITION_FUNC_
#define PARTITION_FUNC_


/**
* partition - partition the subarray around the pivot element
*
* @array: the subarrray to partition
* @low: the first index of the subarray
* @high: the last index of the subarray
*
* Returns: the index of the new pivot
*/
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
 
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i += 1;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}


#endif


/**
* quick_sort - sort the given array by dividing it into partitioned subarrays
*
* @array: the array to sort
* @low: the first index of the array
* @high: the last index of the array
*
* Returns: void
*/
void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int middle = partition(array, low, high);
        quick_sort(array, low, middle - 1);
        quick_sort(array, middle + 1, high);
    }
}
