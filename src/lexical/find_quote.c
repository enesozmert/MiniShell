/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:49 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 15:17:13 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_quote	find_quote(t_rdl *rdl, char c)
{
	int	i;

	i = -1;
	while (rdl->quote_list[++i].sybl != NULL)
	{
		if (rdl->quote_list[i].sybl[0] == c)
			return (rdl->quote_list[i]);
	}
	return (rdl->quote_list[2]);
}
