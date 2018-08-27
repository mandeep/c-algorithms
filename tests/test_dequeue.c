#include "greatest.h"

#include "../src/abstract_data_types/dequeue.c"


TEST test_deque(void) {
    dequeue *deq = initialize_dequeue();

    deq_push(deq, (size_t*) 1);
    deq_push(deq, (size_t*) 2);
    deq_push(deq, (size_t*) 3);
    deq_push(deq, (size_t*) 4);
    deq_push(deq, (size_t*) 5);
    deq_pushleft(deq, (size_t*) 0);

    ASSERT_EQ(deq->list->tail->value, (size_t*) 5);
    ASSERT_EQ(deq->list->head->value, (size_t*) 0);

    deq_pop(deq);
    print_dequeue(deq);

    deq_popleft(deq);

    deq_remove_value(deq, (size_t*) 3);

    ASSERT_EQ(deq_length(deq), 3);
    ASSERT_EQ(deq_count(deq, (size_t*) 2), 1);

    destroy_dequeue(&deq);
    PASS();
}



SUITE(doubleended_queue) {
    RUN_TEST(test_deque);
}
