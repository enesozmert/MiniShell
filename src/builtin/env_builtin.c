/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:05 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/15 16:49:05 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void ft_env_print(char **env)
{
    int i;

    i = -1;
    while(env[++i])
        printf("%s\n", env[i]);
}

int env_start(__attribute__((unused))t_command command)
{
    // (void)command;
    // int arg_count;
    // arg_count = command.arg_count;

    // if(arg_count == 1)
        ft_env_print(g_env.env);
    // else if(arg_count == 3)//env 
    // {
        
    // }
    
    return (0);
}