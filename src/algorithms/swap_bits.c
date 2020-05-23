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
