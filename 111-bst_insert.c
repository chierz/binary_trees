#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 * Return: created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *temp;
    binary_tree_t *aux;

    if (tree == NULL)
        return (NULL);
    
    if (*tree == NULL)
    {
        aux = binary_tree_node((binary_tree_t *)(*tree), value);
        new_node = (bst_t *)aux;
        *tree = new_node;
    }
    else
    {
        temp = *tree;
        if (value < temp->n)
        {
            if (temp->left)
                new_node = bst_insert(&temp->left, value);
            else
            {
                aux = binary_tree_node((binary_tree_t *)temp, value);
                new_node = temp->left = (bst_t *)aux;
            }
        }
        else if (value > temp->n)
        {
            if (temp->right)
                new_node = bst_insert(&temp->right, value);
            else
            {
                aux = binary_tree_node((binary_tree_t *)temp, value);
                new_node = temp->right = (bst_t *)aux;
            }
        }
        else
            return (NULL);  // If the value already exists, return NULL
    }
    return (new_node);
}
