/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keywords_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:43 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 15:12:10 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	commands_size(t_keyword *keywords)
{
	int	i;

	i = 0;
	while (keywords[i].type != NULL)
		i++;
	return (i);
}
