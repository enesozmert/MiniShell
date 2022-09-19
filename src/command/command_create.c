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
    
}

int command_create(t_rdl *rdl)
{
    if (ft_strncmp(rdl->token->type, "keyword", ft_strlen("keyword")))
    {
        rdl->command_list->type = "keyword";
        rdl->command_list->arg = rdl->token->context;
/*         rdl->command_list->option = 
        rdl->command_list->f =  */
    }
    else if (ft_strncmp(rdl->token->type, "arg", ft_strlen("arg")))
    {
        rdl->command_list->type = "arg";
        rdl->command_list->arg = rdl->token->context;
/*         rdl->command_list->option = 
        rdl->command_list->f =  */
    }
    //optionsı alamadığımız için burada ekletemiyoruz :(


        
}