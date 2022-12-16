/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:40:42 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 16:29:06 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_add(char *key, char *value)
{
	int		i;
	int		count;
	char	*tmp;
	char	**new_env;

	i = -1;
	count = env_len(g_env.env);
	if (env_exist(key) == 0)
	{
		new_env = (char **)malloc(sizeof(char *) * (count + 1) + 1);
		while (g_env.env[++i])
			new_env[i] = ft_strdup(g_env.env[i]);
		ft_free_dbl_str(g_env.env);
		tmp = ft_strjoin(key, "=");
		new_env[i] = ft_strjoin(tmp, value);
		new_env[i + 1] = NULL;
		i = -1;
		g_env.env = (char **)malloc(sizeof(char *) * (count + 1) + 1);
		while (new_env[++i])
			g_env.env[i] = ft_strdup(new_env[i]);
		g_env.env[i] = NULL;
		ft_free_dbl_str(new_env);
		free(tmp);
	}
	else
		env_update(key, value);
	return (0);
}
