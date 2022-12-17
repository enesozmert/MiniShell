/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_find_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:12 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 17:41:21 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static char **command_get_path(void)
{
	char *path;
	char **paths;

	path = env_find_value("PATH");
	paths = NULL;
	if (path != NULL)
		paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static int	stat_check(char	*new_path, char	**paths)
{
	struct stat s;

	if (stat(new_path, &s) == 0)
	{
		ft_free_dbl_str(paths);
		return (1);
	}
	else
		free(new_path);
	return (0);
}

char *command_find_path(char *keyword)
{
	int		i;
	char	*tmp;
	char	**paths;
	char	*new_path;


	i = -1;
	new_path = NULL;
	paths = command_get_path();
	if (access(keyword, 0) == 0 && ft_strchr(keyword, '/'))
	{
		ft_free_dbl_str(paths);
		return (ft_strdup(keyword));
	}
	while (paths[++i])
	{
		tmp = ft_strjoin("/", keyword);
		new_path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (stat_check(new_path, paths))
			return (new_path);
	}
	ft_free_dbl_str(paths);
	return (NULL);
}
