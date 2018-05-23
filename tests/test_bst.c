#include <stdio.h>
#include <stdlib.h>

#include "greatest.h"

#include "../src/data_structures/binary_search_tree.c"


TEST test_create_node(void) {
    node *test_node = create_node(10);
    ASSERT_EQ_FMT(test_node->value, (size_t) 10, "%zu");
    ASSERT(test_node->left == NULL);
    ASSERT(test_node->right == NULL);
    PASS();
}


TEST test_create_tree(void) {
    node *test_root = create_node(5);
    insert_node(&test_root, 7);
    insert_node(&test_root, 4);
    insert_node(&test_root, 3);

    ASSERT_EQ_FMT(minimum(test_root)->value, (size_t) 3, "%zu");
    ASSERT_EQ_FMT(maximum(test_root)->value, (size_t) 7, "%zu");
    ASSERT_EQ_FMT(height(test_root), 2, "%d");
    ASSERT_EQ_FMT(count_nodes(test_root), (size_t) 4, "%zu");
    ASSERT_EQ_FMT(count_leaves(test_root), (size_t) 2, "%zu");
    PASS();
}

SUITE(binary_search_tree) {
    RUN_TEST(test_create_node);
    RUN_TEST(test_create_tree);
}
