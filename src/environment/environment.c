/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:57:01 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/14 17:28:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_init(char **env)
{
	int	i;
	int	count;

	i = -1;
	count = env_len(env);
	g_env.env = (char **)malloc(sizeof(char *) * (count) + 1);
	if (g_env.env == NULL)
		return (307);
	while (env[++i])
		g_env.env[i] = ft_strdup(env[i]);
	return (0);
}
