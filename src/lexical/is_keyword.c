/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_keyword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:18:58 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:28:31 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int is_keyword_builtin(t_keyword *keyword_list, char *str)
{
	int i;

	i = -1;
	while (keyword_list[++i].type != NULL)
	{
		if (ft_strncmp(keyword_list[i].type, str,
			ft_strlen(keyword_list[i].type)) == 0 &&
			ft_strlen(keyword_list[i].type) == ft_strlen(str))
		{
			return (1);
		}
	}
	return (0);
}

int is_keyword_exec(t_keyword *keyword_list, char *str)
{
	char *find_path;

	find_path = command_find_path(str);
	if (find_path != NULL && is_keyword_builtin(keyword_list, str) == 0)
	{
		free(find_path);
		return (1);
	}
	return (0);
}

int is_keyword(t_keyword *keyword_list, char *str)
{
	char *keyword;

	keyword = keyword_trim(str);
	if (is_keyword_builtin(keyword_list, keyword) == 1 || is_keyword_exec(keyword_list, keyword) == 1)
		return (1);
	return (0);
}
