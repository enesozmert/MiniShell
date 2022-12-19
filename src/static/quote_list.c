/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:27:08 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:27:23 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	quote_list(t_quote *quote)
{
	quote[0] = (t_quote){"single_quote", "\'"};
	quote[1] = (t_quote){"double_quote", "\""};
	quote[2] = (t_quote){NULL, NULL};
}
