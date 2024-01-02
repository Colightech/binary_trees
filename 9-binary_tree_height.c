#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_t = 0, right_t = 0;

		left_t = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_t = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left_t > right_t) ? left_t : right_t);
	}
	return (0);
}