#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stddef.h>


/**
* node - node data type to be used with the linked list
*
* @value: the value of the element to hold in the node
* @next: the next node to link to when creating a singly linked list
*/
typedef struct node {
    void *value;
    struct node *next;
} node;


/**
* linked_list - the linked_list data structure that holds nodes of data
*
* @head: the head node of the linked list
* @tail: the tail node of the linked list
*/
typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;


/**
* queue - linked list based abstract data type with FIFO properties
*
* @linked_list: the linked list that will hold the elements of the queue
*/
typedef struct queue {
    linked_list *list;
} queue;


queue *initialize_queue(void);

void push(queue *q, void *value);

void pushleft(queue *q, void *value);

void free_node(node **n);

void *pop(queue *q);

void *popleft(queue *q);

void remove_value(queue *q, void *value);

size_t length(queue *q);

size_t count(queue *q, void *value);

void destroy_queue(queue **q);

void print_queue(queue *q);

#endif
