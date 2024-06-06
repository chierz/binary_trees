#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: The pointer to the node to measure the depth
 * 
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    /* If the node is NULL or it has no parent, its depth is 0 */
    if (!tree || !(tree->parent))
        return (0);

    /* Recursively calculate the depth of the parent node and add 1
     * This effectively counts the number of edges from the node to the root
     */
    return (binary_tree_depth(tree->parent) + 1);
}
