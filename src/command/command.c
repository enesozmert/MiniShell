/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:53:10 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 11:53:28 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	command_sub_type(t_rdl *rdl)
{
	int	is_token_type;
	int	command_id;

	command_id = command_find(rdl, rdl->token->keyword_id);
	is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
	if (is_token_type == 1)
	{
		if (rdl->token->type_id == 5)
			rdl->command_list[command_id].token_sub_type_id
				= find_redir_id(rdl->redir_list, rdl->token->context);
	}
	return (0);
}

static int	redir_pipe_prop_index(t_rdl *rdl)
{
	int	i;

	i = -1;
	if (rdl->redir_prop->count > 0)
		i = rdl->redir_prop->index;
	if (rdl->pipe_prop->count > 0)
		i = rdl->pipe_prop->index;
	return (i);
}

int	command(t_rdl *rdl)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	i = redir_pipe_prop_index(rdl);
	command_malloc(rdl);
	while (++i < token_size(rdl->token) + rdl->redir_prop->count
		+ rdl->pipe_prop->count)
	{
		result = command_create(rdl);
		command_sub_type(rdl);
		if (result == -1)
		{
			get_next_token(&rdl->token);
			++i;
			rdl->pipe_prop->index = i;
			rdl->redir_prop->index = i;
			break ;
		}
		get_next_token(&rdl->token);
	}
	command_run(rdl->command_list);
	return (0);
}
