#include "../../include/header.h"

int parser_arg_is(int c, int *k, t_rdl *rdl)
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
	printf("rdl->buffer[j] %s\n", rdl->buffer);
	if (rdl->quote_prop->flag == 1)
		rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) == 1 && is_dollar(rdl->buffer[0]) == 0)
	{
		printf("rdl->buffer[j] %s\n", rdl->buffer);
		rdl->t_flag = 0;
		parser_add(rdl, rdl->buffer);
		*k = i;
		return (2);
	}
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		j = -1;
		while (rdl->buffer[++j])
		{
			if (is_operator(rdl, rdl->buffer[j]))
			{
				parser_add_operator(rdl, rdl->buffer[j]);
				*k = i - (ft_strlen(rdl->buffer) - j) + 1;
				rdl->quote_prop->flag = 1;
				return (0);
			}
			else
			{
				*k = i - ft_strlen(rdl->buffer);
				rdl->quote_prop->flag = 1;
				return (0);
			}
		}
	}
	*k = i;
	return(1);
}

int parser_arg_is_query(int c, int *k, t_rdl *rdl)
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
	if (rdl->quote_prop->flag == 1)
		rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) == 1)
		return (2);
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->t_flag = 0;
		j = -1;
		while (rdl->buffer[++j])
		{
			if (is_operator(rdl, rdl->buffer[j]) && is_operator(rdl, rdl->buffer[j + 1]) == 0)
				return (0);
			else
				return (0);
		}
	}
	return(1);
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (is_operator(rdl, rdl->main_str[i]) && rdl->main_str[i + 1] != '\0')
		return;
	while (is_quote(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && rdl->main_str[i] != '\0' && is_operator(rdl, rdl->main_str[i]) == 0 && is_dollar(rdl->main_str[i]) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
		rdl->quote_prop->flag = 1;
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
