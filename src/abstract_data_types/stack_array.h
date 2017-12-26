#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stddef.h>


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


stack *initialize_stack(size_t capacity);

void push(stack *st, int value);

int pop(stack *st);

int peek(stack *st);

bool is_empty(stack *st);

void destroy_stack(stack **st);

#endif
