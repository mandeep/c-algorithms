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
