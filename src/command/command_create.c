/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 20:06:54 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int command(t_rdl *rdl)
{
    int i;
    int len;
    int result;

    i = -1;
    result = 0;
    len = token_size(rdl->token);
    if (rdl->pipe_prop->count > 0)
        i = rdl->pipe_prop->index;
    command_malloc(rdl);
    while (++i < len && rdl->token)
    {
        result = command_create(rdl);
        if (result == -1)
        {
            rdl->token = rdl->token->next;
            i++;
            rdl->pipe_prop->index = i;
            break ;
        }
        else
            rdl->token = rdl->token->next;
    }
    command_run(rdl);
    token_clear(&rdl->command_list[8].tokens);
    return (0);
}

int command_malloc(t_rdl *rdl)
{
    int command_id;

    rdl->token->context = keyword_trim(rdl->token->context);
    command_id = command_find(rdl, rdl->token->context);
    if (rdl->token->type_id == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        if (rdl->command_list[command_id].count == 0)
            rdl->command_list[command_id].tmp_fd = dup(0);
        rdl->command_list[command_id].count++;
        printf("rdl->command_list[command_id].count %d\n", rdl->command_list[command_id].count);
        rdl->command_list[command_id].pipe_count = rdl->pipe_prop->count;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
    t_token *token;
    int is_token_type;
    int command_id;

    if (rdl->token->type_id == 6)
        return (-1);
    token = get_token_type_id(rdl->token, 0);
    token->context = keyword_trim(token->context);
    command_id = command_find(rdl, token->context);
    if (rdl->token->type_id == 0)
    {
        command_id = command_find(rdl, token->context);
    }
    is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
    if (is_token_type == 1)
        rdl->command_list[command_id].tokens = token_add_copy(rdl->command_list[command_id].tokens, rdl->token);
    return (0);
}
