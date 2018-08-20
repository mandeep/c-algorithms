#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct bst_node {
    size_t value;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

bst_node *create_node(size_t value);

void insert_bst_bst_node(bst_node **root, size_t value);

bst_node *find_node(bst_node *root, size_t value);

bst_node *minimum(bst_node *root);

bst_node *maximum(bst_node *root);

void preorder_traversal(bst_node *root);

void inorder_traversal(bst_node *root);

void postorder_traversal(bst_node *root);


#endif
