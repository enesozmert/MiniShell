#include "../../include/header.h"

static void parser_arg_is_add_buffer(t_rdl *rdl)
{
	int i;
	int j;
	char *buffer;

	i = -1;
	j = -1;
	buffer = malloc(sizeof(char) * ft_strlen(rdl->buffer));
	while (rdl->buffer[++i])
	{
		printf("buffer: %s\n", buffer);
		if (is_dollar(rdl->buffer[i]))
		{
			if (buffer != NULL && ft_strlen(buffer) > 0){
				parser_add(rdl, buffer);
				j = -1;
			}
			parser_add_dollar(rdl, rdl->buffer[i]);
		}
		else if (ft_isalnum(rdl->buffer[i]) == 0)
		{
			if (buffer != NULL && ft_strlen(buffer) > 0){
				parser_add(rdl, buffer);
				j = -1;
			}
			parser_add_notoperator(rdl, rdl->buffer[i]);
		}
		else if (is_operator(rdl, rdl->buffer[i]))
		{
			if (buffer != NULL && ft_strlen(buffer) > 0){
				parser_add(rdl, buffer);
				j = -1;
			}
			parser_add_operator(rdl, rdl->buffer[i]);
		}
		else if (rdl->buffer[i] > 32)
			buffer[++j] = rdl->buffer[i];
	}
	if (buffer != NULL && ft_strlen(buffer) > 0){
		parser_add(rdl, buffer);
	}
}

void parser_arg_is_single_quote(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	i++;
	while (rdl->main_str[i] != '\'')
		rdl->buffer[j++] = rdl->main_str[i++];
	rdl->buffer[j] = '\0';
	parser_arg_is_add_buffer(rdl);
	*k = i;
}

void parser_arg_is_double_quote(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	i++;
	while (rdl->main_str[i] != '\"')
		rdl->buffer[j++] = rdl->main_str[i++];
	rdl->buffer[j] = '\0';
	parser_arg_is_add_buffer(rdl);
	*k = i;
}

void parser_arg_isnot(int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	while (rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]) && is_dollar(rdl->main_str[i]) == 0 && is_operator(rdl, rdl->main_str[i]) == 0)
		rdl->buffer[j++] = rdl->main_str[i++];
	if (ft_strlen(rdl->buffer) > 0)
	{
		rdl->buffer[j] = '\0';
		parser_add(rdl, rdl->buffer);
	}
	i--;
	*k = i;
}