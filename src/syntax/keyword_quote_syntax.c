/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_quote_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:03:57 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/18 01:12:14 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	pass_index(int *k, char c, char *str)
{
	int i;

	i = *k;
	while (str[i] != c && str[i] != '\0')
		++i;
	*k = i;
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
	t_token	*token;

	i = -1;
	if (rdl->token->id != 0)
		return (0);
	token = get_token_id(rdl->token, 0);
	while (++i < (int)ft_strlen(token->context))
	{
		if (is_double_quote(token->context[i]))
		{
			pass_index(&i, '\"', token->context);
			rdl->quote_prop->k_dq++;
		}
		else if (is_single_quote(token->context[i]))
		{
			pass_index(&i, '\'', token->context);
			rdl->quote_prop->k_sq++;
		}
	}
	printf("dq : %d, sq : %d\n",rdl->quote_prop->k_dq, rdl->quote_prop->k_sq);
	return (quote_result(rdl->quote_prop->k_dq, rdl->quote_prop->k_sq));
}
