#include "../../include/header.h"

void parser_arg(t_rdl *rdl)
{
	int i;

	i = 0;
	parser_arg_iskeyword(&i, rdl);
	while (i < rdl->len && rdl->main_str[i] != '\0')
	{
		// if (rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]))
			
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(&i, rdl);
		else if (rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]))
			parser_arg_isnot(&i, rdl);
		else if (is_dollar(rdl->main_str[i]))
			parser_add_dollar(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_redir(rdl, rdl->main_str[i]))
			parser_arg_redir(&i, rdl);
		else if (is_option(rdl->main_str[i]) && rdl->main_str[i - 1] > 32 && rdl->main_str[i + 1] > 32)
			parser_add_option(rdl, rdl->main_str[i]);
		else if (is_pipe(rdl->main_str[i]) && is_pipe(rdl->main_str[i + 1]) == 0)
			parser_arg_pipe(&i, rdl);
		else if (ft_isalnum(rdl->main_str[i]) == 0 && rdl->main_str[i] > 32)
			parser_add_char(rdl, rdl->main_str[i]);
		else if (rdl->main_str[i] <= 32)
			parser_arg_space(&i, rdl);
		i++;
	}
}