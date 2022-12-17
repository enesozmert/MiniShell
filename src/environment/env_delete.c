/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:53:08 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 17:15:57 by eozmert          ###   ########.fr       */
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
	new_env = NULL;
	count = env_len(g_env.env);
	del_env_id = env_find_id(key);
	if (env_exist(key) == 1)
	{
		new_env = (char **)malloc(sizeof(char *) * (count));
		while (g_env.env[++i])
		{
			if (del_env_id != i)
				new_env[j++] = ft_strdup(g_env.env[i]);
		}
		new_env[j] = NULL;
		ft_free_dbl_str(g_env.env);
		env_all_update(new_env, count);
	}
	return (0);
}
