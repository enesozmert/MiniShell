#include "../../include/header.h"

void parser_arg_iskeyword(int *k, t_rdl *rdl)
{
    int i;
	int tmp_i;

    i = *k;
	tmp_i = *k;
	parser_arg_keyword(&i, rdl);

	if (is_keyword(rdl->keyword_list, rdl->buffer))
		parser_add_keyword(rdl, rdl->buffer);
	else if	(is_keyword(rdl->keyword_list, rdl->buffer) == 0)
	{
		parser_add_buffer(rdl, rdl->buffer, &i);
		i--;
		*k = i;
		return ;
	}
	i--;
    *k = i;
}