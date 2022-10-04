/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:43:15 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/04 10:21:22 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void find_pipe_count(t_rdl *rdl)
{
    int i;
    t_rdl *tmp;

    tmp = rdl;
	i = -1;
	while (++i < token_size(tmp->token))
	{
		if (tmp->token->context[0] == '|' && tmp->token->t_flag == 1)
            rdl->pipe_count++;
		get_next_token(&tmp->token);
	}
}