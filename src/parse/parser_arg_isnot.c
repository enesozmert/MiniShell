#include "../../include/header.h"

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int tmp_i;
	int j;

	i = *k;
	tmp_i = *k;
	j = 0;
	while (ft_isalnum(rdl->main_str[i]))
		rdl->buffer[j++] = rdl->main_str[i++];
	rdl->buffer[j] = '\0';
	if (is_keyword(rdl, rdl->buffer))
		parser_arg_iskeyword(&tmp_i, rdl);
	else
	{
		parser_add(rdl, rdl->buffer);
		i--;
	}
	*k = i;
}