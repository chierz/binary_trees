#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 * Return: return a pointer to the created node, or NULL on failure or if          parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
{
    binary_tree_t *new_tree_node =NULL;
    
    if (parent == NULL)
            return (NULL);
    
    new_tree_node = binary_tree_node(parent, value);
    if new_tree_node == NULL;
                      return (NULL);
    new_tree_node->right = parent->right;
    parent->right = new_tree_node;
    if (new_tree_node->right)
                      new_tree_node->right->parent = new_tree_node;
    return (new_tree_node);
};