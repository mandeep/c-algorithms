#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>


/**
* node - data type that serves as the basis of the linked list
*
* @value: the value to hold in the node
* @next: pointer to the next link in the linked list
*/
typedef struct stack_node {
    void *value;
    struct stack_node *next;
} stack_node;


/**
* stack - abstract data type that holds a collection of elements
*
* @top: the node at the top of the stack
*/
typedef struct stack {
     stack_node *top;
} stack;


stack *initialize_stack(size_t size);

void st_free_node(stack_node **n);

void st_push(stack *st, void *value);

void *st_pop(stack *st);

bool st_is_empty(stack *st);

void *st_peek(stack *st);

void st_destroy(stack **st);

#endif
