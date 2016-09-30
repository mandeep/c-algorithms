def binary_search(sorted_list, value):
    """Given a sorted list and a value, returns the value's index.

    Positional arguments:
    sorted_list -- a list sorted from low to high, e.g. [1, 3, 5, 9].
    value -- a float, integer, or string to be found in the sorted list

    Analysis:
    The low variable is set to the sorted list's first index, while the
    high variable is set to the sorted list's last index. The middle variable
    is the middle index of the sorted list. We can determine which part of the
    sorted list the value argument resides by comparing it to the element at
    the middle of the sorted list. If the value argument is less than the
    middle element, the high variable is assigned the middle value's index
    minus 1 since the middle element does not equal the value argument. If the
    value argument is greater than the element at the middle of the sorted
    list, the low variable is assigned the index of the middle element plus 1
    since the middle element does not equal the value argument. The low or high
    variable continues to change until the value argument equals the middle
    element. If the value argument is found, its index is returned. Otherwise,
    the function will return None.
    """
    low = 0
    high = len(sorted_list) - 1
    while low <= high:
        middle = (high + low) // 2
        if value < sorted_list[middle]:
            high = middle - 1
        elif value > sorted_list[middle]:
            low = middle + 1
        else:
            return middle
    return None
