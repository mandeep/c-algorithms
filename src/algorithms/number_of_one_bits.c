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
