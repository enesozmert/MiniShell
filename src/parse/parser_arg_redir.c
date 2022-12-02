#include "../../include/header.h"

void parser_arg_redir(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (rdl->main_str[i] == '>' || rdl->main_str[i] == '<')
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	rdl->buffer[j] = '\0';
	parser_add_redir(rdl, rdl->buffer);
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32);
	i -= 2;
	*k = i;
}