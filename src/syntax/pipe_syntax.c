/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:58:01 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 14:55:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	pipe_syntax(t_rdl *rdl)
{
	if (rdl->token->id == 0)
		return (0);
	if (rdl->token->len == 1)
	{
		if (rdl->token->context[0] == '|')
			rdl->pipe_prop->syntax_count++;
	}
	if (rdl->pipe_prop->count > 2)
		return (105);
	if (rdl->token->next->context[0] != '|')
		rdl->pipe_prop->syntax_count = 0;
	return (0);
}
