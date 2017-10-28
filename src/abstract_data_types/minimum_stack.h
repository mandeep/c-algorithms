/**
* The minimum_stack is a stack abstract data type that holds data
* of the stack_data data type. The stack_data data type contains
* a value and a mimimum. The value is the value of the int to
* insert into the stack. The minimum is the minimum value that
* has been added to the stack. By keeping track of the minimum
* value with each element added to the stack, finding the minimum
* becomes an O(1) operation along with the other stack operations.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct stack_data {
    int value;
    int minimum;
} stack_data;


typedef struct minimum_stack {
    int top;
    stack_data array[];
} minimum_stack;


minimum_stack* initialize_stack(size_t size) {
    minimum_stack *stack = malloc(sizeof(stack_data) * size);
    stack->top = -1;
    
    return stack;
}


void push(minimum_stack* stack, int value) {
    stack_data element;
    element.value = value;

    if (stack->top == -1 || value <= stack->array[stack->top].minimum) {
        element.minimum = value;
    } else {
        element.minimum = stack->array[stack->top].minimum;
    }

    stack->top += 1;
    stack->array[stack->top] = element;    
}


void pop(minimum_stack* stack) {
    if (stack->top > -1) {
        stack->top -= 1;
    }
}


int top(minimum_stack* stack) {
    return stack->array[stack->top].value;
}


int minimum(minimum_stack* stack) {
    return stack->array[stack->top].minimum;
}


void free_stack(minimum_stack* stack) {
    if (stack != NULL) {
        free(stack);    }
        stack = NULL;

}
