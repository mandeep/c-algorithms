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
typedef struct priority_queue_node {
    void *value;
    size_t priority;
    struct priority_queue_node *next;
} priority_queue_node;


/**
* linked_list - the linked_list data structure that holds nodes of data
*
* @head: the head node of the linked list
* @tail: the tail node of the linked list
*/
typedef struct priority_queue_list {
    priority_queue_node *head;
    priority_queue_node *tail;
} priority_queue_list;


/**
* queue - linked list based abstract data type with FIFO properties
*
* @linked_list: the linked list that will hold the elements of the priority queue
*/
typedef struct priority_queue {
    priority_queue_list *list;
} priority_queue;


priority_queue *initialize_priority_queue(void);

void pq_enqueue(priority_queue *q, void *value, size_t priority);

void pq_free_node(priority_queue_node **n);

void pq_dequeue(priority_queue *q);

void pq_dequeue_priority(priority_queue *q, size_t priority);

bool pq_is_empty(priority_queue *q);

void pq_destroy(priority_queue **q);

void pq_print(priority_queue *q);

#endif
