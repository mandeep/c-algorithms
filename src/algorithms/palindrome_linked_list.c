#include "../data_structures/linkedlist.h"

/// Given a linked list, determine if it is a palindrome.
bool is_palindrome(list_node *head){
    if (head == NULL) {
        return true;
    }

    list_node *current = head;
    int length = 0;

    while (current != NULL) {
        length += 1;
        current = current->next;
    }

    int nums[length]; // this array needs to be the same type as node->value

    current = head;

    for (int i = 0; i < length; i++) {
        nums[i] = current->value;
        current = current->next;
    }

    for (int i = 0, j = length-1; i < j; i++, j--) {
        if (nums[i] != nums[j]) {
            return false;
        }
    }

    return true;
}
