#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_linkedlist.h"


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
void st_free_node(stack_node **n) {
    if (n != NULL && *n != NULL) {
        free(*n);
        *n = NULL;
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
void st_push(stack *st, void *value) {
    stack_node *np = malloc(sizeof(stack_node));
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
void *st_pop(stack *st) {
    if (st->top != NULL) {
        void *value = st->top->value;
        stack_node *destroyed_node = st->top;
        st->top = st->top->next;
        st_free_node(&destroyed_node);
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
bool st_is_empty(stack *st) {
    return st->top == NULL;
}


/**
* peek - view the top element of the stack
*
* @st: the stack whose top element will be viewed
*
* Returns: the value of the top element of the stack
*/
void *st_peek(stack *st) {
    if (st->top != NULL) {
        return st->top->value;
    }

    return 0;
}


/**
* destroy_stack - free the memory that was allocated for the stack
*
* @st: the stack to destroy
*
* Each node in the stack needs to be freed since memory was allocated
* for the nodes. Once the nodes are freed, the memory for the stack
* can be freed.
*
* Returns: void
*/
void st_destroy(stack **st) {
    while ((*st)->top != NULL) {
        stack_node *destroyed_node = (*st)->top;
        (*st)->top = (*st)->top->next;
        st_free_node(&destroyed_node);
    }
    if (st != NULL && *st != NULL) {
        free(*st);
        *st = NULL;
    }
}
