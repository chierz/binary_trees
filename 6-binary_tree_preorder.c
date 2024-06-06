#include "binary_trees.h"

/**
 * binary_tree_preorder - function that goes through a binary tree
 * using pre-order traversal
 * @tree: The pointer to the root node of the tree to traverse
 * @func: The pointer to a function to call for each node
 * Return: 1 if node is a leaf, otherwise 0
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	/* traverse left */
	if (tree->left)
		binary_tree_preorder(tree->left, func);
	/* traverse right */
	if (tree->right)
		binary_tree_preorder(tree->right, func);
}
