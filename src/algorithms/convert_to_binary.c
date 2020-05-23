/**
 * int_to_binary - given an integer n, place the bits of n in to the given array
 *
 * @n: the integer whose bits to find
 * @array: the array in which to place the bits
 *
 * Returns: void
 */
void int_to_binary(int n, int array[]) {
    for (int i = 31; i >= 0; i--) {
        array[i] = n & 1;
        n >>= 1;
    }
}
