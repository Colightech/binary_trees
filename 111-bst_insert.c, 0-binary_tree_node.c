111-bst_insert.c
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *newNode;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			newNode = binary_tree_node(curr, value);
			if (newNode == NULL)
				return (NULL);
			return (*tree = newNode);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			newNode = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = newNode);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			newNode = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = newNode);
		}
	}
	return (NULL);
}