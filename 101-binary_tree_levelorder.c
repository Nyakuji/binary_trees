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
* print_level - prints nodes at the same level
* @tree: tree root
* @level: level node
* @func: pointer to a function
*
* Return: void
*/
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
* binary_tree_levelorder - prints data in level-order traversal
* @tree: tree root
* @func: pointer to a function
*
* Return: void
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = recursive_height(tree);

	for (i = 1; i <= height; i++)
		print_level(tree, i, func);
}
