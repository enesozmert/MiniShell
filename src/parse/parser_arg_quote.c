#include "../../include/header.h"

void parser_arg_quote(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_quote(rdl, rdl->main_str[i]);
	// i++;
	if (rdl->quote_prop->flag == 1 )
		rdl->quote_prop->flag = 0;
	else if (rdl->quote_prop->flag == 0)
		rdl->quote_prop->flag = 1;
	*k = i;
}