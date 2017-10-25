#include <stdbool.h>
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


void insert_at_position(linked_list *list, size_t index, size_t number) {
    node *np = malloc(sizeof(node));
    np->value = number;
    node *previous = NULL;
    node *head = list->head;

    if (index == 0) {
        np->next = list->head;
        list->head = np;
    } else {
        size_t count = 0;
        while (count < index && list->head->next != NULL) {
            previous = list->head;
            list->head = list->head->next;
            count += 1;
        }

        if (list->head->next == NULL) {
            previous->next = np;
            np->next = NULL;
        } else {
            previous->next = np;
            np->next = list->head;
        }

        list->head = head;
    }
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


node *get_node(linked_list *list, size_t index) {
    node *current = list->head;
    size_t count = 0;

    if (index == 0) {
        return current;
    }

    while (count < index && current->next != NULL) {
        current = current->next;
        count += 1;
    }

    return current;
}


void swap_nodes(linked_list *list, size_t x, size_t y) {
    node *current_y = list->head;
    node *current_x = list->head;
    node *previous_x = NULL;
    node *previous_y = NULL;

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

            node *temp = current_y->next;
            current_y->next = current_x->next;
            current_x->next = temp;
        }    
    }
}


size_t count_node_occurences(linked_list *list, size_t number) {
    node *current = list->head;
    size_t count = 0;

    while (current != NULL) {
        if (current->value == number) {
            count += 1;
        }
        current = current->next;
    }

    return count;
}


void free_node(node *n) {
    if (n != NULL) {
        free(n);
        n = NULL;
    }
}


void delete_at_head(linked_list *list) {
    node *destroyed_node = list->head;
    list->head = list->head->next;
    free_node(destroyed_node);
}


void delete_at_tail(linked_list *list) {
    node *previous = NULL;
    node *current = list->head;

    if (list->head->next == NULL) {
        node *destroyed_node = list->head;
        list->head = NULL;
        free_node(destroyed_node);
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
        node *destroyed_node = list->head;
        list->head = list->head->next;
        free_node(destroyed_node);
    } else {
        while (current != NULL && current->value != element) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free_node(current);
    }
}


void remove_duplicates(linked_list *list) {
    node *current = list->head;
    node *next = list->head->next;

    if (current != NULL) {
        while (current->next != NULL) {
            if (current->value == next->value) {
                next = current->next->next;
                free_node(current->next);
                current->next = next;
            } else {
                current = current->next;
            }
        }
    }
}


void destroy_list(linked_list *list) {
    while (list->head != NULL) {
        node *destroyed_node = list->head;
        list->head = list->head->next;
        free_node(destroyed_node);
    }
}


void reverse_list(linked_list *list) {
    node *previous = NULL;
    node *current = list->head;

    while (current != NULL) {
        node *temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    list->head = previous;
}


linked_list merge_sorted_lists(linked_list *list1, linked_list *list2) {
    linked_list merged_list;
    initialize_list(&merged_list);

    if (list1->head != NULL && list2->head == NULL) {
        return *list1;
    } else if (list1->head == NULL && list2->head != NULL) {
        return *list2;
    } else if (list1->head == NULL && list2->head == NULL) {
        return merged_list;
    }

    while (list1->head != NULL && list2->head != NULL) {
        if (list1->head->value < list2->head->value) {
            insert_in_order(&merged_list, list1->head->value);
            list1->head = list1->head->next;
        } else {
            insert_in_order(&merged_list, list2->head->value);
            list2->head = list2->head->next;
        }
    }

    if (list1->head == NULL) {
        while (list2->head != NULL) {
            insert_in_order(&merged_list, list2->head->value);
            list2->head = list2->head->next;
        }
    } else {
        while (list1->head != NULL) {
            insert_in_order(&merged_list, list1->head->value);
            list1->head = list1->head->next;
        }
    }

    return merged_list;
}


bool is_list_sorted(linked_list *list) {
    node *current = list->head;

    while (current->next != NULL) {
        if (current->value > current->next->value) {
            return false;
        } else {
            current = current->next;
        }
    }

    return true;
}


size_t list_length(linked_list *list)  {
    size_t length = 0;
    node *current = list->head;

    while (current != NULL) {
        current = current->next;
        length += 1;
    }

    return length;
}


void print_list(linked_list *list) {
    node *current = list->head;

    while (current != NULL) {
        printf("%zu ", current->value);
        current = current->next;
    }

    printf("\n");
}
