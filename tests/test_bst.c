#include <stdio.h>
#include <stdlib.h>

#include "greatest.h"

#include "../src/data_structures/binary_search_tree.c"


TEST test_binary_search_tree(void) {
    bst_node *test_root = create_node(5);
    ASSERT_EQ_FMT(test_root->value, (size_t) 5, "%zu");
    ASSERT(test_root->left == NULL);
    ASSERT(test_root->right == NULL);

    insert_node(&test_root, 7);
    insert_node(&test_root, 4);
    insert_node(&test_root, 3);

    ASSERT_EQ_FMT(minimum(test_root)->value, (size_t) 3, "%zu");
    ASSERT_EQ_FMT(maximum(test_root)->value, (size_t) 7, "%zu");
    ASSERT_EQ_FMT(height(test_root), 2, "%d");
    ASSERT_EQ_FMT(count_nodes(test_root), (size_t) 4, "%zu");
    ASSERT_EQ_FMT(count_leaves(test_root), (size_t) 2, "%zu");

    delete_bst_node(test_root, 4);
    delete_bst_node(test_root, 7);

    ASSERT_EQ_FMT(find_node(test_root, 3)->value, (size_t) 3, "%zu");

    preorder_traversal(test_root);
    inorder_traversal(test_root);
    postorder_traversal(test_root);

    destroy_tree(test_root);
    PASS();
}

SUITE(binary_search_tree) {
    RUN_TEST(test_binary_search_tree);
}
