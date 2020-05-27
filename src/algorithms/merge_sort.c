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
