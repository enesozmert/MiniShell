/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:40:18 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 17:16:09 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	parser(t_rdl *rdl)
{
	parser_create(rdl);
	token_add_type(rdl, &rdl->token);
	keywords_id(rdl);
	token_add_keyword_id(rdl, &rdl->token);
}

void	parser_create(t_rdl *rdl)
{
	parser_arg_iskeyword(&rdl->i, rdl);
	parser_handler(rdl);
}

//	print_token(rdl->token);