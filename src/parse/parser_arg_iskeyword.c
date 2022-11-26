#include "../../include/header.h"

void parser_arg_iskeyword(int *k, t_rdl *rdl)
{
    int i;

    i = *k;
	parser_arg_keyword(rdl);
	if (is_keyword(rdl, rdl->buffer))
		parser_add_keyword(rdl, rdl->buffer);
	else
	{
		parser_add(rdl, rdl->buffer);
		parser_add(rdl, ft_strdup(" "));
	}
	i = char_pos(rdl);
    *k = i;
}