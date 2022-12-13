// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   command_create.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
// /*   Updated: 2022/12/12 23:38:48 by eozmert          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/header.h"

// static int	command_sub_type(t_rdl *rdl)
// {
// 	t_token	*token;
// 	int		is_token_type;
// 	int		command_id;

// 	command_id = command_find(rdl, rdl->token->keyword_id);
// 	token = get_token_id(rdl->token, rdl->token->keyword_id);
// 	token->context = keyword_trim(token->context);
// 	if (rdl->token->type_id == 0)
// 		command_id = command_find(rdl, rdl->token->id);
// 	is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
// 	if (is_token_type == 1)
// 	{
// 		if (rdl->token->type_id == 5)
// 			rdl->command_list[command_id].token_sub_type_id
// 				= find_redir_id(rdl->redir_list, rdl->token->context);
// 	}
// 	return (0);
// }

// static int	redir_pipe_prop_index(t_rdl *rdl)
// {
// 	int	i;

// 	i = -1;
// 	if (rdl->redir_prop->count > 0)
// 		i = rdl->redir_prop->index;
// 	if (rdl->pipe_prop->count > 0)
// 		i = rdl->pipe_prop->index;
// 	return (i);
// }

// int	command(t_rdl *rdl)
// {
// 	int	i;
// 	int	result;

// 	i = -1;
// 	result = 0;
// 	i = redir_pipe_prop_index(rdl);
// 	command_malloc(rdl);
// 	while (++i < token_size(rdl->token) + rdl->redir_prop->count
// 		+ rdl->pipe_prop->count)
// 	{
// 		result = command_create(rdl);
// 		command_sub_type(rdl);
// 		if (result == -1)
// 		{
// 			get_next_token(&rdl->token);
// 			++i;
// 			rdl->pipe_prop->index = i;
// 			rdl->redir_prop->index = i;
// 			break ;
// 		}
// 		get_next_token(&rdl->token);
// 	}
// 	command_run(rdl->command_list);
// 	return (0);
// }

// int	command_malloc(t_rdl *rdl)
// {
// 	int	command_id;

// 	command_id = command_find(rdl, rdl->token->keyword_id);
// 	if (rdl->command_list[command_id].count == 0)
// 		rdl->command_list[command_id].tmp_fd = dup(0);
// 	rdl->command_list[command_id].file_fd = rdl->command_list[9].file_fd;
// 	rdl->command_list[command_id].count++;
// 	rdl->command_list[command_id].pipe_count = rdl->pipe_prop->count;
// 	rdl->command_list[command_id].redir_count = rdl->redir_prop->count;
// 	rdl->command_list[command_id].token_type_pre_id = rdl->token_type_pre_id;
// 	return (0);
// }

// int	command_create(t_rdl *rdl)
// {
// 	t_token	*token;
// 	int		is_token_type;
// 	int		command_id;

// 	if (rdl->token->type_id == 6 || rdl->token->type_id == 5)
// 		return (-1);
// 	command_id = command_find(rdl, rdl->token->keyword_id);
// 	token = get_token_id(rdl->token, rdl->token->keyword_id);
// 	token->context = keyword_trim(token->context);
// 	if (rdl->token->type_id == 0)
// 		command_id = command_find(rdl, rdl->token->id);
// 	is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
// 	if (is_token_type == 1)
// 		rdl->command_list[command_id].tokens
// 			= token_add_copy(rdl->command_list[command_id].tokens, rdl->token);
// 	rdl->command_list[command_id].token_size
// 		= token_size(rdl->command_list[command_id].tokens);
// 	return (0);
// }
