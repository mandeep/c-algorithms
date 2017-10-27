#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/**
* node - data type that serves as the basis of the linked list
*
* @value: the value to hold in the node
* @next: pointer to the next link in the linked list
*/
typedef struct node {
    size_t value;
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


/**
* initialize_stack - allocate memory for the stack and initialize top
*
* @size: the amount of memory to allocate for the stack
*
* Returns: the initialized stack
*/
stack *initialize_stack(size_t size) {
    stack *st = malloc(sizeof(size_t) * size);
    st->top = NULL;

    return st;
}


/**
* free_node - free the memory of an unneeded node
*
* @node: the node whose memory needs freeing
*
* Returns: void
*/
void free_node(node *n) {
    if (n != NULL) {
        free(n);
        n = NULL;
    }
}


/**
* push - add an element to the top of the stack
*
* @st: the initialized stack
* @value: the value to add to the stack 
*
* Returns: void
*/
void push(stack *st, size_t value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->next = st->top;
    st->top = np;
}


/**
* pop - remove the top element of the stack
*
* @st: the stack to remove the element from
*
* Returns: the element removed from the top of the stack 
*/
size_t pop(stack *st) {
    if (st->top != NULL) {
        size_t value = st->top->value;
        node *destroyed_node = st->top;
        st->top = st->top->next;
        free_node(destroyed_node);
        return value;
    } else {
        return 0;
    }
}


/**
* is_empty - determine whether or not the stack is empty
*
* @st: the stack to check for membership
*
* Returns: boolean value of whether or not the stack is empty
*/
bool is_empty(stack *st) {
    return st->top == NULL;
}


/**
* peek - view the top element of the stack
*
* @st: the stack whose top element will be viewed
*
* Returns: the value of the top element of the stack
*/
size_t peek(stack *st) {
    node *current = st->top;
    if (current != NULL) {
        return st->top->value;
    }

    return 0;
}
