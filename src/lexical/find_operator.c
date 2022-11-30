/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:20 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 15:16:44 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_operator	find_operator(t_rdl *rdl, char c)
{
	int	i;

	i = -1;
	while (rdl->operator_list[++i].sybl != NULL)
	{
		if (rdl->operator_list[i].sybl[0] == c)
			return (rdl->operator_list[i]);
	}
	return (rdl->operator_list[5]);
}
