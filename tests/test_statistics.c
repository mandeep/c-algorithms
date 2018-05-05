#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greatest.h"

#include "../src/algorithms/statistics.c"


TEST test_ith_order_statistic(void) {
    int stat_array[] = {1, 2, 3, 4, 5};
    int index = ith_order_statistic(stat_array, 0, 5, 1);
    ASSERT_EQ_FMT(index, 0, "%d");
    PASS();
}

SUITE(statistical_algorithms) {
    RUN_TEST(test_ith_order_statistic);
}
