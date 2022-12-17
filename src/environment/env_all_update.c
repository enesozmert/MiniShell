/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_all_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:13:07 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/17 17:15:04 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void env_all_update(char **env, int count)
{
    int i;

    i = -1;		
    g_env.env = (char **)malloc(sizeof(char *) * (count));		
	i = -1;
    while (env[++i])
        g_env.env[i] = ft_strdup(env[i]);
    g_env.env[i] = NULL;
    ft_free_dbl_str(env);
}