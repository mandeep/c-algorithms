#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


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


/**
* initialize_queue - allocate memory for the queue and initialize the struct's members
*
* @capacity - the number of elements to be held in the queue
*
* Returns: the initialized queue
*/
queue *initialize_queue(int capacity) {
    queue *q = malloc(sizeof(queue) * capacity);
    q->head = 0;
    q->tail = 0;
    q->capacity = capacity;
    return q;
}


/**
* enqueue - add an element to the end of the queue
*
* @queue - the queue in which to add the element
* @value - the value to add to the queue
*
* Returns: void
*/
void enqueue(queue *q, int value) {
    if (q->tail != q->capacity) {
        q->tail += 1;
    } else {
        q->tail = 0;
    }

    q->array[q->tail] = value;
}


/**
* dequeue - remove an element from the front of the queue
*
* @queue - the queue in which to remove the element
*
* Returns: the value of the element removed from the queue
*/
int dequeue(queue *q) {
    if (q->head != q->capacity) {
        q->head += 1;
    } else {
        q->head = 0;
    }

    return q->array[q->head];
}


/**
* is_empty - determine whether or not the queue is empty
*
* @queue - the queue in which check for emptiness
*
* Returns: boolean value of the queue's emptiness
*/
bool is_empty(queue *q) {
    return q->head == q->tail;
}


/**
* destroy_queue - free the memory that was allocated for the queue
*
* @queue - the queue whose memory will be freed
*
* Returns: void
*/
void destroy_queue(queue **q) {
    if (*q != NULL && q != NULL) {
        free(*q);
        *q = NULL;
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
void print_queue(queue *q) {
    int front = q->head;
    
    while (!is_empty(q)) {
        printf("%i ", dequeue(q));
    }
    printf("\n");
    
    q->head = front;
}
