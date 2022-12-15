/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_find_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:12 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 16:13:43 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char *command_find_path(char *keyword)
{
	int i;
	char *path;
	char	*tmp;
	char **paths;
	char *new_path;
	struct stat s;

	i = -1;
	path = env_find_value("PATH");
	paths = NULL;
	new_path = NULL;
	if (access(keyword, 0) == 0 && ft_strchr(keyword, '/'))
		return (ft_strdup(keyword));
	if (path != NULL)
		paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	while (paths[++i])
	{
		tmp = ft_strjoin("/", keyword);
		new_path = ft_strjoin(paths[i], tmp);
		free(tmp);
		if (stat(new_path, &s) == 0)
		{
			ft_free_dbl_str(paths);
			return (new_path);
		}
		else
			free(new_path);
	}
	ft_free_dbl_str(paths);
	return (NULL);
}
