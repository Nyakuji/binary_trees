#include "binary_trees.h"

/**
* binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
* @tree: Pointer to the root node of the tree to count the nodes
*
* Return: Number of nodes with at least 1 child, or 0 if tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node = 0;
	size_t right_node = 0;

	if (tree == NULL)
		return (0);

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		return (1 + left_node + right_node);

	return (0);
}
