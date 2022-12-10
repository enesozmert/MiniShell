/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:32:07 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/10 17:17:41 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void redir_handler(t_rdl *rdl)
{
    int i;
    int len;
    int count;
    // int nproc;
    
    i = -1;
    count = rdl->redir_prop->count;
    // nproc = count + 1;
    len = token_size(rdl->token);
    if (count < 1)
        return;
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
            return ;
        }
        if (syntax(rdl) != -1)
            command(rdl);
        else
            break;
    }
    // while (nproc-- > 0)
    //     waitpid(-1, 0, 0);
}