#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
    int top;
    int array[];
} stack;


stack *initialize_stack(void) {
    stack *st = malloc(sizeof(stack));
    st->top = -1;

    return st;
}


void push(stack *st, int number) {
    st->top += 1;
    st->array[st->top] = number;
}


int pop(stack *st) {
    int top_element = st->array[st->top];
    if (st->top > -1) {
        st->top -= 1;    
    }

    return top_element;
}


int peek(stack *st) {
    if (st->top <= -1) {
        return st->array[st->top];
    } else {
        return 0;
    }
}


bool is_empty(stack *st) {
    return st->top == -1;
}
