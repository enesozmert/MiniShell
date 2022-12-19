/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:06:29 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:06:59 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	token_pre(t_rdl *rdl)
{
	t_token	*token_cpy;

	token_cpy = rdl->token;
	while (token_cpy)
	{
		if (token_cpy->type_id == 5 || token_cpy->type_id == 6)
		{
			rdl->token_type_pre_id = token_cpy->type_id;
			break ;
		}
		token_cpy = token_cpy->next;
	}
}
