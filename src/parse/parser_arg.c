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
	i = 0;
	j = 0;
	s = ft_strdup(rdl->main_str);
	str = ft_split(s, ' ');
	i = ft_strlen(str[0]);
	parser_add(rdl, str[0]);
	while (s[i])
	{
		j = 0;
		if (s[i] == '\'')
		{
			// i++;
			while (s[i] != '\'')
			{
				rdl->buffer[j++] = s[i];
				i++;
			}
			rdl->buffer[j] = '\0';
			parser_add(rdl, rdl->buffer);
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"')
			{
				rdl->buffer[j++] = s[i];
				i++;
			}
			rdl->buffer[j] = '\0';
			parser_add(rdl, rdl->buffer);
		}
		else if (is_operator(rdl, s[i]))
		{
			parser_add_operator(rdl, s[i]);
		}
		else if (is_operator(rdl, s[i]) == 0 && s[i] > 32)
		{
			while (is_operator(rdl, s[i]) == 0 && s[i] != '\0')
			{
				rdl->buffer[j++] = s[i];
				i++;
			}
			rdl->buffer[j] = '\0';
			parser_add(rdl, rdl->buffer);
		}
		i++;
	}
}