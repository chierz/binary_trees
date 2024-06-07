#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation
 * on a binary tree
 * @tree: The Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_node_tree;

    if (tree == NULL || tree->left == NULL)
    {
        return (NULL);
    }
    new_node_tree = tree->left;
    tree->left = new_node_tree->right;
    if (new_node_tree->right != NULL)
    {
        new_node_tree->right->parent = tree;
    }
    new_node_tree->right = tree;
    new_node_tree->parent = tree->parent;
    tree->parent = new_node_tree;

    return (new_node_tree);
}
