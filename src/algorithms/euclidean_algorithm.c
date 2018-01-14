/**
* recursive_gcd - find the greatest common divisor of the two input parameters
*
* @a: one of the numbers to be used in the gcd calculation
* @b: the other number to be used in the gcd calculation
*
* Returns: the greatest common divisor of the two input parameters
*/
int recursive_gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return recursive_gcd(b, a % b);
    }
}


/**
* iterative_gcd - find the greatest common divisor of the two input parameters
*
* @a: one of the numbers to be used in the gcd calculation
* @b: the other number to be used in the gcd calculation
*
* Returns: the greatest common divisor of the two input parameters
*/
int iterative_gcd(int a, int b) {
    while (b > 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
