#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"


/**
* initialize_list - allocate memory for a new linked list
*
* Returns: linked_list
*/
linked_list *initialize_list(void) {
    linked_list *list = malloc(sizeof(list_node) * 2);

    list->head = NULL;
    list->tail = NULL;

    return list;
}


/**
* insert_at_tail - insert a node at the tail end of the linked list
*
* @list: the linked_list in which to insert the node
* @value: the value of the element to insert into the linked list
*
* Returns: void
*
* This method of inserting nodes use both the head and tail nodes
* of the linked_list in order to keep track of the head node
* and tail node separately. This method is not to be used with
* other insertion methods.
*/
void insert_at_tail(linked_list *list, void *value) {
    list_node *np = malloc(sizeof(list_node));
    np->value = value;
    np->next = NULL;

    if (list->head == NULL) {
        list->head = np;
    } else {
        list->tail->next = np;
    }

    list->tail = np;
}


/**
* insert_at_head - insert a node at the head of the linked list
*
* @list: the linked_list in which to insert the node
* @value: the value of the element to insert into the linked list
*
* Returns: void
*
* This method of inserting nodes uses only the head node of
* the linked_list. Thus, nodes are inserted at the head of the
* linked list. This method is not to be used with other insertion
* methods.
*/
void insert_at_head(linked_list *list, void *value) {
    list_node *np = malloc(sizeof(list_node));
    np->value = value;
    np->next = list->head;
    list->head = np;
}


/**
* insert_at_position - insert node at the given position of the linked list
*
* @list: the linked_list in which to insert the node
* @value: the value of the element to insert into the linked list
* @index: the index at which to insert the node
*
* Returns: void
*
* This method is not to be used with other insertion methods.
*/
void insert_at_position(linked_list *list, void *value, size_t index) {
    list_node *np = malloc(sizeof(list_node));
    np->value = value;

    list_node *previous = NULL;
    list_node *current = list->head;

    size_t count = 0;

    if (current != NULL) {
        while (current->next != NULL && count < index) {
            previous = current;
            current = current->next;
            count += 1;
        }
        if (index == 0) {
            np->next = list->head;
            list->head = np;
        } else if (current->next == NULL && index == count + 1) {
            current->next = np;
            np->next = NULL;
        } else if (index > count + 1) {
            printf("Cannot insert into index %zu as the previous index does not contain a node\n", index);
        } else {
            previous->next = np;
            np->next = current;
        }
    } else {
        list->head = np;
        np->next = NULL;
    }
}


/**
* insert_in_order - insert a node into the linked list in sorted order
*
* @list: the linked_list in which to insert the node
* @value: the value of the element to insert into the linked list
*
* Returns: void
*
* This method is not to be used with other insertion methods.
*/
void insert_in_order(linked_list *list, void *value) {
    list_node *np = malloc(sizeof(list_node));
    np->value = value;
    np->next = NULL;
    list_node *previous = NULL;
    list_node *current = list->head;

    while (current != NULL && value > current->value) {
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


/**
* insert_double_link - insert a node with a previous and next pointer into a doubly linked list
*
* @list - the linked_list in which to insert the node
* @value - the value to insert into the linked list
*
* Returns: void
*/
void insert_double_link(linked_list *list, void *value) {
    list_node *np = malloc(sizeof(list_node));
    np->value = value;
    np->next = list->head;
    np->previous = NULL;

    if (list->head != NULL) {
        list->head->previous = np;
    }

    list->head = np;
}


/**
* get_node - get the node at the given index
*
* @list: the linked_list in which to retrieve the node
* @index: the index of the node to retrieve
*
* Returns: the node at the given index
*/
list_node *get_node(linked_list *list, size_t index) {
    list_node *current = list->head;

    size_t count = 0;

    while (current != NULL) {
        if (count == index) {
            return current;
        }
        current = current->next;
        count += 1;
    }

    return NULL;
}


/**
* find_node - search the list for the index of the node with the given value
*
* @list: the linkedlist in which to retrieve the node's index
* @value: the value to search for in the list
*
* Returns: the index of the node with the given value
*/
int find_list_node(linked_list *list, void *value) {
    list_node *current = list->head;

    size_t index = 0;

    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index += 1;
    }

    return -1;
}


/**
* swap_nodes - swap two nodes in the given linked list
*
* @list: the linked_list in which to swap nodes
* @x: the value of the node to swap with y
* @y: the value of the node to swap with x
*
* Returns: void
*/
void swap_nodes(linked_list *list, void *x, void *y) {
    list_node *current_y = list->head;
    list_node *current_x = list->head;
    list_node *previous_x = NULL;
    list_node *previous_y = NULL;

    if (x != y) {

        while (current_x != NULL && current_x->value != x) {
                previous_x = current_x;
                current_x = current_x->next;
        }

        while (current_y != NULL && current_y->value != y) {
                previous_y = current_y;
                current_y = current_y->next;
        }

        if (current_x != NULL && current_y != NULL) {

            if (previous_x != NULL) {
                previous_x->next = current_y;
            } else {
                list->head = current_y;
            }

            if (previous_y != NULL) {
                previous_y->next = current_x;
            } else {
                list->head = current_x;
            }

            list_node *temp = current_y->next;
            current_y->next = current_x->next;
            current_x->next = temp;
        }
    }
}


/**
* count_node_occurrences - count the number of times the given value appears in the linked list
*
* @list: the linked_list in which to count node occurrences
* @value: the value of the element of which to count occurrences
*
* Returns: void
*/
size_t count_node_occurrences(linked_list *list, void *value) {
    list_node *current = list->head;
    size_t count = 0;

    while (current != NULL) {
        if (current->value == value) {
            count += 1;
        }
        current = current->next;
    }

    return count;
}


/**
* free_node - free the memory that was allocated for the given node
*
* @node: the node whose memory to free
*
* Returns: void
*/
void free_list_node(list_node **n) {
    if (n != NULL && *n != NULL) {
        free(*n);
        *n = NULL;
    }
}


/**
* delete_at_head - remove the node at the head of the linked list
*
* @list: the linked_list whose head node will be removed
*
* Returns: void
*/
void delete_at_head(linked_list *list) {
    list_node *destroyed_node = list->head;
    list->head = list->head->next;
    free_list_node(&destroyed_node);
}


/**
* delete_at_tail - remove the node at the tail end of the linked list
*
* @list: the linked_list whose last node will be removed
*
* Returns: void
*/
void delete_at_tail(linked_list *list) {
    list_node *previous = NULL;
    list_node *current = list->head;

    if (list->head->next == NULL) {
        free_list_node(&list->head);
    } else {
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        free_list_node(&previous->next);
    }


}


/**
* delete_node - remove the given element of the linked list
*
* @list: the linked_list whose node will be removed
* @value: the value of the node to remove from the linked list
*
* Returns: void
*/
void delete_node(linked_list *list, void *value) {
    list_node *previous = NULL;
    list_node *current = list->head;

    if (list->head->value == value) {
        list_node *destroyed_node = list->head;
        list->head = list->head->next;
        free_list_node(&destroyed_node);
    } else {
        while (current != NULL && current->value != value) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free_list_node(&current);
    }
}


/**
* remove_sorted_duplicates - remove duplicate nodes from a sorted linked list
*
* @list: the linked_list whose duplicate nodes will be removed
*
* Returns: void
*/
void remove_sorted_duplicates(linked_list *list) {
    list_node *current = list->head;
    list_node *subsequent = list->head->next;

    if (current != NULL) {
        while (current->next != NULL) {
            if (current->value == current->next->value) {
                subsequent = current->next->next;
                list_node *destroyed_node = current->next;
                current->next = subsequent;
                free_list_node(&destroyed_node);
            } else {
                current = current->next;
            }
        }
    }
}


/**
* destroy_list - free the memory allocated for the linked list
*
* @list: the linked_list whose memory will be freed
*
* Returns: void
*/
void destroy_list(linked_list **list) {
    while ((*list)->head != NULL) {
        list_node *destroyed_node = (*list)->head;
        (*list)->head = (*list)->head->next;
        free_list_node(&destroyed_node);
    }

    if (list != NULL && *list != NULL) {
        free(*list);
        *list = NULL;
    }
}


/**
* reverse_list - reverse the nodes of the linked list
*
* @list: the linked_list whose nodes to reverse
*
* Returns: void
*/
void reverse_list(linked_list *list) {
    list_node *previous = NULL;
    list_node *current = list->head;

    while (current != NULL) {
        list_node *temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    list->head = previous;
}


/**
* merged_sorted_lists - merged two sorted lists into a new sorted linked list
*
* @list1: the first sorted linked list to merge
* @list2: the second sorted linked list to merge
*
* Returns: a sorted linked list containing the values of list1 and list2
*/
linked_list *merge_sorted_lists(linked_list *list1, linked_list *list2) {
    linked_list *merged_list = initialize_list();

    if (list1->head != NULL && list2->head == NULL) {
        return list1;
    } else if (list1->head == NULL && list2->head != NULL) {
        return list2;
    } else if (list1->head == NULL && list2->head == NULL) {
        return merged_list;
    }

    while (list1->head != NULL && list2->head != NULL) {
        if (list1->head->value < list2->head->value) {
            insert_in_order(merged_list, list1->head->value);
            list1->head = list1->head->next;
        } else {
            insert_in_order(merged_list, list2->head->value);
            list2->head = list2->head->next;
        }
    }

    if (list1->head == NULL) {
        while (list2->head != NULL) {
            insert_in_order(merged_list, list2->head->value);
            list2->head = list2->head->next;
        }
    } else {
        while (list1->head != NULL) {
            insert_in_order(merged_list, list1->head->value);
            list1->head = list1->head->next;
        }
    }

    return merged_list;
}


/**
* is_list_sorted - determine whether or not a linked list is sorted
*
* @list: the linked_list to check for orderness
*
* Returns: boolean value of linked list orderness
*/
bool is_list_sorted(linked_list *list) {
    list_node *current = list->head;

    while (current->next != NULL) {
        if (current->value > current->next->value) {
            return false;
        } else {
            current = current->next;
        }
    }

    return true;
}


/**
* list_length - the number of nodes in the linked list
*
* @list: the linked_list whose nodes to count
*
* Returns: the number of nodes in the linked list
*/
size_t list_length(linked_list *list)  {
    size_t length = 0;
    list_node *current = list->head;

    while (current != NULL) {
        current = current->next;
        length += 1;
    }

    return length;
}


/**
* traverse_list - traverse the linked list node by node
*
* @list: the linked_list to traverse
*
* Returns: void
*
*/
void traverse_list(linked_list *list, void (*fn)(list_node *node)) {
    list_node *current = list->head;

    while (current != NULL) {
        fn(current);
        current = current->next;
    }

    printf("\n");
}
