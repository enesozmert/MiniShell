/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:20:18 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 11:18:16 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_operator(t_operator *operator_list, char c)
{
	int	i;

	i = -1;
	while (operator_list[++i].sybl != NULL)
	{
		if (operator_list[i].sybl[0] == c)
			return (1);
	}
	return (0);
}
