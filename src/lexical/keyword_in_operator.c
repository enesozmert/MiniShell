/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_in_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:59:12 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 21:43:00 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	keyword_in_operator(t_rdl *rdl, int keyword_id, char operator)
{
	int			i;
	int			operator_id;
	char		**operators_id;

	if (is_operator(rdl->operator_list, operator) == 0)
		return (0);
	i = -1;
	operator_id = -1;
	if (rdl->keyword_list[keyword_id].operators_id == NULL)
		return (0);
	operators_id = ft_split(rdl->keyword_list[keyword_id].operators_id, ',');
	while (rdl->operator_list[++operator_id].name != NULL)
	{
		if (rdl->operator_list[operator_id].sybl[0] == operator)
			break ;
	}
	while (operators_id[++i])
	{
		if (operator_id == ft_atoi(operators_id[i]))
			return (1);
	}
	ft_free_dbl_str(operators_id);
	return (0);
}
