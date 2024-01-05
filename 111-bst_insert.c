#include "binary_trees.h"

/**
* bst_insert - Inserts a value in a Binary Search Tree (BST)
* @tree: Double pointer to the root node of the BST to insert the value
*
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = malloc(sizeof(bst_t));
		if (*tree == NULL)
			return (NULL);
		(*tree)->n = value;
		(*tree)->parent = NULL;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = bst_insert(&((*tree)->left), value);
			if ((*tree)->left != NULL)
				(*tree)->left->parent = *tree;
			return ((*tree)->left);
		}
		else
			return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = bst_insert(&((*tree)->right), value);
			if ((*tree)->right != NULL)
				(*tree)->right->parent = *tree;
			return ((*tree)->right);
		}
		else
			return (bst_insert(&((*tree)->right), value));
	}
	else
		return (NULL);
}
