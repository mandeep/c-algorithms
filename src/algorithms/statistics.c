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
* ith_order_statistic - find the ith smallest number in the array
*
* @array - the array of integers in which to find the ith smallest number
* @low - the first index of the array
* @high - the last index of the array
* @ith - the ith smallest number to find
*
* Returns: the ith smallest number in the array
*/
int ith_order_statistic(int array[], int low, int high, int ith) {
    if (low == high) {
        return array[low];
    }

    int pivot = partition(array, low, high);

    int middle = pivot - low + 1;

    if (ith == middle) {
        return array[pivot];
    } else if (ith < middle) {
        return ith_order_statistic(array, low, pivot - 1, ith);
    } else {
        return ith_order_statistic(array, pivot + 1, high, ith - middle);
    }
}
