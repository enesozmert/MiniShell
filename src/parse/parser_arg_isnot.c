#include "../../include/header.h"

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (rdl->main_str[i] > 32 && !is_delimiter(rdl, rdl->main_str[i]))
		rdl->buffer[j++] = rdl->main_str[i++];
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	i--;
	*k = i;
}