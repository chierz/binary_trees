#include "binary_trees.h"

/**
 * bst_search - function that searches for a value in a Binary Search Tree
 * @tree: The pointer to the root node of the BST to search
 * @value: The value to search in the tree
 * Return: The node with value or NULL if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    bst_t *search;
    
    if (tree == NULL)
        return (NULL);
            
    if (value < tree->n)
    {
        search = bst_search(tree->left, value);
    }
    else if (value > tree->n)  // Removed the semicolon here
    {
        search = bst_search(tree->right, value);
    }
    else if (value == tree->n)
    {
        return ((bst_t *)tree);
    }
    else
    {
        return (NULL);
    }

    return (search);
}
