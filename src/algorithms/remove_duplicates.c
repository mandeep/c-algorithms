/**
* remove_duplicates - remove duplicates in a sorted array by returning the array's new length
*
* @array: the array whose duplicates to remove
* @length: the number of elements in the array
*
* Returns: the index to use for the array with duplicates removed
*
*/
int remove_duplicates(int array[], int length) {
    int index = 1;
    for (int i = 1; i < length; i++) {
        if (array[i-1] != array[i]) {
            array[index] = array[i];
            index += 1;
        }
    }
    return index;
}
