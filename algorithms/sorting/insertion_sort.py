def insertion_sort(array):
    """Given a list of unordered elements, returns a sorted list.

    Positional argument:
    array -- an unordered list of elements

    Analysis:
    For each element in the given array, the element is checked against
    the element preceding it. If the element is smaller than the element
    preceding it, the two elements are swapped. This continues until the
    element is in its correct position in the list. Once the element is
    in its correct position, the for loop moves on to the next index and
    repeats the process.

    Examples:
    >>> insertion_sort([3, 2, 1, 8, 7, 0, 99, 88, 77, 22, 5])
    [0, 1, 2, 3, 5, 7, 8, 22, 77, 88, 99]

    >>> insertion_sort(list(range(1000, 0, -1)))
    [1, 2, 3, ..., 999, 1000]

    >>> import random
    >>> random_list = random.sample(range(1000), 100)
    >>> insertion_sort(random_list) == sorted(random_list)
    True

    Reference: https://en.wikipedia.org/wiki/Insertion_sort
    """
    for index in range(1, len(array)):
        while index > 0 and array[index] < array[index-1]:
            array[index], array[index-1] = array[index-1], array[index]
            index -= 1
    return array
