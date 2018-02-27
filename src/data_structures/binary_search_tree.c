#include "binary_search_tree.h"


node *create_node(size_t value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->left = NULL;
    np->right = NULL;
    return np;
}


void insert_node(node **root, size_t value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else {
        if (value < (*root)->value) {
            insert_node(&(*root)->left, value);
        } else {
            insert_node(&(*root)->right, value);
        }
    }
}


node *find_node(node *root, size_t value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return find_node(root->left, value);
    } else {
        return find_node(root->right, value);
    }
}


node *minimum(node *root) {
    if (root->left == NULL) {
        return root;
    } else {
        return minimum(root->left);
    }
}


node *maximum(node *root) {
    if (root->right == NULL) {
        return root;
    } else {
        return maximum(root->right);
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
