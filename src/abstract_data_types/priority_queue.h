#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stddef.h>
#include <stdbool.h>

/**
* node - node data type to be used with the linked list
*
* @value: the value of the element to hold in the node
* @priority: the priority of the node
* @next: the next node to link to when creating a singly linked list
*/
typedef struct node {
    void *value;
    size_t priority;
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
* @linked_list: the linked list that will hold the elements of the priority queue
*/
typedef struct queue {
    linked_list *list;
} queue;


queue *initialize_queue(void);

void enqueue(queue *q, void *value, size_t priority);

void free_node(node **n);

void dequeue(queue *q);

void dequeue_priority(queue *q, size_t priority);

bool is_empty(queue *q);

void destroy_queue(queue **q);

void print_queue(queue *q);

#endif
