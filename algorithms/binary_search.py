def binary_search(sorted_list, value):
    """Given a sorted list and a value, returns the value's index.

    Positional arguments:
    sorted_list -- a list sorted from low to high, e.g. [1, 3, 5, 9].
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
