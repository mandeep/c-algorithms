#include "greatest.h"

#include "../src/abstract_data_types/queue_array.c"


TEST test_queue_array(void) {
    queue_array *queue = initialize_queue_array(6);
    ASSERT_EQ(qa_is_empty(queue), 1);

    qa_enqueue(queue, 1);
    qa_enqueue(queue, 2);
    qa_enqueue(queue, 3);
    qa_enqueue(queue, 4);
    qa_enqueue(queue, 5);
    qa_enqueue(queue, 6);

    qa_dequeue(queue);
    qa_enqueue(queue, 7);

    qa_print(queue);
    qa_destroy(&queue);
    PASS();
}



SUITE(array_based_queue) {
    RUN_TEST(test_queue_array);
}
