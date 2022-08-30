#include "../../include/header.h"

void parser_arg_isoperator(int c, int *j, t_rdl *rdl)
{
	int i;

	i = *j;
	if ((is_operator(rdl, c) == 0) || c == ' ')
		rdl->buffer[i++] = c;
	else if ((c != ' ' || c != '\t') && (i != 0))
		parser_add_buffer(&i, rdl);
	// if (c == '\0')
	// 	parser_add_buffer(&i, rdl);
	*j = i;
}

void parser_arg_isnotoperator(int c, int *j, t_rdl *rdl)
{
	int i;

	i = *j;
	if (is_operator(rdl, c) == 0 && c != ' ')
		rdl->buffer[i++] = c;
	else if ((c != ' ' || c != '\t') && (i != 0))
		parser_add_buffer(&i, rdl);
	if (c == '\0')
		parser_add_buffer(&i, rdl);
	*j = i;
}

void parser_arg(t_rdl *rdl)
{

	int i;
	int j;
	int k;
	int c;
	int c_n;
	int flag;

	i = -1;
	j = 0;
	k = 0;
	flag = 0;
	while (++i < rdl->len + 1)
	{
		c = rdl->main_str[i];
		c_n = rdl->main_str[i + 1];
		if (c == '\"' || c == '\'')
			flag++;
		if (flag <= 0)
			parser_arg_isnotoperator(c, &j, rdl);
		else if (flag >= rdl->quote_count[k].left && flag < rdl->quote_count[k].right + rdl->quote_count[k].left)
			parser_arg_isoperator(c, &j, rdl);
		else if (flag >= rdl->quote_count[k].right + rdl->quote_count[k].left)
			parser_arg_isnotoperator(c, &j, rdl);
		if (is_operator(rdl, c))
			parser_add_operator(rdl, c);
	}
}

void parser_arg_split(t_rdl *rdl)
{
	int i;
	int findl;
	int findr;
	int find;
	int c_n;
	int c;
	char *str;

	i = 0;
	findl = 0;
	findr = 0;
	find = 0;
	str = ft_strdup(rdl->main_str);
	while (i < rdl->len)
	{
		c = rdl->main_str[i];
		if (c == '\'')
			str[i] = '\"';
		else
			str[i] = c;
		i++;
	}
	// printf("str : %s\n", str);
	i = 0;
	while (i < rdl->len)
	{
		c = str[i];
		c_n = str[i + 1];
		if (c == '\"' && c_n != '\"')
		{
			findl = i + 1;
		}
		else if (c != '\"' && c_n == '\"')
		{
			findr = i;
			if (find % 2 != 0)
				printf("substr : %s \n", ft_substr(str, findl, findr - findl + 1));
			find++;
		}
		i++;
	}

	// parser_arg(rdl);
}