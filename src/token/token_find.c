/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:57:42 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/03 14:07:49 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int token_find_count(t_token *token, char *context)
{
    int i;
    int count;

    count = 0;
    i = -1;
    while (++i < token_size(token))
    {
        if (strncmp(token->context, context, token->len) == 0)
            count++;
        get_next_token(&token);
    }
    return (count);
}