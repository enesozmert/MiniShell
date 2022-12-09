/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:22:40 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/09 14:17:29 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_token_type(t_token_type *token_type_list, char *str)
{
	int	i;

	i = -1;
	while (token_type_list[++i].name != NULL)
	{
		if (ft_strncmp(token_type_list[i].name, str,
				ft_strlen(str)) == 0)
			return (1);
	}
	return (0);
}
