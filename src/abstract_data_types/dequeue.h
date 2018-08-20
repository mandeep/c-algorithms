#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stddef.h>


/**
* node - node data type to be used with the linked list
*
* @value: the value of the element to hold in the node
* @next: the next node to link to when creating a singly linked list
*/
typedef struct dequeue_node {
    void *value;
    struct dequeue_node *next;
} dequeue_node;


/**
* dequeue_list - the linked list data structure that holds nodes of data
*
* @head: the head node of the linked list
* @tail: the tail node of the linked list
*/
typedef struct dequeue_list {
    dequeue_node *head;
    dequeue_node *tail;
} dequeue_list;


/**
* queue - linked list based abstract data type with FIFO properties
*
* @linked_list: the linked list that will hold the elements of the queue
*/
typedef struct dequeue {
    dequeue_list *list;
} dequeue;


dequeue *initialize_dequeue(void);

void deq_push(dequeue *q, void *value);

void deq_pushleft(dequeue *q, void *value);

void free_dequeue_node(dequeue_node **n);

void *deq_pop(dequeue *q);

void *deq_popleft(dequeue *q);

void deq_remove_value(dequeue *q, void *value);

size_t deq_length(dequeue *q);

size_t deq_count(dequeue *q, void *value);

void destroy_dequeue(dequeue **q);

void print_dequeue(dequeue *q);

#endif
