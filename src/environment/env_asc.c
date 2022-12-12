/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_asc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:51:58 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 15:53:06 by cyalniz          ###   ########.fr       */
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
	temp = NULL;
	while (env[i + 1])
	{
		if (ft_tolower(env[i][j]) > ft_tolower(env[i + 1][j]))
		{
			temp = ft_strdup(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			env[i + 1] = ft_strdup(temp);
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
	g_env.env = env;
	return (0);
}
