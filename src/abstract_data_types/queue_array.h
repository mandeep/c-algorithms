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
typedef struct queue {
    int head;
    int tail;
    int capacity;
    int array[];
} queue;


queue *initialize_queue(size_t capacity);

void enqueue(queue *q, int value);

int dequeue(queue *q);

bool is_empty(queue *q);

void destroy_queue(queue **q);

void print_queue(queue *q);

#endif
