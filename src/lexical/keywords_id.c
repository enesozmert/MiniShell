/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keywords_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:53:46 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/17 18:21:31 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void keywords_id(t_rdl *rdl)
{
    int i;
    int j;
    int len;

    i = -1;
    j = -1;
    len = 0;
    while (++i < token_size(rdl->token))
    {
        if (rdl->token->type_id == 0)
            len++;
        get_next_token(&rdl->token);
    }
    rdl->keywords_id = malloc(sizeof(int) * len);
    i = -1;
    while (++i < token_size(rdl->token))
    {
        if (rdl->token->type_id == 0)
            rdl->keywords_id[++j] = rdl->token->id;
        get_next_token(&rdl->token);
    }
}