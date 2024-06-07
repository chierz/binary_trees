#include "binary_trees.h"

/**
 * new_node_tree - Create a new node for linked_t node
 * @node: Pointer to the binary tree node
 * 
 * Return: Pointer to the new linked list node
 */
linked_t *new_node_tree(binary_tree_t *node)
{
    linked_t *new_tree;

    new_tree = malloc(sizeof(linked_t));
    if (new_tree == NULL)
    {
        return (NULL);
    }
    new_tree->node = node;
    new_tree->next = NULL;

    return (new_tree);
}

/**
 * free_qa - Free a linked list
 * @head: Pointer to the head of the linked list
 */
void free_qa(linked_t *head)
{
    linked_t *node_tmp;

    while (head)
    {
        node_tmp = head->next;
        free(head);
        head = node_tmp;
    }
}

/**
 * push_to - Push a binary tree node onto the linked list
 * @node: Pointer to the binary tree node
 * @head: Pointer to the head of the linked list
 * @tail: Pointer to the pointer of the tail of the linked list
 */
void push_to(const binary_tree_t *node, linked_t *head, linked_t **tail)
{
    linked_t *new_tree;

    new_tree = new_node_tree((binary_tree_t *)node);
    if (new_tree == NULL)
    {
        free_qa(head);
        exit(1); // Consider better error handling
    }
    (*tail)->next = new_tree;
    *tail = new_tree;
}

/**
 * pop_up - Pop a node from the linked list
 * @head: Pointer to the pointer of the head of the linked list
 */
void pop_up(linked_t **head)
{
    linked_t *node_tmp;

    node_tmp = (*head)->next;
    free(*head);
    *head = node_tmp;
}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * 
 * Return: 1 if complete, 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    linked_t *head, *tail;
    int flag = 0;

    if (tree == NULL)
    {
        return (0);
    }
    head = tail = new_node_tree((binary_tree_t *)tree);
    if (head == NULL)
    {
        exit(1); // Consider better error handling
    }
    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                free_qa(head);
                return (0);
            }
            push_to(head->node->left, head, &tail);
        }
        else
        {
            flag = 1;
        }

        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                free_qa(head);
                return (0);
            }
            push_to(head->node->right, head, &tail);
        }
        else
        {
            flag = 1;
        }

        pop_up(&head);
    }
    return (1);
}
