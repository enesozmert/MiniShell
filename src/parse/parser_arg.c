#include "../../include/header.h"

void parser_arg_isoperator(char c, int *j, t_rdl *rdl)
{
	int i;

	i = *j;
	if ((ft_isascii(c) && is_operator(rdl, c) == 0) || c == ' ')
		rdl->buffer[i++] = c;
	else if ((c != ' ' || c != '\t') && (i != 0))
	{
		rdl->buffer[i] = '\0';
		i = 0;
		parser_add(rdl, rdl->buffer);
	}
	*j = i;
}

void parser_arg_isnotoperator(char c, int *j, t_rdl *rdl)
{
	int flag;
	int i;

	i = *j;
	flag = 0;
	if (ft_isascii(c) || c != ' ')
	{
		rdl->buffer[i++] = c;
		flag = 1;
	}
	else if ((c == ' ' || c == '\t') && (i != 0))
	{
		rdl->buffer[i] = '\0';
		i = 0;
		parser_add(rdl, rdl->buffer);
	}
	if (c == '\0')
	{
		rdl->buffer[i] = '\0';
		i = 0;
		parser_add(rdl, rdl->buffer);
	}
	*j = i;
}

void parser_arg(t_rdl *rdl)
{

	int i;
	int j;
	int c;

	i = -1;
	j = 0;
	while (++i < rdl->len + 1)
	{
		c = rdl->main_str[i];
		if ((c == '\"' || c == '\'') && c != ' ')
			parser_arg_isoperator(c, &j, rdl);
		if (is_operator(rdl, c) == 0)
			parser_arg_isnotoperator(c, &j, rdl);
		if (is_operator(rdl, c))
			parser_add_operator(rdl, c);
	}
}