#include "../../include/header.h"

void parser_arg_quote(int c, int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_quote(rdl, rdl->main_str[i]);
	parser_arg_is((char)c, &i, rdl);
	rdl->quote_prop->flag = 1;
	*k = i;
}