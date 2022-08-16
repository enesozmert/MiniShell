#include "../../include/header.h"

t_syntax_tree	*syntax_tree_new(char *context)
{
	t_syntax_tree *syntax_tree;

	syntax_tree = malloc(sizeof(t_syntax_tree));
	syntax_tree->context = context;
	syntax_tree->left = NULL;
	syntax_tree->right = NULL;
	return (syntax_tree);
}
