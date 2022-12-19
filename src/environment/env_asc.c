/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_asc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:51:58 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:43:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_asc(char **env)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	while (env[i + 1])
	{
		if (ft_tolower(env[i][j]) > ft_tolower(env[i + 1][j]))
		{
			temp = env[i];
			env[i] = env[i + 1];
			env[i + 1] = temp;
			i = 0;
		}
		else if (ft_tolower(env[i][j]) == ft_tolower(env[i + 1][j]))
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	env_all_update(env, env_len(env));
	return (0);
}
