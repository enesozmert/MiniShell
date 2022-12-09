/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keyword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:15:10 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 11:24:52 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_keyword	find_keyword(t_rdl *rdl, char *str)
{
	int	i;

	i = -1;
	while (rdl->keyword_list[++i].type != NULL)
	{
		if (ft_strnstr(rdl->keyword_list[i].type, str,
				ft_strlen(rdl->keyword_list[i].type)))
			return (rdl->keyword_list[i]);
	}
	return (rdl->keyword_list[7]);
}
