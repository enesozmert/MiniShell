#include "../../include/header.h"

void parser_arg(t_rdl *rdl)
{
	int i;

	i = 0;
	parser_arg_iskeyword(&i, rdl);
	while (i < rdl->len && rdl->main_str[i] != '\0')
	{
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(&i, rdl);
		else if (rdl->main_str[i] > 32 && !is_delimiter(rdl, rdl->main_str[i]) && is_redir(rdl, rdl->main_str[i]) == 0 && is_redir(rdl, rdl->main_str[i]) == 0 && is_pipe(rdl->main_str[i]) == 0 && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
			parser_arg_isnot(&i, rdl);
		else if (is_dollar(rdl->main_str[i]))
			parser_add_dollar(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_redir(rdl, rdl->main_str[i]))
			parser_add_redir(rdl, rdl->main_str[i]);
		// else if (is_option(rdl->main_str[i]))
		// 	parser_add_option(rdl, rdl->main_str[i]);
		else if (is_pipe(rdl->main_str[i]) && is_pipe(rdl->main_str[i + 1]) == 0)
		{
			parser_add_pipe(rdl, rdl->main_str[i]);
			i+=1;
		}
		else if (is_delimiter(rdl, rdl->main_str[i]) && rdl->main_str[i] > 32)
			parser_add_char(rdl, rdl->main_str[i]);
		else if (rdl->main_str[i] <= 32)
			parser_arg_space(&i, rdl);
		i++;
	}
}
