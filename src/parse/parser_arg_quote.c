#include "../../include/header.h"

void parser_arg_quote(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_quote(rdl, rdl->main_str[i]);
	parser_arg_is_quote(rdl->main_str[i], &i, rdl);
	if (is_quote(rdl, rdl->main_str[i]))
		parser_add_quote(rdl, rdl->main_str[i]);
	*k = i;
}