/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:32:07 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/10 12:39:16 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void redir_handler(t_rdl *rdl)
{
    int i;
    int len;
    int count;
    int nproc;
    
    i = -1;
    count = rdl->redir_prop->count;
    nproc = count + 1;
    len = token_size(rdl->token);
    if (count < 1)
        return;
    while (++i < count + 2)
    {
		if (i == count + 1)
        {
			rdl->redir_prop->count = -1;
            return ;
        }
        if (syntax(rdl) != -1)
            command(rdl);
    }
    // while (nproc-- > 0)
    //     waitpid(-1, 0, 0);
}