#include "../../include/header.h"

void parser_arg_isoperator(unsigned int c, int *j, t_rdl *rdl)
{
	int i;

	i = *j;
	if ((is_operator(rdl, c) == 0) || c == ' ')
		rdl->buffer[i++] = c;
	else if ((c != ' ' || c != '\t') && (i != 0))
		parser_add_buffer(&i, rdl);
	if (c == '\0')
		parser_add_buffer(&i, rdl);
	*j = i;
}

void parser_arg_isnotoperator(unsigned int c, int *j, t_rdl *rdl)
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
	int c;
	int flag;

	i = -1;
	j = 0;
	flag = 0;
	while (++i < rdl->len + 1)
	{
		c = rdl->main_str[i];
		if (c == '\"' || c == '\'')
			flag++;
		if (flag % 2 == 0)
			parser_arg_isnotoperator(c, &j, rdl);
		if (flag % 2 != 0)
			parser_arg_isoperator(c, &j, rdl);
		if (is_operator(rdl, c))
			parser_add_operator(rdl, c);
	}
}