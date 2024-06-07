#include <stdlib.h>
#include "binary_trees.h"

/* Define the linked_t structure */
typedef struct linked_s
{
    struct binary_tree_s *node;
    struct linked_s *next;
} linked_t;

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

void free_qa(linked_t *head)
{
    linked_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void push_to(const binary_tree_t *node, linked_t *head, linked_t **tail)
{
    linked_t *new_tree = new_node_tree((binary_tree_t *)node);

    if (new_tree == NULL)
    {
        free_qa(head);
        exit(1);
    }
    (*tail)->next = new_tree;
    *tail = new_tree;
}

void pop_up(linked_t **head)
{
    linked_t *temp;

    if (head == NULL || *head == NULL)
    {
        return;
    }
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

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
        return (0);
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
