/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:32:07 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 13:30:33 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	redir_handler(t_rdl *rdl)
{
	int	i;
	int	count;

	i = -1;
	count = rdl->redir_prop->count;
	if (count < 1)
		return ;
	if (rdl->pipe_prop->count > 0)
		count = rdl->pipe_prop->count + rdl->redir_prop->count + 2;
	else
		count += 2;
	while (++i < count)
	{
		if (i == count - 1)
		{
			rdl->pipe_prop->index = -1;
			rdl->redir_prop->index = -1;
			rdl->redir_prop->count = -1;
			token_clear(&rdl->command_list[9].tokens);
			return ;
		}
		if (syntax(rdl) != -1)
			command(rdl);
		else
			break ;
	}
}
