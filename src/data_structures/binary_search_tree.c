#include "binary_search_tree.h"



/**
* create_node: create a new node that will be inserted into the binary search tree
*
* @value: the value, or key, that the node will hold
*
* Returns: the newly created node
*/
node *create_node(size_t value) {
    node *np = malloc(sizeof(node));
    np->value = value;
    np->left = NULL;
    np->right = NULL;
    return np;
}


/**
* insert_node: create a new node with the passed value into the passed root node
*
* @root: the root node that will contain the new node
* @value: the value, or key, to assign to the inserted node
*
* Returns: void
*/
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


/**
* find_node: find the node with the passed value within the passed root node
*
* @root: the root node of the binary tree to search
* @value: the value, or key, to search for
*
* Returns: the node with the passed value or NULL
*/
node *find_node(node *root, size_t value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return find_node(root->left, value);
    } else {
        return find_node(root->right, value);
    }
}


/**
* minimum: find the node with the minimum value within the passed root node
*
* @root: the root node of the binary tree to search
*
* Returns: the node that contains the minimum value
*/
node *minimum(node *root) {
    if (root->left == NULL) {
        return root;
    } else {
        return minimum(root->left);
    }
}


/**
* maximum: find the node with the maximum value within the passed root node
*
* @root: the root node of the binary tree to search
*
* Returns: the node that contains the maximum value
*/
node *maximum(node *root) {
    if (root->right == NULL) {
        return root;
    } else {
        return maximum(root->right);
    }
}


/**
* preorder_traversal: traverse the passed root node in preorder
*
* @root: the root node of the binary tree to traverse
*
* Returns: void
*/
void preorder_traversal(node *root) {
    if (root != NULL) {
        printf("%zu\n", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}


/**
* inorder_traversal: traverse the passed root node in order
*
* @root: the root node of the binary tree to traverse
*
* Returns: void
*/
void inorder_traversal(node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%zu\n", root->value);
        inorder_traversal(root->right);
    }
}


/**
* preorder_traversal: traverse the passed root node in postorder
*
* @root: the root node of the binary tree to traverse
*
* Returns: void
*/
void postorder_traversal(node *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%zu\n", root->value);
    }
}
