#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *newNode;

	new = malloc(sizeof(levelorder_queue_t));
	if (newNode == NULL)
		return (NULL);

	newNode->node = node;
	newNode->next = NULL;

	return (newNode);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *newNode;

	newNode = create_node(node);
	if (newNode == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = newNode;
	*tail = newNode;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *headNode, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	headNode = tail = create_node((binary_tree_t *)tree);
	if (headNode == NULL)
		exit(1);

	while (headNode != NULL)
	{
		if (headNode->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(headNode);
				return (0);
			}
			push(headNode->node->left, headNode, &tail);
		}
		else
			flag = 1;
		if (headNode->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(headNode);
				return (0);
			}
			push(headNode->node->right, headNode, &tail);
		}
		else
			flag = 1;
		pop(&headNode);
	}
	return (1);
}
