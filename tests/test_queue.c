#include "greatest.h"

#include "../src/abstract_data_types/queue_linkedlist.c"


TEST test_queue(void) {
    queue *q = initialize_queue();
    ASSERT_EQ(q_is_empty(q), 1);

    q_enqueue(q, (size_t*) 1);
    q_enqueue(q, (size_t*) 2);
    q_enqueue(q, (size_t*) 3);
    q_enqueue(q, (size_t*) 4);
    q_enqueue(q, (size_t*) 5);

    ASSERT_EQ(q->list->head->value, (size_t*) 1);

    q_dequeue(q);

    ASSERT_EQ(q->list->head->value, (size_t*) 2);

    q_print(q);
    q_destroy(&q);
    PASS();
}


SUITE(queue_linkedlist) {
    RUN_TEST(test_queue);
}
