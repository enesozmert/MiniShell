#include "../../include/header.h"

void parser_arg(t_rdl *rdl)
{
	int i;
	
	parser_arg_keyword(rdl);
	i = char_pos(rdl->main_str);
	while (i < rdl->len)
	{
		rdl->quote_prop->flag = 0;
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(rdl->main_str[i], &i, rdl);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_quote(rdl, rdl->main_str[i]))
			parser_add_quote(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32)
			parser_arg_isnot(&i, rdl);
		else if(rdl->main_str[i] >= 32)
			parser_arg_space(&i, rdl);
		if (rdl->quote_prop->flag == 0)
			i++;
	}
}