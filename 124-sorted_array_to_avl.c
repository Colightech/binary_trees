124-sorted_array_to_avl.c
#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rootNode;
	size_t middle;

	rootNode = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	rootNode = binary_tree_node(rootNode, array[middle]);

	create_tree(&rootNode, array, middle, 1);
	create_tree(&rootNode, array + middle + 1, (size - 1 - middle), 2);

	return (rootNode);
}