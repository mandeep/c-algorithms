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
