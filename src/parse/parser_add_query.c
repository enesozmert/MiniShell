/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_query.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:21:29 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:45:49 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	parser_add_dollar_q(t_rdl *rdl)
{
	if (is_dollar(rdl->main_str[rdl->i]))
	{
		parser_add_dollar(rdl, rdl->main_str[rdl->i]);
		return (1);
	}
	return (0);
}

int	parser_add_operator_q(t_rdl *rdl)
{
	if (is_operator(rdl->operator_list, rdl->main_str[rdl->i]))
	{
		parser_add_operator(rdl, rdl->main_str[rdl->i]);
		return (1);
	}
	return (0);
}

int	parser_add_option_q(t_rdl *rdl)
{
	if (is_option(rdl->main_str[rdl->i])
		&& rdl->main_str[rdl->i - 1] > 32 && rdl->main_str[rdl->i + 1] > 32)
	{
		parser_add_option(rdl, rdl->main_str[rdl->i]);
		return (1);
	}
	return (0);
}

int	parser_add_char_q(t_rdl *rdl)
{
	if (ft_isalnum(rdl->main_str[rdl->i]) == 0 && rdl->main_str[rdl->i] > 32)
	{
		parser_add_char(rdl, rdl->main_str[rdl->i]);
		return (1);
	}
	return (0);
}

int	parser_arg_space_q(t_rdl *rdl)
{
	if (rdl->main_str[rdl->i] <= 32)
	{
		if (is_next_redir(rdl->i, rdl->main_str) == 0
			&& is_next_pipe(rdl->i, rdl->main_str) == 0)
			parser_arg_space(&rdl->i, rdl);
		return (1);
	}
	return (0);
}
