#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as the left-child of another node
 * @parent: the  pointer to the node to insert the left-child 
 * @value:  value to store in the new node
 * Return: return a pointer to the created node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);
	if (newNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}
	parent->left = newNode;

	return (newNode);
}