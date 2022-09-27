/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:43:15 by cyalniz           #+#    #+#             */
/*   Updated: 2022/09/27 09:50:50 by cyalniz          ###   ########.fr       */
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
		if (tmp->token->context[0] == '|' && is_keyword(tmp, tmp->token->next->type))
            rdl->pipe_count++;
		get_next_token(&tmp->token);
	}
}