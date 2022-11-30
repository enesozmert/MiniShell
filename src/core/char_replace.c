/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:43:19 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 13:05:12 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*char_replace(char *str, char find, char replace)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
	return (str);
}
