/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:05 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/11 21:20:11 by cyalniz          ###   ########.fr       */
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

int env_start(t_command command)
{
    int arg_count;
    arg_count = command.arg_count;

    if(arg_count == 1)
        ft_env_print(g_env.env);
    else if(arg_count == 3)//env 
    {
        
    }
    
    return (1);
}