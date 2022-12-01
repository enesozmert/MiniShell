/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:58:44 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/01 10:05:03 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	quote_syntax(t_rdl *rdl)
{
	if (rdl->token->len == 1 && rdl->token->id != 0)
	{
		if (ft_strncmp(rdl->token->type, "single_quote",
				ft_strlen(rdl->token->type)) == 0)
			rdl->quote_prop->sq++;
		else if (ft_strncmp(rdl->token->type, "double_quote",
				ft_strlen(rdl->token->type)) == 0)
			rdl->quote_prop->dq++;
	}
	if ((rdl->quote_prop->sq % 2 != 0 || rdl->quote_prop->dq % 2 != 0)
		&& rdl->token->id == token_size(rdl->token) - 1)
		return (102);
	return (0);
}
