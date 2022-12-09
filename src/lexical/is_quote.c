/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:48 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:15:54 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_quote(t_quote *quote_list, char c)
{
	int	i;

	i = -1;
	while (quote_list[++i].sybl != NULL)
	{
		if (quote_list[i].sybl[0] == c)
			return (1);
	}
	return (0);
}
