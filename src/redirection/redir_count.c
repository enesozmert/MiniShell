/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:34:23 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 12:56:52 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	redir_count(t_rdl *rdl)
{
	int	i;
	int	len;

	i = -1;
	len = token_size(rdl->token);
	while (++i < len)
	{
		if (rdl->token->type_id == 5)
			rdl->redir_prop->count++;
		get_next_token(&rdl->token);
	}
	return (rdl->redir_prop->count);
}
