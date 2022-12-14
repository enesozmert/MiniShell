#include "../../include/header.h"

void parser_arg_iskeyword(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_arg_keyword(&i, rdl);
	parser_add_keyword(rdl, rdl->buffer);
	if (is_keyword(rdl->keyword_list, rdl->buffer) == 0)
		parser_add_buffer(rdl, rdl->buffer, &i);
	i--;
	*k = i;
}