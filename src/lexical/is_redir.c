/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:58:27 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 15:22:33 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_redir(t_rdl *rdl, char c)
{
	int	i;

	i = -1;
	while (rdl->redir_list[++i].sybl != NULL)
	{
		if (rdl->redir_list[i].sybl[0] == c)
			return (1);
	}
	return (0);
}
