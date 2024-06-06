#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through a
 * binary tree using in-order traversal
 * @tree: The pointer to the root node of the tree to traverse
 * @func: The pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
			if (!tree || !func)
				return;
			/* traverse left */
			if (tree->left)
				binary_tree_inorder(tree->left, func);
			/* Calling current node function */
			func(tree->n);
			/* traverse right */
			if (tree->right)
				binary_tree_inorder(tree->right, func);
}
