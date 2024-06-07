#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation
 * on a binary tree
 * @tree: The Pointer to the root node of the tree to rotate
 * Return: Pointer to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_node_tree;

    if (tree == NULL || tree->right == NULL)
    {
        return (NULL);
    }
    new_node_tree = tree->right;
    tree->right = new_node_tree->left;
    if (new_node_tree->left != NULL)
    {
        new_node_tree->left->parent = tree;
    }
    new_node_tree->left = tree;
    new_node_tree->parent = tree->parent;
    tree->parent = new_node_tree;

    return (new_node_tree);
}
