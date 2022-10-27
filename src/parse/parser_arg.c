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
	if (rdl->quote_prop->flag == 1)
		rdl->buffer[j] = '\0';
	if (ft_strlen(rdl->buffer) != 0)
	{
		rdl->t_flag = 0;
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
	if (rdl->quote_prop->flag == 1 && rdl->main_str[i] <= 32 && rdl->main_str[i] != '\0')
		parser_add(rdl, ft_strdup(" "));
	*k = i;
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (is_quote(rdl, rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] != '\0' && is_keyword_builtin(rdl, rdl->buffer) == 0)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
		rdl->quote_prop->flag = 1;
	}
	rdl->buffer[j] = '\0';
	rdl->t_flag = 0;
	parser_add(rdl, rdl->buffer);
	*k = i;
}

void parser_arg_quote(int c, int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_quote(rdl, rdl->main_str[i]);
	parser_arg_is((char)c, &i, rdl);
	*k = i;
}

void parser_arg_keyword(t_rdl *rdl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (rdl->main_str[i] <= 32 && rdl->main_str[i] != '\0')
		i++;
	while (rdl->main_str[i] != '\0' && rdl->main_str[i] > 32)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	rdl->buffer[j] = '\0';
	rdl->t_flag = 0;
	parser_add(rdl, rdl->buffer);
}

void parser_arg(t_rdl *rdl)
{
	int i;

	parser_arg_keyword(rdl);
	i = char_pos(rdl->main_str);
	while (i < rdl->len + 1)
	{
		rdl->quote_prop->flag = 0;
		if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(rdl->main_str[i], &i, rdl);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_quote(rdl, rdl->main_str[i]))
			parser_add_quote(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]) == 0 && rdl->main_str[i] > 32 && rdl->main_str[i] != '\0')
			parser_arg_isnot(&i, rdl);
		if (rdl->quote_prop->flag == 0)
			i++;
	}
}
