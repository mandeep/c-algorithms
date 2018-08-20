#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue_array.h"


/**
* initialize_queue - allocate memory for the queue and initialize the struct's members
*
* @capacity - the number of elements to be held in the queue
*
* Returns: the initialized queue
*/
queue_array *initialize_queue_array(size_t capacity) {
    queue_array *queue = malloc(sizeof(queue_array) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;
    return queue;
}


/**
* enqueue - add an element to the end of the queue
*
* @queue - the queue in which to add the element
* @value - the value to add to the queue
*
* Returns: void
*/
void qa_enqueue(queue_array *queue, int value) {
    if (queue->tail != queue->capacity) {
        queue->tail += 1;
    } else {
        queue->tail = 0;
    }

    queue->array[queue->tail] = value;
}


/**
* dequeue - remove an element from the front of the queue
*
* @queue - the queue in which to remove the element
*
* Returns: the value of the element removed from the queue
*/
int qa_dequeue(queue_array *queue) {
    if (queue->head != queue->capacity) {
        queue->head += 1;
    } else {
        queue->head = 0;
    }

    return queue->array[queue->head];
}


/**
* is_empty - determine whether or not the queue is empty
*
* @queue - the queue in which check for emptiness
*
* Returns: boolean value of the queue's emptiness
*/
bool qa_is_empty(queue_array *queue) {
    return queue->head == queue->tail;
}


/**
* destroy_queue - free the memory that was allocated for the queue
*
* @queue - the queue whose memory will be freed
*
* Returns: void
*/
void qa_destroy(queue_array **queue) {
    if (queue != NULL && *queue != NULL) {
        free(*queue);
        *queue = NULL;
    }
}


/**
* print_list - display the contents of the queue
*
* @queue - the queue whose contents to display
*
* Returns: void
*
* Because dequeue(queue *q) will alter the value of q->head,
* q->head is reset after the contents of the queue are displayed.
*/
void qa_print(queue_array *queue) {
    int front = queue->head;

    while (!qa_is_empty(queue)) {
        printf("%i ", qa_dequeue(queue));
    }
    printf("\n");

    queue->head = front;
}
