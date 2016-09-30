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
    """
    for i, element in enumerate(unordered_list):
        if element == value:
            return i
    return None
