#include "../../include/header.h"

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (ft_isalnum(rdl->main_str[i]) && rdl->main_str[i])
		rdl->buffer[j++] = rdl->main_str[i++];
	rdl->buffer[j] = '\0';
	parser_add(rdl, rdl->buffer);
	i--;
	*k = i;
}