#include "../../include/header.h"

void parser_arg_quote(int c, int *k, t_rdl *rdl)
{
	int i;
	int result;

	i = *k;
	result = parser_arg_is_query((char)c, &i, rdl);
	if (result == 1 && (is_dollar(rdl->main_str[i - 1]) || is_operator(rdl, rdl->main_str[i - 1])))
		parser_add_notoperator(rdl, rdl->main_str[i - 1]);
	printf("result : %d\n", result);
	parser_add_quote(rdl, rdl->main_str[i]);
	parser_arg_is((char)c, &i, rdl);
	rdl->quote_prop->flag = 1;
	*k = i;
}