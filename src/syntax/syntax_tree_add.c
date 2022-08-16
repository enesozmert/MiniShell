#include "../../include/header.h"

void	syntax_tree_add_left(t_syntax_tree *syml, t_syntax_tree *syntax_tree)
{
	syntax_tree->left = syml;
}

void	syntax_tree_add_right(t_syntax_tree *text, t_syntax_tree *syntax_tree)
{
	syntax_tree->right = text;
}
