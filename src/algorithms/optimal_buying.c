#include <limits.h>
#include <stddef.h>


/**
 * optimal_buy_sell() - compute the optimal buy/sell strategy from an array of prices
 *
 * @prices: the starting prices
 * @length: the length of the prices array
 *
 * Returns: the maximum profit from the given prices
 */
int optimal_buy_sell(int prices[], size_t length) {
    int minimum = INT_MAX;
    int maximum_profit = 0;

    for (size_t i = 0; i < length; i++) {
        int current_profit = prices[i] - minimum;
        if (current_profit > maximum_profit) {
            maximum_profit = current_profit;
        }
        if (prices[i] < minimum) {
            minimum = prices[i];
        }
    }

    return maximum_profit;
}
