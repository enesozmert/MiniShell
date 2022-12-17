/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_quote_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:03:57 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 20:30:27 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	pass_index(int i, char c, char *str)
{
	i++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	quote_result(int d_q, int s_q)
{
	if (d_q % 2 != 0 || s_q % 2 != 0)
		return (100);
	return (0);
}

static int	is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

static int	is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int	keyword_quoute_syntax(t_rdl *rdl)
{
	int		i;
	int		d_q;
	int		s_q;
	t_token	*token;

	d_q = 0;
	s_q = 0;
	i = -1;
	if (rdl->token->id != 0)
		return (0);
	token = get_token_id(rdl->token, 0);
	while (++i < (int)ft_strlen(token->context))
	{
		if (token->context[i] == '\"' && d_q++)
		{
			i += pass_index(i, '\"', token->context);
			d_q += is_double_quote(token->context[i]);
		}
		else if (token->context[i] == '\'' && s_q++)
		{
			i += pass_index(i, '\'', token->context);
			s_q += is_single_quote(token->context[i]);
		}
	}
	return (quote_result(d_q, s_q));
}
