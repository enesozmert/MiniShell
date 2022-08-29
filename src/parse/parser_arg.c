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
		// printf("k = %d\n", k);
	}
}

void parser_arg_split(t_rdl *rdl)
{
	// int i;
	// char **redir_l;
	// char **redir_r;
	// int redir_l_c;
	// int redir_r_c;

	// redir_l = NULL;
	// redir_r = NULL;
	// redir_l_c = 0;
	// redir_r_c = 0;
	// if (ft_strchr(rdl->main_str, '<') != NULL && ft_strchr(rdl->main_str, '>') != NULL)
	// {
	// 	exit(-1);
	// }
	// else if (ft_strchr(rdl->main_str, '>') != NULL)
	// {
	// 	i = -1;
	// 	redir_r = ft_split(rdl->main_str, '>');
	// 	redir_r_c = count_matris((void **)redir_r);
	// 	// printf("redir_r_c %d\n", redir_r_c);
	// 	rdl->quote_count = malloc(sizeof(t_quote_count) * redir_r_c);
	// 	while (++i < redir_r_c)
	// 	{
	// 		rdl->quote_count[i].left = quote_count_left(redir_r[i]);
	// 		rdl->quote_count[i].right = quote_count_right(redir_r[i]);
	// 	}
	// }
	// else if (ft_strchr(rdl->main_str, '<') != NULL)
	// {
	// 	i = -1;
	// 	redir_l = ft_split(rdl->main_str, '<');
	// 	redir_l_c = count_matris((void **)redir_l);
	// 	// printf("redir_l_c %d\n", redir_l_c);
	// 	rdl->quote_count = malloc(sizeof(t_quote_count) * redir_l_c);
	// 	while (++i < redir_l_c)
	// 	{
	// 		rdl->quote_count[i].left = quote_count_left(redir_l[i]);
	// 		rdl->quote_count[i].right = quote_count_right(redir_l[i]);
	// 	}
	// }
	int i;
	int j;
	int len;
	int find;
	int next;
	int l_find;
	int r_find;
	int c;
	int c_n;

	i = 0;
	j = 0;
	c = 0;
	c_n = 0;
	r_find = 0;
	l_find = 0;
	find = 0;
	next = 0;
	len = 0;
	while (i < rdl->len)
	{
		c = rdl->main_str[i];
		c_n = rdl->main_str[i + 1];
		if ((c == '\"' && c_n != '\"') || (c == '\'' && c_n != '\''))
			len++;
		i++;
	}
	rdl->quote_count = malloc(sizeof(t_quote_count) * len / 2);
	i = 0;
	while (i < rdl->len)
	{
		c = rdl->main_str[i];
		c_n = rdl->main_str[i + 1];
		if ((c == '\"' && c_n != '\"') || (c == '\'' && c_n != '\''))
		{
			if (find == 0)
			{
				l_find = i;
			}
			else if (find == 1)
			{
				r_find = i;
				printf("ft_substr: %s\n", ft_substr(rdl->main_str, l_find, next + 2));
				printf("quote_count_left %d : \n", quote_count_left(ft_substr(rdl->main_str, l_find, r_find)));
				printf("quote_count_right %d : \n", quote_count_right(ft_substr(rdl->main_str, l_find, r_find)));
				rdl->quote_count[j].left = quote_count_left(ft_substr(rdl->main_str, l_find, r_find));
				rdl->quote_count[j].right = quote_count_right(ft_substr(rdl->main_str, l_find, r_find));
				find = 0;
				j++;
			}
			find++;
			next = 0;
		}
		else
			next++;
		i++;
	}
	i = 0;
	printf("len %d\n", len);
	while (i < len / 2)
	{
		printf("rdl->quote_count[%d].left\n", rdl->quote_count[i].left);
		printf("rdl->quote_count[%d].right\n", rdl->quote_count[i].right);
		i++;
	}

	parser_arg(rdl);
}