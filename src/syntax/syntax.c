/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:08:49 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:16:05 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	syntax(t_rdl *rdl)
{
	int	i;

	i = -1;
	while (++i < token_size(rdl->token))
	{
		if (exception_handler(rdl) == -1)
			return (-1);
		get_next_token(&rdl->token);
	}
	return (0);
}
