#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through a binary tree using pos-order traversal
 * @tree: The pointer to the root node of the tree to traverse
 * @func: The pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
            return;
    /* traverse left */
    if (tree->left)
            binary_tree_postorder(tree->left, func);
    /* traverse right */
    if (tree->right)
            binary_tree_postorder(tree->right, func);
    /* Calling current node function */
    func(tree->n);
}
