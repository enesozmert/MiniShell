/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:12 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 15:56:57 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_update(char *key, char *value)
{
	int		key_id;
	char	*key_find;
	char	*result;

	key_id = env_find_id(key);
	key_find = ft_split(g_env.env[key_id], '=')[0];
	result = ft_strjoin(key_find, "=");
	result = ft_strjoin(result, value);
	g_env.env[key_id] = ft_strdup(result);
	return (0);
}
