/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:17:52 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:26:54 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	operator_list(t_operator *operator)
{
	operator[0] = (t_operator){"and", "&"};
	operator[1] = (t_operator){"equal", "="};
	operator[2] = (t_operator){NULL, NULL};
}
