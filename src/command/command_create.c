/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/13 17:06:57 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/header.h"

int command(t_rdl *rdl)
{
    int i;

	i = -1;
    command_malloc(rdl);
	while (++i < token_size(rdl->token))
	{
        command_create(rdl);
		get_next_token(&rdl->token);
	}
    command_run(rdl);
    return (0);
}

int command_malloc(t_rdl *rdl)
{
    int command_id;

    command_id = command_find(rdl, rdl->token->context);
    if (rdl->token->type_id == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        rdl->command_list[command_id].count++;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
	(void)rdl;
    // int is_token_type;
    // int command_id;
    // t_token *token;
    
    // token = get_token_id(rdl->token, 0);
    // command_id = command_find(rdl, token->context);
    // if (rdl->token->type && ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    //     command_id = command_find(rdl, token->context);
    // is_token_type = command_in_keyword(rdl, command_id, rdl->token->id);
    return (0);
}