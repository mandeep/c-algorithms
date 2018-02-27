#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    size_t value;
    struct node *left;
    struct node *right;
} node;



node *create_node(size_t value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->left = NULL;
    np->right = NULL;
    return np;
}


void insert(node **root, size_t value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else {
        if (value < (*root)->value) {
            insert(&(*root)->left, value);
        } else {
            insert(&(*root)->right, value);
        }
    }
}


void preorder_traversal(node *root) {
    if (root != NULL) {
        printf("%zu\n", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}


void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%zu\n", root->value);
        inorder_traversal(root->right);
    }
}


void postorder_traversal(node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%zu\n", root->value);
    }
}
