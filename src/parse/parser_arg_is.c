#include "../../include/header.h"

void parser_arg_is(int c, int *k, t_rdl *rdl)
{
	int i;
	int j;

	j = 0;
	i = *k;
	i++;
	while (rdl->main_str[i] != (char)c && rdl->main_str[i] != '\0')
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
		rdl->quote_prop->flag = 1;
	}
	printf("buffer : %s\n", rdl->buffer);
	if (rdl->quote_prop->flag == 1)
		rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) == 1)
	{
		rdl->t_flag = 0;
		parser_add(rdl, rdl->buffer);
	}
	if (ft_strlen(rdl->buffer) > 1)
	{
		rdl->t_flag = 0;
		j = -1;
		while (rdl->buffer[++j])
		{
			if (is_operator(rdl, rdl->buffer[j]))
			{
				*k = j;
				printf("i: %d\n", i);
				return ;
			}
		}
		parser_add(rdl, rdl->buffer);
	}
	else
		ft_bzero(rdl->buffer, ft_strlen(rdl->buffer));
	if (rdl->main_str[i] == (char)c)
	{
		parser_add_quote(rdl, rdl->main_str[i]);
		i++;
		rdl->quote_prop->flag = 1;
	}
	*k = i;
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (is_operator(rdl, rdl->main_str[i]) && rdl->main_str[i] != '\0')
		return ;
	while (is_quote(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && rdl->main_str[i] != '\0' && is_operator(rdl, rdl->main_str[i]) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
		rdl->quote_prop->flag = 0;
	}
	rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		parser_add(rdl, rdl->buffer);
	}
	else
		ft_bzero(rdl->buffer, ft_strlen(rdl->buffer));
	*k = i;
}
