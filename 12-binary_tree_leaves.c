#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: The pointer to the root node of the tree to count the number of leaves
 * 
 * Return: The number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    // If the tree is empty, return 0
    if (!tree)
        return (0);
    
    // If the current node is a leaf node (both left and right children are NULL), return 1
    if (!(tree->left) && !(tree->right))
        return (1);
    
    // Recursively count the leaves in the left and right subtrees
    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
