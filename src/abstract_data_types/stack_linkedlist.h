#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    size_t value;
    struct node *next;
} node;


typedef struct stack {
     node *top;
} stack;


stack *initialize_stack(size_t size) {
    stack *st = malloc(sizeof(size_t) * size);
    st->top = NULL;
    return st;
}


void free_node(node *n) {
    if (n != NULL) {
        free(n);
        n = NULL;
    }
}


void push(stack *st, size_t number) {
    node *np = malloc(sizeof(node));
    np->value = number;
    np->next = st->top;
    st->top = np;
}


size_t pop(stack *st) {
    if (st->top != NULL) {
        size_t value = st->top->value;
        node *destroyed_node = st->top;
        st->top = st->top->next;
        free_node(destroyed_node);
        return value;
    } else {
        return 0;
    }
}


bool is_empty(stack *st) {
    return st->top == NULL;
}


size_t peek(stack *st) {
    node *current = st->top;
    if (current != NULL) {
        return st->top->value;
    }
    return 0;
}
