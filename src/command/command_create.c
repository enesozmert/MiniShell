/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/25 10:00:35 by cyalniz          ###   ########.fr       */
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
    int arg_count;

    command_id = command_find(rdl, rdl->token->context);
    arg_count = token_arg_count(rdl->token);
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        rdl->command_list[command_id].arg = (char **)malloc(arg_count * sizeof(char *) + 1);
        rdl->command_list[command_id].count++;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
    int command_id;
    int arg_id;
    t_token *token;

    arg_id = 0;
    token = get_token_id(rdl->token, 0);
    command_id = command_find(rdl, token->context);
    if (rdl->token->type && ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
        command_id = command_find(rdl, token->context);
    else if (rdl->token->type && ft_strncmp(rdl->token->type, "arg", ft_strlen("arg")) == 0)
    {
        arg_id = rdl->command_list[command_id].arg_count;
        rdl->command_list[command_id].arg[arg_id] = ft_strdup(rdl->token->context);
        rdl->command_list[command_id].arg_count++;
    }
    //optionsı alamadığımız için burada ekletemiyoruz :(
    return (0);
}