#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/**
* stack - abstract data type that holds a collection of elements
*
* @top: the index of the element at the top of the stack
* @array: an array in which to store the stack's elements
*/
typedef struct stack {
    int top;
    int array[];
} stack;


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
stack *initialize_stack(size_t size) {
    stack *st = malloc(sizeof(int) * size);
    st->top = -1;

    return st;
}


/**
* push - add an element to the stack
*
* @st: the initialized stack
* @value: the value to add to the stack
*
* Returns: void
*/
void push(stack *st, int value) {
    st->top += 1;
    st->array[st->top] = value;
}


/**
* pop - remove the top element of the stack
*
* @st: the stack to remove the element from
*
* Returns: the element removed from the top of the stack 
*/
int pop(stack *st) {
    int top_element = st->array[st->top];
    if (st->top > -1) {
        st->top -= 1;    
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
int peek(stack *st) {
    if (st->top > -1) {
        return st->array[st->top];
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
    return st->top == -1;
}


/**
* destroy_stack - free the memory that was allocated for the stack
*
* @st: the stack to destroy
*
* Returns: void
*/
void destroy_stack(stack **st) {
    if (st != NULL && *st != NULL) {
        free(st);
        st = NULL;
    }
}
