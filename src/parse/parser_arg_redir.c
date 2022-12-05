#include "../../include/header.h"

void parser_arg_redir(int *k, t_rdl *rdl)
{
	int		i;
	int		j;
	char	c;

	i = *k;
	j = 0;
	c = rdl->main_str[i];
	while (rdl->main_str[i] == c)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	rdl->buffer[j] = '\0';
	printf("redir buf: %s\n", rdl->buffer);
	parser_add_redir(rdl, rdl->buffer);
	if (rdl->main_str[i] <= 32 && rdl->main_str[i])
	{
		while (rdl->main_str[i] <= 32 && rdl->main_str[i])
			i++;
	}
	i -= 1;
	*k = i;
}