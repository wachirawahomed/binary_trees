#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Recursively get the height of the left subtree */
	left_height = binary_tree_height(tree->left);

	/* Recursively get the height of the right subtree */
	right_height = binary_tree_height(tree->right);

	/**
	 * Return the maximum height of the left or right subtree,
	 * plus 1 for the current node
	 */
	return (left_height > right_height ?
			left_height + 1 : right_height + 1);
}
