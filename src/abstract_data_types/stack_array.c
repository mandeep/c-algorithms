#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_array.h"


/**
* initialize_stack - allocate memory for the stack and initialize top
*
* @size: the amount of memory to allocate for the stack
*
* Returns: the initialized stack
*
* The stack's top element is initialized to -1. As elements are prepared
* to be added to the stack, top is incrmented by 1. Thus, the first
* element to be added to the stack has an index of 0.
*/
stack_array *initialize_stack_array(size_t capacity) {
    stack_array *stack = malloc(sizeof(int) * capacity);
    stack->top = -1;

    return stack;
}


/**
* push - add an element to the stack
*
* @st: the initialized stack
* @value: the value to add to the stack
*
* Returns: void
*/
void sta_push(stack_array *stack, int value) {
    stack->top += 1;
    stack->array[stack->top] = value;
}


/**
* pop - remove the top element of the stack
*
* @st: the stack to remove the element from
*
* Returns: the element removed from the top of the stack
*/
int sta_pop(stack_array *stack) {
    int top_element = stack->array[stack->top];
    if (stack->top > -1) {
        stack->top -= 1;
    }

    return top_element;
}


/**
* peek - view the top element of the stack
*
* @st: the stack whose top element will be viewed
*
* Returns: the value of the top element of the stack
*/
int sta_peek(stack_array *stack) {
    if (stack->top > -1) {
        return stack->array[stack->top];
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
bool sta_is_empty(stack_array *stack) {
    return stack->top == -1;
}


/**
* destroy_stack - free the memory that was allocated for the stack
*
* @st: the stack to destroy
*
* Returns: void
*/
void sta_destroy(stack_array **stack) {
    if (stack != NULL && *stack != NULL) {
        free(*stack);
        *stack = NULL;
    }
}
