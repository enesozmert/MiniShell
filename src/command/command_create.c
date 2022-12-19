/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 11:48:33 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	command_malloc(t_rdl *rdl)
{
	int	command_id;

	command_id = command_find(rdl, rdl->token->keyword_id);
	if (rdl->command_list[command_id].count == 0)
		rdl->command_list[command_id].tmp_fd = dup(0);
	rdl->command_list[command_id].file_fd = rdl->command_list[9].file_fd;
	rdl->command_list[command_id].count++;
	rdl->command_list[command_id].pipe_count = rdl->pipe_prop->count;
	rdl->command_list[command_id].redir_count = rdl->redir_prop->count;
	rdl->command_list[command_id].token_type_pre_id = rdl->token_type_pre_id;
	return (0);
}

int	command_create(t_rdl *rdl)
{
	int		is_token_type;
	int		command_id;

	if (rdl->token->type_id == 6 || rdl->token->type_id == 5)
		return (-1);
	command_id = command_find(rdl, rdl->token->keyword_id);
	is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
	if (is_token_type == 1)
		rdl->command_list[command_id].tokens
			= token_add_copy(rdl->command_list[command_id].tokens, rdl->token);
	rdl->command_list[command_id].token_size
		= token_size(rdl->command_list[command_id].tokens);
	return (0);
}
