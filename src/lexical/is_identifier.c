/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:18:26 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 13:45:54 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_identifier(t_identifier *identifier_list, char *str)
{
	int	i;

	i = -1;
	while (identifier_list[++i].sybl != NULL)
	{
		if (identifier_list[i].sybl[0] == str[0]
			|| (ft_isalnum(str[0]) == 0))
			return (0);
	}
	return (1);
}
