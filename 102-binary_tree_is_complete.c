#include "binary_trees.h"
#include <limits.h>

/**
* enqueue - Adds a new node at the end of a linked list
* @front: Pointer to the front of the linked list
* @tree: Pointer to the binary tree node
* @level: Depth level of the binary tree node
*/
void enqueue(queue_t **front, const binary_tree_t *tree, size_t level)
{
	queue_t *new_node, *temp;

	new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return;

	new_node->n = level;
	new_node->node = tree;
	new_node->next = NULL;

	if (!*front)
		*front = new_node;
	else
	{
		temp = *front;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

/**
* dequeue - Removes a node from the front of the linked list
* @front: Pointer to the front of the linked list
* Return: Pointer to the dequeued node
*/
	queue_t *dequeue(queue_t **front)
	{
	queue_t *temp;

	if (!*front)
		return (NULL);

	temp = *front;
	*front = (*front)->next;
	return (temp);
}

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;
	queue_t *queue = NULL;
	const binary_tree_t *current;

	if (!tree)
		return (0);

	enqueue(&queue, tree, 1);

	while (queue)
	{
		current = queue->node;
		dequeue(&queue);

		if (!current)
			flag = 1;
		else
		{
			if (flag)
				return (0);

			enqueue(&queue, current->left,
					(queue ? queue->n + 1 : 1));
			enqueue(&queue, current->right,
					(queue ? queue->n + 1 : 1));
		}
	}

	return (1);
}
