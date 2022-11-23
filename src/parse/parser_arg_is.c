#include "../../include/header.h"

int parser_arg_is(int *k, t_rdl *rdl)
{
	int i;
	int j;

	j = 0;
	i = *k;
	printf("ok\n");
	while (is_quote(rdl, rdl->main_str[i]) == 0 && is_dollar(rdl->main_str[i]) == 0 && rdl->main_str[i] != '\0')
	{
		rdl->buffer[j++] = rdl->main_str[i++];
		rdl->index_flag = 1;
	}
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	*k = i;
	return (0);
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	printf("ok1\n");
	while(is_quote(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]) == 0 && rdl->main_str[i] != '\0' && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i++];
		rdl->index_flag = 1;
	}
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	while (is_quote(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]) && rdl->main_str[i] != '\0' && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i++];
		rdl->index_flag = 1;
	}
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	*k = i;
}
