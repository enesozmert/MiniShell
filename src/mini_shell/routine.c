/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:50 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/06 14:17:10 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void routine()
{
	t_rdl *rdl;

	rdl = NULL;
	while (1)
	{
		rdl = rdl_init(rdl);
		if (!check_white_space(rdl->main_str))
		{
			lexical_analizer(rdl);
			if(syntax(rdl) == -1)
				//exit(0);//?
			find_pipe_count(rdl);//new
			command(rdl);
			my_add_history(rdl->main_str);
			keywords_clear(rdl->keyword_list);
			token_clear(&rdl->token);
			rdl_clear(rdl);
		}
	}
}
