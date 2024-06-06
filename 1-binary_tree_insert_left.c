#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node to create
 * @value: The value to put in the new node
 * Return: return a pointer to the node, or NULL on failure, or parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_tree_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_tree_node = binary_tree_node(parent, value);
	if (new_tree_node == NULL)
		return (NULL);
	new_tree_node->left = parent->left;
	parent->left = new_tree_node;
	if (new_tree_node->left)
		new_tree_node->left->parent = new_tree_node;
	return (new_tree_node);
}
