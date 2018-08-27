#include "greatest.h"

#include "../src/abstract_data_types/stack_linkedlist.c"


TEST test_linked_list(void) {
    stack *st = initialize_stack(5);

    ASSERT_EQ(st_is_empty(st), 1);

    st_push(st, (size_t*) 1);
    st_push(st, (size_t*) 2);
    st_push(st, (size_t*) 3);
    st_push(st, (size_t*) 4);
    st_push(st, (size_t*) 5);

    st_pop(st);

    ASSERT_EQ(st_peek(st), (size_t*) 4);

    st_destroy(&st);
    PASS();
}


SUITE(stack_linked_list) {
    RUN_TEST(test_linked_list);
}
