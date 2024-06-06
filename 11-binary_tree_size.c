#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: The pointer to the root node of the tree to measure the size
 * 
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    /* If the tree is empty, return size 0 */
    if (!tree)
        return (0);
    
    /* Recursively calculate the size by counting the root node and
     * the sizes of its left and right subtrees */
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
