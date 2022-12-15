/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:12 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 21:12:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	env_update(char *key, char *value)
{
	int		key_id;
	char	**key_find;
	char	*result;
	char	*join_result;

	key_id = env_find_id(key);
	key_find = ft_split(g_env.env[key_id], '=');
	join_result = ft_strjoin(key_find[0], "=");
	result = ft_strjoin(join_result, value);
	g_env.env[key_id] = ft_strdup(result);
	ft_free_dbl_str(key_find);
	free(join_result);
	free(result);
	return (0);
}
