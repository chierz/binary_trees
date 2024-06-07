#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 * Return: root of created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    size_t a;
    bst_t *root = NULL;
    
    if (array == NULL || size == 0)
    {
        return (NULL);
    }

    for (a = 0; a < size; a++)
    {
        bst_insert(&root, array[a]);
    }

    return (root);
}
