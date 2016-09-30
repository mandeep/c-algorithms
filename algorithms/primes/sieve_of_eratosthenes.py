def sieve_of_eratosthenes(limit):
    """
    Given a limit, returns a list of all primes from 2 to the given limit.

    Positional argument:
    limit -- an integer that defines the upper bound for the list of primes

    Examples:
    >>> sieve_of_eratosthenes(10)
    [2, 3, 5, 7]

    >>> sieve_of_eratosthenes(50)
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

    >>> sieve_of_eratosthenes(1000)
    [2, 3, ..., 977, 983, 991, 997]

    >>> sum(sieve_of_eratosthenes(2000000))
    142913828922

    Reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    """
    multiples = set()
    primes = []
    for number in range(2, limit+1):
        if number not in multiples:
            primes.append(number)
            multiples.update(range(number * number, limit+1, number))
    return primes
