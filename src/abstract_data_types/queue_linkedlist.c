#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "queue_linkedlist.h"


/**
* initialize_queue - allocate memory for the queue and initialize the struct's members
*
* Returns: the initialized queue
*/
queue *initialize_queue(void) {
    queue *q = malloc(sizeof(queue));
    q->list = malloc(sizeof(node) * 2);

    q->list->head = NULL;
    q->list->tail = NULL;

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
void enqueue(queue *q, void *value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->next = NULL;

    if (q->list->head == NULL) {
        q->list->head = np;
    } else {
        q->list->tail->next = np;
    }

    q->list->tail = np;
}


/**
* dequeue - remove an element from the front of the queue
*
* @queue - the queue in which to remove the element
*
* Returns: void pointer to the value of the node
*/
void *dequeue(queue *q) {
    node *front = q->list->head;
    void *value = front->value;
    q->list->head = q->list->head->next;
    free_node(&front);

    return value;
}


/**
* free_node - free the memory that was allocated for the given node
*
* @node: the node whose memory to free
*
* Returns: void
*/
void free_node(node **n) {
    if (n != NULL && *n != NULL) {
        free(*n);
        n = NULL;
    }
}


/**
* is_empty - determine whether or not the queue is empty
*
* @queue - the queue in which check for emptiness
*
* Returns: boolean value of the queue's emptiness
*/
bool is_empty(queue *q) {
    return q->list->head == NULL;
}


/**
* destroy_queue - free the memory that was allocated for the queue
*
* @queue - the queue whose memory will be freed
*
* Returns: void
*/
void destroy_queue(queue **q) {
    while ((*q)->list->head != NULL) {
        node *destroyed_node = (*q)->list->head;
        (*q)->list->head = (*q)->list->head->next;
        free_node(&destroyed_node);
    }

    if ((*q)->list != NULL) {
        free((*q)->list);
        (*q)->list = NULL;
    }

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
* printf casts the current->value to intptr_t in order
* to print the value. The cast needs to be changed if
* the value is a type that can't be cast to intptr_t.
*/
void print_queue(queue *q) {
    node *current = q->list->head;
    
    while (current != NULL) {
        printf("%zu ", (intptr_t) current->value);
        current = current->next;
    }
    printf("\n");
}
