#include "../../include/header.h"

void parser_arg_keyword(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	if (rdl->main_str[i] <= 32)
	{
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i])
			;
		i--;
	}
	while (rdl->main_str[i] > 32 && rdl->main_str[i])
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i])
			;
	rdl->buffer[j] = '\0';
	*k = i;
}
