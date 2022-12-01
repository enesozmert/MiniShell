#include "../../include/header.h"

void parser_arg_iskeyword(int *k, t_rdl *rdl)
{
    int i;
	int tmp_i;

    i = *k;
	tmp_i = *k;
	parser_arg_keyword(&i, rdl);
	if (is_keyword(rdl, rdl->buffer))
	{
		parser_add_keyword(rdl, rdl->buffer);
	}
	else
		i = tmp_i;
	i--;
    *k = i;
}