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
    command_malloc(rdl);
	while (++i < token_size(rdl->token))
	{
        command_create(rdl);
		get_next_token(&rdl->token);
	}
    command_run(rdl);
    i = -1;
    while (++i < 8)
    {
        printf("type : %s |", rdl->command_list[i].type);
        printf("arg : %s |", rdl->command_list[i].arg[0]);
        printf("option : %s |", rdl->command_list[i].option);
        printf("count : %d |", rdl->command_list[i].count);
        printf("\n");
    }
    return (0);
}

int command_malloc(t_rdl *rdl)
{
    int command_id;
    int arg_count;

    command_id = 0;
    arg_count = token_arg_count(rdl->token);
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        rdl->command_list[command_id].arg = (char **)ft_calloc(arg_count, sizeof(char *));
        rdl->command_list[command_id].count++;
    }
    return (0);
}

int command_create(t_rdl *rdl)
{
    int command_id;
    int arg_id;
    int arg_count;
    //şimdi header.h da command kısmında arg double poniter tutmalıyız
    //evet
    //şimdi çoklu mesaj yazdırmak vs lazım
    //double pointer olunca *arg string oluyor ya
    //command_id = 0;
    arg_id = 0;
    command_id = command_find(rdl, rdl->token->context);
    arg_count = token_arg_count(rdl->token);
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")) == 0)
    {
        command_id = command_find(rdl, rdl->token->context);
        printf("arg_count %d\n", arg_count);
        rdl->command_list[command_id].count++;
    }
    else if (ft_strncmp(rdl->token->type, "arg", ft_strlen("arg")) == 0)
    {
        if(!rdl->command_list[command_id].arg[arg_id])
            rdl->command_list[command_id].arg[arg_id] = ft_strdup(rdl->token->context);
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