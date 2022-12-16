/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdl_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:42:59 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/16 12:34:52 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void rdl_clear(t_rdl *rdl)
{
	free(rdl->parser_list);
	free(rdl->keyword_list);
	free(rdl->none);
	free(rdl->command_list[7].keyword);
	free(rdl->command_list[8].keyword);
	free(rdl->command_list[9].keyword);
	free(rdl->command_list);
	free(rdl->operator_list);
	free(rdl->delimiter_list);
	free(rdl->identifier_list);
	free(rdl->token_type_list);
	free(rdl->quote_list);
	free(rdl->main_str);
	free(rdl->buffer);
	free(rdl->quote_prop);
	free(rdl->token_type_prop);
}