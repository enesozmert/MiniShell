#include "../../include/header.h"

void parser_arg_isoperator(int c, int *k, t_rdl *rdl)
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
		rdl->flag = 1;
	}
	if (rdl->flag == 1)
		rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) != 0)
		parser_add(rdl, rdl->buffer);
	else
		ft_bzero(rdl->buffer, ft_strlen(rdl->buffer));
	if (rdl->main_str[i] == (char)c)
	{
		parser_add_operator(rdl, rdl->main_str[i]);
		i++;
		rdl->flag = 1;
	}
	*k = i;
}

void parser_arg_isnotoperator(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (is_operator(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] != '\0' && is_keyword(rdl, rdl->buffer) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
		rdl->flag = 1;
	}
	rdl->buffer[j] = '\0';
	parser_add(rdl, rdl->buffer);
	*k = i;
}

void parser_add_quote(int c, int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_operator(rdl, rdl->main_str[i]);
	parser_arg_isoperator((char)c, &i, rdl);
	*k = i;
}

void parser_arg(t_rdl *rdl)
{
	int i;

	i = 0;
	while (i < rdl->len + 1)
	{
		rdl->flag = 0;
		if (rdl->main_str[i] == '\'')
			parser_add_quote('\'', &i, rdl);
		else if (rdl->main_str[i] == '\"')
			parser_add_quote('\"', &i, rdl);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && rdl->main_str[i] != '\0')
			parser_arg_isnotoperator(&i, rdl);
		if (rdl->flag == 0)
			i++;
	}
}