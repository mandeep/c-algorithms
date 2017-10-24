#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    size_t value;
    struct node *previous;
    struct node *next;
} node;


typedef struct linked_list {
    node *head;
    node *tail;
} linked_list;


void initialize_list(linked_list *list) {
    list->head = NULL;
    list->tail = NULL;
}


void free_node(node *n) {
    if (n != NULL) {
        free(n);
        n = NULL;
    }
}


void insert_at_tail(linked_list *list, size_t number) {
    node *np = malloc(sizeof(node));
    np->value = number;
    np->next = NULL;

    if (list->head == NULL) {
        list->head = np;
    } else {
        list->tail->next = np;
    }
    list->tail = np;
}


void insert_at_head(linked_list *list, size_t number) {
    node *np = malloc(sizeof(node));
    np->value = number;
    np->next = list->head;
    list->head = np;
}


void insert_in_order(linked_list *list, size_t number) {
    node *np = malloc(sizeof(node));
    np->value = number;
    np->next = NULL;
    node *previous = NULL;
    node *current = list->head;

    while (current != NULL && number > current->value) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        previous = np;
        list->head = previous;
    }

    previous->next = np;
    np->next = current;
}
