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


void free_node(node *n) {
    if (n != NULL) {
        free(n);
        n = NULL;
    }
}


void delete_at_head(linked_list *list) {
    node *old = list->head;
    list->head = list->head->next;
    free_node(old);
}


void delete_at_tail(linked_list *list) {
    node *previous = NULL;
    node *current = list->head;

    if (list->head->next == NULL) {
        node *old = list->head;
        list->head = NULL;
        free_node(old);
    } else {
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        free_node(current);
    }
}


void delete_node(linked_list *list, size_t element) {
    node *previous = NULL;
    node *current = list->head;

    if (list->head->value == element) {
        node *old = list->head;
        list->head = list->head->next;
        free_node(old);
    } else {
        while (current != NULL && current->value != element) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free_node(current);
    }
}


void destroy_list(linked_list *list) {
    while (list->head != NULL) {
        node *destroyed_node = list->head;
        list->head = list->head->next;
        free_node(destroyed_node);
    }
}


void print_list(linked_list *list) {
    node *current = list->head;
    while (current != NULL) {
        printf("%zu ", current->value);
        current = current->next;
    }
    printf("\n");
}
