/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:00:49 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 11:17:17 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	lexical_analizer(t_rdl *rdl)
{
	keyword_list(rdl->keyword_list);
	operator_list(rdl->operator_list);
	quote_list(rdl->quote_list);
	redir_list(rdl->redir_list);
	command_list(rdl->command_list);
	delimiter_list(rdl->delimiter_list);
	identifier_list(rdl->identifier_list);
	token_type_list(rdl->token_type_list);
}
