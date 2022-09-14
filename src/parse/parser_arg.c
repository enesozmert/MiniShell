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
	char *s;
	char **str;
	int flag = 0;

	i = 1;
	j = 0;
	s = ft_strdup(rdl->main_str);
	str = ft_split(s, ' ');
	i = ft_strlen(str[0]);
	parser_add(rdl, str[0]);
	while (i < rdl->len + 1)
	{
		j = 0;
		flag = 0;
		if (s[i] == '\'')
		{
			parser_add_operator(rdl, s[i]);
			i++;
			while (s[i] != '\'' && s[i] != '\0')
			{
				rdl->buffer[j++] = s[i];
				i++;
				flag = 1;
			}
			if(flag == 1)
				rdl->buffer[j] = '\0';
			if (ft_strlen(rdl->buffer) != 0)
			{
				parser_add(rdl, rdl->buffer);
			}
			else
				ft_bzero(rdl->buffer, ft_strlen(rdl->buffer));
			if (s[i] == '\'')
			{
				parser_add_operator(rdl, s[i]);
				i++;
				flag = 1;
			}	
		}
		else if (s[i] == '\"')
		{
			parser_add_operator(rdl, s[i]);
			i++;
			while (s[i] != '\"' && s[i] != '\0')
			{
				rdl->buffer[j++] = s[i];
				i++;
				flag = 1;
			}
			if(flag == 1)
				rdl->buffer[j] = '\0';
			if (ft_strlen(rdl->buffer) != 0)
			{
				parser_add(rdl, rdl->buffer);
			}
			else
				ft_bzero(rdl->buffer, ft_strlen(rdl->buffer));
			if (s[i] == '\"')
			{
				parser_add_operator(rdl, s[i]);
				i++;
				flag = 1;
			}
		}
		else if (is_operator(rdl, s[i]))
		{
			parser_add_operator(rdl, s[i]);
		}
		else if (is_operator(rdl, s[i]) == 0 && s[i] > 32 && s[i] != '\0')
		{
			while (is_operator(rdl, s[i]) == 0 && s[i] != '\0')
			{
				rdl->buffer[j++] = s[i];
				i++;
				flag = 1;
			}
			rdl->buffer[j] = '\0';
			parser_add(rdl, rdl->buffer);
		}
		if (flag == 0)
			i++;
	}
}