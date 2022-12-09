/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:58:27 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:16:40 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_redir(t_redir *redir_list, char *str)
{
	int	i;

	i = -1;
	while (redir_list[++i].sybl != NULL)
	{
		if (ft_strncmp(redir_list[i].sybl, str,
				ft_strlen(str)) == 0)
			return (1);
	}
	return (0);
}
