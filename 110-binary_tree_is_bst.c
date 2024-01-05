#include "binary_trees.h"
#include <limits.h>

/**
* is_bst_helper - Helper function to perform in-order traversal and check BST
* @tree: Pointer to the current node
* @prev_value: Pointer to the previously visited value
*
* Return: 1 if the subtree is a valid BST, 0 otherwise
*/
int is_bst_helper(const binary_tree_t *tree, int *prev_value)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_helper(tree->left, prev_value))
		return (0);

	if (tree->n <= *prev_value)
		return (0);

	*prev_value = tree->n;

	return (is_bst_helper(tree->right, prev_value));
}

/**
* binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value = INT_MIN;

	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, &prev_value));
}
