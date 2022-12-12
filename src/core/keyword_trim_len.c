/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_trim_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:44:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 12:12:21 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	j_pos(int *k, int *l, char *str, char c)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = *k;
	j = *l;
	while (str[i] != c && str[i++])
		j++;
	if (str[i++] == c)
		flag = 1;
	*k = i;
	*l = j;
	return (flag);
}

int	keyword_trim_len(char *str)
{
	int	i;
	int	j;	
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str[i])
	{
		flag = 0;
		if (str[i++] == '\'')
			flag = j_pos(&i, &j, str, '\'');
		else if (str[i++] == '\"')
			flag = j_pos(&i, &j, str, '\"');
		else
		{
			flag = 1;
			j++;
			i++;
		}
		if (flag == 0)
			i++;
	}
	return (j);
}
