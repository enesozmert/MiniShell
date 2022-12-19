/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:56 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:08:56 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	token_size(t_token *token)
{
	int	size;

	size = 0;
	while (token)
	{
		token = token->next;
		size++;
	}
	return (size);
}
