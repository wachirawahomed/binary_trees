#include "binary_trees.h"

/**
* binary_tree_height_and_full - Measures the height of a binary tree
*                                and checks if it is full.
* @tree: Pointer to the root node of the tree to measure.
*
* Return: Height of the tree if it's full, 0 otherwise.
*/
size_t binary_tree_height_and_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if both left and right subtrees are NULL */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Calculate the height of the left and right subtrees */
	size_t left_height = binary_tree_height_and_full(tree->left);
	size_t right_height = binary_tree_height_and_full(tree->right);

	/**
	 * If any subtree is not full or heights are not equal,
	 * the tree is not full
	 */
	if (left_height == 0 || right_height == 0 ||
			left_height != right_height)
		return (0);

	/* The tree is full, return the height of the tree */
	return (left_height > right_height ? left_height + 1 :
			right_height + 1);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Calculate the height of the tree and check if it's full */
	size_t height = binary_tree_height_and_full(tree);

	/* If the height is non-zero, the tree is perfect */
	return (height != 0);
}
