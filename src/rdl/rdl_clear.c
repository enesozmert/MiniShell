/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdl_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:42:59 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/14 12:43:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void rdl_clear(t_rdl *rdl)
{
	free(rdl->keyword_list);
	free(rdl->command_list);
	free(rdl->operator_list);
	free(rdl->delimiter_list);
	free(rdl->identifier_list);
	free(rdl->token_type_list);
	free(rdl->quote_list);
	free(rdl->main_str);
	free(rdl->buffer);
	free(rdl->token);
	free(rdl->quote_prop);
	free(rdl->token_type_prop);
}