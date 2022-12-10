/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:32:07 by eozmert           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/10 17:16:17 by eozmert          ###   ########.fr       */
=======
/*   Updated: 2022/12/10 13:51:43 by cyalniz          ###   ########.fr       */
>>>>>>> 5211a8a2bed042d6d2ff3a2a9904d9b50c79f327
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