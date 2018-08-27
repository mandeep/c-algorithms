#include "greatest.h"

#include "../src/abstract_data_types/minimum_stack.c"


TEST test_minimum_stack(void) {
    minimum_stack *minstack = initialize_minimum_stack(5);
    minst_push(minstack, (size_t*) 3);
    minst_push(minstack, (size_t*) 5);
    minst_push(minstack, (size_t*) 2);
    minst_push(minstack, (size_t*) 0);
    minst_push(minstack, (size_t*) 1);

    ASSERT_EQ(minst_top(minstack), (size_t*) 1);

    minst_pop(minstack);

    ASSERT_EQ(minst_top(minstack), (size_t*) 0);

    ASSERT_EQ(minst_minimum(minstack), 0);

    minst_destroy_stack(&minstack);
    PASS();
}


SUITE(min_stack) {
    RUN_TEST(test_minimum_stack);
}
