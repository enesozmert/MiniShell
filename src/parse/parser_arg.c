#include "../../include/header.h"

void parser_arg_keyword(int *k, t_rdl *rdl)
{
	int i;
	int j;
	char c;

	i = *k;
	j = 0;
	c = 0;
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
	while (rdl->main_str[i] > 32 && rdl->main_str[i])
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	if (rdl->main_str[i] <= 32)
		while (rdl->main_str[i++] <= 32 && rdl->main_str[i]);
	if (ft_strlen(rdl->buffer) > 0)
		rdl->buffer[j] = '\0';
	*k = i;
}

void parser_arg_pipe(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_pipe(rdl, rdl->main_str[i]);
	i++;
	if (rdl->main_str[i] <= 32 && rdl->main_str[i])
	{
		while (rdl->main_str[i] <= 32 && rdl->main_str[i])
			i++;
	}
	i -= 1;
    *k = i;
}

void parser_arg_quote(int *k, t_rdl *rdl)
{
	int i;

	i = *k;
	parser_add_quote(rdl, rdl->main_str[i]);
	parser_arg_is_quote(rdl->main_str[i], &i, rdl);
	if (is_quote(rdl->quote_list, rdl->main_str[i]))
		parser_add_quote(rdl, rdl->main_str[i]);
	*k = i;
}

void parser_arg_redir(int *k, t_rdl *rdl)
{
	int		i;
	int		j;
	char	c;

	i = *k;
	j = 0;
	c = rdl->main_str[i];
	while (rdl->main_str[i] == c)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	rdl->buffer[j] = '\0';
	parser_add_redir(rdl, rdl->buffer);
	if (rdl->main_str[i] <= 32 && rdl->main_str[i])
	{
		while (rdl->main_str[i] <= 32 && rdl->main_str[i])
			i++;
	}
	i -= 1;
	*k = i;
}

void parser_arg_space(int *k, t_rdl *rdl)
{
	int i;
    
	i = *k; 
	while(rdl->main_str[i] <= 32 && rdl->main_str[i] != '\0')
		i++;
	if (rdl->main_str[i])
		parser_add(rdl, ft_strdup(" "));
	i--;
	*k = i;
}