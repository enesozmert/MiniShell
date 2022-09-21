/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/09/19 17:02:36 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int command(t_rdl *rdl)
{
    int i;

	i = -1;
	while (++i < token_size(rdl->token))
	{
        command_create(rdl);
		get_next_token(&rdl->token);
	}
    command_run(rdl);
    // i = -1;
    // while (++i < 8)
    // {
    //     printf("type : %s |", rdl->command_list[i].type);
    //     printf("arg : %s |", rdl->command_list[i].arg);
    //     printf("option : %s |", rdl->command_list[i].option);
    //     printf("count : %d |", rdl->command_list[i].count);
    //     printf("\n");
    // }
    return (0);
}

int command_create(t_rdl *rdl)
{
    int command_id;

    command_id = 0;
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        // rdl->command_list->type = "keyword";
        // rdl->command_list->arg = rdl->token->context;
        rdl->command_list->count++;
    }
    else if (ft_strncmp(rdl->token->type, "arg", ft_strlen("arg")) == 0)
    {
        rdl->command_list[command_id].arg = rdl->token->context;
    }
    //optionsı alamadığımız için burada ekletemiyoruz :(
    return (0);       
}