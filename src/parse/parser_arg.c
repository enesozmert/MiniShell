#include "../../include/header.h"

void parser_arg(t_rdl *rdl)
{
	int i;

	parser_arg_keyword(rdl);
	i = char_pos(rdl);
	while (i < rdl->len && rdl->main_str[i] != '\0')
	{
		rdl->index_flag = 0;
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(&i, rdl);
		else if (is_dollar(rdl->main_str[i]))
			parser_add_dollar(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (rdl->main_str[i] > 32)
			parser_arg_isnot(&i, rdl);
		// else if (rdl->main_str[i] >= 32 && rdl->quote_prop->flag == 1)
		// 	parser_arg_is(&i, rdl);
		else if (rdl->main_str[i] <= 32 && rdl->quote_prop->flag == 0)
			parser_arg_space(&i, rdl);
		if (rdl->index_flag == 0)
			i++;
	}
}