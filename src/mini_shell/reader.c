/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:40:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 16:19:29 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*ft_read_line(void)
{
	char	*str;

	str = readline("->");
	if (!str)
	{
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
	return (str);
}
