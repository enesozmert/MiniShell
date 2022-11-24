#include "../../include/header.h"

void parser_arg(t_rdl *rdl)
{
	int i;

	parser_arg_keyword(rdl);
	if (is_keyword(rdl, rdl->buffer))
		parser_add_keyword(rdl, rdl->buffer);
	else
		parser_add(rdl, rdl->buffer);
	i = char_pos(rdl);
	while (i < rdl->len && rdl->main_str[i] != '\0')
	{
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(&i, rdl);
		else if (rdl->main_str[i] > 32 && !is_delimiter(rdl, rdl->main_str[i]) && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
			parser_arg_isnot(&i, rdl);
		else if (is_dollar(rdl->main_str[i]))
			parser_add_dollar(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_delimiter(rdl, rdl->main_str[i]))
			parser_add_char(rdl, rdl->main_str[i]);
		else if (rdl->main_str[i] <= 32)
			parser_arg_space(&i, rdl);
		i++;
	}
}
