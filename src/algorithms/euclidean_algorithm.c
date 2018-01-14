/**
* gcd - find the greatest common divisor of the two input parameters
*
* @a: one of the numbers to be used in the gcd calculation
* @b: the other number to be used in the gcd calculation
*
* Returns: the greatest common divisor of the two input parameters
*/
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
