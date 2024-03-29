/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdl_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:42:59 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 16:41:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	rdl_clear(t_rdl *rdl)
{
	free(rdl->parser_list);
	free(rdl->keyword_list);
	free(rdl->none);
	if (!check_white_space(rdl->main_str))
	{
		free(rdl->command_list[7].keyword);
		free(rdl->command_list[8].keyword);
		free(rdl->command_list[9].keyword);
	}
	free(rdl->command_list);
	free(rdl->operator_list);
	free(rdl->delimiter_list);
	free(rdl->identifier_list);
	free(rdl->token_type_list);
	free(rdl->quote_list);
	free(rdl->main_str);
	free(rdl->buffer);
	free(rdl->quote_prop);
	free(rdl->ttp);
	free(rdl->redir_prop);
	free(rdl->pipe_prop);
	free(rdl->keywords_id);
	free(rdl->token);
	free(rdl->redir_list);
}
