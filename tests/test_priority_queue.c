#include "greatest.h"

#include "../src/abstract_data_types/priority_queue.c"


TEST test_priority_queue(void) {
    priority_queue *pq = initialize_priority_queue();

    ASSERT_EQ(pq_is_empty(pq), 1);

    pq_enqueue(pq, (size_t*) 1, 0);
    pq_enqueue(pq, (size_t*) 2, 3);
    pq_enqueue(pq, (size_t*) 3, 2);
    pq_enqueue(pq, (size_t*) 4, 1);

    pq_dequeue(pq);
    pq_dequeue_priority(pq, 1);

    pq_print(pq);

    pq_destroy(&pq);
    PASS();
}



SUITE(priorityqueue) {
    RUN_TEST(test_priority_queue);
}
