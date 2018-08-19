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


/**
* counting_sort - traverse an array and swap minimum elements until the array is sorted
*
* @array: the unsorted array
* @output: an array to place the elements in sorted order from the given array
* @length: the length of the array given as a parameter
* @maximum: the maximum number in the array given as a parameter
*
* Returns: void
*/
void counting_sort(int array[], int output[], int length, int maximum) {
    int temp[maximum+1];

    for (int i = 0; i <= maximum; i++) {
        temp[i] = 0;
    }

    for (int j = 0; j < length; j++) {
        temp[array[j]] += 1;
    }

    for (int k = 1; k <= maximum; k++) {
        temp[k] += temp[k-1];
    }

    for (int m = length-1; m >= 0; m--) {
        output[temp[array[m]]-1] = array[m];
        temp[array[m]] -= 1;
    }
}


/**
* heapify - build a heap from the top down from the given root
*
* @array - the array containing the heap elements
* @size - the size of the heap
* @root - the root of the heap
*
* Returns: void
*/
void heapify(int array[], int size, int root) {
    int maximum = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && array[left] > array[maximum])
        maximum = left;

    if (right < size && array[right] > array[maximum])
        maximum = right;

    if (maximum != root) {
        swap(&array[root], &array[maximum]);
        heapify(array, size, maximum);
    }
}


/**
* heap_sort - sort an array by building a heap
*
* @array - the array whose elements to sort
* @length - the length of the array
*
* Returns: void
*/
void heap_sort(int array[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--)
        heapify(array, length, i);

    for (int i = length - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
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


/**
* merge - copy the elements from the array into two separate arrays and merge them in sorted order
*
* @array: the array to merge
* @front: the first index of the array
* @middle: the middle index of the array
* @end: the last index of the array
*/
void merge(int array[], int front, int middle, int end) {
    int left_length = middle - front + 1;
    int right_length = end - middle;

    // create arrays that will hold the elements of the array passed as the argument
    int left_array[left_length];
    int right_array[right_length];

    // copy the elements from the front of the array to the middle of the array into left_array
    for (int i = 0; i < left_length; i++) {
        left_array[i] = array[i + front];
    }

    // copy the elements from the middle of the array to the end of the array into right_array
    for (int j = 0; j < right_length; j++) {
        right_array[j] = array[j + middle + 1];
    }

    int i = 0;
    int j = 0;
    int k = front;

    // replace the elements in array with the elements in left_array and right_array in sorted order
    while (i < left_length && j < right_length) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i += 1;
        } else {
            array[k] = right_array[j];
            j += 1;
        }
        k += 1;
    }

    // move the remaining elements of left_array into array
    while (i < left_length) {
        array[k] = left_array[i];
        i += 1;
        k += 1;
    }

    while (j < right_length) {
        array[k] = right_array[j];
        j += 1;
        k += 1;
    }
}


/**
* merge_sort - sort the given array by divide and conquer
*
* @array: the array to merge
* @front: the first index of the array
* @end: the last index of the array
*/
void merge_sort(int array[], int front, int end) {
    if (front < end) {
        int middle = (front + end) / 2;
        merge_sort(array, front, middle);
        merge_sort(array, middle+1, end);
        merge(array, front, middle, end);
    }
}


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
