/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1free_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:37:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/17 18:38:45 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char *s1free_join(char *s1, char *s2)
{
	unsigned int counter;
	unsigned int counter2;
	char *ret_val;
	if (s1 == 0)
	{
		s1 = malloc(sizeof(char));
		s1[0] = 0;
	}

	ret_val = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));

	counter = 0;
	while (s1[counter])
	{
		*(ret_val + counter) = *(s1 + counter);
		counter++;
	}
	counter2 = 0;
	while (s2[counter2])
	{
		*(ret_val + counter + counter2) = *(s2 + counter2);
		counter2++;
	}
	*(ret_val + counter + counter2) = 0;
	free(s1);

	return (ret_val);
}