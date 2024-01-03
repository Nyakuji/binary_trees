#include "binary_trees.h"

/**
* binary_tree_sibling - find the sibling of a node
*
* @node:  pointer to the node to find the sibling
* Return: Pointer to the sibling node, or NULL if node is NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left != node)
		return (node->parent->left);

	return (node->parent->right);
}

/**
* binary_tree_uncle - find the uncle of a node
*
* @node: pointer to the node to find the uncle
* Return: pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
