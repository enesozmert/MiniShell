/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:20:18 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 15:20:46 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_operator(t_rdl *rdl, char c)
{
	int	i;

	i = -1;
	while (rdl->operator_list[++i].sybl != NULL)
	{
		if (rdl->operator_list[i].sybl[0] == c)
			return (1);
	}
	return (0);
}
