from algorithms.binary_search import binary_search


def test_binary_search():
    """Checks that the binary_search algorithm returns the correct
    output given a sorted list and value to search for."""
    assert binary_search([1, 2, 3, 4], 2) == 1
    assert binary_search([3.5, 4.5, 6.5, 7.5], 6.5) == 2
    assert binary_search(list(range(1, 100000)), 3496) == 3495
    assert binary_search(
        ['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo'], 'Echo') == 4
