/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:10:05 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 11:10:08 by eozmert          ###   ########.fr       */
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

int env_start(t_command *command)
{
    (void)command;
    env_print(g_env.env);
    return (0);
}
