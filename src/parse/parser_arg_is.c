/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg_is.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:47:04 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:47:46 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	add_buf(t_rdl *rdl, char *buffer, int *j)
{
	if (buffer != NULL && ft_strlen(buffer) > 0)
		parser_add_buffer(rdl, buffer, j);
}

static void	add_arg(t_rdl *rdl, int i, int *j, char *buffer)
{
	int	k;

	k = *j;
	if (is_dollar(rdl->buffer[i]))
	{
		add_buf(rdl, buffer, &k);
		parser_add_dollar(rdl, rdl->buffer[i]);
	}
	else if (is_delimiter(rdl->delimiter_list, rdl->buffer[i]))
	{
		add_buf(rdl, buffer, &k);
		parser_add_char(rdl, rdl->buffer[i]);
	}
	else if (is_operator(rdl->operator_list, rdl->buffer[i]))
	{
		add_buf(rdl, buffer, &k);
		parser_add_operator(rdl, rdl->buffer[i]);
	}
	else if (rdl->buffer[i] > 32)
		buffer[++k] = rdl->buffer[i];
	*j = k;
}

void	parser_arg_is(t_rdl *rdl)
{
	int		i;
	int		j;
	char	*buffer;

	i = -1;
	j = -1;
	buffer = ft_calloc(sizeof(char), ft_strlen(rdl->buffer));
	while (rdl->buffer[++i])
		add_arg(rdl, i, &j, buffer);
	if (buffer != NULL && ft_strlen(buffer) > 0)
		parser_add_buffer(rdl, buffer, &j);
	free (buffer);
}
