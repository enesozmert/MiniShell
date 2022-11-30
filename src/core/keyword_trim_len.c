/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_trim_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:44:35 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 13:06:56 by cyalniz          ###   ########.fr       */
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