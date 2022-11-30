/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/01 00:21:42 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int command(t_rdl *rdl)
{
    int i;
    int result;

    i = -1;
    result = 0;
    if (rdl->pipe_prop->count > 0)
        i = rdl->pipe_prop->index;
    command_malloc(rdl);
    while (++i < token_size(rdl->token))
    {
        result = command_create(rdl);
        if (result == -1)
        {
            get_next_token(&rdl->token);
            rdl->pipe_prop->index = i + 1;
            break;
        }
        get_next_token(&rdl->token);
    }
    command_run(rdl);
    token_clear(&rdl->command_list[8].tokens);
    return (0);
}

int command_malloc(t_rdl *rdl)
{
    int command_id;

    rdl->token->context = keyword_trim(rdl->token->context);
    command_id = command_find(rdl, rdl->token->id);
    if (rdl->token->type_id == 0)
    {
        command_id = command_find(rdl, rdl->token->id);
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
    int count;

    if (rdl->token->type_id == 6)
        return (-1);
    if (rdl->token->next->type_id == 0 && rdl->token->t_flag == -2)
        return (0);
    command_id = command_find(rdl, rdl->token->id);
    count = rdl->command_list[command_id].count;
    token = get_token_type_id(rdl->token, rdl->keywords_id[count - 1]);
    token->context = keyword_trim(token->context);
    if (rdl->token->type_id == 0)
        command_id = command_find(rdl, rdl->token->id);
    is_token_type = command_in_token_type(rdl, command_id, rdl->token->id);
    if (is_token_type == 1)
        rdl->command_list[command_id].tokens = token_add_copy(rdl->command_list[command_id].tokens, rdl->token);
    return (0);
}
