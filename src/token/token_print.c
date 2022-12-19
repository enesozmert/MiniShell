/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:54:58 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:55:16 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	print_token(t_token *token)
{
	int	size;

	size = 0;
	printf("-------------------\n");
	while (token)
	{
		ft_putnbr_fd((token)->id, 1);
		ft_putstr_fd(" \ttoken->id ", 1);
		ft_putstr_fd((token)->context, 1);
		ft_putstr_fd(" \t\t\ttoken->type->id ", 1);
		ft_putnbr_fd((token)->type_id, 1);
		ft_putstr_fd(" \t\ttoken->t_flag ", 1);
		ft_putnbr_fd((token)->t_flag, 1);
		ft_putstr_fd(" \t\ttoken->keyword_id ", 1);
		ft_putnbr_fd((token)->keyword_id, 1);
		ft_putstr_fd("\n", 1);
		token = token->next;
		size++;
	}
	printf("-------------------\n");
	return (size);
}
