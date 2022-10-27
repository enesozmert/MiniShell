/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/25 17:14:08 by efyaz            ###   ########.fr       */
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
    int key_count;
    int value_count;

    command_id = command_find(rdl, rdl->token->context);
    key_count = token_key_count(rdl->token);
    value_count = token_value_count(rdl->token);
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        rdl->command_list[command_id].key = (char **)malloc(key_count * sizeof(char *) + 1);
        rdl->command_list[command_id].value = (char **)malloc(value_count * sizeof(char *) + 1);
        rdl->command_list[command_id].count++;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
    int command_id;
    int key_id;
    int value_id;
    t_token *token;

    key_id = 0;
    value_id = 0;
    token = get_token_id(rdl->token, 0);
    command_id = command_find(rdl, token->context);
    if (rdl->token->type && ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
        command_id = command_find(rdl, token->context);
    else if (rdl->token->type && ft_strncmp(rdl->token->type, "key", ft_strlen("key")) == 0)
    {
        key_id = rdl->command_list[command_id].key_count;
        rdl->command_list[command_id].key[key_id] = ft_strdup(rdl->token->context);
        rdl->command_list[command_id].key_count++;
    }
    else if (rdl->token->type && ft_strncmp(rdl->token->type, "value", ft_strlen("value")) == 0)
    {
        value_id = rdl->command_list[command_id].value_count;
        rdl->command_list[command_id].value[value_id] = ft_strdup(rdl->token->context);
        rdl->command_list[command_id].value_count++;
    }
    //optionsı alamadığımız için burada ekletemiyoruz :(
    return (0);
}