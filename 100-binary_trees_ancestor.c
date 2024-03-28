#include "binary_trees.h"

int binary_tree_is_descendant(const binary_tree_t *node,
		const binary_tree_t *ancestor);

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes
* @first: Pointer to the first node
* @second: Pointer to the second node
*
* Return: Pointer to the lowest common ancestor node, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *current = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	current = first;

	while (current != NULL)
	{
		if (binary_tree_is_descendant(current, second))
			return ((binary_tree_t *)current);
		current = current->parent;
	}

	return (NULL);
}

/**
* binary_tree_is_descendant - Checks if a node is descendant of another
* @node: Pointer to the potential descendant node
* @ancestor: Pointer to the potential ancestor node
*
* Return: 1 if @node is a descendant of @ancestor, 0 otherwise
*/
int binary_tree_is_descendant(const binary_tree_t *node,
		const binary_tree_t *ancestor)
{
	if (node == NULL)
		return (0);

	if (node == ancestor)
		return (1);

	return (binary_tree_is_descendant(node->left, ancestor) ||
			binary_tree_is_descendant(node->right, ancestor));
}

