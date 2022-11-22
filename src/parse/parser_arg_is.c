#include "../../include/header.h"

int parser_arg_is(int c, int *k, t_rdl *rdl)
{
	(void)c;
	(void)k;
	(void)rdl;
	return (1);
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (is_quote(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && rdl->main_str[i] != '\0' && is_dollar(rdl->main_str[i]) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i++];
		rdl->quote_prop->flag = 1;
	}
	rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		parser_add(rdl, rdl->buffer);
	}
	*k = i;
}
