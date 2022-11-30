/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:39:08 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 12:40:21 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	option_count(t_token *token)
{
	int		i;
	int		count;
	t_token	*tmp;

	i = -1;
	tmp = token;
	count = 0;
	while (++i < token_size(tmp))
	{
		if (tmp->context[0] == '-')
			count++;
		get_next_token(&tmp);
	}
	return (count);
}
