/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keyword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:15:10 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:13:35 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_keyword	find_keyword(t_keyword *keyword_list, char *str)
{
	int	i;

	i = -1;
	while (keyword_list[++i].type != NULL)
	{
		if (ft_strnstr(keyword_list[i].type, str,
				ft_strlen(keyword_list[i].type)))
			return (keyword_list[i]);
	}
	return (keyword_list[7]);
}
