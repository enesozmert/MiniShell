/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/09/26 11:27:31 by cyalniz          ###   ########.fr       */
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
    i = -1;
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
    int arg_id;
    int arg_count;
    //int op_id;

    //op_id = 0;
    command_id = 0;
    arg_id = 0;
    arg_count = token_arg_count(rdl->token);
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        rdl->command_list[command_id].arg = (char **)malloc(sizeof(char *) * arg_count);
        rdl->command_list[command_id].count++;
    }
    else if (ft_strncmp(rdl->token->type, "arg", ft_strlen("arg")) == 0)
    {
		// printf("arg id : %d\n", arg_id);
        // rdl->command_list[command_id].arg[arg_id][0] = 'a';
        rdl->command_list[command_id].arg[arg_id] = (char *)malloc(sizeof(char) * rdl->token->len);
        rdl->command_list[command_id].arg[arg_id] = rdl->token->context;
        // printf("%s\n",rdl->command_list[command_id].arg[0]);
        // printf("%s\n",rdl->command_list[command_id].arg[arg_id]);
        // printf("command_id %d\n", command_id);
        arg_id++;
    }
/*     else if(ft_strncmp(rdl->token->type, "operator", ft_strlen("operator")) == 0)
    {
        rdl->operator_list[op_id].sybl = rdl->token->context;
        op_id++;
    } */
    //optionsı alamadığımız için burada ekletemiyoruz :(

    return (0);
}