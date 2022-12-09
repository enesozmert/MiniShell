/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:49 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 11:29:35 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_quote	find_quote(t_quote *quote_list, char c)
{
	int	i;

	i = -1;
	while (quote_list[++i].sybl != NULL)
	{
		if (quote_list[i].sybl[0] == c)
			return (quote_list[i]);
	}
	return (quote_list[2]);
}
