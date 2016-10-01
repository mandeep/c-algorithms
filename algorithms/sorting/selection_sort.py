def selection_sort(array):
    """Sorts a list in place via selection sort and returns the sorted list.

    Positional argument:
    array -- a list with unordered elements

    Analysis:
    The first index of the array is set as the minimum. The rest of the
    list is then searched for an element that is smaller in value than
    the element in the first index. If this element exists, the element
    at the first index and the new minimum element are swapped. With the
    minimum of the list now at the first index, the second index is
    then set as the minimum, and the rest of the list is searched for a
    value smaller than this minimum. If the element exists, the element
    at the second index and the new minimum element are swapped. This
    process continues until the list is fully sorted.

    Examples:
    >>> selection_sort([8, 5, 2, 6, 9, 3, 1, 4, 0, 7])
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    >>> selection_sort([0, 2, 4, 6, 1, 8, 9, 3, 5, 7])
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    >>> import random
    >>> random_list = random.sample(list(range(1000)), 100)
    >>> selection_sort(random_list) == sorted(random_list)
    True

    Reference: https://en.wikipedia.org/wiki/Selection_sort
    """
    for ordered in range(0, len(array)-1):
        minimum = ordered
        for unordered in range(ordered+1, len(array)):
            if array[unordered] < array[minimum]:
                minimum = unordered
        array[minimum], array[ordered] = array[ordered], array[minimum]
    return array
