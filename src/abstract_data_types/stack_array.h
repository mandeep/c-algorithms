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
typedef struct stack_array {
    int top;
    int array[];
} stack_array;


stack_array *initialize_stack_array(size_t capacity);

void sta_push(stack_array *st, int value);

int sta_pop(stack_array *st);

int sta_peek(stack_array *st);

bool sta_is_empty(stack_array *st);

void sta_destroy(stack_array **st);

#endif
