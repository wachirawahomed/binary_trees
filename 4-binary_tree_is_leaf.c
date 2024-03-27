#include "binary_trees.h"

/**
* binary_tree_is_leaf - Checks if a node is a leaf
* @node: Pointer to the node to check
*
* Return: 1 if node is a leaf, 0 otherwise
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* If node is NULL or has at least one child, it's not a leaf */
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	/* Otherwise, it's a leaf */
	return (1);
}
