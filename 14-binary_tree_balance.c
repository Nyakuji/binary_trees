#include "binary_trees.h"

/**
* recursive_height - Measures the height of a binary tree recursively.
* @node: Pointer to the root of the tree.
*
* Return: Height of the tree.
*/
size_t recursive_height(const binary_tree_t *node)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (node == NULL)
		return (0);

	l_height = recursive_height(node->left);
	r_height = recursive_height(node->right);

	return ((l_height > r_height) ? (l_height + 1) : (r_height + 1));
}

/**
* binary_tree_height - Calls recursive_height to return the height
*
* @tree: Pointer to the root of the tree.
* Return: Height of the tree or 0 if tree is NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recursive_height(tree) - 1);
}

/**
* binary_tree_balance - calls recursive_balance to return the balance
* @tree: pointer to root of the tree
*
* Return: balance factor of the tree or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
