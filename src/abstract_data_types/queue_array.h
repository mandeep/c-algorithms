#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>


/**
* queue - array based abstract data type with FIFO properties
*
* @head - the index of the front of the queue
* @tail - the index of the end of the queue
* @capacity - the number of elements to be held in the queue
* @array - the array that will hold the queue's elements
*/
typedef struct queue_array {
    int head;
    int tail;
    int capacity;
    int array[];
} queue_array;


queue_array *initialize_queue_array(size_t capacity);

void qa_enqueue(queue_array *queue, int value);

int qa_dequeue(queue_array *queue);

bool qa_is_empty(queue_array *queue);

void qa_destroy(queue_array **queue);

void qa_print(queue_array *queue);

#endif
