def bubble_sort(array):
    """Sort a list in place and return the sorted list.

    Positional argument:
    array -- a list with unordered elements

    Analysis:
    Each element in the list is compared to the next element in the list.
    If the first element is larger than the second element, the two elements
    are swapped. This occurs until the end of the list is reached. At this
    point the largest value in the list has reached the last index of the
    list, therefore one less iteration through the list is needed. This is
    accomplished with a for loop that strictly deals with iterations of
    the list.

    Examples:
    >>> bubble_sort([6, 5, 3, 1, 8, 7, 2, 4])
    [1, 2, 3, 4, 5, 6, 7, 8]

    >>> bubble_sort([5, 3, 97, 29, 91, 17])
    [3, 5, 17, 29, 91, 97]

    >>> import random
    >>> random_list = random.sample(list(range(1000)), 100)
    >>> bubble_sort(random_list) == sorted(random_list)
    True

    Reference: https://en.wikipedia.org/wiki/Bubble_sort
    """
    for _ in range(len(array)):
        for i in range(len(array)-1):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
    return array
