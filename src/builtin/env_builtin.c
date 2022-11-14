/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:05 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/14 23:30:05 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void env_print(char **env)
{
    int i;

    i = -1;
    while(env[++i])
        printf("%s\n", env[i]);
}

int env_start(t_command command)
{
    (void)command;
    env_print(g_env.env);
    return (0);
}
