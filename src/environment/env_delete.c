/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:53:08 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 15:54:23 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_delete(char *key)
{
	int		i;
	int		j;
	int		del_env_id;
	int		count;
	char	**new_env;

	i = -1;
	j = 0;
	count = env_len(g_env.env);
	del_env_id = env_find_id(key);
	if (env_exist(key) == 1)
	{
		new_env = (char **)malloc(sizeof(char *) * (count));
		while (g_env.env[++i])
		{
			if (del_env_id != i)
				new_env[j++] = g_env.env[i];
		}
		new_env[i + 1] = NULL;
		g_env.env = new_env;
	}
	return (0);
}
