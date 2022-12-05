#include "../../include/header.h"

void parser_arg_pipe(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_pipe(rdl, rdl->main_str[i]);
	i++;
	if (rdl->main_str[i] <= 32 && rdl->main_str[i])
	{
		while (rdl->main_str[i] <= 32 && rdl->main_str[i])
			i++;
	}
	i -= 1;
    *k = i;
}