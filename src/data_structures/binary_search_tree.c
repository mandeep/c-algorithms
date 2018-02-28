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
* free_node: free the node passed as an argument from memory
*
* @node: the node to free
*
* Returns: void
*/
void free_node(node **n) {
    if (*n != NULL && n != NULL) {
        free(*n);
        n = NULL;
    }
}


/**
* delete_node: delete the node with the passed value from the passed node
*
* @root: the root node of the binary search tree
* @value: the value, or key, of the node to delete
*
* Returns: the deleted node
*/
node *delete_node(node *root, size_t value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = delete_node(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node(root->right, value);
    } else {
        if (root->left == NULL) {
            node *temp = root->right;
            free_node(&root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free_node(&root);
            return temp;
        }
        node *temp = minimum(root->right);
        root->value = temp->value;
        delete_node(root->right, temp->value);
    }
    return root;
}

/**
* find_node: find the node with the passed value within the passed root node
*
* @root: the root node of the binary tree to search
* @value: the value, or key, to search for*
ge
e* Returns: the node with the passed value or NULL
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


/**
* destroy_tree: delete the entire tree from memory
* 
* @root: the root node of the binary search tree
*
* Returns: void
*/
void destroy_tree(node *root) {
    if (root != NULL) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        free_node(&root);
    }
}
