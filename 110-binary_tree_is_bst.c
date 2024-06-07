#include "binary_trees.h"
#include <limits.h>

/**
 * valid_bst - Helper function that checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @minim: Minimum allowable value for the current node
 * @maxim: Maximum allowable value for the current node
 * Return: 1 if the node is valid, otherwise 0
 */
int valid_bst(const binary_tree_t *tree, int minim, int maxim)
{
    if (tree != NULL)
    {
        if (tree->n < minim || tree->n > maxim)
            return (0);
        return (valid_bst(tree->left, minim, tree->n - 1) &&
                valid_bst(tree->right, tree->n + 1, maxim));
    }
    return (1);
}

/**
 * binary_tree_is_bst - Function that checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (valid_bst(tree, INT_MIN, INT_MAX));
}
