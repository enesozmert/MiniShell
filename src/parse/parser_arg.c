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
	int flag;

	i = -1;
	j = 0;
	k = 0;
	flag = 0;
	while (++i < rdl->len + 1)
	{
		c = rdl->main_str[i];
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
		if (rdl->main_str[i] != '>' && rdl->main_str[i + 1] == '>')
		{
			flag = 0;
			k++;
		}
		if (rdl->main_str[i] == '<' && rdl->main_str[i + 1] != '<')
		{
			flag = 0;
			k++;
		}
		// printf("k = %d\n", k);
	}
}

void parser_arg_split(t_rdl *rdl)
{
	int i;
	char **redir_l;
	char **redir_r;
	int redir_l_c;
	int redir_r_c;

	redir_l = NULL;
	redir_r = NULL;
	redir_l_c = 0;
	redir_r_c = 0;
	if (ft_strchr(rdl->main_str, '<') != NULL && ft_strchr(rdl->main_str, '>') != NULL)
	{
		exit(-1);
	}
	else if (ft_strchr(rdl->main_str, '>') != NULL)
	{
		i = -1;
		redir_r = ft_split(rdl->main_str, '>');
		redir_r_c = count_matris((void **)redir_r);
		// printf("redir_r_c %d\n", redir_r_c);
		rdl->quote_count = malloc(sizeof(t_quote_count) * redir_r_c);
		while (++i < redir_r_c)
		{
			rdl->quote_count[i].left = quote_count_left(redir_r[i]);
			rdl->quote_count[i].right = quote_count_right(redir_r[i]);
		}
	}
	else if (ft_strchr(rdl->main_str, '<') != NULL)
	{
		i = -1;
		redir_l = ft_split(rdl->main_str, '<');
		redir_l_c = count_matris((void **)redir_l);
		// printf("redir_l_c %d\n", redir_l_c);
		rdl->quote_count = malloc(sizeof(t_quote_count) * redir_l_c);
		while (++i < redir_l_c)
		{
			rdl->quote_count[i].left = quote_count_left(redir_l[i]);
			rdl->quote_count[i].right = quote_count_right(redir_l[i]);
		}
	}
	parser_arg(rdl);
}