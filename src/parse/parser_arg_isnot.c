#include "../../include/header.h"

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (rdl->main_str[i] > 32 && !is_delimiter(rdl, rdl->main_str[i]) && is_redir(rdl, rdl->main_str[i]) == 0 && is_redir(rdl, rdl->main_str[i]) == 0 && is_pipe(rdl->main_str[i]) == 0 && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
		rdl->buffer[j++] = rdl->main_str[i++];
	if (is_keyword(rdl, rdl->buffer))
	{
		parser_add_keyword(rdl, rdl->buffer);
		while (rdl->main_str[i] <= 32)
			i++;
	}
	else if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	i--;
	*k = i;
}