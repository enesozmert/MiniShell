/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:54:54 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/18 00:02:25 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*env_find_value(char *key)
{
	int		i;
	int		key_len;
	int		env_id;

	i = -1;
	key_len = ft_strlen(key);
	env_id = env_find_id(key);
	if (env_id == -1)
		return (0);
	while (g_env.env[++i])
	{
		if (ft_strncmp(g_env.env[i], key, key_len) == 0
			&& g_env.env[i][key_len] == '=')
			return (g_env.env[env_id] + key_len + 1);
	}
	return (0);
}

int	env_find_id(char *key)
{
	int		i;
	int		key_len;

	i = -1;
	key_len = ft_strlen(key);
	while (g_env.env[++i])
	{
		if (ft_strncmp(g_env.env[i], key, ft_strlen(key)) == 0
			&& g_env.env[i][key_len] == '=')
			return (i);
	}
	return (-1);
}
