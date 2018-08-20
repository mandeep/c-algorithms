#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <stdbool.h>


/**
* node - node data type to be used with the linked list
*
* @value: the value of the element to hold in the node
* @next: the next node to link to when creating a singly linked list
*/
typedef struct queue_node {
    void *value;
    struct queue_node *next;
} queue_node;


/**
* linked_list - the linked_list data structure that holds nodes of data
*
* @head: the head node of the linked list
* @tail: the tail node of the linked list
*/
typedef struct queue_list {
    queue_node *head;
    queue_node *tail;
} queue_list;


/**
* queue - linked list based abstract data type with FIFO properties
*
* @linked_list: the linked list that will hold the elements of the queue
*/
typedef struct queue {
    queue_list *list;
} queue;

queue *initialize_queue(void);

void q_enqueue(queue *q, void *value);

void *q_dequeue(queue *q);

void q_free_node(queue_node **n);

bool q_is_empty(queue *q);

void q_destroy(queue **q);

void q_print(queue *q);

#endif
