/**
 * counting_sort - traverse an array and swap minimum elements until the array is sorted
 *
 * @array: the unsorted array
 * @length: the length of the array given as a parameter
 * @digit: the digit to sort by, 1 for ones, 10 for tens, 100 for hundreds, etc.
 *
 * Returns: void
 */
void counting_sort(int array[], int length, int digit) {
    int output[length];
    int count[10] = {0};

    for (int i = 0; i < length; i++) {
        int index = array[i] / digit;
        count[index % 10] += 1;
    }

    for (int j = 1; j < 10; j++) {
        count[j] += count[j-1];
    }

    for (int k = length - 1; k >= 0; k--) {
        int index = array[k] / digit;
        output[count[index % 10] - 1] = array[k];
        count[index % 10] -= 1;
    }

    for (int l = 0; l < length; l++) {
        array[l] = output[l];
    }
}


/**
 * radix_sort - sort a list of integers with regard to their radix (base)
 *
 * @array: the unsorted array
 * @length: the length of the array given as a parameter
 * In order to perform Radix Sort, we need a stable sorting algorithm.
 * We can use Counting Sort as our sorting algorithm so that the runtime
 * is still O(n+k).
 *
 * Returns: void
 */
void radix_sort(int array[], int length) {
    int maximum = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }

    for (int digit = 1; maximum / digit > 0; digit *= 10) {
        counting_sort(array, length, digit);
    }
}
