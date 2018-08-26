#include "greatest.h"

#include "../src/abstract_data_types/stack_array.c"

TEST test_stack_array(void) {
    stack_array *stack = initialize_stack_array(3);
    sta_push(stack, 1);
    sta_push(stack, 2);
    sta_push(stack, 3);

    ASSERT_EQ(sta_peek(stack), 3);

    sta_pop(stack);

    ASSERT_EQ(sta_peek(stack), 2);

    ASSERT_EQ(sta_is_empty(stack), 0);

    sta_pop(stack);
    sta_pop(stack);

    ASSERT_EQ(sta_is_empty(stack), 1);
    ASSERT_EQ(sta_peek(stack), 0);

    sta_destroy(&stack);

    PASS();
}


SUITE(array_based_stack) {
    RUN_TEST(test_stack_array);
}
