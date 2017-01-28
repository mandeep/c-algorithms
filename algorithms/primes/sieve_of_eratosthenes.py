def sieve_of_eratosthenes(limit):
    """Generate primes up to the given limit and yield them as a generator.

    Positional argument:
    limit -- an integer that defines the upper bound for the list of primes

    Analysis:
    Starting from the number 2, the number 2 is yielded as a prime number
    and all of its multiples up to the limit argument are added to the
    multiples set. Then, the number 3 is yielded as a prime number and all
    of its multiples up to the limit argument are added to the multiples set.
    By continually adding multiples of primes to the multiples set as the
    for loop iterates from 2 to the limit, the only numbers remaining
    are prime numbers.

    Examples:
    >>> list(sieve_of_eratosthenes(50))
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

    >>> list(sieve_of_eratosthenes(1000))
    [2, 3, ..., 977, 983, 991, 997]

    >>> len(list(sieve_of_eratosthenes(50)))
    15

    >>> sum(sieve_of_eratosthenes(2000000))
    142913828922

    Reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    """
    multiples = set()
    for number in range(2, limit+1):
        if number not in multiples:
            yield number
            multiples.update(range(number * number, limit+1, number))
