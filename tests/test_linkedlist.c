#include "greatest.h"

#include "../src/data_structures/linkedlist.c"

void print_node(list_node *node) {
    printf("%zu\n", (size_t) node->value);
}


TEST test_insert_at_tail(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 4);
    insert_at_tail(list, (size_t*) 5);

    ASSERT_EQ((size_t) list->head->value, 3);

    destroy_list(&list);
    PASS();
}


TEST test_insert_at_head(void) {
    linked_list *list = initialize_list();
    insert_at_head(list, (size_t*) 3);
    insert_at_head(list, (size_t*) 4);
    insert_at_head(list, (size_t*) 5);

    ASSERT_EQ((size_t) list->head->value, 5);

    destroy_list(&list);
    PASS();
}


TEST test_insert_at_position(void) {
    linked_list *list = initialize_list();
    insert_at_position(list, (size_t*) 3, 0);
    insert_at_position(list, (size_t*) 4, 1);
    insert_at_position(list, (size_t*) 5, 0);

    ASSERT_EQ((size_t) list->head->value, 5);
    ASSERT_EQ((size_t) list->head->next->value, 3);
    ASSERT_EQ((size_t) list->head->next->next->value, 4);

    destroy_list(&list);
    PASS();
}


TEST test_insert_in_order(void) {
    linked_list *list = initialize_list();
    insert_in_order(list, (size_t*) 4);
    insert_in_order(list, (size_t*) 0);
    insert_in_order(list, (size_t*) 2);

    ASSERT_EQ((size_t) list->head->value, 0);
    ASSERT_EQ((size_t) list->head->next->value, 2);
    ASSERT_EQ((size_t) list->head->next->next->value, 4);

    destroy_list(&list);
    PASS();
}


TEST test_insert_double_link(void) {
    linked_list *list = initialize_list();
    insert_double_link(list, (size_t*) 1);
    insert_double_link(list, (size_t*) 2);
    insert_double_link(list, (size_t*) 3);

    ASSERT_EQ((size_t) list->head->value, 3);
    ASSERT_EQ((size_t) list->head->next->value, 2);
    ASSERT_EQ((size_t) list->head->next->next->value, 1);
    ASSERT_EQ(list->head->previous, NULL);
    ASSERT_EQ((size_t) list->head->next->previous->value, 3);
    ASSERT_EQ((size_t) list->head->next->next->previous->value, 2);

    destroy_list(&list);
    PASS();
}


TEST test_get_node(void) {
    linked_list *list = initialize_list();
    insert_at_head(list, (size_t*) 1);
    insert_at_head(list, (size_t*) 2);
    insert_at_head(list, (size_t*) 3);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 3);
    ASSERT_EQ_FMT((size_t) get_node(list, 1)->value, (size_t) 2, "%zu");
    ASSERT_EQ((size_t) get_node(list, 2)->value, 1);

    destroy_list(&list);
    PASS();
}


TEST test_find_node(void) {
    linked_list *list = initialize_list();
    insert_at_head(list, (size_t*) 1);
    insert_at_head(list, (size_t*) 2);
    insert_at_head(list, (size_t*) 3);

    ASSERT_EQ((int) find_list_node(list, (size_t*) 1), 2);
    ASSERT_EQ((int) find_list_node(list, (size_t*) 2), 1);
    ASSERT_EQ((int) find_list_node(list, (size_t*) 3), 0);
    ASSERT_EQ((int) find_list_node(list, (size_t*) 4), -1);

    destroy_list(&list);
    PASS();
}


TEST test_swap_nodes(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);
    swap_nodes(list, (size_t*) 3, (size_t*) 2);
    ASSERT_EQ((size_t) get_node(list, 0)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 3);
    ASSERT_EQ((size_t) get_node(list, 2)->value, 2);

    destroy_list(&list);
    PASS();
}


TEST test_count_node_occurrences(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);

    ASSERT_EQ(count_node_occurrences(list, (size_t *) 2), 2);

    destroy_list(&list);
    PASS();
}


TEST test_delete_at_head(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);

    delete_at_head(list);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 2);

    destroy_list(&list);
    PASS();
}


TEST test_delete_at_tail(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);

    delete_at_tail(list);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 2);
    ASSERT_EQ(get_node(list, 2), NULL);

    destroy_list(&list);
    PASS();
}


TEST test_delete_node(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);

    delete_node(list, (size_t*) 2);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 3);
    ASSERT_EQ(get_node(list, 2), NULL);

    destroy_list(&list);
    PASS();
}


TEST test_remove_sorted_duplicates(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 2);
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 3);

    remove_sorted_duplicates(list);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 2);
    ASSERT_EQ((size_t) get_node(list, 2)->value, 3);
    ASSERT_EQ(get_node(list, 3), NULL);

    destroy_list(&list);
    PASS();
}


TEST test_reverse_list(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 5);
    insert_at_tail(list, (size_t*) 0);

    reverse_list(list);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 0);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 5);
    ASSERT_EQ((size_t) get_node(list, 2)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 3)->value, 3);

    destroy_list(&list);
    PASS();
}


TEST test_merge_sorted_lists(void) {
    linked_list *list1 = initialize_list();
    insert_at_tail(list1, (size_t*) 2);
    insert_at_tail(list1, (size_t*) 4);
    insert_at_tail(list1, (size_t*) 6);

    linked_list *list2 = initialize_list();
    insert_at_tail(list2, (size_t*) 1);
    insert_at_tail(list2, (size_t*) 3);
    insert_at_tail(list2, (size_t*) 5);

    linked_list *list = merge_sorted_lists(list1, list2);

    ASSERT_EQ((size_t) get_node(list, 0)->value, 1);
    ASSERT_EQ((size_t) get_node(list, 1)->value, 2);
    ASSERT_EQ((size_t) get_node(list, 2)->value, 3);
    ASSERT_EQ((size_t) get_node(list, 3)->value, 4);
    ASSERT_EQ((size_t) get_node(list, 4)->value, 5);
    ASSERT_EQ((size_t) get_node(list, 5)->value, 6);

    destroy_list(&list1);
    destroy_list(&list2);
    destroy_list(&list);
    PASS();
}


TEST test_is_list_sorted(void) {
    linked_list *list1 = initialize_list();
    insert_at_tail(list1, (size_t*) 2);
    insert_at_tail(list1, (size_t*) 4);
    insert_at_tail(list1, (size_t*) 6);

    linked_list *list2 = initialize_list();
    insert_at_tail(list2, (size_t*) 0);
    insert_at_tail(list2, (size_t*) 3);
    insert_at_tail(list2, (size_t*) 1);

    ASSERT_EQ(is_list_sorted(list1), 1);
    ASSERT_EQ(is_list_sorted(list2), 0);

    destroy_list(&list1);
    destroy_list(&list2);
    PASS();
}


TEST test_list_length(void) {
    linked_list *list = initialize_list();
    insert_at_tail(list, (size_t*) 3);
    insert_at_tail(list, (size_t*) 1);
    insert_at_tail(list, (size_t*) 5);
    insert_at_tail(list, (size_t*) 0);

    ASSERT_EQ(list_length(list), 4);

    destroy_list(&list);
    PASS();
}


TEST test_traverse_list(void) {

    linked_list *list = initialize_list();
    insert_at_head(list, (size_t*) 3);
    insert_at_head(list, (size_t*) 1);
    insert_at_head(list, (size_t*) 5);
    insert_at_head(list, (size_t*) 0);

    traverse_list(list, print_node);
    destroy_list(&list);
    PASS();
}


SUITE(linkedlist) {
    RUN_TEST(test_insert_at_tail);
    RUN_TEST(test_insert_at_head);
    RUN_TEST(test_insert_at_position);
    RUN_TEST(test_insert_in_order);
    RUN_TEST(test_insert_double_link);
    RUN_TEST(test_get_node);
    RUN_TEST(test_find_node);
    RUN_TEST(test_swap_nodes);
    RUN_TEST(test_count_node_occurrences);
    RUN_TEST(test_delete_at_head);
    RUN_TEST(test_delete_at_tail);
    RUN_TEST(test_delete_node);
    RUN_TEST(test_remove_sorted_duplicates);
    RUN_TEST(test_reverse_list);
    RUN_TEST(test_merge_sorted_lists);
    RUN_TEST(test_is_list_sorted);
    RUN_TEST(test_list_length);
    RUN_TEST(test_traverse_list);
}
