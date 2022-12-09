/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keyword_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:13:47 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:14:40 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	find_keyword_id(t_keyword *keyword_list, char *str)
{
	int	i;

	i = -1;
	while (keyword_list[++i].type != NULL)
	{
		if (ft_strnstr(keyword_list[i].type, str,
				ft_strlen(keyword_list[i].type)))
			return (i);
	}
	return (-1);
}
