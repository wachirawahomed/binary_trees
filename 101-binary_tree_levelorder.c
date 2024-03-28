#include "binary_trees.h"

/**
* enqueue - Adds a new node at the end of a linked list (enqueue operation)
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
* dequeue - Removes a node from the front of the
*         linked list (dequeue operation)
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
* binary_tree_levelorder - Traverses a binary tree using level-order traversal
* @tree: Pointer to the root node of the binary tree
* @func: Pointer to the function to be called for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *front, *temp;
	size_t depth;

	if (!tree || !func)
		return;

	front = NULL;
	depth = 0;

	enqueue(&front, tree, depth);

	while (front)
	{
		temp = dequeue(&front);
		func(temp->node->n);

		if (temp->node->left)
			enqueue(&front, temp->node->left, temp->n + 1);
		if (temp->node->right)
			enqueue(&front, temp->node->right, temp->n + 1);

		free(temp);
	}
}
