#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    size_t value;
    struct node *left;
    struct node *right;
} node;

node *create_node(size_t value);

void insert_node(node **root, size_t value);

node *find_node(node *root, size_t value);

node *minimum(node *root);

node *maximum(node *root);

void preorder_traversal(node *root);

void inorder_traversal(node *root);

void postorder_traversal(node *root);


#endif
