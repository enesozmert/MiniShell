/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:40:42 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 22:50:51 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_add(char *key, char *value)
{
	int		i;
	int		count;
	char	**new_env;

	i = -1;
	count = env_len(g_env.env);
	if (env_exist(key) == 0)
	{
		new_env = (char **)malloc(sizeof(char *) * (count) + 2);
		while (g_env.env[++i])
			new_env[i] = g_env.env[i];
		new_env[i] = ft_strjoin(key, "=");
		new_env[i] = ft_strjoin(new_env[i], value);
		new_env[i + 1] = NULL;
		g_env.env = new_env;
	}
	else
		env_update(key, value);
	return (0);
}
