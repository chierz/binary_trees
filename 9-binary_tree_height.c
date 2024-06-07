#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: The pointer to the root node of the tree to measure the height.
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	/* traverse left */
	a = binary_tree_height(tree->right);
	b = binary_tree_height(tree->left);
	if (a > b)
		a = b;
	return (a + 1);
}
