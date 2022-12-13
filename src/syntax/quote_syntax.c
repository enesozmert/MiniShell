/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:58:44 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 12:23:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	quote_syntax(t_rdl *rdl)
{
	if (rdl->token->len == 1 && rdl->token->id != 0)
	{
		if (rdl->token->type_id == 1)
			rdl->quote_prop->sq++;
		else if (rdl->token->type_id == 2)
			rdl->quote_prop->dq++;
	}
	if ((rdl->quote_prop->sq % 2 != 0 || rdl->quote_prop->dq % 2 != 0)
		&& rdl->token->id == token_size(rdl->token) - 1)
		return (102);
	return (0);
}
