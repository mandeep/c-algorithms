/**
* The minimum_stack is an abstract data type that holds data
* of the tuple data type. The tuple data type contains
* a value and a mimimum. The value is the value of the int to
* insert into the stack. The minimum is the minimum value that
* has been added to the stack. By keeping track of the minimum
* value with each element added to the stack, finding the minimum
* becomes an O(1) operation along with the other stack operations.
*/

#include <stdio.h>
#include <stdlib.h>


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


/**
* initialize_stack - allocate memory for the stack
*
* @size - the number of elements that will be added on the stack
*
* Returns: the newly initialized minimum_stack
*/
minimum_stack *initialize_stack(size_t size) {
    minimum_stack *stack = malloc(sizeof(tuple) * size);
    stack->top = -1;
    
    return stack;
}


/**
* push - push the value onto the stack
*
* @stack: the stack to push an element on to
* @value: the value to add to the stack
*
* Returns: void
*/
void push(minimum_stack *stack, void *value) {
    tuple element;
    element.value = value;

    if (stack->top == -1 || value <= stack->array[stack->top].minimum) {
        element.minimum = value;
    } else {
        element.minimum = stack->array[stack->top].minimum;
    }

    stack->top += 1;
    stack->array[stack->top] = element;    
}


/**
* pop - remove the last element that was added to the stack
*
* @stack: the stack from which to remove an element
*
* Returns: the element removed from the stack
*/
void *pop(minimum_stack *stack) {
    if (stack->top > -1) {
        stack->top -= 1;
    }

    return stack->array[stack->top].value;
}


/**
* top - show the last value that was added to the stack
*
* @stack: the stack whose last value added to show
*
* Returns: the value of the last element added to the stack
*/
void *top(minimum_stack *stack) {
    return stack->array[stack->top].value;
}


/**
* minimum - the minimum value on the stack
*
* @stack: the stack whose minimum value to show
*
* Returns: the minimum value of the stack
*/
void *minimum(minimum_stack *stack) {
    return stack->array[stack->top].minimum;
}


/**
* free_stack - free the memory that was allocated for the stack
*
* @stack: the stack whose memory to free
*
* Returns: void
*/
void destroy_stack(minimum_stack **stack) {
    if (*stack != NULL && stack != NULL) {
        free(*stack);
        stack = NULL;
    }
}
