/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:04:53 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/17 19:44:15 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	str_to_dest(char *str, char *dest, int *k, int *l)
{
	int		i;
	int		j;
	char	c;

	i = *k;
	j = *l;
	c = str[i];
	i++;
	while (str[i] != c && str[i])
		dest[j++] = str[i++];
	*k = i;
	*l = j;
}

static char	*keyword_trim_dest(char *str, char *dest, int i, int j)
{
	while (str[i])
	{
		if (str[i] == '\'')
		{
			str_to_dest(str, dest, &i, &j);
			if (str[i++] == '\'')
				continue ;
		}
		else if (str[i] == '\"')
		{
			str_to_dest(str, dest, &i, &j);
			if (str[i++] == '\"')
				continue ;
		}
		else
		{
			dest[j++] = str[i++];
			continue ;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*keyword_trim(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	j = 0;
	dest = NULL;
	len = keyword_trim_len(str);
	dest = malloc(sizeof(char) * len);
	dest = keyword_trim_dest(str, dest, i, j);
	return (dest);
}
