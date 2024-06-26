#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "priority_queue.h"


/**
* initialize_queue - allocate memory for the priority queue and initialize the struct's members
*
* Returns: the initialized queue
*/
priority_queue *initialize_priority_queue(void) {
    priority_queue *q = malloc(sizeof(priority_queue));
    q->list = malloc(sizeof(priority_queue_list));

    q->list->head = NULL;
    q->list->tail = NULL;

    return q;
}


/**
* enqueue - add an element to the priority queue with placement according to its priority
*
* @queue - the priority queue in which to add the element
* @value - the value to add to the priority queue
* @priority - the priority of the node
*
* Returns: void
*
* A node is placed in the priority queue according to its priority.
* Nodes with the highest priority are placed at the front
* of the priority queue with the lowest priority nodes appearing
* towards the end of the priority queue.
*/
void pq_enqueue(priority_queue *q, void *value, size_t priority) {
    priority_queue_node *np = malloc(sizeof(priority_queue_node));
    np->value = value;
    np->priority = priority;
    np->next = NULL;
    priority_queue_node *previous = NULL;
    priority_queue_node *current = q->list->head;

    while (current != NULL && priority < current->priority) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        previous = np;
        q->list->head = previous;
    }

    previous->next = np;
    np->next = current;

}


/**
* free_node - free the memory that was allocated for the given node
*
* @node: the node whose memory to free
*
* Returns: void
*/
void pq_free_node(priority_queue_node **n) {
    if (n != NULL && *n != NULL) {
        free(*n);
        *n = NULL;
    }
}


/**
* dequeue - remove an element from the front of the priority queue
*
* @queue - the priority queue in which to remove the element
*
* Returns: void
*/
void pq_dequeue(priority_queue *q) {
    priority_queue_node *front = q->list->head;
    q->list->head = q->list->head->next;

    pq_free_node(&front);
}


/**
* dequeue - remove the element with the given priority from the priority queue
*
* @queue - the priority queue in which to remove the element
*
* Returns: void
*/
void pq_dequeue_priority(priority_queue *q, size_t priority) {
    priority_queue_node *previous = NULL;
    priority_queue_node *current = q->list->head;

    while (priority != current->priority) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    pq_free_node(&current);

}


/**
* is_empty - determine whether or not the priority queue is empty
*
* @queue - the priority queue in which check for emptiness
*
* Returns: boolean value of the priority queue's emptiness
*/
bool pq_is_empty(priority_queue *q) {
    return q->list->head == NULL;
}


/**
* destroy_queue - free the memory that was allocated for the priority queue
*
* @queue - the priority queue whose memory will be freed
*
* Returns: void
*/
void pq_destroy(priority_queue **q) {
    while ((*q)->list->head != NULL) {
        priority_queue_node *destroyed_node = (*q)->list->head;
        (*q)->list->head = (*q)->list->head->next;
        pq_free_node(&destroyed_node);
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
* print_list - display the contents of the priority queue
*
* @queue - the priority queue whose contents to display
*
* Returns: void
*
* printf casts the current->value to intptr_t in order
* to print the value. The cast needs to be changed if
* the value is a type that can't be cast to intptr_t.
*/
void pq_print(priority_queue *q) {
    priority_queue_node *current = q->list->head;

    while (current != NULL) {
        printf("%zu ", (intptr_t) current->value);
        current = current->next;
    }
    printf("\n");
}
