#include "../../include/header.h"

void parser_arg_is(t_rdl *rdl)
{
	int i;
	int j;
	char *buffer;

	i = -1;
	j = -1;
	buffer = malloc(sizeof(char) * ft_strlen(rdl->buffer));
	while (rdl->buffer[++i])
	{
		if (is_dollar(rdl->buffer[i]))
		{
			if (buffer != NULL && ft_strlen(buffer) > 0)
				parser_add_buffer(rdl, buffer, &j);
			parser_add_dollar(rdl, rdl->buffer[i]);
		}
		else if (is_delimiter(rdl, rdl->buffer[i]))
		{
			if (buffer != NULL && ft_strlen(buffer) > 0)
				parser_add_buffer(rdl, buffer, &j);
			parser_add_char(rdl, rdl->buffer[i]);
		}
		else if (is_operator(rdl->operator_list, rdl->buffer[i]))
		{
			if (buffer != NULL && ft_strlen(buffer) > 0)
				parser_add_buffer(rdl, buffer, &j);
			parser_add_operator(rdl, rdl->buffer[i]);
		}
		else if (rdl->buffer[i] > 32)
			buffer[++j] = rdl->buffer[i];
	}
	if (buffer != NULL && ft_strlen(buffer) > 0)
		parser_add_buffer(rdl, buffer, &j + 1);
	if (!buffer)
		free (buffer);
}
