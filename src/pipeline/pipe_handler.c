/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:08:18 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:09:10 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	pipe_handler(t_rdl *rdl)
{
	int	i;
	int	count;
	int	nproc;

	i = -1;
	count = rdl->pipe_prop->count;
	nproc = count + 1;
	if (count < 1)
		return ;
	while (++i < count + 1)
	{
		if (syntax(rdl) != -1)
			command(rdl);
	}
	while (nproc-- > 0)
		waitpid(-1, 0, 0);
}
