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
