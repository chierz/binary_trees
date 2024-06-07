#include "binary_trees.h"

/**
 * search_successor - function that searches the next successor
 * @node: The pointer to the tree node
 * Return: The value to remove in the tree
 */
int search_successor(bst_t *node)
{
    int left = 0;
    
    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left = search_successor(node->left);
        if (left == 0)
        {
            return (node->n);
        }
        return (left);
    }
}

/**
 * replace_two_children - function that gets the next successor in the tree
 * @node: The pointer to the node with two children
 * Return: The value found
 */
int replace_two_children(bst_t *node)
{
    int value_found = 0;
    
    value_found = search_successor(node->right);
    node->n = value_found;
    return (value_found);
}
    
/**
 * bst_delete_value - function that deletes a node from the binary tree
 * @node: The pointer to the node to be removed
 * Return: The value to remove or 0 if it has no children
 */
int bst_delete_value(bst_t *node) 
{
    if (node == NULL)
    {
        return (0);
    }
    if (!node->left && !node->right)
    {
        if (node->parent->right == node)
        {
            node->parent->right = NULL;
        }
        else
        {
            node->parent->left = NULL;
        }
        free(node);
        return (0);
    }
    else if ((!node->left && node->right) || (!node->right && node->left))
    {
        if (!node->left)
        {
            if (node->parent->right == node)
            {
                node->parent->right = node->right;
            }
            else
            {
                node->parent->left = node->right;
            }
            node->right->parent = node->parent;
        }
        if (!node->right)
        {
            if (node->parent->right == node)
            {
                node->parent->right = node->left;
            }
            else
            {
                node->parent->left = node->left;
            }
            node->left->parent = node->parent;
        }
        free(node);
        return (0);
    }
    else
    {
        return (replace_two_children(node));
    }
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: The pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: The pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
    {
        return (NULL);
    }

    if (value < root->n)
    {
        root->left = bst_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = bst_remove(root->right, value);
    }
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return (NULL);
        }
        else if (!root->left)
        {
            bst_t *temp = root->right;
            temp->parent = root->parent;
            free(root);
            return (temp);
        }
        else if (!root->right)
        {
            bst_t *temp = root->left;
            temp->parent = root->parent;
            free(root);
            return (temp);
        }
        else
        {
            int successor_value = search_successor(root->right);
            root->n = successor_value;
            root->right = bst_remove(root->right, successor_value);
        }
    }
    return (root);
}
