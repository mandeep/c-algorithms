/**
* count_ones - count the number of one bits in the given integer
*
* @n: the integer whose bits to count
*
* Returns: an integer of the number of one bits in the argument
*/
int count_ones(int n) {
    int ones = 0;

    while (n > 0) {
        n &= n - 1;
        ones += 1;
    }

    return ones;
}


/**
* check_parity - check the parity of the given integer's bits
*
* @n: the integer whose parity to check
*
* Returns: 1 if the number of one bits is odd, 0 if the number of one bits is even
*/
int check_parity(int n) {
    int parity = 0;

    while (n > 0) {
        n &= n - 1;
        parity ^= 1;
    }

    return parity;
}


/**
 * swap_bits - swap the bits at index i and index j
 *
 * @n: the integer whose bits to swap
 * @i: the index of the bit to swap with the bit at index j
 * @j: the index of the bit to swap with the bit at index i
 *
 * Returns: the integer obtained when swapping the bits at i and j
 *
 * Since bits are shifted from the end, the i and j indexes
 * are counted from the right not from the left.
 */
int swap_bits(int n, int i, int j) {
    if ((n >> i & 1) != (n >> j & 1)) {
        int bit_mask = (1 << i) | (1 << j);
        n ^= bit_mask;
    }

    return n;
}


/**
 * reverse_bits - reverse the bits in the given integer
 *
 * @n: the integer whose bits to reverse
 *
 * Returns: the integer obtained when reversing the bits in n
 *
 */
int reverse_bits(int n) {
    int m = 0;
    while (n > 0) {
        m <<= 1;
        m |= n & 1;
        n >>= 1;
    }

    return m;
}


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
