/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/26 18:20:00 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void routine()
{
	t_rdl *rdl;
	int	i;

	i = 0;
	rdl = NULL;
	while (1)
	{
		signal(SIGINT, set_signal);
		rdl = rdl_init(rdl);
		if (!check_white_space(rdl->main_str))
		{
			lexical_analizer(rdl);
			parser(rdl);
			pipe_count(rdl);
			if (rdl->pipe_prop->count == 0)
			{
				if(syntax(rdl) != -1)
					command(rdl);
			}
			else
				pipe_handler(rdl);
			my_add_history(rdl->main_str);
			keywords_clear(rdl->keyword_list);
			token_clear(&rdl->token);
			rdl_clear(rdl);
		}
	}
}
