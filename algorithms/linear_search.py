def linear_search(unordered_list, value):
    """Given an unordered list and value, returns the index of the value.

    Positional arguments:
    unodered list -- a list of values of any type
    value -- the element to be found in the list

    Analysis:
    Starting at the beginning of the unordered list, the value of each
    element is checked against the value of the value argument. Once
    there is a match, the index of the element is returned. If the
    value argument is not contained within the list, None is returned.

    Examples:

    >>> linear_search([2, 1, 3, 4], 3)
    2

    >>> linear_search(list(range(1, 589437)), 7383)
    7382

    >>> linear_search(['1', '3', '6', '4', '5', '2'], '5')
    4

    >>> linear_search([2.2, 1.1, 3.3, 5.5, 4.4], 2.2)
    0

    >>> linear_search([8, 3, 233, 7845, 191, 2389], 0) is None
    True

    Reference: https://en.wikipedia.org/wiki/Linear_search
    """
    for index, element in enumerate(unordered_list):
        if element == value:
            return index
    return None
