#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/**
* node - node data type to be used with the linked list
*
* @value: the value of the element to hold in the node
* @next: the next node to link to when creating a singly linked list
*/
typedef struct node {
    size_t value;
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


/**
* initialize_queue - allocate memory for the queue and initialize its members
*
* Returns: the initialized queue
*/
queue *initialize_queue(void) {
    queue *q = malloc(sizeof(queue));
    q->list = malloc(sizeof(linked_list));

    q->list->head = NULL;
    q->list->tail = NULL;

    return q;
}


/**
* push - add an element to the end of the queue
*
* @queue - the queue in which to add the element
* @value - the value to add to the queue
*
* Returns: void
*/
void push(queue *q, size_t value) {
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
* pushleft - add an element to the front of the queue
*
* @queue - the queue in which to add the element
* @value - the value to add to the queue
*
* Returns: void
*/
void pushleft(queue *q, size_t value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->next = q->list->head;
    q->list->head = np;
}


/**
* free_node - free the memory that was allocated for the given node
*
* @node: the node whose memory to free
*
* Returns: void
*/
void free_node(node **n) {
    if (*n != NULL && n != NULL) {
        free(*n);
        *n = NULL;
    }
}


/**
* pop - remove an element from the end of the queue
*
* @queue - the queue in which to remove the element
*
* Returns: the value of the node removed from the queue
*/
size_t pop(queue *q) {
    node *previous = NULL;
    node *current = q->list->head;

    size_t value = current->value;

    if (current->next == NULL) {
        node *destroyed_node = current;
        value = current->value;
        current = NULL;
        free_node(&destroyed_node);
    } else {
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        value = current->value;
        previous->next = NULL;
        free_node(&current);
    }

    return value;
}


/**
* popleft - remove an element from the front of the queue
*
* @queue - the queue in which to remove the element
*
* Returns: the value of the node removed from the queue
*/
size_t popleft(queue *q) {
    size_t value = q->list->head->value;

    node *destroyed_node = q->list->head;

    q->list->head = q->list->head->next;

    free_node(&destroyed_node);

    return value;
}


/**
* remove_value - remove the node with the given value from the queue
*
* @queue - the queue in which to remove the element
*
* Returns: void
*/
void remove_value(queue *q, size_t value) {
    node *previous = NULL;
    node *current = q->list->head;

    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free_node(&current);
}


/**
* length - the number of elements in the queue
*
* @queue - the queue whose length to return
*
* Returns: the number of elements in the queue
*/
size_t length(queue *q) {
    node *current = q->list->head;
    size_t count = 0;

    while (current != NULL) {
        current = current->next;
        count += 1;
    }

    return count;
}


/**
* count - the number of times a value occurs in the queue
*
* @queue - the queue whose occurrences to count for the given value
*
* Returns: the count of the occurrences of the given value
*/
size_t count(queue *q, size_t value) {
    node *current = q->list->head;
    size_t count = 0;

    while (current != NULL) {
        if (current->value == value) {
            count += 1;
        }
        current = current->next;
    }

    return count;
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
*/
void print_queue(queue *q) {
    node *current = q->list->head;

    while (current != NULL) {
        printf("%zu ", current->value);
        current = current->next;
    }

    printf("\n");
}
