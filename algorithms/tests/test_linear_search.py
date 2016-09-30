from algorithms.linear_search import linear_search


def test_linear_search():
    """Checks that the linear_search algorithm returns the correct
    output given an unordered list and value to search for."""
    assert linear_search([2, 1, 3, 4], 3) == 2
    assert linear_search(list(range(1, 589437)), 7383) == 7382
    assert linear_search(['1', '3', '6', '4', '5', '2'], '5') == 4
    assert linear_search([2.2, 1.1, 3.3, 5.5, 4.4], 2.2) == 0
