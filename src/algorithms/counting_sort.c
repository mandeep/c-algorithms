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
