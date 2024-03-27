#include "binary_trees.h"

/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If both children are NULL, it's a leaf (full) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If one child is NULL and the other is not, it's not full */
	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		return (0);

	/* Recursively check if both subtrees are full */
	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}

