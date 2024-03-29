#include "binary_trees.h"

/**
* binary_tree_size - Measures the size of a binary tree
* @tree: Pointer to the root node of the tree to measure the size
*
* Return: Size of the tree, or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree ==  NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

/**
* tree_is_complete - checks if tree is complete
* @tree: pointer to the tree root
* @i: node index
* @nodes: number of nodes
* Return: 1 if tree is complete, 0 otherwise
*/
int tree_is_complete(const binary_tree_t *tree, int i, int nodes)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (i >= nodes)
		return (0);

	left = tree_is_complete(tree->left, (2 * i) + 1, nodes);
	right = tree_is_complete(tree->right, (2 * i) + 2, nodes);

	return (left && right);
}

/**
* binary_tree_is_complete - calls to tree_is_complete function
*
* @tree: tree root
* Return: 1 if tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, nodes));
}
