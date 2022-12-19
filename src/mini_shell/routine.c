/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 16:45:21 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	routine_crud(t_rdl *rdl)
{
	lexical_analizer(rdl);
	parser(rdl);
	token_pre(rdl);
	redir_count(rdl);
	pipe_count(rdl);
	redir_handler(rdl);
	pipe_handler(rdl);
	if (rdl->pipe_prop->count == 0 && rdl->redir_prop->count <= 0)
	{
		if (syntax(rdl) != -1)
			command(rdl);
	}
	my_add_history(rdl->main_str);
	token_clear(&rdl->token);
}

void	routine(void)
{
	t_rdl	*rdl;

	rdl = NULL;
	while (1)
	{
		signal(SIGINT, set_signal);
		rdl = rdl_init(rdl);
		if (!check_white_space(rdl->main_str))
		{
			routine_crud(rdl);
		}
		rdl_clear(rdl);
	}
}
