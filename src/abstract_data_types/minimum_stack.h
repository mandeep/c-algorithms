#ifndef MINIMUM_STACK_H
#define MINIMUM_STACK_H

#include <stddef.h>

/**
* tuple - the data to use in the minimum_stack
*
* @value: the value to hold in the data type
* @minimum: the minimum seen so far in the stack
*
* Acts as a tuple containing the value and the minimum of the stack
*/
typedef struct tuple {
    void *value;
    void *minimum;
} tuple;


/**
* minimum_stack - abstract data type allowing for easy operations to one of a collection
*
* @top: the index of the top element of the stack
* @array: the flexible array member that will hold the values of the stack
*/
typedef struct minimum_stack {
    int top;
    tuple array[];
} minimum_stack;


minimum_stack *initialize_minimum_stack(size_t size);

void minst_push(minimum_stack *stack, void *value);

void *minst_pop(minimum_stack *stack);

void *minst_top(minimum_stack *stack);

void *minst_minimum(minimum_stack *stack);

void minst_destroy(minimum_stack **stack);

#endif
