/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_token_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:12:27 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 11:18:17 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int command_in_token_type(t_rdl *rdl, int command_id, int token_id)
{
	int i;
	t_token *token;
	char **tkn_types_id;

	i = -1;
	tkn_types_id = ft_split(rdl->command_list[command_id].token_types_id, ',');
	token = get_token_id(rdl->token, token_id);
	while (tkn_types_id[++i] != NULL)
	{
		if (token->type_id == ft_atoi(tkn_types_id[i]))
		{
			ft_free_dbl_str(tkn_types_id);
			return (1);
		}
	}
	ft_free_dbl_str(tkn_types_id);
	return (0);
}
