#include "binary_trees.h"

void binary_tree_level(const binary_tree_t *tree,
		size_t lev, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_height - measure height of binary tree
 * @tree: The pointer to the root node of the tree to measure height
 *
 * Return: height of tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_level - function that perform specific level
 * @tree: The pointer to the root node of the tree
 * @lev: The level of tree
 * @func: The pointer to a function to perfom
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree,
		size_t lev, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (lev == 1)
		func(tree->n);
	else if (lev > 1)
	{
		binary_tree_level(tree->left, lev - 1, func);
		binary_tree_level(tree->right, lev - 1, func);
	}
}

/**
 * binary_tree_levelorder - function that goes through a binary tree
 * using level-order traversal
 * @tree: The pointer to the root node of the tree to traverse
 * @func: The pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, a;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (a = 1; a <= height; a++)
		binary_tree_level(tree, a, func);
}
