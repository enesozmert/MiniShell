#include "../../include/header.h"

void parser_arg_quote(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	rdl->quote_prop->flag = 1;
	parser_add_quote(rdl, rdl->main_str[i]);
	i++;
	parser_arg_is(&i, rdl);
	*k = i;
}