/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:20 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:15:05 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_operator	find_operator(t_operator *operator_list, char c)
{
	int	i;

	i = -1;
	while (operator_list[++i].sybl != NULL)
	{
		if (operator_list[i].sybl[0] == c)
			return (operator_list[i]);
	}
	return (operator_list[5]);
}
