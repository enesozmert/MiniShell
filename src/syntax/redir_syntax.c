/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:07:31 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/05 12:36:01 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int redir_syntax_first_single_next(t_rdl *rdl)
{
	if (rdl->token->next->t_flag == 5 
		&& (rdl->token->context[0] != rdl->token->next->context[0]))
			return (103);
	else 
		return (0);
}

static int redir_syntax_first_plural_next(t_rdl *rdl)
{
	if (rdl->token->next->t_flag == 5 
		&& (rdl->token->context[1] != rdl->token->next->context[0]))
			return (103);
	else 
		return (0);
}

int	redir_syntax(t_rdl *rdl)
{
	if (rdl->token->type_id == 0)
		return (0);
	if (rdl->token->t_flag == 5)
	{
		if (ft_strlen(rdl->token->context) == 1)
			return (redir_syntax_first_single_next(rdl));
		if (ft_strlen(rdl->token->context) > 2)
			return (103);
		else if (ft_strlen(rdl->token->context) == 2)
			return (redir_syntax_first_plural_next(rdl));
	}
	return (0);
}
