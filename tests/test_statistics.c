#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greatest.h"

#include "../src/algorithms/statistics.c"


TEST test_ith_order_statistic(void) {
    int stat_array[] = {1, 2, 3, 4, 5};
    int i = ith_order_statistic(stat_array, 0, 5, 1);
    int j = ith_order_statistic(stat_array, 0, 0, 0);
    int k = ith_order_statistic(stat_array, 0, 5, 4);
    ASSERT_EQ_FMT(i, 0, "%d");
    ASSERT_EQ_FMT(j, 0, "%d");
    ASSERT_EQ_FMT(k, 3, "%d");
    PASS();
}

SUITE(statistical_algorithms) {
    RUN_TEST(test_ith_order_statistic);
}
