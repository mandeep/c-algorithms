#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
    int top;
    int array[];
} stack;


stack *initialize_stack(int size) {
    stack *st = malloc(sizeof(int) * size);
    st->top = -1;

    return st;
}


void push(stack *st, int number) {
    st->top += 1;
    st->array[st->top] = number;
}


int pop(stack *st) {
    int top_element = st->array[st->top];
    st->top -= 1;
    return top_element;
}


size_t peek(stack *st) {
    return st->array[st->top];
}


bool is_empty(stack *st) {
    return st->top == -1;
}
