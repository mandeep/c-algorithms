#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>


/**
* node - node data type to be used with the linked list
*
* @value: the element to hold in the node
* @next: the next node to link to when creating a singly linked list
* @previous: the previous node to link if creating a doubly linked list
*/
typedef struct list_node {
    void *value;
    struct list_node *next;
    struct list_node *previous;
} list_node;


/**
* linked_list - the linked_list data structure that holds nodes of data
*
* @head: the head node of the linked list
* @tail: the tail node of the linked list (used when keeping track of the last node)
*/
typedef struct linked_list {
    list_node *head;
    list_node *tail;
} linked_list;


linked_list *initialize_list(void);

void insert_at_tail(linked_list *list, void *value);

void insert_at_head(linked_list *list, void *value);

void insert_at_position(linked_list *list, void *value, size_t index);

void insert_in_order(linked_list *list, void *value);

void insert_double_link(linked_list *list, void *value);

list_node *get_node(linked_list *list, size_t index);

void swap_nodes(linked_list *list, void *x, void *y);

size_t count_node_occurences(linked_list *list, void *value);

void free_list_node(list_node **n);

void delete_at_head(linked_list *list);

void delete_at_tail(linked_list *list);

void delete_node(linked_list *list, void *value);

void remove_sorted_duplicates(linked_list *list);

void destroy_list(linked_list **list);

void reverse_list(linked_list *list);

linked_list *merge_sorted_lists(linked_list *list1, linked_list *list2);

bool is_list_sorted(linked_list *list);

size_t list_length(linked_list *list);

void print_list(linked_list *list);

#endif
