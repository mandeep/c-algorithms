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
typedef struct node {
    void *value;
    struct node *next;
} node;


/**
* stack - abstract data type that holds a collection of elements
*
* @top: the node at the top of the stack
*/
typedef struct stack {
     node *top;
} stack;


stack *initialize_stack(size_t size);

void free_node(node **n);

void push(stack *st, void *value);

void *pop(stack *st);

bool is_empty(stack *st);

void *peek(stack *st);

void destroy_stack(stack **st);

#endif
