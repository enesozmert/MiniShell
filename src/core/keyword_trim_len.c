/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_trim_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:44:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/25 10:45:46 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int keyword_trim_len(char *str)
{
    int i;
	int j;	
	int flag;

	i = 0;
	j = 0;
    flag = 0;
	// if (ft_strncmp(str, "\'", ft_strlen(str)) != 0 && ft_strncmp(str, "\"", ft_strlen(str)) != 0)
	// 	return (ft_strlen(str));
	while(str[i])
	{
	    flag = 0;
		if(str[i] == '\'')
		{
			i++;
			while(str[i] != '\'' && str[i])
			{
				i++;
				j++;
			}
			if(str[i] == '\''){
			    flag = 1;
			    i++;
			}
		}
		else if(str[i] == '\"')
		{
			i++;
			while( str[i] != '\"' && str[i])
			{
				i++;
				j++;
			}
			if(str[i] == '\"')
			{
			    flag = 1;
			    i++;
			}
		}
		else
		{
		    flag = 1;
		    j++;
		    i++;
		}
		if(flag == 0)
		    i++;
	}
	return (j);
}