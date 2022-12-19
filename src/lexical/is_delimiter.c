/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delimiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:17:22 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:14:15 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_delimiter(t_delimiter *delimiter_list, char c)
{
	int	i;

	i = -1;
	while (delimiter_list[++i].sybl != NULL)
	{
		if (delimiter_list[i].sybl[0] == c)
			return (1);
	}
	return (0);
}
